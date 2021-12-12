#ifndef FOUR_TECH_RULES_HANDLER_H
#define FOUR_TECH_RULES_HANDLER_H

// TEMPORARY.
#include <iostream>

#include <functional>
#include "GameBoard.h"

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

	// To be filled out later.
	void setTurnHandler(int * t_turnHandler);

	/// <summary>
	/// Sets the game board to perform operations on.
	/// </summary>
	/// <param name="t_gameBoard">the game board.</param>
	void setGameBoard(GameBoard * t_gameBoard);

private:

	/// <summary>
	/// Checks if either player have won or a draw has been reached.
	/// </summary>
	void checkForGameOver();

	/// <summary>
	/// Checks if there's a win by the total value of a row and calls the game
	///		over function if so.
	/// </summary>
	/// <param name="t_rowValue">the total value of the row.</param>
	/// <returns>Whether or not the game is over.</returns>
	bool evaluateRow(int t_rowValue);

	int getLineValue(size_t t_x, size_t t_y, size_t t_z);

	GameBoard * m_gameBoard;
	OnGameOverFunction m_onGameOverFunction;

};

#endif // !FOUR_TECH_RULES_HANDLER_H
