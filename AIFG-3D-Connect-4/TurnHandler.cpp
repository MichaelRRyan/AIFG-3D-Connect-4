#include "TurnHandler.h"

TurnHandler::TurnHandler() : m_coordinate(0,0,0), m_playersTurn(true)
{
	// Set the players to nullptr, the user will set these up later.
	m_player1 = nullptr;
	m_player2 = nullptr;
}

TurnHandler::~TurnHandler()
{
	delete m_player1;
	delete m_player2;
}

void TurnHandler::setPlayer1(Input* t_player1)
{
	m_player1 = t_player1;
}

void TurnHandler::setPlayer2(Input* t_player2)
{
	m_player2 = t_player2;
}

Coordinate TurnHandler::getCoordinate()
{
	// Handles the turn order and gets the position the player or AI wants.
	if (m_playersTurn)
	{
		m_coordinate = m_player1->getCoordinate();
	}
	else
	{
		m_coordinate = m_player2->getCoordinate();
	}
	return m_coordinate;
}

void TurnHandler::changeTurn()
{
	// Switch turns.
	m_playersTurn = !m_playersTurn;
}
