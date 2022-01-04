#ifndef INPUT_H
#define INPUT_H
#include "Coordinate.h"
class Input
{
public:
	Input() = default;
	~Input() = default;
	virtual Coordinate getCoordinate() = 0;
};

#endif
