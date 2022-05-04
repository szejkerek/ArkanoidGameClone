#include "LevelSelectorScene.h"
#include "../Program.h"
#include "../Utility/Utility.h"

void LevelSelectorScene::CreateButtnos()
{
	backToMenuBtn = new Button(program);
	playBtn = new Button(program);
	nextStageBtn = new Button(program);
	previousStageBtn = new Button(program);
	programableSwapStageBtn = new Button(program);
}

void LevelSelectorScene::LayoutButtons()
{
	sf::Vector2f window = static_cast<sf::Vector2f>(PixelSizes::GetInstance().windowResolution);
	float screenMargin = 0;
	float buttonPadding = 150;

	backToMenuBtn->PlaceOnScene({ screenMargin + backToMenuBtn->GetSize().x, window.y - backToMenuBtn->GetSize().y - screenMargin }, ButtonType::RectangleMedium, "Back", Scenes::Menu);
	playBtn->PlaceOnScene({ window.x / 2, window.y - playBtn->GetSize().y - screenMargin }, ButtonType::RectangleBig, "Play");
	programableSwapStageBtn->PlaceOnScene({ window.x - screenMargin - programableSwapStageBtn->GetSize().x, window.y - programableSwapStageBtn->GetSize().y - screenMargin }, ButtonType::RectangleMedium, "Play");

	nextStageBtn->PlaceOnScene({ window.x / 2 + buttonPadding, screenMargin + nextStageBtn->GetSize().y }, ButtonType::squareMedium);
	previousStageBtn->PlaceOnScene({ window.x / 2 - buttonPadding,screenMargin + previousStageBtn->GetSize().y }, ButtonType::squareMedium);

	nextStageBtn->SetOnClickFunction(std::bind(&LevelSelectorScene::IncrementIndex, this));
	previousStageBtn->SetOnClickFunction(std::bind(&LevelSelectorScene::DecrementIndex, this));
	playBtn->SetOnClickFunction(std::bind(&LevelSelectorScene::LoadGame, this));
}

LevelSelectorScene::LevelSelectorScene(Program* _program) : Scene(_program)
{
	CreateButtnos();
}

LevelSelectorScene::~LevelSelectorScene()
{
	delete backToMenuBtn;
	delete playBtn;
	delete nextStageBtn;
	delete previousStageBtn;
	delete programableSwapStageBtn;

	for (auto stage : stages)
	{ 
		if(stage != nullptr)
		delete stage;
	}
}

void LevelSelectorScene::SetUpScene()
{
	sf::Vector2f window = static_cast<sf::Vector2f>(PixelSizes::GetInstance().windowResolution);
	preview.setSize({ 500, 660 });
	preview.setOrigin(preview.getSize().x / 2, preview.getSize().y / 2);
	preview.setPosition({ window.x / 2,window.y / 2 });

	LayoutButtons();
	ChoosePreviewImage();

}

void LevelSelectorScene::IncrementIndex()
{
	if (currentIndex < stages.size() - 1)
		currentIndex++;


	ChoosePreviewImage();
}

void LevelSelectorScene::DecrementIndex()
{
	if (currentIndex > 0)
		currentIndex--;


	ChoosePreviewImage();
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

void LevelSelectorScene::ChoosePreviewImage()
{
	if (currentIndex == 0)
		previousStageBtn->Disable();
	else
		previousStageBtn->Enable();


	if (currentIndex == stages.size() - 1)
		nextStageBtn->Disable();
	else
		nextStageBtn->Enable();

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
	for (int i = 0; i < 5; i++) //TODO change to 33
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

LevelSelectorCustom::LevelSelectorCustom(Program* _program) : LevelSelectorScene(_program)
{
	LoadStages();
	SetUpScene();
	programableSwapStageBtn->LoadSceneOnClick(Scenes::LevelSelectorOriginal);
}

LevelSelectorOriginal::LevelSelectorOriginal(Program* _program) : LevelSelectorScene(_program)
{
	LoadStages();
	SetUpScene();
	programableSwapStageBtn->LoadSceneOnClick(Scenes::LevelSelectorCustom);

}

void LevelSelectorCustom::LoadStages()
{
	std::filesystem::path current = std::filesystem::current_path().append("Resources/Stages/Custom");

	int i = 0;
	for (std::filesystem::directory_entry entry : std::filesystem::directory_iterator(current))
	{	
		Stage* tempStage = new Stage(i, entry.path().stem().string(), StageType::custom);
		if (tempStage->LoadedSucessfuly())
		{
			stages.push_back(tempStage);
		}
		else
		{
			stages.push_back(nullptr);
			delete tempStage;
		}

		i++;
	}
}

void LevelSelectorScene::Update(float& dt)
{
	backToMenuBtn->Update(dt);
	playBtn->Update(dt);
	nextStageBtn->Update(dt);
	previousStageBtn->Update(dt);
	programableSwapStageBtn->Update(dt);
}

void LevelSelectorScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*backToMenuBtn);
	target.draw(*playBtn);
	target.draw(*nextStageBtn);
	target.draw(*previousStageBtn);
	target.draw(*programableSwapStageBtn);
	target.draw(preview);
}