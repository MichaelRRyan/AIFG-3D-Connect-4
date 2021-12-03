#include "ConsoleGameBoardRenderer.h"

ConsoleGameBoardRenderer::ConsoleGameBoardRenderer()
{
	m_renderBoard = true;
}

ConsoleGameBoardRenderer::~ConsoleGameBoardRenderer()
{
	delete m_gameBoard;
}

void ConsoleGameBoardRenderer::render()
{
	if (m_gameBoard != nullptr && m_renderBoard)
	{
		m_renderBoard = false;
	}
}

void ConsoleGameBoardRenderer::setGameBoard(GameBoard* t_gameBoard)
{
	if(t_gameBoard != nullptr) 
		m_gameBoard = t_gameBoard;
}
