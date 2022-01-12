#include "Button.h"

Button::Button(Game& t_game, sf::Vector2f t_size, std::function<void(Game&, int)> t_function, sf::Vector2f t_pos, std::string t_buttonText, sf::Font& t_font, int t_depthLevel) :
	m_string(t_buttonText),
	m_font(t_font),
	m_game(&t_game),
	m_function(t_function),
	m_depthLevel(t_depthLevel)
{
	m_string = t_buttonText;
	m_body.setSize(t_size);
	m_body.setPosition(t_pos);
	m_body.setFillColor(sf::Color::Red);
	m_text.setFont(t_font);
	m_text.setString(m_string);
	m_text.setCharacterSize(60);
	m_text.setFillColor(sf::Color::Black);
}

Button::~Button()
{
}

void Button::onButtonPress()
{
	// HANDLES IF THE USER PRESS A BUTTON.
	if (m_function != nullptr)
	{
		std::cout << "hit";
		m_function(*m_game, m_depthLevel);
	}
	// HANDLES IF THE USER PRESS A BUTTON.
}

void Button::update(sf::Time t_deltaTime)
{
	// CHECKS WHICH BUTTON IS SELECTED AND IF ONE IS, THEN CHANGE THE ALPHA OF THAT BUTTON.
	if (m_isFocused)
	{
		m_body.setFillColor(sf::Color{ 255, 255, 255, 255 });
		m_text.setFillColor(sf::Color{ 0, 0, 0, 255 });
	}
	else
	{
		m_body.setFillColor(sf::Color{ 255, 255, 255, 100 });
		m_text.setFillColor(sf::Color{ 0, 0, 0, 100 });
	}
	// CHECKS WHICH BUTTON IS SELECTED AND IF ONE IS, THEN CHANGE THE ALPHA OF THAT BUTTON.
}

void Button::draw(sf::RenderWindow& t_window) const
{
	t_window.draw(m_body);
	t_window.draw(m_text);
}

void Button::setPosition(sf::Vector2f t_newPos)
{
	m_body.setPosition(t_newPos);
	sf::FloatRect rectBounds = m_body.getGlobalBounds();
	m_text.setPosition(
		rectBounds.left + (rectBounds.width / 2),
		rectBounds.top + (rectBounds.height / 2)
	);
}

const sf::Vector2f Button::getPosition() const
{
	return m_body.getPosition();
}

sf::Vector2f Button::getSize() const
{
	return m_body.getSize();
}

inline bool Button::getFocused()
{
	return m_isFocused;
}

inline void Button::setFocus(bool t_isFocused)
{
	m_isFocused = t_isFocused;
}

void Button::setTextColour(sf::Color t_color)
{
	m_text.setFillColor(t_color);
}

void Button::setWidgetColor(sf::Color t_color)
{
	m_body.setFillColor(t_color);
}

void Button::centerText()
{
	// CENTERS THE TEXT TO THE BUTTON.
	sf::FloatRect textRect = m_text.getLocalBounds();
	sf::FloatRect textBounds = m_text.getGlobalBounds();

	m_text.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);

	sf::FloatRect rectBounds = m_body.getGlobalBounds();
	m_body.setScale((textBounds.width / rectBounds.width * 1.5), (textBounds.height / rectBounds.height * 1.75));
	rectBounds = m_body.getGlobalBounds();

	m_text.setPosition(
		rectBounds.left + (rectBounds.width / 2),
		rectBounds.top + (rectBounds.height / 2)
	);
	// CENTERS THE TEXT TO THE BUTTON.
}

void Button::processEvents(sf::Event t_event)
{
	if (sf::Event::MouseButtonPressed == t_event.type)
	{
		sf::Vector2f mousePos = Window::getWindow().mapPixelToCoords(sf::Mouse::getPosition(Window::getWindow()));
		if (m_body.getGlobalBounds().contains(mousePos))
		{
			onButtonPress();
		}
	}
}
