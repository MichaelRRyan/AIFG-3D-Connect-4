#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "GameBoard.h"
#include "ConsoleGameBoardRenderer.h"
#include "FourTechRulesHandler.h"
#include "SfmlGameBoardRenderer.h"
#include "Window.h"
#include "SfmlInput.h"
#include "ConsoleInput.h"
#include "FourTechAI.h"
#include "SceneManager.h"

/// <summary>
/// Handles initialisation, the game loop, and frame rate. This class contains 
///		all others.
/// @author Michael R Ryan & Mantas Zalnierius
/// @date 26/11/2021
/// </summary>
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
	/// Closes the window and ends the game.
	/// </summary>
	void exit();

	/// <summary>
	/// Called when the game is over.
	/// </summary>
	/// <param name="t_winner">the winning piece colour.</param>
	void onGameOver(PieceType t_winner);

	bool m_freezeUntilInput;
	bool m_exitGame; // control exiting game

	sf::Font m_font;

	SceneManager * m_sceneManager;
};
#endif // !GAME_H

