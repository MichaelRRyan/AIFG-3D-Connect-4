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
	if (m_playersTurn)
	{
		// Takes the player's input - will be moved to it's own class with time.
		Coordinate pos{ 0, 0, 0 };
		std::cout << "Enter your move: ";
		std::cin >> pos.x >> pos.y >> pos.z;

		if (PieceType::None == m_board.getPiece(pos))
		{
			m_board.setPiece(pos, PieceType::Red);
			++m_piecesPlaced;

			// Checks if the move won the game.
			if (FourTechEvaluator::isMoveAWin(m_board, { pos, PieceType::Red }))
				m_onGameOverFunction(PieceType::Red);

			// Calls a draw if all tiles are filled with no win.
			else if (m_piecesPlaced == m_TOTAL_BOARD_TILES)
				m_onGameOverFunction(PieceType::None);
		}
		else
		{
			std::cout << "Invalid position" << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max());
			std::cin.get();
		}
	}
	else
	{
		Coordinate pos = m_ai.getMove();
		m_board.setPiece(pos, PieceType::Yellow);
		++m_piecesPlaced;

		// Checks if the move won the game.
		if (FourTechEvaluator::isMoveAWin(m_board, { pos, PieceType::Yellow }))
			m_onGameOverFunction(PieceType::Yellow);

		// Calls a draw if all tiles are filled with no win.
		else if (m_piecesPlaced == m_TOTAL_BOARD_TILES)
			m_onGameOverFunction(PieceType::None);
	}

	m_playersTurn = !m_playersTurn;
}

///////////////////////////////////////////////////////////////////////////////
void FourTechRulesHandler::setOnGameOverFunction(OnGameOverFunction t_function)
{
	m_onGameOverFunction = t_function;
}

///////////////////////////////////////////////////////////////////////////////