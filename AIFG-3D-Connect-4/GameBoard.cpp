#include "GameBoard.h"

Coordinate::Type const GameBoard::SIZE;

///////////////////////////////////////////////////////////////////////////////
GameBoard::GameBoard() :
	m_TOTAL_TILES{ 64u },
	m_piecesPlaced{ 0u },
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
	PieceType & cell = 
		m_pieces.at(t_position.x).at(t_position.y).at(t_position.z);

	// If the new type is None.
	if (PieceType::None == t_type)
	{
		// Decrement pieces placed if the old type was a valid piece.
		if (PieceType::None != cell) m_piecesPlaced--;
	}

	// If the new type is a piece and the old type was None, increases pieces
	//		placed.
	else if (PieceType::None == cell)
		m_piecesPlaced++;

	// Sets the new cell type.
	cell = t_type;
}

///////////////////////////////////////////////////////////////////////////////
PieceType const& GameBoard::getPiece(Coordinate const & t_position) const
{
	return m_pieces.at(t_position.x).at(t_position.y).at(t_position.z);
}

///////////////////////////////////////////////////////////////////////////////
bool GameBoard::isFull() const
{
	return m_TOTAL_TILES == m_piecesPlaced;
}

///////////////////////////////////////////////////////////////////////////////