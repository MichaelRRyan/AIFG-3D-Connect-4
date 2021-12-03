#ifndef RENDERER_H
#define RENDERER_H

class GameBoard;

class Renderer
{
public:
	Renderer() = default;
	~Renderer() = default;
	virtual void render() = 0;
	virtual void setGameBoard(GameBoard* t_gameBoard) = 0;
};
#endif
#include "GameBoard.h"