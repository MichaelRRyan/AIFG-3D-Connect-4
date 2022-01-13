#ifndef PLAYER_SELECTION_SCENE_H
#define PLAYER_SELECTION_SCENE_H

#include "Scene.h"
#include "Button.h"

class PlayerSelectionScene : public Scene
{
public:

	PlayerSelectionScene(sf::Font t_font);

	void update(float t_deltaTime) override;

	void render() override;

	void processEvent(sf::Event t_event) override;

private:

	/// <summary>
	/// Creates and sets up all the necessary widgets for the scene.
	/// </summary>
	void setupWidgets();

	enum class PlayerType
	{
		None,
		Human,
		AI
	};

	std::vector<Widget *> m_widgets;
	Renderer * m_renderer;
	sf::Font m_font;

	PlayerType m_player1Type;
	PlayerType m_player2Type;

};

#endif // !PLAYER_SELECTION_SCENE_H