#include "TurnHandler.h"

///////////////////////////////////////////////////////////////////////////////
TurnHandler::TurnHandler() : m_playerOnesTurn(true), m_player1(nullptr), m_player2(nullptr)
{
}

///////////////////////////////////////////////////////////////////////////////
TurnHandler::~TurnHandler()
{
	delete m_player1;
	delete m_player2;
}

///////////////////////////////////////////////////////////////////////////////
void TurnHandler::setPlayer1(Input* t_player1)
{
	// Cleans up the previous input.
	if (m_player1) delete m_player1;

	m_player1 = t_player1;
}

///////////////////////////////////////////////////////////////////////////////
void TurnHandler::setPlayer2(Input* t_player2)
{
	// Cleans up the previous input.
	if (m_player2) delete m_player2;

	m_player2 = t_player2;
}

///////////////////////////////////////////////////////////////////////////////
void TurnHandler::changeTurn()
{
	// Switch turns.
	m_playerOnesTurn = !m_playerOnesTurn;
}

///////////////////////////////////////////////////////////////////////////////
Move TurnHandler::getMove()
{
	// Handles the turn order and gets the position the player or AI wants.
	if (m_playerOnesTurn)
	{
		m_move.position = m_player1->getCoordinate();
		m_move.type = PieceType::Red; // x
	}
	else
	{
		m_move.position = m_player2->getCoordinate();
		m_move.type = PieceType::Yellow; // o
	}
	return m_move;
}
///////////////////////////////////////////////////////////////////////////////
