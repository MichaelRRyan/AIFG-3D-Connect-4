#include "FourTechAI.h"

///////////////////////////////////////////////////////////////////////////////
FourTechAI::FourTechAI(GameBoard & t_board) :
	m_board{ t_board }
{
}

///////////////////////////////////////////////////////////////////////////////
Coordinate FourTechAI::getMove()
{
	// Move position and score.
	std::vector<std::pair<Coordinate, int>> moves;

	// Loops through each position on the board.
	Coordinate position{ 0u, 0u, 0u };

	for (; position.x < GameBoard::SIZE; ++position.x)
	{
		for (; position.y < GameBoard::SIZE; ++position.y)
		{
			for (; position.z < GameBoard::SIZE; ++position.z)
			{
				// If the position has no piece on it.
				if (PieceType::None == m_board.getPiece(position))
				{
					// Gets the score of the move.
					int moveScore = FourTechEvaluator::evaluateMove(m_board,
										{ position, PieceType::Yellow });

					// Stores the move position and score.
					moves.push_back({ position, moveScore });
				}
			}
		}
	}

	// Finds the highest scoring move.
	auto const * bestMove = &moves.front();
	for (auto const & move : moves)
		if (move.second > bestMove->second)
			bestMove = &move;

	return bestMove->first; // Returns the position of the best move.
}

///////////////////////////////////////////////////////////////////////////////