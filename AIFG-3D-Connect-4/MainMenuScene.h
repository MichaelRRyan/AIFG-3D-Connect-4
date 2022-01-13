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
	/// <param name="t_function">Function pointer to the button click function.</param>
	/// <param name="m_font">The font.</param>
	MainMenuScene(Game& t_game, std::function<void(Game&, int)> t_function, sf::Font t_font);

	/// <summary>
	/// Default destructor for the MainMenuScene.
	/// </summary>
	virtual ~MainMenuScene();

	/// <summary>
	/// Updates the MainMenuScene.
	/// </summary>
	void update(float t_deltaTime) override;

	/// <summary>
	/// Gets if the MainMenuScene has ended.
	/// </summary>
	/// <returns>A boolean to see if the MainMenuScene has ended.</returns>
	const bool& isEnded() const override;

	/// <summary>
	/// Gets the new game state after the MainMenuScene.
	/// </summary>
	/// <returns>A new game state.</returns>
	const GameState& getNewGameState() const override;

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
	std::vector<Widget*> m_widgets;
	Renderer* m_renderer;
	Game& m_game;
	sf::Font m_font;
	GameState m_nextState = GameState::GameScene;
};

#endif