#ifndef MOVE_H
#define MOVE_H

#include "Coordinate.h"
#include "PieceType.h"

/// <summary>
/// Represents a move (or ply) in the game. The class contains a position and
///		piece type, everything needed to replicate a move.
/// </summary>
class Move
{
public:

	/// The position on the board the piece was placed.
	Coordinate position;

	/// The piece type that was placed.
	PieceType type;

};

#endif // !MOVE_H