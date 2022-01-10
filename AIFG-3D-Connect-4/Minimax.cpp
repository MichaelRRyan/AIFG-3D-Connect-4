#include "Minimax.h"

int const Minimax::m_MAX_SCORE = std::numeric_limits<int>::max();
int const Minimax::m_MIN_SCORE = std::numeric_limits<int>::min();
int Minimax::m_maxDepth = 3;

///////////////////////////////////////////////////////////////////////////////
void Minimax::setMaxDepth(int t_depth)
{
	m_maxDepth = t_depth;
}

///////////////////////////////////////////////////////////////////////////////
Coordinate Minimax::getCoordinate(GameBoard & t_board, 
								  PieceType t_pieceType)
{
	// Gets all available moves and sets up a temporary best move.
	std::vector<Coordinate> * availableMoves = getAvailableMoves(t_board);
	Ply bestPly{ Move(), m_MIN_SCORE };

	for (Coordinate const & coord : * availableMoves)
	{
		Move move{ coord, t_pieceType };

		// Recursively calls minimax and saves the value.
		int score = minimax(t_board, move, 1);

		// Stores the move as the best if better than the previous best.
		if (score > bestPly.score)
		{
			bestPly.score = score;
			bestPly.move = move;
		}
	}
	
	delete availableMoves; // Cleans up the moves.
	return bestPly.move.position; // Returns the best ply.
}

///////////////////////////////////////////////////////////////////////////////
int Minimax::minimax(GameBoard & t_board, Move t_move, int t_depth)
{
	// If the depth is odd, we're min.
	bool isMin = t_depth % 2 == 1;

	// Returns the max score if the AI will win this move or the min score if
	//		the enemy wins this turn.
	if (FourTechEvaluator::isMoveAWin(t_board, t_move))
		return (isMin) ? m_MAX_SCORE : m_MIN_SCORE;

	// If below the max depth or if ending on max (meaning t_move, which will
	//		will be evaluated, is the enemies move).
	if (t_depth < m_maxDepth || !isMin)
	{
		// Performs the move we're checking.
		t_board.setPiece(t_move.position, t_move.type);

		std::vector<Coordinate> * availableMoves = getAvailableMoves(t_board);
		int bestScore = isMin ? m_MAX_SCORE : m_MIN_SCORE;

		if (isMin)
		{
			// Recursively calls minimax and keeps the lowest score.
			for (Coordinate const& coord : *availableMoves)
				bestScore = std::min(bestScore, minimax(t_board,
					{ coord, opposite(t_move.type) }, t_depth + 1));
		}
		else
		{
			// Recursively calls minimax and keeps the highest score.
			for (Coordinate const& coord : *availableMoves)
				bestScore = std::max(bestScore, minimax(t_board,
					{ coord, opposite(t_move.type) }, t_depth + 1));
		}

		// Cleans up the moves.
		delete availableMoves;

		// Returns the piece to it's original empty state.
		t_board.setPiece(t_move.position, PieceType::None);

		return bestScore;
	}

	// Return the best estimated coord if already met the depth.
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