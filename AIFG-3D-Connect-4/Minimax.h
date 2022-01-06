#ifndef MINIMAX_H
#define MINIMAX_H

#include <vector>
#include <cmath>

#include "GameBoard.h"
#include "Coordinate.h"
#include "PieceType.h"
#include "Move.h"
#include "FourTechEvaluator.h"

class Minimax
{
public:

	static Coordinate getCoordinate(GameBoard & t_board, PieceType t_pieceType, size_t t_maxDepth);

private:

	struct Ply
	{
		Move move;
		int score;
	};

	static int minimax(GameBoard& t_board, Move t_move, size_t t_remainingDepth);

	static std::vector<Coordinate> * getAvailableMoves(GameBoard const & t_board);

	static int const m_MAX_SCORE;
	static int const m_MIN_SCORE;

};

#endif // !MINIMAX_H