#pragma once
#include <SFML/Graphics.hpp>
class Widget
{
public:
	Widget() = default;
	virtual ~Widget() = default;
	virtual void update(float t_deltaTime) = 0;
	virtual void draw(sf::RenderWindow& t_window) const = 0;
	virtual void centerText() = 0;
	virtual void processEvents(sf::Event t_event) = 0;
	virtual void setPosition(sf::Vector2f t_pos) = 0;
};
