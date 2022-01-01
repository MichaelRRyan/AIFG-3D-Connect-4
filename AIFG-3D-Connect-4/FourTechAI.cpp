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

	for (size_t x = 0u; x < 4u; ++x)
	{
		for (size_t y = 0u; y < 4u; ++y)
		{
			for (size_t z = 0u; z < 4u; ++z)
			{
				if (PieceType::None == m_board.getPiece(x, y, z))
				{
					Coordinate position{ x, y, z };
					moves.push_back({ position, 
						FourTechEvaluator::evaluateMove(m_board, 
							{ position, PieceType::Yellow }) });
				}
			}
		}
	}

	std::pair<Coordinate, int> const * bestMove = &moves.front();

	for (auto const & move : moves)
	{
		if (move.second > bestMove->second)
		{
			bestMove = &move;
		}
	}

	return bestMove->first;
}

///////////////////////////////////////////////////////////////////////////////