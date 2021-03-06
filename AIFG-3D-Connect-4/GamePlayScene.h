#ifndef GAME_PLAY_SCENE_H
#define GAME_PLAY_SCENE_H

#include "Scene.h"
#include "Grid.h"
#include "SfmlGameBoardRenderer.h"
#include "FourTechRulesHandler.h"
#include "SfmlInput.h"
#include "FourTechAI.h"
#include "PlayerType.h"

class Game;

/// <summary>
/// repersents the game play scene in the game.
/// </summary>
class GamePlayScene : public Scene
{
public:

	/// <summary>
	/// Constructor for the GamePlayScene.
	/// </summary>
	/// <param name="t_game">The game</param>
	/// <param name="t_function">Function pointer to the on game over function.</param>
	GamePlayScene(Game& t_game, std::function<void(Game&, PieceType)> t_function);

	/// <summary>
	/// Default destructor for the GamePlayScene.
	/// </summary>
	virtual ~GamePlayScene();

	/// <summary>
	/// Updates the GamePlayScene.
	/// </summary>
	void update(float t_deltaTime) override;

	/// <summary>
	/// Renders the GamePlayScene.
	/// </summary>
	void render() override;

	/// <summary>
	/// Handles process Events for the GamePlayScene.
	/// </summary>
	/// <param name="t_event">New event.</param>
	void processEvent(sf::Event t_event) override;

	/// <summary>
	/// Sets the input types of the players to either Human or AI.
	/// </summary>
	/// <param name="t_p1">Player 1 type.</param>
	/// <param name="t_p2">Player 2 type.</param>
	void setPlayerTypes(PlayerType t_p1, PlayerType t_p2);

private:

	std::vector<Grid> m_grids;
	Renderer* m_renderer;
	GameBoard m_gameBoard;
	TurnHandler m_turnHandler;
	FourTechRulesHandler m_rulesHandler;
};
#include "Game.h"
#endif
