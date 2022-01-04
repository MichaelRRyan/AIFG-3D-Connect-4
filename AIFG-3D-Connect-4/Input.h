#ifndef INPUT_H
#define INPUT_H
#include "Coordinate.h"
/// <summary>
/// This repersents an abstract input that will be used for AI and player input.
/// </summary>
class Input
{
public:
	/// <summary>
	/// This is the default constructor for the Input.
	/// </summary>
	Input() = default;

	/// <summary>
	/// This is the default destructor for the Input.
	/// </summary>
	~Input() = default;

	/// <summary>
	/// This repersents how the AI and player will get the position they want to
	/// put thier piece into the game board.
	/// </summary>
	/// <returns>returns the players or AI's position in the game board.</returns>
	virtual Coordinate getCoordinate() = 0;
};

#endif
