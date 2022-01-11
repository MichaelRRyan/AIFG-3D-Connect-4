#ifndef MINIMAX_H
#define MINIMAX_H

#include <vector>
#include <cmath>
#include <functional>
#include <chrono>
#include <iostream>

#include "GameBoard.h"
#include "Move.h"
#include "FourTechEvaluator.h"

// Displays the time Minimax took to run.
// Implementation written by Ben Millar.
//#define OUTPUT_DURATION

/// <summary>
/// A class for getting the best next move position in a game of 4Tec using an
///		implementation of the Minimax algorithm.
/// </summary>
class Minimax
{
public:

	/// <summary>
	/// Sets the maximum depth to recursively search to.
	/// <para>If set to an even number, the algorithm will search one level deeper
	///		to avoid getting a heuristic of the enemies move.</para>
	/// </summary>
	/// <param name="t_depth">The new depth value.</param>
	static void setMaxDepth(int t_depth);

	/// <summary>
	/// Gets the best next move position for the piece type passed, using the 
	///		Minimax algorithm to recursivelly search along future moves.
	/// </summary>
	/// <param name="t_board">The board to play on.</param>
	/// <param name="t_pieceType">The piece type to check with.</param>
	/// <returns>The best next move position.</returns>
	static Coordinate getCoordinate(GameBoard & t_board, PieceType t_pieceType);

private:

	/// <summary>
	/// A recursive function that returns a more accurate heuristic score of
	///		the passed move by simulating future moves.
	/// </summary>
	/// <param name="t_board">The board to play on.</param>
	/// <param name="t_move">The move of which to score.</param>
	/// <param name="t_depth">The current number of moves deep.</param>
	/// <returns>The best heuristic score of the move.</returns>
	static int minimax(GameBoard& t_board, Move t_move, 
					   int t_depth, int t_alpha, int t_beta);

	/// An alias for the function declaration for forEachValidMove().
	using EachMoveFunc = std::function<bool(Coordinate const& t_coord)>;

	/// <summary>
	/// Calls the passed function for each valid move on the board. Exits if
	///		the passed function returns true.
	/// </summary>
	/// <param name="t_board">The board to check for moves on.</param>
	/// <param name="t_func">The function to call.</param>
	static void forEachValidMove(GameBoard const & t_board, 
								 EachMoveFunc const & t_func);


	/// The maximum value of an integer.
	static int const m_INT_MAX;

	/// The minimum value of an integer.
	static int const m_INT_MIN;

	/// The max depth searched to by minimax().
	static int m_maxDepth;

};

#endif // !MINIMAX_H