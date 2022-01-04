#ifndef CONSOLE_INPUT_H
#define CONSOLE_INPUT_H
#include "Input.h"
#include <iostream>
#include "GameBoard.h"

/// <summary>
/// Reperensents input that the player will use via the console command.
/// </summary>
class ConsoleInput : public Input
{
public:
	/// <summary>
	/// Constructs the console input with the game board.
	/// </summary>
	/// <param name="t_board">The game board to play on.</param>
	ConsoleInput(GameBoard& t_board);

	/// <summary>
	/// Destructor for the console input
	/// </summary>
	virtual ~ConsoleInput() = default;

	/// <summary>
	/// This will get the coordinate of the position the player wants to put thier piece into
	/// </summary>
	/// <returns>the position the player wants to put thier piece into</returns>
	Coordinate getCoordinate() override;
private:
	/// <summary>
	/// This will check if the input the player provides is witin the bounds of the game baord.
	/// </summary>
	/// <param name="t_pos">the position the player wants to put thier piece into.</param>
	/// <returns>returns if the position is within the bounds of the game board.</returns>
	bool validateIfInputWithinGameBoard(Coordinate t_pos);

	// The board the game is played on
	GameBoard& m_board;
};
#endif