#include "Minimax.h"

int const Minimax::m_MAX_SCORE = std::numeric_limits<int>::max();
int const Minimax::m_MIN_SCORE = std::numeric_limits<int>::min();

///////////////////////////////////////////////////////////////////////////////
Coordinate Minimax::getCoordinate(GameBoard & t_board, 
								  PieceType t_pieceType, 
								  size_t t_maxDepth)
{

	std::vector<Coordinate>* availableMoves =
		getAvailableMoves(t_board);

	Ply bestPly;
	bestPly.score = m_MIN_SCORE;

	for (Coordinate const& coord : *availableMoves)
	{
		Move move{ coord, t_pieceType };

		// Does the move.
		t_board.setPiece(coord, move.type);

		// Recursively calls minimax and saves the value.
		int score = minimax(t_board, t_pieceType, move, 1, t_maxDepth);

		if (score > bestPly.score)
		{
			bestPly.score = score;
			bestPly.move = move;
		}

		// Returns the piece to it's original empty state.
		t_board.setPiece(coord, PieceType::None);
	}

	// Cleans up.
	delete availableMoves;

	return bestPly.move.position; // Returns the best ply.
}

///////////////////////////////////////////////////////////////////////////////
int Minimax::minimax(GameBoard & t_board, Move t_move, size_t t_remainingDepth)
{
	if (t_remainingDepth > 0)
	{
		// Performs the move we're checking.
		t_board.setPiece(t_move.position, t_move.type);

		std::vector<Coordinate> * availableMoves = 
			getAvailableMoves(t_board);

		// If the depth is odd, we're min.
		bool isMin = t_remainingDepth % 2 == 1;
		int bestScore = isMin ? m_MAX_SCORE : m_MIN_SCORE;

		if (isMin)
		{
			// Recursively calls minimax and keeps the lowest score.
			for (Coordinate const& coord : *availableMoves)
				bestScore = std::min(bestScore, minimax(t_board,
					{ coord, opposite(t_move.type) }, t_remainingDepth - 1));
		}
		else
		{
			// Recursively calls minimax and keeps the highest score.
			for (Coordinate const& coord : *availableMoves)
				bestScore = std::max(bestScore, minimax(t_board,
					{ coord, opposite(t_move.type) }, t_remainingDepth - 1));
		}

		// Cleans up.
		delete availableMoves;

		// Returns the piece to it's original empty state.
		t_board.setPiece(t_move.position, PieceType::None);

		return bestScore;
	}

	// If greater than or equal to the depth, return the best estimated coord.
	return FourTechEvaluator::evaluateMove(t_board, t_move);
}

///////////////////////////////////////////////////////////////////////////////
std::vector<Coordinate> * Minimax::getAvailableMoves(GameBoard const & t_board)
{
	// Move position and score.
	std::vector<Coordinate>* moves = new std::vector<Coordinate>;

	// Loops through each position on the board.
	Coordinate position;
	for (; position.x < GameBoard::SIZE; ++position.x)
	{
		for (position.y = 0; position.y < GameBoard::SIZE; ++position.y)
		{
			for (position.z = 0; position.z < GameBoard::SIZE; ++position.z)
			{
				// If the position has no piece on it.
				if (PieceType::None == t_board.getPiece(position))
				{
					// Stores the move position.
					moves->push_back(position);
				}
			}
		}
	}

	return moves;
}

///////////////////////////////////////////////////////////////////////////////