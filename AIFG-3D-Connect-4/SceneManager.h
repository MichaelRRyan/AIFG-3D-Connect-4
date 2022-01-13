#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include "Scene.h"
#include <map>
#include <functional>
#include "PieceType.h"

class GamePlayScene;
class MainMenuScene;
class Game;

/// <summary>
/// Repersents a manager that will manage all the scenes in the game.
/// </summary>
class SceneManager
{
public:
	/// <summary>
	/// Default constructor for the SceneManager.
	/// </summary>
	SceneManager() = default;

	/// <summary>
	/// Overloaded constructor for the SceneManager.
	/// </summary>
	/// <param name="t_game">The game.</param>
	/// <param name="t_ButtonClickfunction">Function pointer to a button click event function.</param>
	/// <param name="t_gameOverfunction">Function pointer to a game over function.</param>
	/// <param name="m_font">The font.</param>
	SceneManager(Game& t_game, std::function<void(Game&, int)> t_buttonClickfunction, std::function<void(Game&, PieceType)> t_gameOverfunction, sf::Font t_font);

	/// <summary>
	/// Default destructor for the SceneManager.
	/// </summary>
	~SceneManager();

	/// <summary>
	/// Manages the screens for the game.
	/// </summary>
	void update(float t_deltaTime);

	/// <summary>
	/// Renders the current screen.
	/// </summary>
	void render();

	/// <summary>
	/// Handles Inputs for the current scene.
	/// </summary>
	void processEvent(sf::Event t_event);

	/// <summary>
	/// Sets the new game state.
	/// </summary>
	/// <param name="t_newGameState">New game state.</param>
	void setNewGameState(GameState t_newGameState);

	/// <summary>
	/// Gets the current scene.
	/// </summary>
	/// <returns>Current scene.</returns>
	inline const Scene* getCurrentScene() const { return m_currentScene; }

private:
	Scene* m_currentScene; // The current Scene.

	std::map<GameState, Scene*> m_sceneHaspMap; // map that has all the scenes with GameStates as keys.
	
};
#include "MainMenuScene.h"
#include "GamePlayScene.h"
#include "Game.h"
#endif
