#include "SfmlInput.h"
#include <iostream>
SfmlInput::SfmlInput(GameBoard& t_gameBoard, std::vector<Grid>& t_grids) : m_gameBoard(t_gameBoard), m_grids(t_grids)
{
}

Coordinate SfmlInput::getCoordinate()
{
	sf::Event newEvent;
	Coordinate pos = Coordinate(-1, -1, -1 );
	while (Window::getWindow().pollEvent(newEvent))
	{
		if (sf::Event::Closed == newEvent.type) // window message
		{
			Window().getWindow().close();
		}
		else if (sf::Event::KeyPressed == newEvent.type)
		{
			processKeys(newEvent);
		}
		else if (sf::Event::MouseButtonPressed == newEvent.type)
		{
			sf::Vector2f mousePos = Window::getWindow().mapPixelToCoords(sf::Mouse::getPosition(Window::getWindow()));
			for (int i = 0; i < m_grids.size(); i++)
			{
				std::vector<sf::RectangleShape> rects = m_grids.at(i).getRects();
				for (int j = 0; j < rects.size(); j++)
				{
					if (rects.at(j).getGlobalBounds().contains(mousePos))
					{
						int index = i * 16 + j;
						int board = index / 16;
						int row = (index % 16) / GameBoard::SIZE;
						int col = (index % 16) - (row * GameBoard::SIZE);
						pos.x = row;
						pos.y = board;
						pos.z = col;
					}
				}
			}
		}
	}

	return pos;
}

void SfmlInput::processKeys(sf::Event t_newEvent)
{
	if (sf::Keyboard::Escape == t_newEvent.key.code)
	{
		Window().getWindow().close();
	}
}
