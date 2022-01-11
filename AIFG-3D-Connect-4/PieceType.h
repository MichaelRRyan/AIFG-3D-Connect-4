#ifndef PIECE_TYPE_H
#define PIECE_TYPE_H

/// <summary>
/// Represents the piece types stored in the game board.
/// </summary>
enum class PieceType : char
{
	None = '-',
	Red = 'x',
	Yellow = 'o'
};

///////////////////////////////////////////////////////////////////////////////
/// <summary>
/// Returns the opposite colour piece type, or None if None is passed.
/// </summary>
/// <param name="t_type">The type to get the opposite of.</param>
/// <returns>The opposite colour or None.</returns>
inline PieceType opposite(PieceType t_type)
{
	if (PieceType::None == t_type) return PieceType::None;
	return (PieceType::Red == t_type) ? PieceType::Yellow : PieceType::Red;
}

///////////////////////////////////////////////////////////////////////////////

#endif // !PIECE_TYPE_H
