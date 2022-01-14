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
	using namespace std::chrono;
	auto start = high_resolution_clock::now();
#endif // OUTPUT_DURATION

	// Sets up a best move variables.
	int alpha = m_INT_MIN;
	Coordinate bestCoord;

	forEachValidMove(t_board,
		[&](Coordinate const& t_coord)
		{
			// Recursively calls minimax and saves the value.
			int v = minimax(t_board, { t_coord, t_pieceType }, 1, alpha, m_INT_MAX);

			// Stores the move as the best if better than the previous best.
			if (v > alpha)
			{
				alpha = v;
				bestCoord = t_coord;
			}

			// If the move has the same score as the best, 2% chance of 
			//		taking the new one instead.
			/*else if (v == alpha && rand() % 50 == 0)
				bestCoord = t_coord;*/

			return false;
		});

#ifdef OUTPUT_DURATION
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(end - start);
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
	if (t_depth < m_maxDepth)
	{
		// Performs the move we're checking.
		t_board.setPiece(t_move.position, t_move.type);

		// Returns a score of zero if this move results in a draw.
		if (t_board.isFull())
		{
			t_board.setPiece(t_move.position, PieceType::None);
			return 0;
		}

		// Calls the following lambda for each valid move.
		forEachValidMove(t_board,
			[&](Coordinate const& t_coord)
			{
				// Recursively calls minimax and takes the value returned.
				int value = minimax(t_board,
					{ t_coord, opposite(t_move.type) },
					t_depth + 1, t_alpha, t_beta);

				// Sets the relevant value (alpha or beta) if applicable.
				if (isMin) t_beta = std::min(t_beta, value);
				else t_alpha = std::max(t_alpha, value);

				// Should we prune?
				if (t_alpha >= t_beta) return true; // Stops looping each move.
				return false; // Continue looping each move.
			});

		// Returns the piece to it's original empty state and returns.
		t_board.setPiece(t_move.position, PieceType::None);
		return (isMin) ? t_beta : t_alpha; // Returns the relevant value.
	}

	// Return the best estimated coord if already met the depth.
	return FourTechEvaluator::evaluateMove(t_board, t_move) * ((isMin) ? 1 : -1);
}

///////////////////////////////////////////////////////////////////////////////
void Minimax::forEachValidMove(GameBoard const & t_board, 
							   EachMoveFunc const & t_func)
{
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
					// Calls the function with the current board position.
					if (t_func(position)) return;
				}
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////