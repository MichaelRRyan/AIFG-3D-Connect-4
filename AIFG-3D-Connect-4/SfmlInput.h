#pragma once
#include "Input.h"
#include "GameBoard.h"
#include <vector>
#include "Grid.h"
class SfmlInput : public Input
{
public:
	SfmlInput(GameBoard& t_gameBoard, std::vector<Grid>& t_grids);
	virtual ~SfmlInput() = default;
	Coordinate getCoordinate() override;
private:
	void processKeys(sf::Event t_newEvent);
	GameBoard& m_gameBoard;
	std::vector<Grid>& m_grids;
};
