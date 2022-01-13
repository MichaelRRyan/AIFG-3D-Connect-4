#ifndef SFML_UI_RENDERER_H
#define SFML_UI_RENDERER_H

#include "Renderer.h"
#include "Button.h"

/// <summary>
/// Repersents a renderer, that will render UI in SFML.
/// </summary>
class SfmlUIRenderer : public Renderer
{
public:
	/// <summary>
	/// Constructor for the SfmlUIRenderer
	/// </summary>
	/// <param name="t_game">The game</param>
	/// <param name="t_function">Function pointer to a button click function.</param>
	/// <param name="t_font">The font.</param>
	/// <param name="t_widgets">The widgets for the UI.</param>
	SfmlUIRenderer(Game& t_game, std::function<void(Game&, int)> t_function, sf::Font t_font, std::vector<Widget*>& t_widgets);

	/// <summary>
	/// Default Destructor for the SfmlUIRenderer.
	/// </summary>
	virtual ~SfmlUIRenderer();

	/// <summary>
	/// Renders the UI.
	/// </summary>
	void render() override;

	/// <summary>
	/// Sets the game board.
	/// </summary>
	/// <param name="t_gameBoard">The current game board.</param>
	void setGameBoard(GameBoard* t_gameBoard) override;
private:
	std::vector<Widget*> m_widgets;
	sf::Font m_font;
	Game& m_game;
};

#endif