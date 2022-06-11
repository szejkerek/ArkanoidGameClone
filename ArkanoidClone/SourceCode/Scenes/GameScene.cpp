#include "GameScene.h"
#include "../Program.h"
#include <ranges>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <iostream>

GameScene::GameScene(Program* _program, float& _deltaTime) : program(_program), Scene(_program) 
{
	
	backgroundBehind.setSize(static_cast<sf::Vector2f>( PixelSizes::GetInstance().windowResolution ));
	backgroundBehind.setTexture(ResourceManager::Get().GetTexture("backgroundGame"));

	

	srand(time(NULL));
	StartGame(); 
}

void GameScene::StartGame() //Preload level
{
	FreeMemory();

	if(background == nullptr)
	background = new Background(this);

	if (vaus == nullptr)
	vaus = new Vaus();

	if (healthManager == nullptr)
	healthManager = new HealthManager(this);

	if (powerUpManager == nullptr)
	powerUpManager = new PowerUpManager(program);
	
	if (endScreen == nullptr)
		endScreen = new EndScreen(program);

	if (balls.size() == 0)
	{
		balls.push_back(  new Ball(this) );
		balls[0]->SetPlaygroundConstrains(background->GetCollider());
		balls[0]->StickBallToVaus();
	}

	healthManager->RestoreFullHp();
	playable = true;
	SetUpScoresText();
	background->PickBackground(program->levelSelectorOriginal->GetIndex());
}

void GameScene::FreeMemory()
{
	for (size_t i = 0; i < balls.size(); i++)
	{
		if (balls[i] != nullptr)
		{
			delete balls[i];
			balls[i] = nullptr;
		}
	}

	for (size_t i = 0; i < balls.size(); i++)
	{
		delete balls[i];
		balls[i] = nullptr;
	}
	balls.clear();

	delete background;
	delete vaus;
	delete healthManager;
	delete scoreCount;
	delete highScoreCount;
	delete highscoreNotification;
	delete scoreLabel;
	delete highScoreLabel;
	delete powerUpManager;
	delete endScreen;

	background = nullptr;
	vaus = nullptr;
	healthManager = nullptr;
	scoreCount = nullptr;
	highScoreCount = nullptr;
	highscoreNotification = nullptr;
	scoreLabel = nullptr;
	highScoreLabel = nullptr;
	powerUpManager = nullptr;
	endScreen = nullptr;
}

void GameScene::AddBall()
{
	Ball* newBall = new Ball(this);
	newBall->SetPlaygroundConstrains(background->GetCollider());
	newBall->SetPosition(balls[0]->GetPosition());


	float randomX= static_cast<float> (rand() % 30 + 10);
	float randomY = static_cast<float> (rand() % 30 + 10);

	sf::Vector2f newAngles = NormalizeVector({randomX, randomY });
	sf::Vector2f newDirection =  MultipyVectors( balls[0]->GetDirection(), newAngles);

	newBall->ChangeDirection(newDirection);
	balls.push_back(newBall);
}

void GameScene::RemoveBall(Ball* ballToDelete)
{
	auto ret = std::ranges::remove_if(balls, [&](Ball* ball) { return ball == ballToDelete; });
	balls.erase(ret.begin(), ret.end());

	delete ballToDelete;
	ballToDelete = nullptr;
}

void GameScene::RemoveBallNoDelete(Ball* ballToDelete)
{
	auto ret = std::ranges::remove_if(balls, [&](Ball* ball) { return ball == ballToDelete; });
	balls.erase(ret.begin(), ret.end());
	ballsToDelete.push_back(ballToDelete);
}

void GameScene::SetUpScoresText()
{
	float screenWidth = static_cast<float>(PixelSizes::GetInstance().windowResolution.x);

	if(highScoreLabel == nullptr)
	highScoreLabel = new TextElement(program);

	if (scoreLabel == nullptr)
	scoreLabel = new TextElement(program);

	if (highScoreCount == nullptr)
	highScoreCount = new TextElement(program);

	if (scoreCount == nullptr)
	scoreCount = new TextElement(program);

	if (highscoreNotification == nullptr)
	highscoreNotification = new TextElement(program);

	highScoreLabel->SetTextPosition({ screenWidth - 184 ,170});
	highScoreCount->SetTextPosition({ screenWidth - 184 ,190});
	highscoreNotification->SetTextPosition({ screenWidth - 184 ,145});

	highScoreLabel->SetText("Highscore", 12, sf::Color::Color(140,140,140));
	highscoreNotification->SetText("", 8, sf::Color::Yellow);
	highScoreCount->SetText(std::to_string(currentHighscore), 18, sf::Color(140, 140, 140));

	scoreLabel->SetTextPosition({ screenWidth - 184 ,240 });
	scoreCount->SetTextPosition({ screenWidth - 184 ,275 });
	scoreLabel->SetText("Score", 20, sf::Color::White);
	scoreCount->SetText("0", 35, sf::Color::White);

	highscoreNotification->Disable();
}

void GameScene::UpdateScores()
{
	highScoreCount->SetText(std::to_string(currentHighscore), 18, sf::Color(140, 140, 140));
	scoreCount->SetText(std::to_string(currentScore), 35, sf::Color::White);
}

GameScene::~GameScene()
{
	FreeMemory();
}

void GameScene::AddPoints(const int& brickPoint, const int& multiplyier)
{
	currentScore += brickPoint * multiplyier;
	if (currentScore > currentHighscore)
	{
		if (program->highScoreManager->GetCurrentHighscore(currentStage) != 0)
		{
			highscoreNotification->SetText("NEW HIGHSCORE!", 16, sf::Color::Yellow);
		}
		currentHighscore = currentScore;
	}

	UpdateScores();
}

void GameScene::SelectStage(Stage* _stage)
{
	currentStage = _stage;
	currentHighscore = program->highScoreManager->GetCurrentHighscore(currentStage);
	SetUpScoresText();
	
}

void GameScene::EndGame(bool win)
{
	if (win)
		endScreen->SetWinning();

	for (size_t i = 0; i < balls.size(); i++)
		balls[i]->StickBallToVaus();

	playable = false;
	ballAirTime = 0;
	program->highScoreManager->UpdateScore(currentStage, currentScore);
	program->highScoreManager->SaveScores();
	currentScore = 0;
	powerUpManager->FreeMemory();
	
}

void GameScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	
	
		target.draw(backgroundBehind);
		target.draw(*background);
		target.draw(*currentStage);
		target.draw(*vaus);
		target.draw(*healthManager);

		if (playable)
			for (size_t i = 0; i < balls.size(); i++)
			{
				if (balls[i] != nullptr)
					target.draw(*balls[i]);
			}

		
		target.draw(*powerUpManager);


		target.draw(*highScoreLabel);
		target.draw(*scoreLabel);
		target.draw(*highScoreCount);
		target.draw(*highscoreNotification);
		target.draw(*scoreCount);


		if(!playable)
			target.draw(*endScreen);



}

void GameScene::Update( float& dt )
{
	if (playable)
	{

		ballAirTime += dt; //GameTime

		for (size_t i = 0; i < balls.size(); i++)
		{
			if (balls[i] != nullptr)
				balls[i]->Update(dt);
		}

		vaus->Update(dt);
		powerUpManager->Update(dt);
		currentStage->Update(dt);

	}
	else
	{
		vaus->Update(dt);
		endScreen->Update(dt);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		for (size_t i = 0; i < balls.size(); i++)
			balls[i]->StickBallToVaus();

		playable = false;
		ballAirTime = 0;
		program->highScoreManager->UpdateScore(currentStage, currentScore);
		program->highScoreManager->SaveScores();
		currentScore = 0;
		powerUpManager->FreeMemory();
		FreeMemory();
		program->sceneManager->LoadScene(Scenes::LevelSelectorOriginal);
	}
}

