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
	/// <summary>
	/// Default constructor for the Button.
	/// </summary>
	Button() = default;

	/// <summary>
	/// Overloaded constructor for the Button.
	/// </summary>
	/// <param name="t_game">The game</param>
	/// <param name="t_size">size of button</param>
	/// <param name="t_function">Game over function</param>
	/// <param name="t_pos">position of button</param>
	/// <param name="t_buttonText">text of button</param>
	/// <param name="t_Font">font used with button</param>
	/// <param name="t_depthLevel">The depth level the AI uses for minimax.</param>
	Button(Game& t_game, sf::Vector2f t_size, std::function<void(Game&, int)> t_function, sf::Vector2f t_pos, std::string t_buttonText, sf::Font& t_Font, int t_depthLevel);

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
private:
	/// <summary>
	/// Handles on Button click events.
	/// </summary>
	void onButtonPress();

	std::function<void(Game&, int)> m_function; // On game over function.
	sf::RectangleShape m_body;
	sf::Text m_text;
	sf::Font m_font;
	Game* m_game;
	int m_depthLevel; // The depth level the AI will use.
};

#include "Game.h"
#endif