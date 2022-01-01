#include "FourTechEvaluator.h"

int const FourTechEvaluator::m_WIN_POINTS = 1000;
int const FourTechEvaluator::m_BLOCK_WIN_POINTS = 50;
int const FourTechEvaluator::m_BLOCK_THREE_IN_A_ROW_POINTS = 25;
int const FourTechEvaluator::m_THREE_IN_A_ROW_POINTS = 15;
int const FourTechEvaluator::m_TWO_IN_A_ROW_POINTS = 5;
int const FourTechEvaluator::m_CENTRE_POINTS = 5;

///////////////////////////////////////////////////////////////////////////////
int FourTechEvaluator::evaluateMove(GameBoard& t_board, Move const& t_move)
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
bool FourTechEvaluator::isMoveAWin(GameBoard& t_board, Move const& t_move)
{
	return false;
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