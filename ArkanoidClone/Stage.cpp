#include "Stage.h"
#include "Bricks.h"
#include "Utility.h"
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <filesystem>

bool Stage::CalculateBricksPositions() 
{
	sf::Vector2f startingPosition = playgroundPosition;
	sf::Vector2f offset = PixelSizes::GetInstance().brickSize;

}

void GenerateDefaultMapFile(std::string filename)
{
	std::filesystem::path path = std::filesystem::current_path().append("Stages");
	std::filesystem::create_directory(path);
	path.append(filename).concat(".txt");

	std::ofstream file(path);

	if(file) 
	{
		for (size_t i = 0; i < 21; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				file << "* ";
			}
			file << std::endl;
		}
	}
	file.close();
}

Stage::Stage(int _stageNumber, sf::Vector2f _playgroundPosition): stageNumber(_stageNumber), playgroundPosition(_playgroundPosition)
{
	GenerateDefaultMapFile("default");
	if (!LoadMapFromFileToArray())
	{
		playable = false;
		return;
	}

	SetUpBlocks();

	playable = true;
}

inline std::string GetFilename(int _stageNumber)
{
	if (_stageNumber > 0 && _stageNumber <= 32)
	{
		std::string filename = "Stage_" + std::to_string(_stageNumber);
		return filename;
	}
	return "Stage_1";
}

inline void Stage::FillStageArray(std::vector<char> stageVector)
{
	int vectorIndex = 0;
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			char letter = tolower( stageVector[vectorIndex] );
			stageArray[i][j] = stageVector[vectorIndex];
			
			vectorIndex++;
		}
	}
}

IBrick* Stage::ChooseBrick(char letter)
{
	switch (letter)
	{
	case '*':
		return nullptr;
		break;
	case 's':
		return new SilverBrick(stageNumber);
		break;
	case 'x':
		return new GoldBrick();
		break;
	case 'w':
		return new ColorBrick(ColorsEnum::white);
		break;
	case 'o':
		return new ColorBrick(ColorsEnum::orange);
		break;
	case 't':
		return new ColorBrick(ColorsEnum::turquoise);
		break;
	case 'g':
		return new ColorBrick(ColorsEnum::green);
		break;
	case 'r':
		return new ColorBrick(ColorsEnum::red);
		break;
	case 'b':
		return new ColorBrick(ColorsEnum::blue);
		break;
	case 'p':
		return new ColorBrick(ColorsEnum::pink);
		break;
	case 'y':
		return new ColorBrick(ColorsEnum::yelow);
		break;

	default:
		std::cout << "ERROR, CHECK SYNTAX IN FILE Stage_"<< stageNumber << std::endl;
		return nullptr;
		break;
	}
}

std::vector<char> ReadFile(int _stageNumber)
{
	std::vector<char> tempVector; 
	std::filesystem::path path = std::filesystem::current_path().append("Stages");
	path.append(GetFilename(_stageNumber)).concat(".txt");

	if (!std::filesystem::exists(path))
	{
		std::cout << "Couldnt find folder Stage" << std::endl;
		return tempVector;
	}

	std::ifstream file(path);
	if (file)
	{
		char brickID;
		while (file >> brickID)
		{
			tempVector.push_back(brickID);
		}
	}
	file.close();
	return tempVector;
}

bool ValidateStageArray(char _stageArray[13][21])
{
	std::regex validate("[sxwotgrbpy\\*]");
	std::vector<char> validSymbols{ '*','s','x','w','o','t','g','r','b','p','y' };
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			std::string s(1, _stageArray[i][j]);
			if (!std::regex_match( s , validate))
			{
				std::cerr << "Blad w pliku stage, znaleziono \"" << s << "\"" << std::endl;
				return false;
			}
		}
	}
	return true;
}

bool Stage::LoadMapFromFileToArray()
{
	FillStageArray(ReadFile(stageNumber));
	return ValidateStageArray(stageArray);
}

bool Stage::SetUpBlocks()
{
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			blocks[i][j] = ChooseBrick(stageArray[i][j]);
		}
	}
	return true;
}

void Stage::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}
