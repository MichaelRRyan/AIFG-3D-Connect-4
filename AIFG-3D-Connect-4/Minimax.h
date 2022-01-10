#ifndef MINIMAX_H
#define MINIMAX_H

#include <vector>
#include <cmath>
#include <functional>

#include "GameBoard.h"
#include "Coordinate.h"
#include "PieceType.h"
#include "Move.h"
#include "FourTechEvaluator.h"

class Minimax
{
public:

	static Coordinate getCoordinate(GameBoard & t_board, PieceType t_pieceType);

	static void setMaxDepth(int t_depth);

private:

	struct Ply
	{
		Move move;
		int score;
	};

	static int minimax(GameBoard& t_board, Move t_move, int t_depth);

	static std::vector<Coordinate> * getAvailableMoves(GameBoard const& t_board);

	static int const m_MAX_SCORE;
	static int const m_MIN_SCORE;

	static int m_maxDepth;

};

#endif // !MINIMAX_H