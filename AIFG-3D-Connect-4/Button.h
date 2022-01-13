#ifndef BUTTON_H
#define BUTTON_H

#include "Widget.h"
#include <functional>

class Game;

/// <summary>
/// Repersents A UI button you can click in SFML.
/// </summary>
class Button : public Widget
{
public:

	using Callback = std::function<void(Button & t_self)>;

	/// <summary>
	/// Default constructor for the Button.
	/// </summary>
	Button() = default;

	/// <summary>
	/// Overloaded constructor for the Button.
	/// </summary>
	/// <param name="t_size">size of button</param>
	/// <param name="t_pos">position of button</param>
	/// <param name="t_buttonText">text of button</param>
	/// <param name="t_Font">font used with button</param>
	/// <param name="t_function">The function callback</param>
	Button(sf::Vector2f t_size, sf::Vector2f t_pos, std::string t_buttonText,
		   sf::Font& t_Font, Callback t_function = nullptr);

	/// <summary>
	/// Default constructor for the Button.
	/// </summary>
	~Button();

	/// <summary>
	/// Update for the Button
	/// </summary>
	/// <param name="t_deltaTime">Time since last update.</param>
	void update(float t_deltaTime) override;

	/// <summary>
	/// Renders the Button to the screen.
	/// </summary>
	/// <param name="t_window">Reference to the SFML window.</param>
	void draw(sf::RenderWindow& t_window) const override;

	/// <summary>
	/// Centers text to the Buttons center.
	/// </summary>
	void centerText() override;

	/// <summary>
	/// Handles events for the Buttons.
	/// </summary>
	/// <param name="t_event">new event.</param>
	void processEvents(sf::Event t_event) override;

	/// <summary>
	/// Set the position of the Button.
	/// </summary>
	/// <param name="t_pos">New position.</param>
	void setPosition(sf::Vector2f t_pos) override;

	/// <summary>
	/// Sets the function called when the button is pressed.
	/// </summary>
	/// <param name="t_callback">The function to call on button press.</param>
	void setCallback(Callback t_callback);

	/// <summary>
	/// Sets the string the button displays.
	/// </summary>
	/// <param name="t_string">The new string.</param>
	void setString(std::string const & t_string);

private:

	/// <summary>
	/// Handles on Button click events.
	/// </summary>
	void onButtonPress();

	/// On press callback function.
	Callback m_callback;

	sf::RectangleShape m_body;
	sf::Text m_text;
	sf::Font m_font;

};

#include "Game.h"
#endif