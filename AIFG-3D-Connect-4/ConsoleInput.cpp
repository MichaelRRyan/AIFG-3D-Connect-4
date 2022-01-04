#include "ConsoleInput.h"

ConsoleInput::ConsoleInput(GameBoard& t_board) : m_board(t_board)
{}

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
			pos = { 0, 0, 0 };
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else
		{
			validInput = true; // if the input has gone through vaildation, then the input is vaild.
			continue;
		}
	} while (PieceType::None != m_board.getPiece(pos) || !validInput); // Loop, until you find pos that is valid.
	return pos;
}

bool ConsoleInput::validateIfInputWithinGameBoard(Coordinate t_pos)
{
	// Checks if the input is within the bounds of the game board.
	return ((t_pos.x > 3 || t_pos.x < 0) || (t_pos.y > 3 || t_pos.y < 0) || (t_pos.z > 3 || t_pos.z < 0));
}
