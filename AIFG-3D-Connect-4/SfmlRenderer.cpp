#include "SfmlRenderer.h"

///////////////////////////////////////////////////////////////////////////////
SfmlRenderer::SfmlRenderer(std::vector<Grid>& t_grid, std::vector<Widget*>& t_widgets) :
	m_gameBoard(nullptr),
	m_grids(t_grid),
	m_widgets(t_widgets)
{
	// Sets up each grid and assings the grid index to each grid.
	for (Coordinate::Type board = 0u; board < 4; board++)
	{
		m_grids.push_back(Grid(board));
	}
}

///////////////////////////////////////////////////////////////////////////////
SfmlRenderer::~SfmlRenderer()
{
}

///////////////////////////////////////////////////////////////////////////////
void SfmlRenderer::render()
{
	Window::getWindow().clear(sf::Color::Black);
	//for (auto grid : m_grids)
	//{
	//	grid.render(Window::getWindow());
	//}
	for (auto widget : m_widgets)
	{
		widget->draw(Window::getWindow());
	}
	Window::getWindow().display();
}

///////////////////////////////////////////////////////////////////////////////
void SfmlRenderer::setGameBoard(GameBoard* t_gameBoard)
{
	m_gameBoard = t_gameBoard;
	// Make every board be aware of the game board.
	for (auto& grid : m_grids)
	{
		grid.setGameBoard(t_gameBoard);
	}
}
///////////////////////////////////////////////////////////////////////////////