#include "Stage.h"
#include "Bricks.h"
#include "../Utility/Utility.h"
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <filesystem>

Stage::Stage(const int& _stageNumber) :stageNumber(_stageNumber)
{
	LoadVectorFromFile("Stage_1.txt", StageType::original);
}

Stage::~Stage()
{	
	for (auto brick : playableBricks)
	{
		if (brick != nullptr)
			delete brick;
	}
}

inline void Stage::LoadVectorFromFile(const std::string& filename, const StageType& stageType)
{
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

	if (!std::filesystem::exists(path))
	{
		std::cout << "Error: Couldn`t find file" << std::endl;
		std::cout << path.string() << std::endl;
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
		std::cerr << "Error: Loaded stage was too large." << std::endl;
		std::cout << "Expected size = " << expectedSize << std::endl;
		std::cout << "File size =" << fileSize << std::endl;
		return false;
	}
	else if(fileSize < expectedSize)
	{
		std::cerr << "Error: Loaded stage was too small." << std::endl;
		std::cout << "Expected size = " << expectedSize << std::endl;
		std::cout << "File size =" << fileSize << std::endl;
		return false;
	}

	std::regex validate("[sxwotgrbpy\\*]");
	std::vector<char> validSymbols{ '*','s','x','w','o','t','g','r','b','p','y' };

	for (char brickChar : brickChars)
	{
		std::string s(1, brickChar);
		if (!std::regex_match(s, validate))
		{
			std::cerr << "Error: Invalid character found in stage file \"" << s << "\"" << std::endl;
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
		playableBricks.push_back( SetUpBrick(row, collumn, brickChar) );

		collumn++;
		if (collumn == BRICK_COLUMNS)
		{
			collumn = 0;
			row++;
		}
	}
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
	for (int i = 0; i < playableBricks.size(); i++)
	{
		if (playableBricks[i] == nullptr)
			continue;
		if (playableBricks[i] != brickToDelete)
			continue;

		if (brickToDelete->OnCollisionEnter())
		{
			delete playableBricks[i];
			playableBricks[i] = nullptr;
		}
	}
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


