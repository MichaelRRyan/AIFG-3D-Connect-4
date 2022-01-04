#include "ConsoleInput.h"
///////////////////////////////////////////////////////////////////////////////
ConsoleInput::ConsoleInput(GameBoard& t_board) : m_board(t_board)
{}

///////////////////////////////////////////////////////////////////////////////
Coordinate ConsoleInput::getCoordinate()
{
	Coordinate pos{ 0, 0, 0 }; // set the coordinates to a default value.
	bool validInput = false;
	do
	{
		std::cout << "Enter your move: ";
		std::cin >> pos.x >> pos.y >> pos.z;
		if (std::cin.fail() || validateIfInputWithinGameBoard(pos)) // checks if the input is valid.
		{
			std::cout << "You have entered incorrect values. Please enter 3 numbers with spaces, ranging from 0-3. i.e (0 1 2)" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else
		{
			validInput = true; // if the input has gone through vaildation, then the input is vaild.
			continue;
		}
	} while (!validInput); // Loop, until you find a valid input.
	return pos;
}

///////////////////////////////////////////////////////////////////////////////
bool ConsoleInput::validateIfInputWithinGameBoard(Coordinate t_pos)
{
	// Checks if the input is within the bounds of the game board.
	return ((t_pos.x > 3 || t_pos.x < 0) || (t_pos.y > 3 || t_pos.y < 0) || (t_pos.z > 3 || t_pos.z < 0));
}
///////////////////////////////////////////////////////////////////////////////
