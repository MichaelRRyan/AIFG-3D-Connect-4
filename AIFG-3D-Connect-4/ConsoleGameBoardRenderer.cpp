#include "ConsoleGameBoardRenderer.h"

///////////////////////////////////////////////////////////////////////////////
ConsoleGameBoardRenderer::ConsoleGameBoardRenderer() :
	m_gameBoard{ nullptr }
{
}

///////////////////////////////////////////////////////////////////////////////
ConsoleGameBoardRenderer::~ConsoleGameBoardRenderer()
{
}

///////////////////////////////////////////////////////////////////////////////
void ConsoleGameBoardRenderer::render()
{
	if (m_gameBoard != nullptr)
	{
		for (Coordinate::Type board = 0u; board < GameBoard::SIZE; board++)
		{
			for (Coordinate::Type col = 0u; col < GameBoard::SIZE; col++)
			{
				for (Coordinate::Type row = 0u; row < GameBoard::SIZE; row++)
				{
					std::cout << static_cast<char>(
						m_gameBoard->getPiece({ row, board, col }))
						<< " ";
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
	}
}

void ConsoleGameBoardRenderer::setGameBoard(GameBoard* t_gameBoard)
{
	if(t_gameBoard != nullptr) 
		m_gameBoard = t_gameBoard;
}

///////////////////////////////////////////////////////////////////////////////