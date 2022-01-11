#include "Grid.h"

Grid::Grid(int t_gridIndex)
{
	m_gridIndex = t_gridIndex;
	sf::RectangleShape rect = sf::RectangleShape(sf::Vector2f(static_cast<float>(m_PIECE_SIZE), static_cast<float>(m_PIECE_SIZE)));
	for (Coordinate::Type col = 0u; col < GameBoard::SIZE; col++)
	{
		for (Coordinate::Type row = 0u; row < GameBoard::SIZE; row++)
		{
			setUpRect(sf::Color::Black, rect, row, col);
		}
	}
}

Grid::~Grid()
{

}

void Grid::render(sf::RenderWindow& t_window)
{
	sf::CircleShape piece = sf::CircleShape(m_PIECE_SIZE / 2, m_PIECE_SIZE / 2);
	for (Coordinate::Type col = 0u; col < GameBoard::SIZE; col++)
	{
		for (Coordinate::Type row = 0u; row < GameBoard::SIZE; row++)
		{
			PieceType type = m_gameBoard->getPiece({ row, static_cast<Coordinate::Type>(m_gridIndex), col });
			if (type == PieceType::None) { continue; }
			else if (type == PieceType::Red)
			{
				setUpPiece(sf::Color::Red, piece, row, col);
			}
			else if(type == PieceType::Yellow)
			{
				setUpPiece(sf::Color::Yellow, piece, row, col);
			}
		}
	}

	for (auto rect : m_rects)
	{
		t_window.draw(rect);
	}
	for (auto piece : m_pieces)
	{
		t_window.draw(piece);
	}
}

void Grid::setGameBoard(GameBoard* t_gameBoard)
{
	m_gameBoard = t_gameBoard;
}

void Grid::setUpPiece(sf::Color t_color, sf::CircleShape t_piece, Coordinate::Type t_row, Coordinate::Type t_col)
{
	// Create pieces on the grid depending on what type of piece it is. 
	t_piece.setFillColor(t_color);
	int topLeftX = (Window::getWindowWidth() / 2) - m_PIECE_SIZE * 2;
	int topLeftY = 15 + (50 * m_gridIndex) + m_PIECE_SIZE * m_gridIndex * 4;
	int x = topLeftX + m_PIECE_SIZE * t_row;
	int y = topLeftY + t_col * m_PIECE_SIZE;
	t_piece.setPosition(static_cast<float>(x), static_cast<float>(y));
	m_pieces.push_back(t_piece);
}

void Grid::setUpRect(sf::Color t_color, sf::RectangleShape t_rect, Coordinate::Type t_row, Coordinate::Type t_col)
{
	// This sets up each board to be in the center of the screen and appear one after the other going downwards.
	// The top most Board will have grid index of 0.
	t_rect.setFillColor(sf::Color::Black);
	t_rect.setOutlineColor(sf::Color::White);
	t_rect.setOutlineThickness(2u);
	int topLeftX = (Window::getWindowWidth() / 2) - m_PIECE_SIZE * 2;
	int topLeftY = 15 + (50 * m_gridIndex) + m_PIECE_SIZE * m_gridIndex * 4;
	int x = topLeftX + m_PIECE_SIZE * t_col;
	int y = topLeftY + t_row * m_PIECE_SIZE;
	t_rect.setPosition(static_cast<float>(x), static_cast<float>(y));
	m_rects.push_back(t_rect);
}
