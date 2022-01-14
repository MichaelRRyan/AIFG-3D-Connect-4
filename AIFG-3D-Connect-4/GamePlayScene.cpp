#include "GamePlayScene.h"

GamePlayScene::GamePlayScene(Game& t_game, std::function<void(Game&, PieceType)> t_function) :
	Scene(GameState::None),
	m_rulesHandler(t_game, m_gameBoard)
{
	m_renderer = new SfmlGameBoardRenderer(m_grids);
	m_renderer->setGameBoard(&m_gameBoard);
	m_rulesHandler.setOnGameOverFunction(t_function);
	m_turnHandler.setPlayer1(new SfmlInput(m_gameBoard, m_grids));
	m_turnHandler.setPlayer2(new FourTechAI(m_gameBoard, PieceType::Yellow));
	m_rulesHandler.setTurnHandler(&m_turnHandler);
}

GamePlayScene::~GamePlayScene()
{
}

void GamePlayScene::update(float t_deltaTime)
{
	m_rulesHandler.update();
}

void GamePlayScene::render()
{
	m_renderer->render();
}

void GamePlayScene::processEvent(sf::Event t_event)
{
}

void GamePlayScene::setPlayerTypes(PlayerType t_p1, PlayerType t_p2)
{
	// Sets the first player input.
	if (t_p1 == PlayerType::Human)
		m_turnHandler.setPlayer1(new SfmlInput(m_gameBoard, m_grids));
	else
		m_turnHandler.setPlayer1(new FourTechAI(m_gameBoard, PieceType::Red));

	// Sets the second player input.
	if (t_p2 == PlayerType::Human)
		m_turnHandler.setPlayer2(new SfmlInput(m_gameBoard, m_grids));
	else
		m_turnHandler.setPlayer2(new FourTechAI(m_gameBoard, PieceType::Yellow));
}
