#ifndef MAIN_MENU_SCENE_H
#define MAIN_MENU_SCENE_H

#include "Scene.h"
#include "Game.h"
#include <functional>
#include "Button.h"
#include "SfmlUIRenderer.h"

/// <summary>
/// Repersents the MainMenuScene in the game.
/// </summary>
class MainMenuScene : public Scene
{
public:
	/// <summary>
	/// Constructor for the MainMenuScene.
	/// </summary>
	/// <param name="t_game">The game.</param>
	/// <param name="m_font">The font.</param>
	MainMenuScene(Game& t_game, sf::Font t_font);

	/// <summary>
	/// Default destructor for the MainMenuScene.
	/// </summary>
	virtual ~MainMenuScene();

	/// <summary>
	/// Updates the MainMenuScene.
	/// </summary>
	void update(float t_deltaTime) override;

	/// <summary>
	/// Renders the MainMenuScene.
	/// </summary>
	void render() override;

	/// <summary>
	/// Handles the events for the MainMenuScene.
	/// </summary>
	/// <param name="t_event">New event.</param>
	void processEvent(sf::Event t_event) override;

private:

	/// <summary>
	/// Creates and sets up all the necessary widgets for the scene.
	/// </summary>
	void setupWidgets();

	std::vector<Widget*> m_widgets;
	Renderer* m_renderer;
	Game& m_game;
	sf::Font m_font;
};

#endif