#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.hpp>
#include "GameStates.h"

class Scene
{
public:
	// Virtual Functions for the Scene Abstraction.
	Scene(bool t_isEnded);
	virtual ~Scene() = default;

	virtual void update(float t_deltaTime) = 0; // Updates a scene.
	virtual const bool& isEnded() const = 0; // return if the scene has ended.
	virtual const GameState& getNewGameState() const = 0; // Gets the next scene after the current scene.
	virtual void render() = 0; // Renders a scene.
	virtual void processEvent(sf::Event t_event) = 0;
protected:
	bool m_isEnded;
};
#endif
