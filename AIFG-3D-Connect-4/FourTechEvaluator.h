#ifndef FOUR_TECH_EVALUATOR_H
#define FOUR_TECH_EVALUATOR_H

#include "GameBoard.h"
#include "Move.h"

/// <summary>
/// Provides methods for evaluating the state of the board after a move.
/// <para>The class can be used to check if a move will result in a win, or to
///		assign a score to a potential move based on a number of weighted 
///		factors.</para>
/// </summary>
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
	///		values, counting each occurrence of the specified piece type.
	/// </summary>
	/// <param name="t_board">The board to check on.</param>
	/// <param name="t_type">The type of piece to check for.</param>
	/// <param name="t_start">The start tile to check from.</param>
	/// <param name="t_xInc">The x increment.</param>
	/// <param name="t_yInc">The y increment.</param>
	/// <param name="t_zInc">The z increment.</param>
	/// <returns>The piece that won along the axis or PieceType::None.</returns>
	static int countAlongAxis(GameBoard& t_board, PieceType t_type,
		Coordinate const& t_start,
		int t_xInc, int t_yInc, int t_zInc);

	/// <summary>
	/// Counts and returns the number of rows of the type and size specified
	///		immediately around the passed position.
	/// </summary>
	/// <param name="t_board">The board to check on.</param>
	/// <param name="t_position">The position to check around.</param>
	/// <param name="t_type">The type to check for.</param>
	/// <param name="t_size">The size to check for.</param>
	/// <returns>The number of rows of matching type and size</returns>
	static int countRowsOfTypeAndSize(GameBoard & t_board, 
									  Coordinate const & t_position,
									  PieceType t_type, int t_size);

	
	/// <summary>
	/// Counts and returns the number of rows of the type and size specified
	///		along the three straight axis from the passed position.
	/// </summary>
	/// <param name="t_board">The board to check on.</param>
	/// <param name="t_position">The position to check around.</param>
	/// <param name="t_type">The type to check for.</param>
	/// <param name="t_size">The size to check for.</param>
	/// <returns>The number of rows of matching type and size</returns>
	static int countStraightRows(GameBoard& t_board,
								 Coordinate const& t_position,
								 PieceType t_type, int t_size);

	/// Counts and returns the number of rows of the type and size specified
	///		along the two diagonals on each of the three axis from the passed
	///		position.
	/// </summary>
	/// <param name="t_board">The board to check on.</param>
	/// <param name="t_position">The position to check around.</param>
	/// <param name="t_type">The type to check for.</param>
	/// <param name="t_size">The size to check for.</param>
	/// <returns>The number of rows of matching type and size</returns>
	static int countSingleAxisDiagonalRows(GameBoard& t_board,
										   Coordinate const& t_position,
										   PieceType t_type, int t_size);

	/// Counts and returns the number of rows of the type and size specified
	///		along the four diagonals along all three axis from the passed
	///		position.
	/// </summary>
	/// <param name="t_board">The board to check on.</param>
	/// <param name="t_position">The position to check around.</param>
	/// <param name="t_type">The type to check for.</param>
	/// <param name="t_size">The size to check for.</param>
	/// <returns>The number of rows of matching type and size</returns>
	static int countAllAxisDiagonalRows(GameBoard& t_board,
										Coordinate const& t_position,
										PieceType t_type, int t_size);

	/// <summary>
	/// Checks if the move passed blocks a win for the opponent on the passed
	///		game board.
	/// </summary>
	/// <param name="t_board">The board to check on.</param>
	/// <param name="t_move">The move to check.</param>
	/// <returns>Whether or not the opponent's win was blocked.</returns>
	static bool doesMoveBlockWin(GameBoard& t_board, Move const& t_move);

	/// <summary>
	/// Counts the number of blocked potential three in a rows the opponent
	///		could achieve, if any.
	/// </summary>
	/// <param name="t_board">The board to check on.</param>
	/// <param name="t_move">The move to check.</param>
	/// <returns>The number of blocked three in a rows.</returns>
	static int countBlockedThreeInARows(GameBoard& t_board, Move const& t_move);

	/// <summary>
	/// Counts the number of three in a rows the passed move would achieve.
	/// </summary>
	/// <param name="t_board">The board to check on.</param>
	/// <param name="t_move">The move to check.</param>
	/// <returns>The number of three in a rows achieved from this move.</returns>
	static int countThreeInARows(GameBoard& t_board, Move const& t_move);

	/// <summary>
	/// Counts the number of two in a rows the passed move would achieve.
	/// </summary>
	/// <param name="t_board">The board to check on.</param>
	/// <param name="t_move">The move to check.</param>
	/// <returns>The number of two in a rows achieved from this move.</returns>
	static int countTwoInARows(GameBoard& t_board, Move const& t_move);

	/// <summary>
	/// Counts the number of the three axis this move is centred on.
	/// </summary>
	/// <param name="t_board">The board to check on.</param>
	/// <param name="t_move">The move to check.</param>
	/// <returns>The number of centred axis.</returns>
	static int countCentredAxis(GameBoard& t_board, Move const& t_move);

	/// <summary>
	/// Returns the last cell index minus the passed cell number, effectively
	///		reversing the coordinate.
	/// </summary>
	/// <param name="t_cell">The cell index to reverse.</param>
	/// <returns>The reversed cell index.</returns>
	static size_t reversed(size_t t_cell);

private: // PRIVATE VARIABLES.

	/// The number of points given to a move for a win.
	static int const m_WIN_POINTS;

	/// The number of points given to a move for blocking an opponent's win.
	static int const m_BLOCK_WIN_POINTS;

	/// The number of points given to a move for blocking an opponent's three in a row.
	static int const m_BLOCK_THREE_IN_A_ROW_POINTS;

	/// The number of points given to a move for achieving a three in a row.
	static int const m_THREE_IN_A_ROW_POINTS;

	/// The number of points given to a move for achieving a two in a row.
	static int const m_TWO_IN_A_ROW_POINTS;

	/// The number of points given to a move for being centred along an axis.
	static int const m_CENTRE_POINTS;

	/// The index of the last cell in a row on the game board.
	static size_t const m_LAST_CELL_INDEX;

};

#endif // !FOUR_TECH_EVALUATOR_H