#ifndef CONSOLE_INPUT_H
#define CONSOLE_INPUT_H
#include "Input.h"
#include <iostream>
#include "GameBoard.h"
class ConsoleInput : public Input
{
public:
	ConsoleInput(GameBoard& t_board);
	virtual ~ConsoleInput() = default;
	Coordinate getCoordinate() override;
private:
	bool validateIfInputWithinGameBoard(Coordinate t_pos);
	GameBoard& m_board;
};
#endif