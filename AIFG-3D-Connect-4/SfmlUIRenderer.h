#pragma once
#include "Renderer.h"
#include "Button.h"
class SfmlUIRenderer : public Renderer
{
public:
	SfmlUIRenderer();
	~SfmlUIRenderer();

	void render() override;
	void setGameBoard(GameBoard* t_gameBoard) override;
private:
	std::vector<Widget*> m_widget;
};