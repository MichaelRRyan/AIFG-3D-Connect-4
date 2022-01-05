#include "FourTechAI.h"

///////////////////////////////////////////////////////////////////////////////
FourTechAI::FourTechAI(GameBoard & t_board) :
	m_board{ t_board }
{
}

///////////////////////////////////////////////////////////////////////////////
Coordinate FourTechAI::getCoordinate()
{
	return Minimax::getCoordinate(m_board, PieceType::Yellow, 2);
}
///////////////////////////////////////////////////////////////////////////////