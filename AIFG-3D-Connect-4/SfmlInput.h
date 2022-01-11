#pragma once
#include "Input.h"
#include "GameBoard.h"
#include <vector>
#include "Grid.h"
class SfmlInput : public Input
{
public:
	/// <summary>
	/// Constructor for the SFML Input.
	/// </summary>
	/// <param name="t_gameBoard">repersents the entire game board state.</param>
	/// <param name="t_grids">The grids within the game.</param>
	SfmlInput(GameBoard& t_gameBoard, std::vector<Grid>& t_grids);

	/// <summary>
	/// Default Destructor for SFML Input.
	/// </summary>
	virtual ~SfmlInput() = default;

	/// <summary>
	/// Overriden function that gets the coordinates from the players input player.
	/// </summary>
	/// <returns></returns>
	Coordinate getCoordinate() override;
private:
	/// <summary>
	/// Handles key events
	/// </summary>
	/// <param name="t_newEvent">New Key Pressed Event</param>
	void processKeys(sf::Event t_newEvent);

	GameBoard& m_gameBoard;

	// The grids in the game.
	std::vector<Grid>& m_grids;
};
