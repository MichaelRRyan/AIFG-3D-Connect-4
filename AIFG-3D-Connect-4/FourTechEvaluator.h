#ifndef FOUR_TECH_EVALUATOR_H
#define FOUR_TECH_EVALUATOR_H

#include "GameBoard.h"
#include "Move.h"

class FourTechEvaluator
{
public: // PUBLIC METHODS.

	/// <summary>
	/// Checks if the passed move is a win.
	/// </summary>
	/// <param name="t_board">The board to check on.</param>
	/// <param name="t_move">The move to check.</param>
	/// <returns>Whether a win occurred</returns>
	static bool isMoveAWin(GameBoard & t_board, Move const & t_move);

	/// <summary>
	/// Returns the score of a potential move.
	/// </summary>
	/// <param name="t_board">The board to check on.</param>
	/// <param name="t_move">The move to check.</param>
	/// <returns>The score of the move.</returns>
	static int evaluateMove(GameBoard & t_board, Move const & t_move);

private: // PRIVATE METHODS.

	/// <summary>
	/// Checks for a straight win along the three axis.
	/// </summary>
	/// <param name="t_board">The board to check on.</param>
	/// <param name="t_move">The move to check.</param>
	/// <returns>Whether or not a win was determined.</returns>
	static bool checkForStraightWin(GameBoard & t_board, Move const & t_move);

	/// <summary>
	/// Checks for a win along the two diagonals on each of the three axis.
	/// </summary>
	/// <param name="t_board">The board to check on.</param>
	/// <param name="t_move">The move to check.</param>
	/// <returns>Whether or not a win was determined.</returns>
	static bool checkForSingleAxisDiagonalWin(GameBoard & t_board, Move const & t_move);

	/// <summary>
	/// Checks for a win along the four diagonals along all three axis.
	/// </summary>
	/// <param name="t_board">The board to check on.</param>
	/// <param name="t_move">The move to check.</param>
	/// <returns>Whether or not a win was determined.</returns>
	static bool checkForAllAxisDiagonalWin(GameBoard & t_board, Move const & t_move);

	/// <summary>
	/// Loops four times from the start position and icrements by the increment
	///		values, checking if the values along the axis add up to a win and 
	///		returns the winning piece if so.
	/// </summary>
	/// <param name="t_board">The board to check on.</param>
	/// <param name="t_start">- The start tile to check from.</param>
	/// <param name="t_xInc">- The x increment.</param>
	/// <param name="t_yInc">- The y increment.</param>
	/// <param name="t_zInc">- The z increment.</param>
	/// <returns>The piece that won along the axis or PieceType::None.</returns>
	static PieceType evaluateAxis(GameBoard & t_board, Coordinate const& t_start,
								  int t_xInc, int t_yInc, int t_zInc);

	/// <summary>
	/// Checks if there's a win by the total value of a row and returns the 
	///		piece that won if so.
	/// </summary>
	/// <param name="t_rowValue">the total value of the row.</param>
	/// <returns>The piece that won or PieceType::None.</returns>
	static PieceType evaluateRow(int t_rowValue);


	static bool doesMoveBlockWin(GameBoard& t_board, Move const& t_move);
	static bool doesMoveBlockThreeInARow(GameBoard& t_board, Move const& t_move);
	static bool isMoveThreeInARow(GameBoard& t_board, Move const& t_move);
	static bool isMoveTwoInARow(GameBoard& t_board, Move const& t_move);
	static int getMoveCentredValue(GameBoard& t_board, Move const& t_move);

private: // PRIVATE VARIABLES.

	static int const m_WIN_POINTS;
	static int const m_BLOCK_WIN_POINTS;
	static int const m_BLOCK_THREE_IN_A_ROW_POINTS;
	static int const m_THREE_IN_A_ROW_POINTS;
	static int const m_TWO_IN_A_ROW_POINTS;
	static int const m_CENTRE_POINTS;

};

#endif // !FOUR_TECH_EVALUATOR_H