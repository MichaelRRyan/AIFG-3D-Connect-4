#ifndef RENDERER_H
#define RENDERER_H

#include "GameBoard.h"
/// <summary>
/// Repersents an Abstract renderer, so that we can have both a console/SFML application of 4TEC
/// </summary>
class Renderer
{
public:
	Renderer() = default;
	~Renderer() = default;

	/// <summary>
	/// This is an abstract render function, that will let the user to render anything from a derived class.
	/// </summary>
	virtual void render() = 0;

	/// <summary>
	/// This sets the board game, so that the renderer can display the board.
	/// </summary>
	/// <param name="t_gameBoard"></param>
	virtual void setGameBoard(GameBoard* t_gameBoard) = 0;

	/// <summary>
	/// This sets a boolean, so that the application knows when it can render the board again (i.e after a process event)
	/// </summary>
	/// <param name="t_canRenderer"></param>
	virtual void setCanRender(bool t_canRenderer) = 0;
};
#endif