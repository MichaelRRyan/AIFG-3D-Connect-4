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
	m_window{ sf::VideoMode{ m_WINDOW_WIDTH, m_WINDOW_HEIGHT, 32U }, "SFML Game" },
	m_exitGame{false}
{
	setupFontAndText();
	setupSprite();
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
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame.asSeconds()); //60 fps
		}
		render(); // as many as possible
	}
}

///////////////////////////////////////////////////////////////////////////////
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type) // window message
			exit();

		else if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
			processKeys(newEvent);
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
}

///////////////////////////////////////////////////////////////////////////////
void Game::render()
{
	m_window.clear(sf::Color::White);
	m_window.draw(m_welcomeMessage);
	m_window.draw(m_logoSprite);
	m_window.display();
}

///////////////////////////////////////////////////////////////////////////////
void Game::setupFontAndText()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	m_welcomeMessage.setFont(m_ArialBlackfont);
	m_welcomeMessage.setString("SFML Game");
	m_welcomeMessage.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	m_welcomeMessage.setPosition(40.0f, 40.0f);
	m_welcomeMessage.setCharacterSize(80U);
	m_welcomeMessage.setOutlineColor(sf::Color::Red);
	m_welcomeMessage.setFillColor(sf::Color::Black);
	m_welcomeMessage.setOutlineThickness(3.0f);

}

///////////////////////////////////////////////////////////////////////////////
void Game::setupSprite()
{
	if (!m_logoTexture.loadFromFile("ASSETS\\IMAGES\\SFML-LOGO.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	m_logoSprite.setTexture(m_logoTexture);
	m_logoSprite.setPosition(300.0f, 180.0f);
}

///////////////////////////////////////////////////////////////////////////////
void Game::exit()
{
	m_window.close();
}

///////////////////////////////////////////////////////////////////////////////