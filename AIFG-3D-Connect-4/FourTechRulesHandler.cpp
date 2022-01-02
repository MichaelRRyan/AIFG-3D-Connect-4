#include "FourTechRulesHandler.h"

///////////////////////////////////////////////////////////////////////////////
FourTechRulesHandler::FourTechRulesHandler(GameBoard & t_board) :
	m_TOTAL_BOARD_TILES{ 64u },
	m_board{ t_board },
	m_piecesPlaced{ 0u },
	m_ai{ t_board },
	m_playersTurn{ true }
{
}

// TEMPORARY.
#include <limits>

///////////////////////////////////////////////////////////////////////////////
void FourTechRulesHandler::update()
{
	Coordinate pos{ 0, 0, 0 };

	if (m_playersTurn)
	{
		// Takes the player's input - will be moved to it's own class with time.
		std::cout << "Enter your move: ";

		std::cin >> pos.x >> pos.y >> pos.z;

		if (PieceType::None != m_board.getPiece(pos))
		{
			std::cout << "Invalid position" << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max());
			std::cin.get();
			return;
		}
	}
	else
	{
		pos = m_ai.getMove();
	}

	// Get the piece type and place it.
	PieceType type = m_playersTurn ? PieceType::Red : PieceType::Yellow;
	m_board.setPiece(pos, type);

	// Increase the number of pieces placed and add the move to the history.
	++m_piecesPlaced;
	m_moveHistory.push_back(pos);
	
	// Checks if the move won the game.
	if (FourTechEvaluator::isMoveAWin(m_board, { pos, type }))
		m_onGameOverFunction(type);

	// Calls a draw if all tiles are filled with no win.
	else if (m_piecesPlaced == m_TOTAL_BOARD_TILES)
		m_onGameOverFunction(PieceType::None);

	// Switch turns.
	//m_playersTurn = !m_playersTurn;
}

///////////////////////////////////////////////////////////////////////////////
void FourTechRulesHandler::setOnGameOverFunction(OnGameOverFunction t_function)
{
	m_onGameOverFunction = t_function;
}

///////////////////////////////////////////////////////////////////////////////
void FourTechRulesHandler::printMoves() const
{
	std::cout << "History:" << std::endl;
	bool redsTurn = true;
	for (Coordinate const & move : m_moveHistory)
	{
		std::cout << (redsTurn ? "X: " : "O: ")
			<< move.x << " " << move.y << " " << move.z << std::endl;
		redsTurn = !redsTurn;
	}
}

///////////////////////////////////////////////////////////////////////////////