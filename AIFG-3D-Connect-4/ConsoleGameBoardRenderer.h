#ifndef CONSOLE_GAME_BOARD_RENDERER_H
#define CONSOLE_GAME_BOARD_RENDERER_H

#include <iostream>
#include "Renderer.h"

/// <summary>
/// Renders the game board and all its pieces to the console.
/// </summary>
class ConsoleGameBoardRenderer : public Renderer
{
public:
	/// <summary>
	/// This constructs the console game board renderer.
	/// </summary>
	ConsoleGameBoardRenderer();

	/// <summary>
	/// This destructs the console game board renderer.
	/// </summary>
	~ConsoleGameBoardRenderer();

	/// <summary>
	/// This will render the game board via the console.
	/// </summary>
	void render() override;

	/// <summary>
	/// This will set the game board so that the console knows what pieces to render in the console.
	/// </summary>
	/// <param name="t_gameBoard"></param>
	void setGameBoard(GameBoard* t_gameBoard) override;

private:

	// This is the game board, the pieces within the game board is what will be drawn onto the console.
	GameBoard* m_gameBoard;
};
#endif
