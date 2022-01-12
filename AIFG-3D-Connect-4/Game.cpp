/// <summary>
/// @author Michael R Ryan & Mantas Zalnierius
/// @date 26/11/2021
/// </summary>

#include "Game.h"
#include <iostream>

///////////////////////////////////////////////////////////////////////////////
Game::Game() :
	m_exitGame{false},
	m_rulesHandler{ m_gameBoard }
{
	if (!m_font.loadFromFile("ASSETS//FONTS//ariblk.ttf")) {};
	m_renderer = new SfmlGameBoardRenderer(m_grids);
	m_renderer->setGameBoard(&m_gameBoard);
	m_rulesHandler.setOnGameOverFunction(
		[&](PieceType t_winner) { onGameOver(t_winner); });
	TurnHandler* turnHandler = new TurnHandler();
	turnHandler->setPlayer1(new SfmlInput(m_gameBoard, m_grids));
	turnHandler->setPlayer2(new FourTechAI(m_gameBoard));
	m_rulesHandler.setTurnHandler(turnHandler);
}

///////////////////////////////////////////////////////////////////////////////
Game::~Game()
{
	if (m_renderer) delete m_renderer;
}

///////////////////////////////////////////////////////////////////////////////
void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (!m_exitGame)
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		render(); // as many as possible
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame.asSeconds()); //60 fps
			render(); // as many as possible
			if (m_exitGame) break;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
void Game::processEvents()
{
	sf::Event newEvent;
	while (Window::getWindow().pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type) // window message
			exit();

		else if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
			processKeys(newEvent);
		if (sf::Event::MouseButtonPressed == newEvent.type)
		{
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
		exit();
}

///////////////////////////////////////////////////////////////////////////////
void Game::update(float t_delta)
{
	system("cls");
	m_rulesHandler.printMoves();
	std::cout << std::endl;
	m_rulesHandler.update();
}

///////////////////////////////////////////////////////////////////////////////
void Game::render()
{
	m_renderer->render();
}

///////////////////////////////////////////////////////////////////////////////
void Game::exit()
{
	Window::getWindow().close();
}

///////////////////////////////////////////////////////////////////////////////
void Game::onGameOver(PieceType t_winner)
{
	system("cls");
	m_renderer->render();

	if (PieceType::None == t_winner)
		std::cout << "The game was a draw!" << std::endl;
	else if (PieceType::Red == t_winner)
		std::cout << "The red player won!" << std::endl;
	else
		std::cout << "The yellow player won!" << std::endl;

	std::cout << std::endl;
	m_rulesHandler.printMoves();

	m_exitGame = true;
}

void Game::setDifficulty(int t_difficulty)
{
	Minimax::setMaxDepth(t_difficulty);
}

///////////////////////////////////////////////////////////////////////////////