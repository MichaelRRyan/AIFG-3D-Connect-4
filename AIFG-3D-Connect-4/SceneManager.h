#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include "Scene.h"
#include <map>

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	/// <summary>
	/// Manages the screens for the game.
	/// </summary>
	void update(float t_deltaTime);

	/// <summary>
	/// Renders the current screen.
	/// </summary>
	void render(sf::RenderWindow& t_window);

	/// <summary>
	/// Handles Inputs for the current scene.
	/// </summary>
	void processEvent(sf::Event t_event);

private:
	void setNewGameState(GameState t_newGameState);
	Scene* m_currentScene; // The current Scene.
	std::map<GameState, Scene*> m_sceneHaspMap;
};
#endif
