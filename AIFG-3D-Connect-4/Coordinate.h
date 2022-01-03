#ifndef COORDINATE_H
#define COORDINATE_H

/// <summary>
/// Represents a position in 3D space on the game board.
/// </summary>
struct Coordinate
{
	/// The underlying type of the coordinate components (x, y, z).
	using Type = size_t;

	Type x;
	Type y;
	Type z;

	/// <summary>
	/// The coordinate default constructor, initialises all values to 0.
	/// </summary>
	Coordinate() :
		x{ 0u },
		y{ 0u },
		z{ 0u }
	{}

	/// <summary>
	/// Constructs the coordinate object with the values passed.
	/// </summary>
	/// <param name="t_x">The x value.</param>
	/// <param name="t_y">The y value.</param>
	/// <param name="t_z">The z value.</param>
	Coordinate(Type t_x, Type t_y, Type t_z) :
		x{ t_x },
		y{ t_y },
		z{ t_z }
	{}
};

#endif // !COORDINATE_H
