#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include "Scene.h"
#include <map>
#include <functional>
#include "PieceType.h"

class GamePlayScene;
class MainMenuScene;
class Game;

class SceneManager
{
public:
	SceneManager() = default;
	SceneManager(Game& t_game, std::function<void(Game&, int)> t_ButtonClickfunction, std::function<void(Game&, PieceType)> t_gameOverfunction, sf::Font m_font);
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

	void setNewGameState(GameState t_newGameState);

	inline const Scene* getCurrentScene() const { return m_currentScene; }

private:
	Scene* m_currentScene; // The current Scene.
	GamePlayScene* m_gamePlayScene;
	MainMenuScene* m_mainMenuScene;

	std::map<GameState, Scene*> m_sceneHaspMap;
	
};

#include "MainMenuScene.h"
#include "GamePlayScene.h"
#include "Game.h"
#endif
