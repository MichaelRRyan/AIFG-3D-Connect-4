#include "SceneManager.h"

SceneManager::SceneManager(Game& t_game, std::function<void(Game&, PieceType)> t_gameOverfunction, sf::Font t_font)
{
	m_gamePlayScene = new GamePlayScene(t_game, t_gameOverfunction);
	m_sceneHaspMap.emplace(GameState::GameScene, m_gamePlayScene);
	m_sceneHaspMap.emplace(GameState::MainMenuScene, new MainMenuScene(t_game, t_font));
	m_sceneHaspMap.emplace(GameState::None, nullptr);

	m_sceneHaspMap.emplace(GameState::PlayerSelectionScene, new PlayerSelectionScene(t_font,
		[&](PlayerType t_p1, PlayerType t_p2)
		{
			m_gamePlayScene->setPlayerTypes(t_p1, t_p2);
		}));

	m_currentScene = m_sceneHaspMap[GameState::MainMenuScene];
}

SceneManager::~SceneManager()
{
	for (std::pair<const GameState, Scene *> & pair : m_sceneHaspMap)
		if (pair.second) delete pair.second;
}

void SceneManager::update(float t_deltaTime)
{
	if (m_currentScene)
	{
		m_currentScene->update(t_deltaTime); // Updates the current screen of the game.
		if (m_currentScene->isEnded())
		{
			setNewGameState(m_currentScene->getNewGameState());
		}
	}
}

void SceneManager::render()
{
	if (m_currentScene)
		m_currentScene->render(); // Renders the current screen of the game.
}

void SceneManager::processEvent(sf::Event t_event)
{
	if (m_currentScene)
		m_currentScene->processEvent(t_event);
}

void SceneManager::setNewGameState(GameState t_newGameState)
{
	m_currentScene = m_sceneHaspMap[t_newGameState];
}
