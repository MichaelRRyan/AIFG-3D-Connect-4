#include "FourTechRulesHandler.h"

///////////////////////////////////////////////////////////////////////////////
FourTechRulesHandler::FourTechRulesHandler() :
	m_TOTAL_BOARD_TILES{ 64u },
	m_gameBoard{ nullptr },
	m_piecesPlaced{ 0u }
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
	{
		m_gameBoard->setPiece(x, y, z, PieceType::Red);
		++m_piecesPlaced;
		checkForGameOver({ (size_t)x, (size_t)y, (size_t)z });
	}
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
void FourTechRulesHandler::checkForGameOver(Coordinate const & t_pos)
{
	// Checks the 3 straight axis.
	checkForStraightWin(t_pos);

	// Checks both diagonals along each of the 3 axis.
	checkForSingleAxisDiagonalWin(t_pos);
	
	// Checks the diagonals along all axis.
	checkForAllAxisDiagonalWin(t_pos);

	// Calls a draw if all tiles are filled with no win.
	if (m_piecesPlaced == m_TOTAL_BOARD_TILES)
		m_onGameOverFunction(PieceType::None);
}

///////////////////////////////////////////////////////////////////////////////
bool FourTechRulesHandler::checkForStraightWin(Coordinate const& t_pos)
{
	// Checks the 3 straight axis.
	if (evaluateAxis({ 0, t_pos.y, t_pos.z }, 1, 0, 0)) return true;
	if (evaluateAxis({ t_pos.x, 0, t_pos.z }, 0, 1, 0)) return true;
	if (evaluateAxis({ t_pos.x, t_pos.y, 0 }, 0, 0, 1)) return true;

	return false;
}

///////////////////////////////////////////////////////////////////////////////
bool FourTechRulesHandler::checkForSingleAxisDiagonalWin(Coordinate const& t_pos)
{
	// Checks the diagonals along the x axis.
	if (t_pos.y == t_pos.z && evaluateAxis({ t_pos.x, 0, 0 }, 0, 1, 1))
		return true;
	if (t_pos.y == 3 - t_pos.z && evaluateAxis({ t_pos.x, 0, 3 }, 0, 1, -1))
		return true;

	// Checks the diagonals along the y axis.
	if (t_pos.x == t_pos.z && evaluateAxis({ 0, t_pos.y, 0 }, 1, 0, 1))
		return true;
	if (t_pos.x == 3 - t_pos.z && evaluateAxis({ 0, t_pos.y, 3 }, 1, 0, -1))
		return true;

	// Checks the diagonals along the z axis.
	if (t_pos.x == t_pos.y && evaluateAxis({ 0, 0, t_pos.z }, 1, 1, 0))
		return true;
	if (t_pos.x == 3 - t_pos.y && evaluateAxis({ 0, 3, t_pos.z }, 1, -1, 0))
		return true;

	return false;
}

///////////////////////////////////////////////////////////////////////////////
bool FourTechRulesHandler::checkForAllAxisDiagonalWin(Coordinate const& t_pos)
{
	if (t_pos.x == t_pos.y && t_pos.x == t_pos.z
		&& evaluateAxis({ 0, 0, 0 }, 1, 1, 1))
		return true;

	if (3 - t_pos.x == t_pos.y && 3 - t_pos.x == t_pos.z
		&& evaluateAxis({ 3, 0, 0 }, -1, 1, 1))
		return true;

	if (t_pos.x == 3 - t_pos.y && t_pos.x == t_pos.z
		&& evaluateAxis({ 0, 3, 0 }, 1, -1, 1))
		return true;

	if (t_pos.x == 3 - t_pos.y && t_pos.x == 3 - t_pos.z
		&& evaluateAxis({ 0, 0, 3 }, 1, 1, -1))
		return true;

	return false;
}

///////////////////////////////////////////////////////////////////////////////
bool FourTechRulesHandler::evaluateAxis(Coordinate const & t_start, 
										int t_xInc, int t_yInc, int t_zInc)
{
	int value = 0;
	Coordinate cur = t_start;

	for (int i = 0; i < 4; ++i)
	{
		PieceType const& type = m_gameBoard->getPiece(cur.x, cur.y, cur.z);

		if (PieceType::Red == type)
			++value;
		else if (PieceType::Yellow == type)
			--value;

		cur.x += t_xInc;
		cur.y += t_yInc;
		cur.z += t_zInc;
	}

	return evaluateRow(value);
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