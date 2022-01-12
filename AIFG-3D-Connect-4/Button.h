#pragma once
#include "Widget.h"
#include <functional>

class Game;

class Button : public Widget
{
public:
	Button() = default;
	Button(Game& t_game, sf::Vector2f t_size, std::function<void(Game&, int)> t_function, sf::Vector2f t_pos, std::string t_buttonText, sf::Font& t_Font, int t_depthLevel);
	~Button();
	void update(float t_deltaTime) override;
	void draw(sf::RenderWindow& t_window) const override;
	void centerText() override;
	void processEvents(sf::Event t_event) override;
	void setPosition(sf::Vector2f t_pos) override;
private:
	void onButtonPress();
	std::function<void(Game&, int)> m_function;
	std::string m_string;
	sf::RectangleShape m_body;
	sf::Text m_text;
	sf::Font m_font;
	Game* m_game;
	int m_depthLevel;
};

#include "Game.h"