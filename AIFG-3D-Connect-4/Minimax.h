#ifndef MINIMAX_H
#define MINIMAX_H

#include <vector>

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

	static Ply * minimax(GameBoard& t_board, PieceType t_pieceType, Move t_move, size_t t_depth, size_t t_maxDepth);

	static std::vector<Coordinate> * getAllAvailableMoves(GameBoard const & t_board);

};

#endif // !MINIMAX_H