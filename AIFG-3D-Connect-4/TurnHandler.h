#ifndef TURN_HANDLER_H
#define TURN_HANDLER_H
#include "ConsoleInput.h"
#include "FourTechAI.h"
class TurnHandler
{
public:
	TurnHandler();
	~TurnHandler();
	void setPlayer1(Input* t_player1);
	void setPlayer2(Input* t_player2);
	Coordinate getCoordinate();
	void changeTurn();
	inline bool getPlayersTurn() { return m_playersTurn; }
private:
	Input* m_player1;
	Input* m_player2;
	Coordinate m_coordinate;
	bool m_playersTurn;
};
#endif
