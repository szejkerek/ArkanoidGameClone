#include "LevelSelectorScene.h"
#include "../Program.h"
#include "../Utility/Utility.h"

LevelSelectorScene::LevelSelectorScene(Program* _program) : Scene(_program)
{
	SetUpScene();
}

LevelSelectorScene::~LevelSelectorScene()
{
	delete backToMenuBtn;
	delete playBtn;
	delete nextStageBtn;
	delete previousStageBtn;

	for (auto stage : stages)
	{ 
		if(stage != nullptr)
		delete stage;
	}
}

void LevelSelectorScene::SetUpScene()
{
	sf::Vector2f window = static_cast<sf::Vector2f>(PixelSizes::GetInstance().windowResolution);
	float screenMargin = 0;
	float buttonPadding = 150;

	preview.setSize({ 500, 660 });
	preview.setOrigin(preview.getSize().x/2, preview.getSize().y / 2);
	preview.setPosition({ window.x / 2,window.y / 2 });
	
	backToMenuBtn = new Button(program);
	playBtn = new Button(program);
	nextStageBtn = new Button(program);
	previousStageBtn = new Button(program);

	backToMenuBtn->PlaceOnScene({ screenMargin + backToMenuBtn->GetSize().x, window.y - backToMenuBtn->GetSize().y - screenMargin}, {150,75}, "Back", Scenes::Menu);
	playBtn->PlaceOnScene({ window.x / 2, window.y - playBtn->GetSize().y - screenMargin }, { 150,75 }, "Play");

	nextStageBtn->PlaceOnScene({ window.x / 2 + buttonPadding, screenMargin + nextStageBtn->GetSize().y }, { 75,75 });
	previousStageBtn->PlaceOnScene({ window.x/2 - buttonPadding,screenMargin + previousStageBtn->GetSize().y }, { 75,75 });

	nextStageBtn->SetOnClickFunction(std::bind(&LevelSelectorScene::IncrementIndex, this));
	previousStageBtn->SetOnClickFunction(std::bind(&LevelSelectorScene::DecrementIndex, this));
	playBtn->SetOnClickFunction(std::bind(&LevelSelectorScene::LoadGame, this));
}

void LevelSelectorScene::IncrementIndex()
{
	if (currentIndex < stages.size())
		currentIndex++;

	SetFullPreview();
}

void LevelSelectorScene::DecrementIndex()
{
	if (currentIndex > 0)
		currentIndex--;

	SetFullPreview();
}

void LevelSelectorScene::LoadGame()
{
	if (stages[currentIndex] != nullptr)
	{
		program->game->SelectStage(stages[currentIndex]);
		program->sceneManager->LoadScene(Scenes::Game);

	}
	else
	{
		preview.setTexture(ResourceManager::Get().GetTexture("StageNotFound"));
	}

}

void LevelSelectorScene::SetFullPreview()
{
	if (stages[currentIndex] != nullptr)
	{
		playBtn->Enable();
		preview.setTexture(stages[currentIndex]->GetPreview());
		
	}
	else
	{
		playBtn->Disable();
		preview.setTexture(ResourceManager::Get().GetTexture("StageNotFound"));
	}
}

void LevelSelectorOriginal::LoadStages()
{
	for (int i = 0; i < 33; i++)
	{
		Stage* tempStage = new Stage(i);
		if (tempStage->LoadedSucessfuly())
		{
			stages.push_back(tempStage);
		}
		else
		{
			delete tempStage;
			stages.push_back(nullptr);
		}
	}
}

void LevelSelectorCustom::LoadStages()
{
	for (int i = 0; i < 33; i++)
	{
		Stage* tempStage = new Stage(i);
		if (tempStage->LoadedSucessfuly())
		{
			stages.push_back(tempStage);
		}
		else
		{
			delete tempStage;
			stages.push_back(nullptr);
		}
	}
}

void LevelSelectorScene::Update(float& dt)
{
	backToMenuBtn->Update(dt);
	playBtn->Update(dt);
	nextStageBtn->Update(dt);
	previousStageBtn->Update(dt);
}

void LevelSelectorScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*backToMenuBtn);
	target.draw(*playBtn);
	target.draw(*nextStageBtn);
	target.draw(*previousStageBtn);
	target.draw(preview);
}