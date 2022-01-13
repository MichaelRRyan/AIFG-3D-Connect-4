#include "MainMenuScene.h"

///////////////////////////////////////////////////////////////////////////////
MainMenuScene::MainMenuScene(Game& t_game, sf::Font t_font) :
	Scene(GameState::PlayerSelectionScene),
	m_font(t_font),
	m_game(t_game)
{
	setupWidgets();
	m_renderer = new SfmlUIRenderer(t_font, m_widgets);
}

///////////////////////////////////////////////////////////////////////////////
MainMenuScene::~MainMenuScene()
{
	for (Widget * widget : m_widgets)
		delete widget;
}

///////////////////////////////////////////////////////////////////////////////
void MainMenuScene::update(float t_deltaTime)
{
	for (auto& widget : m_widgets)
		widget->update(t_deltaTime);
}

///////////////////////////////////////////////////////////////////////////////
void MainMenuScene::render()
{
	m_renderer->render();
}

///////////////////////////////////////////////////////////////////////////////
void MainMenuScene::processEvent(sf::Event t_event)
{
	for (auto& widget : m_widgets)
		widget->processEvents(t_event);
}

///////////////////////////////////////////////////////////////////////////////
void MainMenuScene::setupWidgets()
{
	m_widgets.push_back(new Button(sf::Vector2f(420.0f, 120.0f),
		sf::Vector2f(600.0f, 275.0f), "EASY", m_font,
		[&](Button& t_self) {
			Minimax::setMaxDepth(2);
			m_isEnded = true;
		}));

	m_widgets.push_back(new Button(sf::Vector2f(420.0f, 120.0f),
		sf::Vector2f(600.0f, 475.0f), "MEDIUM", m_font,
		[&](Button& t_self) {
			Minimax::setMaxDepth(3);
			m_isEnded = true;
		}));

	m_widgets.push_back(new Button(sf::Vector2f(420.0f, 120.0f),
		sf::Vector2f(600.0f, 675.0f), "HARD", m_font,
		[&](Button& t_self) {
			Minimax::setMaxDepth(4);
			m_isEnded = true;
		}));

	for (auto& widget : m_widgets)
		widget->centerText();
}

///////////////////////////////////////////////////////////////////////////////