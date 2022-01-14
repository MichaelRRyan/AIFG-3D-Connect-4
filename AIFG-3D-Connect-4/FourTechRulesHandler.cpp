#include "FourTechRulesHandler.h"

///////////////////////////////////////////////////////////////////////////////
FourTechRulesHandler::FourTechRulesHandler(Game& t_game, GameBoard & t_board) :
	m_board{ t_board },
	m_game(t_game)
{
	std::cout << "Move History:" << std::endl;
}

FourTechRulesHandler::~FourTechRulesHandler()
{
	delete m_turnHandler;
}

// TEMPORARY.
#include <limits>

///////////////////////////////////////////////////////////////////////////////
void FourTechRulesHandler::update()
{
	// Gets the position either the player or AI wants.
	Move move;

	// Loops until it finds a position that that player/AI can place, or the
	//		window closes.
	while (true) 
	{ 
		move = m_turnHandler->getMove();
		if (move.position.x != -1 
			&& PieceType::None == m_board.getPiece(move.position))
			break;

		// Handle the case of the input closing the window.
		if (!Window::getWindow().isOpen()) return;
	}

	// Get the piece type and place it.
	m_board.setPiece(move.position, move.type);

	// Prints the move to the console.
	std::cout << (PieceType::Red == move.type ? "X: " : "O: ")
		<< move.position.x << " " << move.position.y << " " << move.position.z << std::endl;
	
	// Checks if the move won the game.
	if (FourTechEvaluator::isMoveAWin(m_board, move))
		m_onGameOverFunction(m_game, move.type);

	// Calls a draw if all tiles are filled with no win.
	else if (m_board.isFull())
		m_onGameOverFunction(m_game, PieceType::None);

	// Switches turn to either the player or the AI.
	m_turnHandler->changeTurn();
}

///////////////////////////////////////////////////////////////////////////////
void FourTechRulesHandler::setOnGameOverFunction(OnGameOverFunction t_function)
{
	m_onGameOverFunction = t_function;
}

///////////////////////////////////////////////////////////////////////////////
void FourTechRulesHandler::setTurnHandler(TurnHandler* t_turnHandler)
{
	m_turnHandler = t_turnHandler;
}

///////////////////////////////////////////////////////////////////////////////