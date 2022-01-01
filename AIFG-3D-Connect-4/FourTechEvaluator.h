#ifndef FOUR_TECH_EVALUATOR_H
#define FOUR_TECH_EVALUATOR_H

#include "GameBoard.h"
#include "Move.h"

class FourTechEvaluator
{
public:

	static int evaluateMove(GameBoard & t_board, Move const & t_move);

private:

	static bool isMoveAWin(GameBoard& t_board, Move const& t_move);
	static bool doesMoveBlockWin(GameBoard& t_board, Move const& t_move);
	static bool doesMoveBlockThreeInARow(GameBoard& t_board, Move const& t_move);
	static bool isMoveThreeInARow(GameBoard& t_board, Move const& t_move);
	static bool isMoveTwoInARow(GameBoard& t_board, Move const& t_move);
	static bool isMoveInCentre(GameBoard& t_board, Move const& t_move);

	static int const m_WIN_POINTS;
	static int const m_BLOCK_WIN_POINTS;
	static int const m_BLOCK_THREE_IN_A_ROW_POINTS;
	static int const m_THREE_IN_A_ROW_POINTS;
	static int const m_TWO_IN_A_ROW_POINTS;
	static int const m_CENTRE_POINTS;

};

#endif // !FOUR_TECH_EVALUATOR_H