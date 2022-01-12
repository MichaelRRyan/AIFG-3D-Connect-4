#pragma once

#include "Scene.h"
#include "Grid.h"
#include "SfmlGameBoardRenderer.h"
#include "FourTechRulesHandler.h"
#include "SfmlInput.h"
#include "FourTechAI.h"

class Game;

class GamePlayScene : public Scene
{
public:
	GamePlayScene(Game& t_game, std::function<void(Game&, PieceType)> t_function);
	virtual ~GamePlayScene();
	void update(float t_deltaTime) override; // Updates a scene.
	const bool& isEnded() const override; // return if the scene has ended.
	const GameState& getNewGameState() const override; // Gets the next scene after the current scene.
	void render() override; // Renders a scene.
	void processEvent(sf::Event t_event) override;
private:
	std::vector<Grid> m_grids;
	Renderer* m_renderer;
	GameBoard m_gameBoard;
	FourTechRulesHandler m_rulesHandler;
	GameState m_nextState = GameState::None;
};
#include "Game.h"
