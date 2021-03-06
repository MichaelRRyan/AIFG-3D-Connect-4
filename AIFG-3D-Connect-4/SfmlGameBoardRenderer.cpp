#include "SfmlGameBoardRenderer.h"

///////////////////////////////////////////////////////////////////////////////
SfmlGameBoardRenderer::SfmlGameBoardRenderer(std::vector<Grid>& t_grid) :
	m_gameBoard(nullptr),
	m_grids(t_grid)
{
	// Sets up each grid and assings the grid index to each grid.
	for (Coordinate::Type board = 0u; board < 4; board++)
	{
		m_grids.push_back(Grid(board));
	}
}

///////////////////////////////////////////////////////////////////////////////
SfmlGameBoardRenderer::~SfmlGameBoardRenderer()
{
}

///////////////////////////////////////////////////////////////////////////////
void SfmlGameBoardRenderer::render()
{
	Window::getWindow().clear(sf::Color::Black);
	for (auto grid : m_grids)
	{
		grid.render(Window::getWindow());
	}
	Window::getWindow().display();
}

///////////////////////////////////////////////////////////////////////////////
void SfmlGameBoardRenderer::setGameBoard(GameBoard* t_gameBoard)
{
	m_gameBoard = t_gameBoard;
	// Make every board be aware of the game board.
	for (auto& grid : m_grids)
	{
		grid.setGameBoard(t_gameBoard);
	}
}
///////////////////////////////////////////////////////////////////////////////