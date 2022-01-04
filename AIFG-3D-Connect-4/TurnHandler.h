#ifndef TURN_HANDLER_H
#define TURN_HANDLER_H
#include "ConsoleInput.h"
#include "FourTechAI.h"
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
	/// This will get the coordinate of either player 1 player 2, where they want to place
	/// thier piece onto the game board.
	/// </summary>
	/// <returns>returns the position either player 1 or 2 want to place in the game board.</returns>
	Coordinate getCoordinate();

	/// <summary>
	/// This will change the turns to Player 1 -> Player 2 and vice versa.
	/// </summary>
	void changeTurn();

	/// <summary>
	/// This will return who's active turn it is.
	/// </summary>
	/// <returns>returns who the active player is.</returns>
	inline bool getPlayersTurn() { return m_playersTurn; }
private:
	Input* m_player1; // Player 1 can be a user or AI.
	Input* m_player2; // Player 2 can be a user or AI.
	Coordinate m_coordinate; // The position the players want to place thier piece.
	bool m_playersTurn; // handles who's turns is the active one.
};
#endif
