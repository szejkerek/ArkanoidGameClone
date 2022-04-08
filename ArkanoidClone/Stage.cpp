#include "Stage.h"
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>

Stage::Stage(int stageNumber)
{
	LoadMapFromFileToArray(stageNumber);
}

void Stage::GenerateDefaultMapFile(std::string filename)
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
			char letter = stageVector[vectorIndex];

			if (letter == '*')
			{
			stageArray[i][j] = 0;
			}
			else
			{
			stageArray[i][j] = static_cast<int>( stageVector[vectorIndex] );
			}
			
			vectorIndex++;
		}
	}
}

void Stage::LoadMapFromFileToArray(int _stageNumber)
{
	std::vector<char> stageVector;
	std::filesystem::path path = std::filesystem::current_path().append("Stages");
	path.append(GetFilename(_stageNumber)).concat(".txt");

	if (!std::filesystem::exists(path))
	{
		std::cout << "Couldnt find folder Stage" << std::endl;
		return;
	}
	
	std::ifstream file(path);
	if(file)
	{
		
		char brickID;
		while (file >> brickID)
		{
			stageVector.push_back(brickID);
		}
		
	}
	file.close();

	FillStageArray(stageVector);
}



void Stage::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}
