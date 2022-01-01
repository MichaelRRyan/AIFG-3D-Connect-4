#ifndef COORDINATE_H
#define COORDINATE_H

/// <summary>
/// Represents a position in 3D space on the game board.
/// </summary>
struct Coordinate
{
	using Type = size_t;

	Type x;
	Type y;
	Type z;

	Coordinate(Type t_x, Type t_y, Type t_z) :
		x{ t_x },
		y{ t_y },
		z{ t_z }
	{}
};

#endif // !COORDINATE_H
