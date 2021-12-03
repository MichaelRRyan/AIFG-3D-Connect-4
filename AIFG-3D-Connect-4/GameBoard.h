#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <array>

/// <summary>
/// Represents the piece types stored in the game board.
/// </summary>
enum class PieceType
{
	None = 0,
	Red = 1,
	Yellow = 2
};

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
	/// </para>
	/// </summary>
	/// <param name="t_x">the x coordinate of the piece.</param>
	/// <param name="t_y">the y coordinate of the piece.</param>
	/// <param name="t_z">the z coordinate of the piece.</param>
	/// <param name="t_type">the new type of the piece.</param>
	void setPiece(size_t t_x, size_t t_y, size_t t_z, PieceType const & t_type);

	/// <summary>
	/// Returns the PieceType of the piece at the given coordinates.
	/// <para>This method does no error checking for the range of the 
	///		coordinates so values outside the board bounds will throw an 
	///		'Out of Bounds' error.
	/// </para>
	/// </summary>
	/// <param name="t_x">the x coordinate of the piece.</param>
	/// <param name="t_y">the y coordinate of the piece.</param>
	/// <param name="t_z">the z coordinate of the piece.</param>
	/// <returns>The PieceType of the piece at the given coordinates.</returns>
	PieceType const & getPiece(size_t t_x, size_t t_y, size_t t_z) const;

private:

	// Holds all the game board data.
	std::array<std::array<std::array<PieceType, 4>, 4>, 4> m_pieces;

};

#endif // !GAME_BOARD_H
