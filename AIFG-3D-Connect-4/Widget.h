#ifndef WIDGET_H
#define WIDGET_H

#include <SFML/Graphics.hpp>

/// <summary>
/// A Widget abstraction for UI.
/// </summary>
class Widget
{
public:
	/// <summary>
	/// Default constructor for the Widget.
	/// </summary>
	Widget() = default;

	/// <summary>
	/// Default desturctor.
	/// </summary>
	virtual ~Widget() = default;

	/// <summary>
	/// Updates a Widget.
	/// </summary>
	/// <param name="t_deltaTime">time since last update.</param>
	virtual void update(float t_deltaTime) = 0;

	/// <summary>
	/// Renders the Widget.
	/// </summary>
	/// <param name="t_window">The SFML window.</param>
	virtual void draw(sf::RenderWindow& t_window) const = 0;

	/// <summary>
	/// Centers text to the center of a Widget.
	/// </summary>
	virtual void centerText() = 0;

	/// <summary>
	/// Processes events for a Widget.
	/// </summary>
	/// <param name="t_event">New event.</param>
	virtual void processEvents(sf::Event t_event) = 0;

	/// <summary>
	/// Sets the position of a Widget.
	/// </summary>
	/// <param name="t_pos">New position.</param>
	virtual void setPosition(sf::Vector2f t_pos) = 0;
};

#endif
