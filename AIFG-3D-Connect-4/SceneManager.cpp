#include "SceneManager.h"

SceneManager::SceneManager(Game& t_game, std::function<void(Game&, int)> t_function, sf::Font m_font)
{
	m_mainMenuScene = new MainMenuScene(t_game, t_function, m_font);
	m_currentScene = m_mainMenuScene;
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
