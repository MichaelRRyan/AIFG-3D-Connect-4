#ifndef COORDINATE_H
#define COORDINATE_H

/// <summary>
/// Represents a position in 3D space on the game board.
/// </summary>
struct Coordinate
{
	size_t x;
	size_t y;
	size_t z;

	Coordinate(size_t t_x, size_t t_y, size_t t_z) :
		x{ t_x },
		y{ t_y },
		z{ t_z }
	{}
};

#endif // !COORDINATE_H
