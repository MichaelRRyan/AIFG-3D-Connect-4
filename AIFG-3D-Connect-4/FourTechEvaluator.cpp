#include "FourTechEvaluator.h"

int const FourTechEvaluator::m_WIN_POINTS = 1000;
int const FourTechEvaluator::m_BLOCK_WIN_POINTS = 50;
int const FourTechEvaluator::m_BLOCK_THREE_IN_A_ROW_POINTS = 25;
int const FourTechEvaluator::m_THREE_IN_A_ROW_POINTS = 15;
int const FourTechEvaluator::m_TWO_IN_A_ROW_POINTS = 5;
int const FourTechEvaluator::m_CENTRE_POINTS = 5;

///////////////////////////////////////////////////////////////////////////////
bool FourTechEvaluator::isMoveAWin(GameBoard & t_board, Move const & t_move)
{
	PieceType prevType = t_board.getPiece(t_move.position);
	t_board.setPiece(t_move.position, t_move.type);
	bool success = false;

	// Checks the 3 straight axis.
	if (checkForStraightWin(t_board, t_move))
		success = true;

	// Checks both diagonals along each of the 3 axis.
	else if (checkForSingleAxisDiagonalWin(t_board, t_move))
		success = true;

	// Checks the diagonals along all axis.
	else if (checkForAllAxisDiagonalWin(t_board, t_move))
		success = true;

	t_board.setPiece(t_move.position, prevType);
	return success;
}

///////////////////////////////////////////////////////////////////////////////
int FourTechEvaluator::evaluateMove(GameBoard & t_board, Move const & t_move)
{
	int score = 0;

	// Checks for win.
	if (isMoveAWin(t_board, t_move))
		score += m_WIN_POINTS;

	// Checks for block opponent win.
	if (doesMoveBlockWin(t_board, t_move))
		score += m_BLOCK_WIN_POINTS;

	// Checks for block opponent three in a row.
	if (doesMoveBlockThreeInARow(t_board, t_move))
		score += m_BLOCK_THREE_IN_A_ROW_POINTS;

	// Checks for three in a row.
	if (isMoveThreeInARow(t_board, t_move))
		score += m_THREE_IN_A_ROW_POINTS;

	// Checks for two in a row.
	if (isMoveTwoInARow(t_board, t_move))
		score += m_TWO_IN_A_ROW_POINTS;

	// Checks for centre.
	if (isMoveInCentre(t_board, t_move))
		score += m_CENTRE_POINTS;

	return score;
}

///////////////////////////////////////////////////////////////////////////////
bool FourTechEvaluator::checkForStraightWin(GameBoard& t_board, Move const & t_move)
{
	Coordinate const & pos = t_move.position;

	// Checks the 3 straight axis.
	return evaluateAxis(t_board, { 0, pos.y, pos.z }, 1, 0, 0) == t_move.type
		|| evaluateAxis(t_board, { pos.x, 0, pos.z }, 0, 1, 0) == t_move.type
		|| evaluateAxis(t_board, { pos.x, pos.y, 0 }, 0, 0, 1) == t_move.type;
}

///////////////////////////////////////////////////////////////////////////////
bool FourTechEvaluator::checkForSingleAxisDiagonalWin(GameBoard& t_board, Move const & t_move)
{
	// The last valid position along any axis.
	size_t const LAST_CELL = GameBoard::SIZE - 1;
	Coordinate const& pos = t_move.position;

	// Checks the diagonals along the x axis.
	return (pos.y == pos.z && evaluateAxis(t_board, { pos.x, 0, 0 }, 0, 1, 1) == t_move.type)
		|| (pos.y == LAST_CELL - pos.z && evaluateAxis(t_board, { pos.x, 0, LAST_CELL }, 0, 1, -1) == t_move.type)

		// Checks the diagonals along the y axis.
		|| (pos.x == pos.z && evaluateAxis(t_board, { 0, pos.y, 0 }, 1, 0, 1) == t_move.type)
		|| (pos.x == LAST_CELL - pos.z && evaluateAxis(t_board, { 0, pos.y, LAST_CELL }, 1, 0, -1) == t_move.type)

		// Checks the diagonals along the z axis.
		|| (pos.x == pos.y && evaluateAxis(t_board, { 0, 0, pos.z }, 1, 1, 0) == t_move.type)
		|| (pos.x == LAST_CELL - pos.y && evaluateAxis(t_board, { 0, LAST_CELL, pos.z }, 1, -1, 0) == t_move.type);
}

///////////////////////////////////////////////////////////////////////////////
bool FourTechEvaluator::checkForAllAxisDiagonalWin(GameBoard& t_board, Move const & t_move)
{
	// The last valid position along any axis.
	size_t const LAST_CELL = GameBoard::SIZE - 1;
	Coordinate const& pos = t_move.position;

	return (pos.x == pos.y && pos.x == pos.z
			&& evaluateAxis(t_board, { 0, 0, 0 }, 1, 1, 1) == t_move.type)

		|| (LAST_CELL - pos.x == pos.y && LAST_CELL - pos.x == pos.z
			&& evaluateAxis(t_board, { LAST_CELL, 0, 0 }, -1, 1, 1) == t_move.type)

		|| (pos.x == LAST_CELL - pos.y && pos.x == pos.z
			&& evaluateAxis(t_board, { 0, LAST_CELL, 0 }, 1, -1, 1) == t_move.type)

		|| (pos.x == LAST_CELL - pos.y && pos.x == LAST_CELL - pos.z
			&& evaluateAxis(t_board, { 0, 0, LAST_CELL }, 1, 1, -1) == t_move.type);
}

///////////////////////////////////////////////////////////////////////////////
PieceType FourTechEvaluator::evaluateAxis(GameBoard& t_board, Coordinate const& t_start,
	int t_xInc, int t_yInc, int t_zInc)
{
	int value = 0;
	Coordinate cur = t_start;

	for (int i = 0; i < GameBoard::SIZE; ++i)
	{
		PieceType const& type = t_board.getPiece(cur);

		if (PieceType::Red == type)
			++value;
		else if (PieceType::Yellow == type)
			--value;

		cur.x += t_xInc;
		cur.y += t_yInc;
		cur.z += t_zInc;
	}

	return evaluateRow(value);
}

///////////////////////////////////////////////////////////////////////////////
PieceType FourTechEvaluator::evaluateRow(int t_rowValue)
{
	if (abs(t_rowValue) == GameBoard::SIZE)
		return (t_rowValue > 0) ? PieceType::Red : PieceType::Yellow;
	return PieceType::None;
}

///////////////////////////////////////////////////////////////////////////////
bool FourTechEvaluator::doesMoveBlockWin(GameBoard& t_board, Move const& t_move)
{
	return false;
}

///////////////////////////////////////////////////////////////////////////////
bool FourTechEvaluator::doesMoveBlockThreeInARow(GameBoard& t_board, Move const& t_move)
{
	return false;
}

///////////////////////////////////////////////////////////////////////////////
bool FourTechEvaluator::isMoveThreeInARow(GameBoard& t_board, Move const& t_move)
{
	return false;
}

///////////////////////////////////////////////////////////////////////////////
bool FourTechEvaluator::isMoveTwoInARow(GameBoard& t_board, Move const& t_move)
{
	return false;
}

///////////////////////////////////////////////////////////////////////////////
bool FourTechEvaluator::isMoveInCentre(GameBoard& t_board, Move const& t_move)
{
	return false;
}

///////////////////////////////////////////////////////////////////////////////