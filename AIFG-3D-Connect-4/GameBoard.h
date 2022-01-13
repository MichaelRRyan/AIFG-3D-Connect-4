#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <array>
#include "PieceType.h"
#include "Coordinate.h"

/// <summary>
/// Represents the game board, holding all data and interface for the board
///		of pieces.
/// </summary>
class GameBoard
{
public:

	/// <summary>
	/// Constructs the board and initialises every piece type to PieceType::None.
	/// </summary>
	GameBoard();
	
	/// <summary>
	/// Sets the PieceType of the piece at the given coordinates.
	/// <para>This method does no error checking for the range of the 
	///		coordinates so values outside the board bounds will throw an 
	///		'Out of Bounds' error.
	/// </summary>
	/// <param name="t_position">The x, y, z position to set.</param>
	/// <param name="t_type">the new type of the piece.</param>
	void setPiece(Coordinate const & t_position, PieceType const & t_type);

	/// <summary>
	/// Returns the PieceType of the piece at the given coordinates.
	/// <para>This method does no error checking for the range of the 
	///		coordinates so values outside the board bounds will throw an 
	///		'Out of Bounds' error.
	/// </para>
	/// </summary>
	/// <param name="t_position">The x, y, z position to set.</param>
	/// <returns>The PieceType of the piece at the given coordinates.</returns>
	PieceType const & getPiece(Coordinate const& t_position) const;

	/// <summary>
	/// Returns whether or not the board is full of pieces.
	/// </summary>
	/// <returns>Whether or not the board is full of pieces.</returns>
	bool isFull() const;

public: // PUBLIC VARIABLES.
	
	/// The max value of each axis.
	static Coordinate::Type const SIZE{ 4 };

private: // PRIVATE VARIABLES.
	
	/// The total number of positions a piece can be placed in on the board.
	size_t const m_TOTAL_TILES;

	/// The total number of pieces placed by this rules handler.
	size_t m_piecesPlaced;

	// Holds all the game board data.
	std::array<std::array<std::array<PieceType, SIZE>, SIZE>, SIZE> m_pieces;

};

#endif // !GAME_BOARD_H
