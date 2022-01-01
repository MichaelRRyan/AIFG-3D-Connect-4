#include "GameBoard.h"

Coordinate::Type const GameBoard::SIZE;

///////////////////////////////////////////////////////////////////////////////
GameBoard::GameBoard() :
	m_pieces() // To remove uninitialised variable warnings.
{
	for (auto & slice : m_pieces) // Gets an array of y and z for every x.
		for (auto & row : slice) // Gets an array of z for every x and y.
			for (PieceType & type : row) // Gets every piece for each x, y, z.
				type = PieceType::None;
}

///////////////////////////////////////////////////////////////////////////////
void GameBoard::setPiece(Coordinate const & t_position,
						 PieceType const & t_type)
{
	m_pieces.at(t_position.x).at(t_position.y).at(t_position.z) = t_type;
}

///////////////////////////////////////////////////////////////////////////////
PieceType const& GameBoard::getPiece(Coordinate const & t_position) const
{
	return m_pieces.at(t_position.x).at(t_position.y).at(t_position.z);
}

///////////////////////////////////////////////////////////////////////////////