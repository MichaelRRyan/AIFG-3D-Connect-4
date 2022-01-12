#include "MainMenuScene.h"

MainMenuScene::MainMenuScene(Game& t_game, std::function<void(Game&, int)> t_function, sf::Font t_font) :
	Scene(false),
	m_font(t_font),
	m_game(t_game)
{
	m_widgets.push_back(new Button(m_game, sf::Vector2f(120.0f, 120), t_function, sf::Vector2f(100.0f, 100.0f), "EASY", m_font, 2));
	m_widgets.push_back(new Button(m_game, sf::Vector2f(120, 120), t_function, sf::Vector2f(100.0f, 200.0f), "MEDIUM", m_font, 3));
	m_widgets.push_back(new Button(m_game, sf::Vector2f(120, 120), t_function, sf::Vector2f(100.0f, 300.0f), "HARD", m_font, 4));

	for (auto& widget : m_widgets)
	{
		widget->centerText();
	}

	m_renderer = new SfmlUIRenderer(t_game, t_function, t_font, m_widgets);
}

MainMenuScene::~MainMenuScene()
{
}

void MainMenuScene::update(float t_deltaTime)
{
	for (auto& widget : m_widgets)
	{
		widget->update(t_deltaTime);
	}
}

const bool& MainMenuScene::isEnded() const
{
	return m_isEnded;
}

const GameState& MainMenuScene::getNewGameState() const
{
	return GameState::GameScene;
}

void MainMenuScene::render()
{
	m_renderer->render();
}

void MainMenuScene::processEvent(sf::Event t_event)
{
	for (auto& widget : m_widgets)
	{
		widget->processEvents(t_event);
	}
}