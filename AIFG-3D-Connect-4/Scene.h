#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.hpp>
#include "GameStates.h"

/// <summary>
/// Repersents a Scene Abstraction.
/// </summary>
class Scene
{
public:
	/// <summary>
	/// Constructs base class with a boolean that will let the Scene know if has ended.
	/// </summary>
	/// <param name="t_isEnded">A boolean to tell the Scene if it has ended.</param>
	Scene(bool t_isEnded);

	/// <summary>
	/// Default destructor for the Scene. 
	/// </summary>
	virtual ~Scene() = default;

	/// <summary>
	/// Updates a Scene.
	/// </summary>
	virtual void update(float t_deltaTime) = 0;

	/// <summary>
	/// Gets a boolean to check if the Scene has ended.
	/// </summary>
	/// <returns>Boolean to check if a Scene has ended.</returns>
	virtual const bool& isEnded() const = 0;

	/// <summary>
	/// Gets the next Game State after a Scene.
	/// </summary>
	/// <returns></returns>
	virtual const GameState& getNewGameState() const = 0;

	/// <summary>
	/// Renders a Scene.
	/// </summary>
	virtual void render() = 0;

	/// <summary>
	/// Handles the Process Events for the Scene.
	/// </summary>
	/// <param name="t_event">New event.</param>
	virtual void processEvent(sf::Event t_event) = 0;
protected:
	bool m_isEnded;
};
#endif
