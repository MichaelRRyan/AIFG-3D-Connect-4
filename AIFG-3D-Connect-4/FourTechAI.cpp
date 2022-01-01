#include "FourTechAI.h"

FourTechAI::FourTechAI(GameBoard & t_board) :
	m_board{ t_board }
{
}

Coordinate FourTechAI::getMove()
{
	std::vector<Coordinate> moves;

	for (size_t x = 0u; x < 4u; ++x)
	{
		for (size_t y = 0u; y < 4u; ++y)
		{
			for (size_t z = 0u; z < 4u; ++z)
			{
				if (PieceType::None == m_board.getPiece(x, y, z))
				{
					moves.push_back(Coordinate{ x, y, z });
				}
			}
		}
	}

	return moves.front();
}
