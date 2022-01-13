#include "SceneManager.h"

SceneManager::SceneManager(Game& t_game, std::function<void(Game&, int)> t_buttonClickfunction, std::function<void(Game&, PieceType)> t_gameOverfunction, sf::Font t_font)
{
	m_sceneHaspMap.emplace(GameState::GameScene, new GamePlayScene(t_game, t_gameOverfunction));
	m_sceneHaspMap.emplace(GameState::MainMenuScene, new MainMenuScene(t_game, t_buttonClickfunction, t_font));
	m_sceneHaspMap.emplace(GameState::None, nullptr);

	m_currentScene = m_sceneHaspMap[GameState::MainMenuScene];
}

SceneManager::~SceneManager()
{
}

void SceneManager::update(float t_deltaTime)
{
	m_currentScene->update(t_deltaTime); // Updates the current screen of the game.
	if (m_currentScene->isEnded())
	{
		setNewGameState(m_currentScene->getNewGameState());
	}
}

void SceneManager::render()
{
	m_currentScene->render(); // Renders the current screen of the game.
}

void SceneManager::processEvent(sf::Event t_event)
{
	m_currentScene->processEvent(t_event);
}

void SceneManager::setNewGameState(GameState t_newGameState)
{
	m_currentScene = m_sceneHaspMap[t_newGameState];
}
