#ifndef PLAYER_SELECTION_SCENE_H
#define PLAYER_SELECTION_SCENE_H

#include "Scene.h"
#include "Button.h"
#include "Label.h"
#include "PlayerType.h"

/// <summary>
/// A screen that allows the user to select what types of players will be
///		playing. The options are Human or AI for both player 1 and 2.
/// <para>E.g. The player can play against an AI, another human, or have
///		two AI's battle each other.</para>
/// </summary>
class PlayerSelectionScene : public Scene
{
public:

	/// The function definition for setting the player types.
	using SetPlayersFunction = std::function<void(PlayerType t_p1, PlayerType t_p2)>;

	/// <summary>
	/// Initialises the scene and all it's widgets.
	/// </summary>
	/// <param name="t_font">The font used in the widgets.</param>
	/// <param name="t_setPlayers">The set player function called on scene end.</param>
	PlayerSelectionScene(sf::Font t_font, SetPlayersFunction t_setPlayers);

	/// <summary>
	/// The destructor, where all the widgets and the renderer are deleted.
	/// </summary>
	virtual ~PlayerSelectionScene();

	/// <summary>
	/// Updates the scene and it's widgets.
	/// </summary>
	/// <param name="t_deltaTime">The time since last frame.</param>
	void update(float t_deltaTime) override;

	/// <summary>
	/// Renders the scene to whatever renderer the scene uses.
	/// </summary>
	void render() override;

	/// <summary>
	/// Processes the user events and passes them to the widgets.
	/// </summary>
	/// <param name="t_event">A user event.</param>
	void processEvent(sf::Event t_event) override;

private:

	/// <summary>
	/// Creates and sets up all the necessary widgets for the scene.
	/// </summary>
	void setupWidgets();

	std::vector<Widget *> m_widgets;
	Renderer * m_renderer;
	sf::Font m_font;

	PlayerType m_player1Type;
	PlayerType m_player2Type;

	SetPlayersFunction m_setPlayers;

};

#endif // !PLAYER_SELECTION_SCENE_H