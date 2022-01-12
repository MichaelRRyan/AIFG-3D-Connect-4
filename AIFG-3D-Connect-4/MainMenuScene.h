#pragma once
#include "Scene.h"
#include "Game.h"
#include <functional>
#include "Button.h"
#include "SfmlUIRenderer.h"
class MainMenuScene : public Scene
{
public:
	MainMenuScene(Game& t_game, std::function<void(Game&, int)> t_function, sf::Font m_font);
	virtual ~MainMenuScene();
	void update(float t_deltaTime) override; // Updates a scene.
	const bool& isEnded() const override; // return if the scene has ended.
	const GameState& getNewGameState() const override; // Gets the next scene after the current scene.
	void render() override; // Renders a scene.
	void processEvent(sf::Event t_event) override;
private:
	std::vector<Widget*> m_widgets;
	Renderer* m_renderer;
	Game& m_game;
	sf::Font m_font;
	GameState m_nextState = GameState::GameScene;
};