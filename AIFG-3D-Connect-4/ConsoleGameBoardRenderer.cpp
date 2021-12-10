#include "ConsoleGameBoardRenderer.h"

ConsoleGameBoardRenderer::ConsoleGameBoardRenderer()
{
	m_canRender = true;
}

ConsoleGameBoardRenderer::~ConsoleGameBoardRenderer()
{
}

void ConsoleGameBoardRenderer::render()
{
	if (m_gameBoard != nullptr && m_canRender)
	{
		for (int row = 0; row < 4; row++)
		{
			for (int board = 0; board < 4; board++)
			{
				for (int col = 0; col < 4; col++)
				{
					std::cout << static_cast<char>(
						m_gameBoard->getPiece(row, board, col));
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
		m_canRender = false;
	}
}

void ConsoleGameBoardRenderer::setGameBoard(GameBoard* t_gameBoard)
{
	if(t_gameBoard != nullptr) 
		m_gameBoard = t_gameBoard;
}

void ConsoleGameBoardRenderer::setCanRender(bool t_canRender)
{
	m_canRender = t_canRender;
}
