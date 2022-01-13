/// <summary>
/// @author Michael R Ryan & Mantas Zalnierius
/// @date 26/11/2021
/// </summary>

#include "Game.h"
#include <iostream>

///////////////////////////////////////////////////////////////////////////////
Game::Game() :
	m_exitGame{false}
{
	if (!m_font.loadFromFile("ASSETS//FONTS//ariblk.ttf")) {};
	m_sceneManager = new SceneManager(*this, &Game::onGameOver, m_font);
}

///////////////////////////////////////////////////////////////////////////////
Game::~Game()
{
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
		if (sf::Event::MouseButtonPressed == newEvent.type || sf::Event::MouseMoved == newEvent.type)
		{
			m_sceneManager->processEvent(newEvent);
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
	m_sceneManager->update(t_delta);
}

///////////////////////////////////////////////////////////////////////////////
void Game::render()
{
	m_sceneManager->render();
}

///////////////////////////////////////////////////////////////////////////////
void Game::exit()
{
	m_exitGame = true;
	Window::getWindow().close();
}

///////////////////////////////////////////////////////////////////////////////
void Game::onGameOver(PieceType t_winner)
{
	system("cls");

	if (PieceType::None == t_winner)
		std::cout << "The game was a draw!" << std::endl;
	else if (PieceType::Red == t_winner)
		std::cout << "The red player won!" << std::endl;
	else
		std::cout << "The yellow player won!" << std::endl;

	std::cout << std::endl;
	//t_rulesHandler.printMoves();

	system("pause");

	m_exitGame = true;
}

///////////////////////////////////////////////////////////////////////////////