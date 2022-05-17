#include "Stage.h"
#include "Bricks.h"
#include "../Utility/Utility.h"
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <filesystem>
#include <../ArkanoidClone/SourceCode/Program.h>

inline std::string Stage::GenerateStageName(const int& _stageNumber)
{
	stageName = "Stage_" + std::to_string(_stageNumber);
	return  stageName;
}

Stage::Stage(const int& _stageNumber, Program* _program): program(_program)
{
	LoadStageFromFile(_stageNumber, GenerateStageName(_stageNumber), StageType::original);
}

Stage::Stage(const int& _stageNumber, const std::string& stageName, const StageType& stageType, Program* _program) : program(_program)
{
	LoadStageFromFile(_stageNumber, stageName, stageType);
}

Stage::~Stage()
{	
	//std::cout << stageName << std::endl;
	for (auto brick : playableBricks)
	{
		if (brick != nullptr)
			delete brick;
	}

}

inline void Stage::LoadStageFromFile(const int& _stageNumber, const std::string& filename, const StageType& stageType)
{
	stageNumber = _stageNumber;
	stageName = filename;
	std::filesystem::path path = std::filesystem::current_path().append("Resources/Stages");
	switch (stageType)
	{
	case StageType::original:
		path.append("Original");
		break;
	case StageType::custom:
		path.append("Custom");
		break;
	}
	path.append(filename);
	path.concat(".txt");

	if (!std::filesystem::exists(path))
	{
		std::cout << "Error: Couldn`t find file of Stage " << stageNumber << std::endl;
		std::cout << path.string() << std::endl << std::endl;
		return;
	}

	std::vector<char> temp;
	std::ifstream file(path);
	if (file)
	{
		char brickChar;
		while (file >> brickChar)
		{
			temp.push_back(brickChar);
		}
	}
	file.close();

	SetUpStage(temp);
}

inline bool Stage::ValidateVector(const std::vector<char>& brickChars)
{
	int expectedSize = BRICK_COLUMNS * BRICK_ROWS;
	size_t fileSize = brickChars.size();
	if (fileSize > expectedSize)
	{
		std::cerr << "Error: Stage " << stageNumber << " is too large." << std::endl;
		std::cout << "Expected size = " << expectedSize << std::endl;
		std::cout << "File size =" << fileSize << std::endl;
		return false;
	}
	else if(fileSize < expectedSize)
	{
		std::cerr << "Error: Stage " << stageNumber << " is too small." << std::endl;
		std::cout << "Expected size = " << expectedSize << std::endl;
		std::cout << "File size = " << fileSize << std::endl;
		return false;
	}

	std::regex validate("[sxwotgrbpy\\*]");
	std::vector<char> validSymbols{ '*','s','x','w','o','t','g','r','b','p','y' };

	for (char brickChar : brickChars)
	{
		std::string s(1, brickChar);
		if (!std::regex_match(s, validate))
		{
			std::cerr << "Error: Invalid character found in stage "<< stageNumber <<" file \"" << s << "\"" << std::endl;
			return false;
		}
	}

	return true;
}

inline void Stage::SetUpStage(const std::vector<char>& brickChars)
{
	if (!ValidateVector(brickChars))
		return;

	int collumn = 0, row = 0;
	for (char brickChar : brickChars)
	{	
		loadedStage.push_back( SetUpBrick(row, collumn, brickChar) );

		collumn++;
		if (collumn == BRICK_COLUMNS)
		{
			collumn = 0;
			row++;
		}
	}

	loadedSuccesfuly = true;
	playableBricks = loadedStage;
}

inline IBrick* Stage::SetUpBrick(const int& row, const int& collumn, const char& brickChar)
{
	IBrick* temp;

	switch (brickChar)
	{
	case '*':
		temp = nullptr;
		break;
	case 's':
		temp = new SilverBrick(stageNumber);
		break;
	case 'x':
		temp = new GoldBrick();
		break;
	case 'w':
		temp = new ColorBrick(ColorsEnum::white);
		break;
	case 'o':
		temp = new ColorBrick(ColorsEnum::orange);
		break;
	case 't':
		temp = new ColorBrick(ColorsEnum::turquoise);
		break;
	case 'g':
		temp = new ColorBrick(ColorsEnum::green);
		break;
	case 'r':
		temp = new ColorBrick(ColorsEnum::red);
		break;
	case 'b':
		temp = new ColorBrick(ColorsEnum::blue);
		break;
	case 'p':
		temp = new ColorBrick(ColorsEnum::pink);
		break;
	case 'y':
		temp = new ColorBrick(ColorsEnum::yelow);
		break;
		
	default:
		std::cerr << "Error: Internal switch failure." << std::endl;
		temp = nullptr;
		break;
	}

	if (temp != nullptr)
		temp->SetRelativePosition(row, collumn);

	return temp;
}

void Stage::CollisionDetected(IBrick* brickToDelete)
{
	int destructibleBlocks = 0;
	for (int i = 0; i < playableBricks.size(); i++)
	{
		if (playableBricks[i] == nullptr)
			continue;	

		if (playableBricks[i] != brickToDelete)
		{
			if (playableBricks[i]->IsDestructible())
			{
				destructibleBlocks++;
			}
			continue;
		}

		if (brickToDelete->OnCollisionEnter())
		{
			delete playableBricks[i];
			playableBricks[i] = nullptr;
		}	
	}

	if (destructibleBlocks == 0)
		WinStage();
	
}

bool Stage::LoadedSucessfuly()
{
	return loadedSuccesfuly;
}

sf::Texture* Stage::GetPreview()
{
	if ( stageName.size() == 0 || ResourceManager::Get().GetTexture("Preview" + stageName) == nullptr)
	{
		return ResourceManager::Get().GetTexture("PreviewNotFound");
	}
	else
	{
		return ResourceManager::Get().GetTexture("Preview" + stageName);
	}
}

std::string Stage::GetStageName()
{
	return stageName;
}

void Stage::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (playableBricks.size() == 0)
		return;

	for (auto& brick : playableBricks)
	{
		if(brick != nullptr)
		target.draw(*brick);
	}
}

void Stage::WinStage()
{
	program->game->EndGame();
}


