#include "GameBoard.h"

///////////////////////////////////////////////////////////////////////////////
GameBoard::GameBoard() :
	m_pieces() // To remove uninitialised variable warnings.
{
	for (auto & slice : m_pieces) // Gets an array of y and z for every x.
		for (auto & row : slice) // Gets an array of z for every x and y.
			for (PieceType & type : row) // Gets every piece for each x, y, z.
				type = PieceType::None;
	m_BoardRenderer = new ConsoleGameBoardRenderer();
	m_BoardRenderer->setGameBoard(this);
}

///////////////////////////////////////////////////////////////////////////////
void GameBoard::setPiece(size_t t_x, size_t t_y, size_t t_z, 
						 PieceType const & t_type)
{
	m_pieces.at(t_x).at(t_y).at(t_z) = t_type;
}

///////////////////////////////////////////////////////////////////////////////
PieceType const& GameBoard::getPiece(size_t t_x, size_t t_y, size_t t_z) const
{
	return m_pieces.at(t_x).at(t_y).at(t_z);
}

void GameBoard::render()
{
	m_BoardRenderer->render();
}

///////////////////////////////////////////////////////////////////////////////