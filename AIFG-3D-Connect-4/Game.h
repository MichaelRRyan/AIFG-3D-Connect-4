#ifndef GAME_H
#define GAME_H

/// <summary>
/// @author Michael R Ryan & Mantas Zalnierius
/// @date 26/11/2021
/// </summary>

#include <SFML/Graphics.hpp>
#include "GameBoard.h"
#include "ConsoleGameBoardRenderer.h"
#include "FourTechRulesHandler.h"
#include "SfmlGameBoardRenderer.h"
#include "Window.h"
#include "Grid.h"
#include "SfmlInput.h"
#include "ConsoleInput.h"
#include "FourTechAI.h"

class Button;
class Widget;

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

	void setDifficulty(int t_difficulty);

	//sf::RenderWindow m_window; // main SFML window
	Renderer * m_renderer;
	bool m_exitGame; // control exiting game

	GameBoard m_gameBoard;
	FourTechRulesHandler m_rulesHandler;

	// Repersents the grids within the game.
	std::vector<Grid> m_grids;

	std::vector<Widget*> m_widgets;

	sf::Font m_font;

};

#include "Button.h"
#include "Widget.h"

#endif // !GAME_H

