#include "GamePlayScene.h"

GamePlayScene::GamePlayScene(Game& t_game, std::function<void(Game&, PieceType)> t_function) :
	Scene(GameState::None),
	m_rulesHandler(t_game, m_gameBoard)
{
	m_renderer = new SfmlGameBoardRenderer(m_grids);
	m_renderer->setGameBoard(&m_gameBoard);
	m_rulesHandler.setOnGameOverFunction(t_function);
	TurnHandler* turnHandler = new TurnHandler();
	turnHandler->setPlayer1(new SfmlInput(m_gameBoard, m_grids));
	turnHandler->setPlayer2(new FourTechAI(m_gameBoard));
	m_rulesHandler.setTurnHandler(turnHandler);
}

GamePlayScene::~GamePlayScene()
{
}

void GamePlayScene::update(float t_deltaTime)
{
	system("cls");
	m_rulesHandler.printMoves();
	std::cout << std::endl;
	m_rulesHandler.update();
}

void GamePlayScene::render()
{
	m_renderer->render();
}

void GamePlayScene::processEvent(sf::Event t_event)
{
}
