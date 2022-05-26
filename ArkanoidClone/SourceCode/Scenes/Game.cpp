#include "Game.h"
#include "../Program.h"

#include <iostream>

GameScene::GameScene(Program* _program, float& _deltaTime) : program(_program), Scene(_program) { InitVariables(); }

void GameScene::InitializeBall()
{
	ball = new Ball(this);
	ball->SetPlaygroundConstrains(background->GetCollider());	
}

void GameScene::InitVariables() //Preload level
{
	FreeMemory();
	background = new Background(this);
	vaus = new Vaus();
	healthManager = new HealthManager(this);
	InitializeBall();
}

void GameScene::FreeMemory()
{
	delete scoreCount;
	delete highScoreCount;
	delete highscoreNotification;
	delete scoreLabel;
	delete highScoreLabel;
	delete background;
	delete ball;
	delete vaus;
	delete healthManager;
}

void GameScene::SetUpScoresText()
{
	float screenWidth = static_cast<float>(PixelSizes::GetInstance().windowResolution.x);

	highScoreLabel = new TextElement(program);
	scoreLabel = new TextElement(program);
	highScoreCount = new TextElement(program);
	scoreCount = new TextElement(program);
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

void GameScene::StartGame()
{	
	healthManager->RestoreFullHp();
	playable = true;	
}

void GameScene::AddPoints(const int& brickPoint)
{
	currentScore += brickPoint * healthManager->GetCurrentHealth();
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

void GameScene::EndGame()
{
	ball->StickBallToVaus();
	playable = false;
	ballAirTime = 0;
	program->highScoreManager->UpdateScore(currentStage, currentScore);
	program->highScoreManager->SaveScores();
	currentScore = 0;
	program->sceneManager->LoadScene(Scenes::Menu);
}

void GameScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (!playable)
		return;

	target.draw(*background);
	target.draw(*currentStage);
	target.draw(*vaus);
	target.draw(*ball);
	target.draw(*healthManager);

	target.draw(*highScoreLabel);
	target.draw(*scoreLabel);
	target.draw(*highScoreCount);
	target.draw(*highscoreNotification);
	target.draw(*scoreCount);


}

void GameScene::Update( float& dt )
{
	if (!playable)
		return;
	
	ballAirTime += dt; //GameTime
	ball->Update(dt);	
	vaus->Update(dt);	
}

