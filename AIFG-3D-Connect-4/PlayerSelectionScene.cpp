#include "PlayerSelectionScene.h"

///////////////////////////////////////////////////////////////////////////////
PlayerSelectionScene::PlayerSelectionScene(sf::Font t_font) :
	Scene{ GameState::GameScene },
	m_font{ t_font },
	m_player1Type{ PlayerType::Human },
	m_player2Type{ PlayerType::AI }
{
	setupWidgets();
	m_renderer = new SfmlUIRenderer(t_font, m_widgets);
}

///////////////////////////////////////////////////////////////////////////////
void PlayerSelectionScene::update(float t_deltaTime)
{
	for (auto widget : m_widgets)
		widget->update(t_deltaTime);
}

///////////////////////////////////////////////////////////////////////////////
void PlayerSelectionScene::render()
{
	m_renderer->render();
}

///////////////////////////////////////////////////////////////////////////////
void PlayerSelectionScene::processEvent(sf::Event t_event)
{
	for (auto widget : m_widgets)
		widget->processEvents(t_event);
}

///////////////////////////////////////////////////////////////////////////////
void PlayerSelectionScene::setupWidgets()
{
	// Sets up player 1's button.
	m_widgets.push_back(new Button(sf::Vector2f(420.0f, 120.0f),
		sf::Vector2f(180.0f, 275.0f), "Human", m_font,
		[&](Button & t_self) {
			if (m_player1Type == PlayerType::Human)
			{
				m_player1Type = PlayerType::AI;
				t_self.setString("AI");
			}
			else
			{
				m_player1Type = PlayerType::Human;
				t_self.setString("Human");
			}

			t_self.centerText();
		}));
	
	// Sets up player 2's button.
	m_widgets.push_back(new Button(sf::Vector2f(420.0f, 120.0f),
		sf::Vector2f(1020.0f, 275.0f), "AI", m_font,
		[&](Button& t_self) {
			if (m_player2Type == PlayerType::Human)
			{
				m_player2Type = PlayerType::AI;
				t_self.setString("AI");
			}
			else
			{
				m_player2Type = PlayerType::Human;
				t_self.setString("Human");
			}

			t_self.centerText();
		}));

	// Sets up the Play button.
	m_widgets.push_back(new Button(sf::Vector2f(420.0f, 120.0f),
		sf::Vector2f(600.0f, 700.0f), "Play", m_font,
		[&](Button& t_self) { m_isEnded = true; }));

	for (auto& widget : m_widgets)
		widget->centerText();
}

///////////////////////////////////////////////////////////////////////////////