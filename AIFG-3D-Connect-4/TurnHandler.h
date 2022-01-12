#ifndef TURN_HANDLER_H
#define TURN_HANDLER_H

#include "Input.h"
#include "Move.h"

/// <summary>
/// This repersents a turn handler, which will handle the AI's and player's turns 
/// and also the swithcing of turns.
/// </summary>
class TurnHandler
{
public:
	/// <summary>
	/// This is the default constructor of the turn handler,
	/// this will set the two player objects to nullptr and will also
	/// set the position to all 0's
	/// </summary>
	TurnHandler();

	/// <summary>
	/// This is the default destrutor, this will delete
	/// both of the players when they go out of scope.
	/// </summary>
	~TurnHandler();

	/// <summary>
	/// This will let the user set which type of Input behaviour they want for the first Player.
	/// </summary>
	/// <param name="t_player1">Type of Input Behaviour, either a user or AI.</param>
	void setPlayer1(Input* t_player1);

	/// <summary>
	/// This will let the user set which type of Input behaviour they want for the second Player.
	/// </summary>
	/// <param name="t_player1">Type of Input Behaviour, either a user or AI.</param>
	void setPlayer2(Input* t_player2);

	/// <summary>
	/// This will change the turns to Player 1 -> Player 2 and vice versa.
	/// </summary>
	void changeTurn();

	/// <summary>
	/// Returns the position and type of piece for the gamebaord.
	/// </summary>
	/// <returns>Returns a Move object.</returns>
	Move getMove();

	/// <summary>
	/// This will return who's active turn it is.
	/// </summary>
	/// <returns>returns who the active player is.</returns>
	inline bool getPlayersTurn() { return m_playerOnesTurn; }
private:
	Input* m_player1; // Player 1 can be a user or AI.
	Input* m_player2; // Player 2 can be a user or AI.
	Move m_move; // contains the coordinate and the type of piece for the game board.
	bool m_playerOnesTurn; // handles who's turns is the active one.
};
#endif
