#include "SfmlRenderer.h"

SfmlRenderer::SfmlRenderer() :
	m_gameBoard(nullptr)
{
	// Sets up each grid and assings the grid index to each grid.
	for (Coordinate::Type board = 0u; board < 4; board++)
	{
		m_grids.push_back(Grid(board));
	}
}

SfmlRenderer::~SfmlRenderer()
{
}

void SfmlRenderer::render()
{
	Window::getWindow().clear(sf::Color::Black);
	for (auto grid : m_grids)
	{
		grid.render(Window::getWindow());
	}
	Window::getWindow().display();
}

void SfmlRenderer::setGameBoard(GameBoard* t_gameBoard)
{
	m_gameBoard = t_gameBoard;
}