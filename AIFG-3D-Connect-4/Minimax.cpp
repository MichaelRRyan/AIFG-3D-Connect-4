#include "Minimax.h"

int const Minimax::m_INT_MAX = std::numeric_limits<int>::max();
int const Minimax::m_INT_MIN = std::numeric_limits<int>::min();
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
#ifdef OUTPUT_DURATION
	auto start = std::chrono::high_resolution_clock::now();
#endif // OUTPUT_DURATION

	// Gets all available moves and sets up a best move variables.
	std::vector<Coordinate> * availableMoves = getAvailableMoves(t_board);
	int bestScore = m_INT_MIN;
	int alpha = m_INT_MIN;
	int beta = m_INT_MAX;
	Coordinate bestCoord;

	for (Coordinate const & coord : * availableMoves)
	{
		// Recursively calls minimax and saves the value.
		int score = minimax(t_board, { coord, t_pieceType }, 1, 
							alpha, beta);

		// Stores the move as the best if better than the previous best.
		if (score > bestScore)
		{
			bestScore = score;
			bestCoord = coord;
		}
	}
	
	delete availableMoves; // Cleans up the moves.

#ifdef OUTPUT_DURATION
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "Minimax took: " << duration.count() / 1000.0f << std::endl;
	system("pause");
#endif // OUTPUT_DURATION

	return bestCoord; // Returns the best move position.
}

///////////////////////////////////////////////////////////////////////////////
int Minimax::minimax(GameBoard & t_board, Move t_move, 
					 int t_depth, int t_alpha, int t_beta)
{
	// If the depth is odd, we're min.
	bool isMin = t_depth % 2 == 1;

	// Returns the max score if the AI will win this move or the min score if
	//		the enemy wins this turn.
	if (FourTechEvaluator::isMoveAWin(t_board, t_move))
		return (isMin) ? m_INT_MAX - 1 : m_INT_MIN + 1;

	// If below the max depth or if ending on max (meaning t_move, which will
	//		will be evaluated, is the enemies move).
	if (t_depth < m_maxDepth || !isMin)
	{
		// Performs the move we're checking.
		t_board.setPiece(t_move.position, t_move.type);

		std::vector<Coordinate> * availableMoves = getAvailableMoves(t_board);
		int bestScore = isMin ? m_INT_MAX : m_INT_MIN;

		if (isMin)
		{
			// Recursively calls minimax and keeps the lowest score.
			for (Coordinate const& coord : *availableMoves)
				bestScore = std::min(bestScore, minimax(t_board,
								{ coord, opposite(t_move.type) }, 
								t_depth + 1, t_alpha, t_beta));
		}
		else
		{
			// Recursively calls minimax and keeps the highest score.
			for (Coordinate const& coord : *availableMoves)
				bestScore = std::max(bestScore, minimax(t_board,
								{ coord, opposite(t_move.type) }, 
								t_depth + 1, t_alpha, t_beta));
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