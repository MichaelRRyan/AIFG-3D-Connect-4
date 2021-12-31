#ifndef FOUR_TECH_RULES_HANDLER_H
#define FOUR_TECH_RULES_HANDLER_H

// TEMPORARY.
#include <iostream>

#include <functional>
#include "GameBoard.h"
#include "Coordinate.h"

/// <summary>
/// Runs the 4Tech game and handles the rules. 
/// <para>Calls a turn handler to get input from the relevant player and
///		validates the input.</para>
/// <para>After a piece is placed, the handler checks if the game has finished,
///		and calls a function pointer if it has.</para>
/// </summary>
class FourTechRulesHandler
{
public:

	// Declares a type alias to the OnGameOverFunction type.
	using OnGameOverFunction = std::function<void(PieceType)>;

	/// <summary>
	/// Initialises the handler.
	/// </summary>
	FourTechRulesHandler();

	/// <summary>
	/// Checks for input from the relevant player and checks for game over.
	/// </summary>
	void update();

	/// <summary>
	/// Sets the function callback to be called on game over.
	/// </summary>
	/// <param name="t_function">the function to call on game over.</param>
	void setOnGameOverFunction(OnGameOverFunction t_function);

	// TODO: To be filled out later.
	void setTurnHandler(int * t_turnHandler);

	/// <summary>
	/// Sets the game board to perform operations on.
	/// </summary>
	/// <param name="t_gameBoard">- The game board.</param>
	void setGameBoard(GameBoard * t_gameBoard);

private: 
	
	/// <summary>
	/// Checks if either player have won or a draw has been reached.
	/// </summary>
	/// <param name="t_position">The position of the last placed piece.</param>
	void checkForGameOver(Coordinate const & t_position);

	/// <summary>
	/// Checks for a straight win along the three axis.
	/// </summary>
	/// <param name="t_position">The position of the last placed piece.</param>
	/// <returns>Whether or not a win was determined.</returns>
	bool checkForStraightWin(Coordinate const& t_position);

	/// <summary>
	/// Checks for a win along the two diagonals on each of the three axis.
	/// </summary>
	/// <param name="t_position">The position of the last placed piece.</param>
	/// <returns>Whether or not a win was determined.</returns>
	bool checkForSingleAxisDiagonalWin(Coordinate const& t_position);

	/// <summary>
	/// Checks for a win along the four diagonals along all three axis.
	/// </summary>
	/// <param name="t_position">The position of the last placed piece.</param>
	/// <returns>Whether or not a win was determined.</returns>
	bool checkForAllAxisDiagonalWin(Coordinate const& t_position);
	
	/// <summary>
	/// Loops four times from the start position and icrements by the increment
	///		values, checking if the values along the axis add up to a win.
	/// </summary>
	/// <param name="t_start">- The start tile to check from.</param>
	/// <param name="t_xInc">- The x increment.</param>
	/// <param name="t_yInc">- The y increment.</param>
	/// <param name="t_zInc">- The z increment.</param>
	/// <returns>Whether or not the game was won on this axis.</returns>
	bool evaluateAxis(Coordinate const & t_start, int t_xInc, int t_yInc, int t_zInc);

	/// <summary>
	/// Checks if there's a win by the total value of a row and calls the game
	///		over function if so.
	/// </summary>
	/// <param name="t_rowValue">the total value of the row.</param>
	/// <returns>Whether or not a win was determined.</returns>
	bool evaluateRow(int t_rowValue);

	/// The total number of positions a piece can be placed in on the board.
	size_t const m_TOTAL_BOARD_TILES;

	/// <summary>
	/// The game board object to place the pieces on. 
	///	Assumed to be empty when passed.
	/// </summary>
	GameBoard * m_gameBoard;

	/// The function to call with the results once a game over has been found.
	OnGameOverFunction m_onGameOverFunction;

	/// The total number of pieces placed by this rules handler.
	size_t m_piecesPlaced;

};

#endif // !FOUR_TECH_RULES_HANDLER_H
