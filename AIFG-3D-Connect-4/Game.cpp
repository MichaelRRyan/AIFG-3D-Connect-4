/// <summary>
/// @author Michael R Ryan & Mantas Zalnierius
/// @date 26/11/2021
/// </summary>

#include "Game.h"
#include <iostream>

///////////////////////////////////////////////////////////////////////////////
Game::Game() :
	m_WINDOW_WIDTH{ 800u },
	m_WINDOW_HEIGHT{ 600u },
	//m_window{ sf::VideoMode{ m_WINDOW_WIDTH, m_WINDOW_HEIGHT, 32U }, "SFML Game" },
	m_exitGame{false},
	m_rulesHandler{ m_gameBoard }
{
	m_renderer = new ConsoleGameBoardRenderer();
	m_renderer->setGameBoard(&m_gameBoard);
	m_rulesHandler.setOnGameOverFunction(
		[&](PieceType t_winner) { onGameOver(t_winner); });
}

///////////////////////////////////////////////////////////////////////////////
Game::~Game()
{
	if (m_renderer) delete m_renderer;
}

///////////////////////////////////////////////////////////////////////////////
void Game::run()
{	
	//sf::Clock clock;
	//sf::Time timeSinceLastUpdate = sf::Time::Zero;
	//const float fps{ 60.0f };
	//sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (!m_exitGame)
	{
		update(1.0f);

		//processEvents(); // as many as possible
		//timeSinceLastUpdate += clock.restart();
		//while (timeSinceLastUpdate > timePerFrame)
		//{
		//	timeSinceLastUpdate -= timePerFrame;
		//	processEvents(); // at least 60 fps
		//	update(timePerFrame.asSeconds()); //60 fps
		//}
		//render(); // as many as possible
	}
}

///////////////////////////////////////////////////////////////////////////////
void Game::processEvents()
{
	

	//sf::Event newEvent;
	//while (m_window.pollEvent(newEvent))
	//{
	//	if ( sf::Event::Closed == newEvent.type) // window message
	//		exit();

	//	else if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
	//		processKeys(newEvent);
	//}
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
	m_renderer->render();
	m_rulesHandler.update();
}

///////////////////////////////////////////////////////////////////////////////
void Game::render()
{
	//m_window.clear(sf::Color::Black);
	
	//m_consoleRenderer->render();
	
	//m_window.display();
}

///////////////////////////////////////////////////////////////////////////////
void Game::exit()
{
	//m_window.close();
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

	m_exitGame = true;
}

///////////////////////////////////////////////////////////////////////////////