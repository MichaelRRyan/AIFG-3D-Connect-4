#include "SfmlUIRenderer.h"

SfmlUIRenderer::SfmlUIRenderer(sf::Font t_font, std::vector<Widget *> & t_widgets) :
	m_font(t_font),
	m_widgets(t_widgets)
{
}

SfmlUIRenderer::~SfmlUIRenderer()
{
}

void SfmlUIRenderer::render()
{
	Window::getWindow().clear(sf::Color::Black);
	for (auto& widget : m_widgets)
	{
		widget->draw(Window::getWindow());
	}
	Window::getWindow().display();
}

void SfmlUIRenderer::setGameBoard(GameBoard* t_gameBoard)
{
}
