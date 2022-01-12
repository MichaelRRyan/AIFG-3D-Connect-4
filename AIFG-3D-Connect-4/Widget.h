#pragma once
#include <SFML/Graphics.hpp>
class Widget
{
public:
	Widget() = default;
	virtual ~Widget() = default;
	virtual void update(sf::Time t_deltaTime) = 0;
	virtual void draw(sf::RenderWindow& t_window) const = 0;
	virtual void setPosition(sf::Vector2f t_newPos) = 0;
	virtual const sf::Vector2f getPosition() const = 0;
	virtual sf::Vector2f getSize() const = 0;
	virtual inline bool getFocused() = 0;
	virtual inline void setFocus(bool t_isFocused) = 0;
	virtual void setTextColour(sf::Color t_color) = 0;
	virtual void setWidgetColor(sf::Color t_color) = 0;
	virtual void centerText() = 0;
	virtual void processEvents(sf::Event t_event) = 0;
};
