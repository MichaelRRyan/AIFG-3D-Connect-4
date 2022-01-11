#pragma once
#include <SFML/Graphics.hpp>
#include "GameBoard.h"
#include "Window.h"
/// <summary>
/// This repernsets a grid within the 4 Tec Game
/// </summary>
class Grid
{
public:
	/// <summary>
	/// Constructor for the grid.
	/// </summary>
	/// <param name="t_gridIndex">the grid index</param>
	Grid(int t_gridIndex);

	/// <summary>
	/// Default Destructor for the Grid.
	/// </summary>
	~Grid();

	/// <summary>
	/// Renders the grids.
	/// </summary>
	/// <param name="t_window">SFML render window.</param>
	void render(sf::RenderWindow& t_window);

	/// <summary>
	/// Gets the grid index of a board.
	/// </summary>
	inline int getGridIndex() { return m_gridIndex; };

	/// <summary>
	/// Sets the game board, so the grid knows of the board state.
	/// </summary>
	/// <param name="t_gameBoard">Game board</param>
	void setGameBoard(GameBoard* t_gameBoard);

	inline std::vector<sf::RectangleShape> getRects() { return m_rects; }

	inline const float getRectSize() { return m_PIECE_SIZE; }
private:
	// rects within the grid.
	std::vector<sf::RectangleShape> m_rects;

	// The grid index, that tells what board it is. The top most board will be a value of 0.
	int m_gridIndex;

	// Size of each piece within the grid.
	const float m_PIECE_SIZE = 64;

	// The spacing between each grid.
	const float m_Y_SPACING_Multiplier = 50;

	// The offset from the top of a grid.
	const float m_Y_OFFSET = 15;

	float m_topLeftX;

	float m_topLeftY;

	GameBoard* m_gameBoard;

	/// <summary>
	/// Sets a piece depending on the type of piece it is.
	/// </summary>
	/// <param name="t_color">The color of the piece</param>
	/// <param name="t_row">row position for the piece.</param>
	/// <param name="t_col">col position for the piece.</param>
	/// <returns>returns a created piece</returns>
	sf::CircleShape getNewPiece(sf::Color t_color, Coordinate::Type t_row, Coordinate::Type t_col);

	/// <summary>
	/// Sets up the rects for the grid.
	/// </summary>
	/// <param name="t_color">The color of the grid.</param>
	/// <param name="t_row">row position for the rect.</param>
	/// <param name="t_col">col position of the rect.</param>
	void setUpRect(sf::Color t_color, Coordinate::Type t_row, Coordinate::Type t_col);
};
