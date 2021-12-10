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