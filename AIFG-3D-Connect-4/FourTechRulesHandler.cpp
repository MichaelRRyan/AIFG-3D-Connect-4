#include "FourTechRulesHandler.h"

///////////////////////////////////////////////////////////////////////////////
FourTechRulesHandler::FourTechRulesHandler() :
	m_gameBoard{ nullptr }
{
}

// TEMPORARY.
#include <limits>

///////////////////////////////////////////////////////////////////////////////
void FourTechRulesHandler::update()
{
	// Takes the player's input - will be moved to it's own class with time.
	int x, y, z;
	std::cout << "Enter your move: ";
	std::cin >> x >> y >> z;

	if (PieceType::None == m_gameBoard->getPiece(x, y, z))
		m_gameBoard->setPiece(x, y, z, PieceType::Red);
	else
	{
		std::cout << "Invalid position" << std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max());
		std::cin.get();
	}

	checkForGameOver();
}

///////////////////////////////////////////////////////////////////////////////
void FourTechRulesHandler::setOnGameOverFunction(OnGameOverFunction t_function)
{
	m_onGameOverFunction = t_function;
}

///////////////////////////////////////////////////////////////////////////////
void FourTechRulesHandler::setGameBoard(GameBoard * t_gameBoard)
{
	m_gameBoard = t_gameBoard;
}

///////////////////////////////////////////////////////////////////////////////
void FourTechRulesHandler::checkForGameOver()
{
	for (int y = 0; y < 4; ++y)
	{
		int xInRows[4] = { 0, 0, 0, 0 };

		for (int x = 0; x < 4; x++)
		{
			int zInRow = 0;

			for (int z = 0; z < 4; z++)
			{
				if (PieceType::Red == m_gameBoard->getPiece(x, y, z))
				{
					zInRow++;
					xInRows[z]++;
				}
				else if (PieceType::Yellow == m_gameBoard->getPiece(x, y, z))
				{
					zInRow--;
					xInRows[z]--;
				}
			}

			if (abs(zInRow) == 4)
			{
				m_onGameOverFunction((zInRow > 0) ?
					PieceType::Red : PieceType::Yellow);
				return;
			}
		}

		for (int i = 0; i < 4; ++i)
		{
			if (abs(xInRows[i]) == 4)
			{
				m_onGameOverFunction((xInRows[i] > 0) ?
					PieceType::Red : PieceType::Yellow);
				return;
			}
		}
	}
}

int FourTechRulesHandler::getLineValue(size_t t_x, size_t t_y, size_t t_z)
{
	return 0;
}

///////////////////////////////////////////////////////////////////////////////