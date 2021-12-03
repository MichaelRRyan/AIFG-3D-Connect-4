#ifndef CONSOLE_GAME_BOARD_RENDERER_H
#define CONSOLE_GAME_BOARD_RENDERER_H

#include "Renderer.h"
class ConsoleGameBoardRenderer : public Renderer
{
public:
	ConsoleGameBoardRenderer();
	~ConsoleGameBoardRenderer();
	void render() override;
	void setGameBoard(GameBoard* t_gameBoard) override;
private:
	bool m_renderBoard;
	GameBoard* m_gameBoard;
};
#endif
