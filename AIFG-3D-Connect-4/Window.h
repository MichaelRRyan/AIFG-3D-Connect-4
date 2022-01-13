#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>

/// <summary>
/// This is static class that holds information on a SFML window.
/// </summary>
class Window
{
public:
	/// <summary>
	/// This will get back the window width of the screen.
	/// </summary>
	/// <returns>Window width</returns>
	inline static const unsigned int getWindowWidth() { return m_WINDOW_WIDTH; }

	/// <summary>
	/// This will get the window height of the screen.
	/// </summary>
	/// <returns>Window Height</returns>
	/// 
	inline static const unsigned int getWindowHeight() { return m_WINDOW_HEIGHT; }

	/// <summary>
	/// This will an instance of the SFML window.
	/// </summary>
	/// <returns>Returns the SFML render window</returns>
	inline static sf::RenderWindow& getWindow() { return m_window; }
private:
	static const unsigned int m_WINDOW_WIDTH = 1600;
	static const unsigned int m_WINDOW_HEIGHT = 1200;
	static sf::RenderWindow m_window;
};
#endif
