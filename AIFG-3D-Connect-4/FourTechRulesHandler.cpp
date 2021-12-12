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
	int8_t xValues[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	for (int x = 0; x < 4; ++x)
	{
		int8_t yValues[4] = { 0, 0, 0, 0 };

		for (int y = 0; y < 4; ++y)
		{
			int8_t zValue = 0;

			for (int z = 0; z < 4; ++z)
			{
				if (PieceType::Red == m_gameBoard->getPiece(x, y, z))
				{
					zValue++;
					yValues[z]++;
					xValues[(y * 4) + z]++;
				}
				else if (PieceType::Yellow == m_gameBoard->getPiece(x, y, z))
				{
					zValue--;
					yValues[z]--;
					xValues[(y * 4) + z]--;
				}
			}

			if (evaluateRow(zValue)) return;
		}

		for (int i = 0; i < 4; ++i)
			if (evaluateRow(yValues[i])) return;
	}

	for (int i = 0; i < 16; ++i)
		if (evaluateRow(xValues[i])) return;
}

///////////////////////////////////////////////////////////////////////////////
bool FourTechRulesHandler::evaluateRow(int t_rowValue)
{
	if (abs(t_rowValue) == 4)
	{
		PieceType type = (t_rowValue > 0) ? PieceType::Red : PieceType::Yellow;
		m_onGameOverFunction(type);
		return true;
	}
	return false;
}

///////////////////////////////////////////////////////////////////////////////
int FourTechRulesHandler::getLineValue(size_t t_x, size_t t_y, size_t t_z)
{
	return 0;
}

///////////////////////////////////////////////////////////////////////////////