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
private:
	// Pieces within the grid.
	std::vector<sf::RectangleShape> m_pieces;

	int m_gridIndex;

	// Size of each piece within the grid.
	const unsigned int m_PIECE_SIZE = 64;
};
