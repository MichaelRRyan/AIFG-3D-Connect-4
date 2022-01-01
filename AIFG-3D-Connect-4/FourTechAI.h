#ifndef FOUR_TECH_AI_H
#define FOUR_TECH_AI_H

#include <vector>

#include "Coordinate.h"
#include "GameBoard.h"

class FourTechAI
{
public:

	FourTechAI(GameBoard & t_board);

	Coordinate getMove();

private:

	GameBoard & m_board;

};

#endif // !FOUR_TECH_AI_H