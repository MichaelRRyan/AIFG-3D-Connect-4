#ifndef Sfml_Renderer_H
#define Sfml_Renderer_H

#include "Renderer.h"

class SfmlRenderer : public Renderer
{
public:
	SfmlRenderer();
	~SfmlRenderer();
	void render() override;
	void setGameBoard(GameBoard* t_gameBoard) override;
private:
	GameBoard* m_gameBoard;
};
#endif