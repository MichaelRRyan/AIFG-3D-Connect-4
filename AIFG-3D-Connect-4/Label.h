#ifndef LABEL_H
#define LABEL_H

#include "Widget.h"

/// <summary>
/// A wrapper class for the SFML text to allow it to be added to treated as a
///		widget.
/// </summary>
class Label : public Widget
{
public:

	/// <summary>
	/// Initialises the label and its inner text object.
	/// </summary>
	/// <param name="t_font">The font to use for the text.</param>
	/// <param name="t_string">The initial string to use.</param>
	/// <param name="t_position">The position of the label.</param>
	Label(sf::Font const & t_font, std::string t_string = "New Label", sf::Vector2f t_position = sf::Vector2f());

	/// <summary>
	/// Does nothing. Present just to satisfy base class Widget.
	/// </summary>
	/// <param name="t_deltaTime">Time since last frame.</param>
	virtual void update(float t_deltaTime) override;

	/// <summary>
	/// Draws the label's text to a render window.
	/// </summary>
	/// <param name="t_window">The window to draw to.</param>
	virtual void draw(sf::RenderWindow& t_window) const override;

	/// <summary>
	/// Centres the text around its position.
	/// </summary>
	virtual void centerText() override;

	/// <summary>
	/// Does nothing. Present just to satisfy base class Widget.
	/// </summary>
	/// <param name="t_event">A user event.</param>
	virtual void processEvents(sf::Event t_event) override;

	/// <summary>
	/// Sets the position of the label.
	/// </summary>
	/// <param name="t_pos">The new position.</param>
	virtual void setPosition(sf::Vector2f t_pos) override;

	/// <summary>
	/// Sets the string of the label's text.
	/// </summary>
	/// <param name="t_string">The new string.</param>
	void setString(std::string t_string);

private:

	sf::Text m_text;

};

#endif // !LABEL_H
