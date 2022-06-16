#include "Program.h"
#include "Utility/Utility.h"
#include "Utility/Resources.h"
Program::Program() 
	: highScoreManager(new HighScoreManager(this)), game (new GameScene(this, deltaTime)), sceneManager(new SceneManager(this)), menu (new MenuScene(this))
	, levelSelectorOriginal(new LevelSelectorOriginal(this)), tutorialScene(new TutorialScene(this))
		
{
	int screenWidth  = PixelSizes::GetInstance().windowResolution.x;
	int screenHeight = PixelSizes::GetInstance().windowResolution.y;
	InitializeWindow(screenWidth, screenHeight, windowTitle);
	sceneManager->LoadScene(Scenes::Menu);
	highScoreManager->LoadScores();
}

Program::~Program()
{
	delete sceneManager;
	delete levelSelectorOriginal;
	delete menu;
	delete game;
	delete window;
	delete highScoreManager;
	delete tutorialScene;
}

void Program::InitializeWindow(unsigned int width, unsigned int height, std::string title)
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), title, sf::Style::Titlebar | sf::Style::Close);
	window->setPosition(PixelSizes::GetInstance().windowPosition);
}

void Program::CalculateDeltaTime()
{
	deltaTime = clock.restart().asSeconds();
}

void Program::UpdateEvents()
{	
	while (window->pollEvent(this->sfEvent))
	{
		if (sfEvent.type == sf::Event::Closed)
		{
			profiler.SaveProfile(); 
			CloseWindow();
		}
	}
}

void Program::Update()
{
	UpdateEvents();
	CalculateDeltaTime();

	sceneManager->Update(deltaTime);
}

void Program::Render()
{
	window->clear(backgroundColor);

	window->draw(*sceneManager);
	
	window->display();
}

void Program::CloseWindow()
{
	window->close();
}

void Program::Run()
{
	while (window->isOpen())
	{
		Update();
		Render();
		profiler.Update();
	}
}
