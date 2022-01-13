#ifndef FOUR_TECH_RULES_HANDLER_H
#define FOUR_TECH_RULES_HANDLER_H

// TEMPORARY.
#include <iostream>
#include <vector>
#include <functional>

#include "GameBoard.h"
#include "Coordinate.h"
#include "FourTechEvaluator.h"
#include "TurnHandler.h"

class Game;

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
	using OnGameOverFunction = std::function<void(Game&, PieceType)>;

	/// <summary>
	/// Initialises the handler.
	/// </summary>
	FourTechRulesHandler(Game& t_game, GameBoard & t_board);

	/// <summary>
	/// Destrutor that cleans all heap allocated memory.
	/// </summary>
	~FourTechRulesHandler();

	/// <summary>
	/// Checks for input from the relevant player and checks for game over.
	/// </summary>
	void update();

	/// <summary>
	/// Sets the function callback to be called on game over.
	/// </summary>
	/// <param name="t_function">the function to call on game over.</param>
	void setOnGameOverFunction(OnGameOverFunction t_function);

	/// <summary>
	/// This will set the turn Handler.
	/// </summary>
	/// <param name="t_turnHandler">Turn handler that handles who's turn it is and the swithces of turns</param>
	void setTurnHandler(TurnHandler* t_turnHandler);

	// TEMPORARY.
	void printMoves() const;
		
private: 
	Game& m_game;
	/// The total number of positions a piece can be placed in on the board.
	size_t const m_TOTAL_BOARD_TILES;

	/// <summary>
	/// The game board object to place the pieces on. 
	///	Assumed to be empty when passed.
	/// </summary>
	GameBoard & m_board;

	/// The function to call with the results once a game over has been found.
	OnGameOverFunction m_onGameOverFunction;

	/// The total number of pieces placed by this rules handler.
	size_t m_piecesPlaced;

	// This repersents a turn handler, which handles turns and handles the change of turns.
	TurnHandler* m_turnHandler;

	// TEMPORARY.
	std::vector<Coordinate> m_moveHistory;
};
#include "Game.h"
#endif // !FOUR_TECH_RULES_HANDLER_H
