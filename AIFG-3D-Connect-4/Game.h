#ifndef GAME_H
#define GAME_H

/// <summary>
/// @author Michael R Ryan & Mantas Zalnierius
/// @date 26/11/2021
/// </summary>

#include <SFML/Graphics.hpp>

class Game
{
public:

	/// <summary>
	/// default constructor
	/// setup the window properties
	/// load and setup the text 
	/// load and setup the image
	/// </summary>
	Game();

	/// <summary>
	/// default destructor we didn't dynamically allocate anything
	/// so we don't need to free it, but mthod needs to be here
	/// </summary>
	~Game();

	/// <summary>
	/// main game loop
	/// update 60 times per second,
	/// process update as often as possible and at least 60 times per second
	/// draw as often as possible but only updates are on time
	/// if updates run slow then don't render frames
	/// </summary>
	void run();

private:

	/// <summary>
	/// handle user and system events/ input
	/// get key presses/ mouse moves etc. from OS
	/// and user :: Don't do game update here
	/// </summary>
	void processEvents();

	/// <summary>
	/// deal with key presses from the user
	/// </summary>
	/// <param name="t_event">key press event</param>
	void processKeys(sf::Event t_event);

	/// <summary>
	/// Update the game world
	/// </summary>
	/// <param name="t_delta">seconds per frame</param>
	void update(float t_delta);

	/// <summary>
	/// draw the frame and then switch buffers
	/// </summary>
	void render();
	
	/// <summary>
	/// load the font and setup the text message for screen
	/// </summary>
	void setupFontAndText();

	/// <summary>
	/// load the texture and setup the sprite for the logo
	/// </summary>
	void setupSprite();

	/// <summary>
	/// Closes the window and ends the game.
	/// </summary>
	void exit();

	const unsigned m_WINDOW_WIDTH;
	const unsigned m_WINDOW_HEIGHT;

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo
	bool m_exitGame; // control exiting game

};

#endif // !GAME_H

