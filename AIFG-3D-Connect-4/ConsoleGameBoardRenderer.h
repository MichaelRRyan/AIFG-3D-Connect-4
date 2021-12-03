#ifndef CONSOLE_GAME_BOARD_RENDERER_H
#define CONSOLE_GAME_BOARD_RENDERER_H

#include "Renderer.h"
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

	/// <summary>
	/// This will set a boolean that lets the renderer know when it can render the board.
	/// </summary>
	/// <param name="t_canRender"></param>
	void setCanRender(bool t_canRender) override;

	/// <summary>
	/// This will render a piece by the type that piece repersents (None = "- ")
	/// </summary>
	/// <param name="t_type"></param>
	void renderPiece(PieceType t_type);
private:
	// Lets the renderer know when to render.
	bool m_canRender;

	// This is the game board, the pieces within the game board is what will be drawn onto the console.
	GameBoard* m_gameBoard;
};
#endif
