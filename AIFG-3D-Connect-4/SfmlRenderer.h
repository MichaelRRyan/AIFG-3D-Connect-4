#ifndef SFML_RENDERER_H
#define SFML_RENDERER_H

#include "Renderer.h"
#include "Grid.h"
#include <SFML/Graphics.hpp>
#include "Window.h"

/// <summary>
/// This is a SFML renderer, that will render game objects using SFML objects.
/// </summary>
class SfmlRenderer : public Renderer
{
public:
	/// <summary>
	/// Constructor for the SFML renderer.
	/// </summary>
	SfmlRenderer(std::vector<Grid>& t_grid);

	/// <summary>
	/// Default Destructor for the SFML renderer.
	/// </summary>
	~SfmlRenderer();

	/// <summary>
	/// Overriden Render function that will render using the SFML render window.
	/// </summary>
	void render() override;

	/// <summary>
	/// This will set the game board so that the game knows what pieces to render with the SFML render window.
	/// </summary>
	/// <param name="t_gameBoard"></param>
	void setGameBoard(GameBoard* t_gameBoard) override;
private:
	GameBoard* m_gameBoard;

	// Grids for the 4 Tec, there will be 4 grids in total.
	std::vector<Grid>& m_grids;
};
#endif