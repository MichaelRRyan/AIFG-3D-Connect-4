#include "Grid.h"

///////////////////////////////////////////////////////////////////////////////
Grid::Grid(int t_gridIndex)
{
	m_gridIndex = t_gridIndex;

	// Pre-calcuation for positioning of grid and pieces within the grid.
	m_topLeftX = (Window::getWindowWidth() / 2) - m_PIECE_SIZE * 2;
	m_topLeftY = m_Y_OFFSET + (m_Y_SPACING_Multiplier * m_gridIndex) + m_PIECE_SIZE * m_gridIndex * GameBoard::SIZE;

	for (Coordinate::Type col = 0u; col < GameBoard::SIZE; col++)
	{
		for (Coordinate::Type row = 0u; row < GameBoard::SIZE; row++)
		{
			setUpRect(sf::Color::Black, row, col);
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
Grid::~Grid()
{

}

///////////////////////////////////////////////////////////////////////////////
void Grid::render(sf::RenderWindow& t_window)
{
	for (auto rect : m_rects)
	{
		t_window.draw(rect);
	}
	for (Coordinate::Type col = 0u; col < GameBoard::SIZE; col++)
	{
		for (Coordinate::Type row = 0u; row < GameBoard::SIZE; row++)
		{
			PieceType type = m_gameBoard->getPiece({ row, static_cast<Coordinate::Type>(m_gridIndex), col });
			if (type == PieceType::None) { continue; }
			else
			{
				t_window.draw(getNewPiece((type == PieceType::Red) ? sf::Color::Red : sf::Color::Yellow, row, col));
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
void Grid::setGameBoard(GameBoard* t_gameBoard)
{
	m_gameBoard = t_gameBoard;
}

///////////////////////////////////////////////////////////////////////////////
sf::CircleShape Grid::getNewPiece(sf::Color t_color, Coordinate::Type t_row, Coordinate::Type t_col)
{
	// Create pieces on the grid depending on what type of piece it is. 
	sf::CircleShape piece = sf::CircleShape(m_PIECE_SIZE / 2 - 1);
	piece.setFillColor(t_color);
	float x = m_topLeftX + m_PIECE_SIZE * t_row;
	float y = m_topLeftY + t_col * m_PIECE_SIZE;
	piece.setPosition(x,y);
	return piece;
}

///////////////////////////////////////////////////////////////////////////////
void Grid::setUpRect(sf::Color t_color, Coordinate::Type t_row, Coordinate::Type t_col)
{
	// This sets up each board to be in the center of the screen and appear one after the other going downwards.
	// The top most Board will have grid index of 0.
	sf::RectangleShape rect = sf::RectangleShape(sf::Vector2f(m_PIECE_SIZE, m_PIECE_SIZE));
	rect.setFillColor(sf::Color::Black);
	rect.setOutlineColor(sf::Color::White);
	rect.setOutlineThickness(2u);
	float x = m_topLeftX + m_PIECE_SIZE * t_col;
	float y = m_topLeftY + t_row * m_PIECE_SIZE;
	rect.setPosition(x,y);
	m_rects.push_back(rect);
}
///////////////////////////////////////////////////////////////////////////////
