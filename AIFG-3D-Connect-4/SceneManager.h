#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include "Scene.h"
#include <map>
#include <functional>

class MainMenuScene;
class Game;

class SceneManager
{
public:
	SceneManager() = default;
	SceneManager(Game& t_game, std::function<void(Game&, int)> t_function, sf::Font m_font);
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

private:
	void setNewGameState(GameState t_newGameState);
	Scene* m_currentScene; // The current Scene.
	MainMenuScene* m_mainMenuScene;
	std::map<GameState, Scene*> m_sceneHaspMap;
};

#include "MainMenuScene.h"
#include "Game.h"
#endif
