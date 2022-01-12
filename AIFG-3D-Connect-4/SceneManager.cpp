#include "SceneManager.h"

SceneManager::SceneManager()
{
	m_currentScene = nullptr;
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

void SceneManager::render(sf::RenderWindow& t_window)
{
}

void SceneManager::processEvent(sf::Event t_event)
{
}

void SceneManager::setNewGameState(GameState t_newGameState)
{
	m_currentScene = m_sceneHaspMap[t_newGameState];
}
