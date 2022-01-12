#pragma once
#include "Renderer.h"
#include "Button.h"
class SfmlUIRenderer : public Renderer
{
public:
	SfmlUIRenderer(Game& t_game, std::function<void(Game&, int)> t_function, sf::Font t_font, std::vector<Widget*>& t_widgets);
	virtual ~SfmlUIRenderer();

	void render() override;
	void setGameBoard(GameBoard* t_gameBoard) override;
private:
	std::vector<Widget*> m_widgets;
	sf::Font m_font;
	Game& m_game;
};