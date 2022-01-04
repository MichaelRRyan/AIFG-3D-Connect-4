#ifndef FOUR_TECH_AI_H
#define FOUR_TECH_AI_H

#include <vector>

#include "Coordinate.h"
#include "GameBoard.h"
#include "FourTechEvaluator.h"
#include "Input.h"

/// <summary>
/// A simple class used to find the next best move for the yellow player
///		in a game of 4Tec.
/// </summary>
class FourTechAI : public Input
{
public:

	/// <summary>
	/// Constructs the object and assigns the stored game board reference.
	/// </summary>
	/// <param name="t_board">The game board to play on.</param>
	FourTechAI(GameBoard & t_board);

	/// <summary>
	/// Destructor for the AI.
	/// </summary>
	virtual ~FourTechAI() = default;

	/// <summary>
	/// This will get the best move position the AI wants to put in the game board.
	/// </summary>
	/// <returns>returns the best position the AI wants to put in the game board.</returns>
	Coordinate getCoordinate() override;

private:
	/// <summary>
	/// Get's the immediate best next move.
	/// </summary>
	/// <returns>The position of the best move.</returns>
	Coordinate getMove();

	/// The game board to play on.
	GameBoard & m_board;

};

#endif // !FOUR_TECH_AI_H