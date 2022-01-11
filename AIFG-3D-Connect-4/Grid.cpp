#include "Grid.h"

Grid::Grid(int t_gridIndex)
{
	m_gridIndex = t_gridIndex;
	sf::RectangleShape piece = sf::RectangleShape(sf::Vector2f(static_cast<float>(m_PIECE_SIZE), static_cast<float>(m_PIECE_SIZE)));
	for (Coordinate::Type col = 0u; col < GameBoard::SIZE; col++)
	{
		for (Coordinate::Type row = 0u; row < GameBoard::SIZE; row++)
		{
			// This sets up each board to be in the center of the screen and appear one after the other going downwards.
			// The top most Board will have grid index of 0.
			piece.setFillColor(sf::Color::Black);
			piece.setOutlineColor(sf::Color::White);
			piece.setOutlineThickness(2u);
			int topLeftX = (Window::getWindowWidth() / 2) - m_PIECE_SIZE * 2;
			int topLeftY = 15 + (50 * m_gridIndex) + m_PIECE_SIZE * m_gridIndex * 4;
			int x = topLeftX + m_PIECE_SIZE * col;
			int y = topLeftY + row * m_PIECE_SIZE;
			piece.setPosition(static_cast<float>(x), static_cast<float>(y));
			m_pieces.push_back(piece);
		}
	}
}

Grid::~Grid()
{

}

void Grid::render(sf::RenderWindow& t_window)
{
	for (auto piece : m_pieces)
	{
		t_window.draw(piece);
	}
}
