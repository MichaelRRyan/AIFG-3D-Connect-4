#include "FourTechRulesHandler.h"

///////////////////////////////////////////////////////////////////////////////
FourTechRulesHandler::FourTechRulesHandler(Game& t_game, GameBoard & t_board) :
	m_TOTAL_BOARD_TILES{ 64u },
	m_board{ t_board },
	m_piecesPlaced{ 0u },
	m_game(t_game)
{
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
	while (true) // Loops until it finds a position that that player/AI can place.
	{ 
		move = m_turnHandler->getMove();
		if (move.position.x != -1 && PieceType::None == m_board.getPiece(move.position)){ break; }
	}
	Coordinate pos = move.position;
	// Get the piece type and place it.
	PieceType type = move.type;
	m_board.setPiece(pos, type);

	// Increase the number of pieces placed and add the move to the history.
	++m_piecesPlaced;
	m_moveHistory.push_back(pos);
	
	// Checks if the move won the game.
	if (FourTechEvaluator::isMoveAWin(m_board, { pos, type }))
		m_onGameOverFunction(m_game, type);

	// Calls a draw if all tiles are filled with no win.
	else if (m_piecesPlaced == m_TOTAL_BOARD_TILES)
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