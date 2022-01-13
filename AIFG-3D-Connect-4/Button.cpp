#include "Button.h"

///////////////////////////////////////////////////////////////////////////////
Button::Button(sf::Vector2f t_size, sf::Vector2f t_pos, std::string t_buttonText, sf::Font& t_font, Callback t_function) :
	m_callback(t_function)
{
	m_body.setSize(t_size);
	m_body.setPosition(t_pos);
	m_body.setFillColor(sf::Color::Red);
	m_text.setFont(t_font);
	m_text.setString(t_buttonText);
	m_text.setCharacterSize(60);
	m_text.setFillColor(sf::Color::Black);
}

///////////////////////////////////////////////////////////////////////////////
Button::~Button()
{
}

///////////////////////////////////////////////////////////////////////////////
void Button::onButtonPress()
{
	if (m_callback != nullptr)
		m_callback(*this);
}

///////////////////////////////////////////////////////////////////////////////
void Button::update(float t_deltaTime)
{
}

///////////////////////////////////////////////////////////////////////////////
void Button::draw(sf::RenderWindow& t_window) const
{
	t_window.draw(m_body);
	t_window.draw(m_text);
}

///////////////////////////////////////////////////////////////////////////////
void Button::setPosition(sf::Vector2f t_newPos)
{
	m_body.setPosition(t_newPos);
	sf::FloatRect rectBounds = m_body.getGlobalBounds();
	m_text.setPosition(
		rectBounds.left + (rectBounds.width / 2),
		rectBounds.top + (rectBounds.height / 2)
	);
}

///////////////////////////////////////////////////////////////////////////////
void Button::setCallback(Callback t_callback)
{
	m_callback = t_callback;
}

///////////////////////////////////////////////////////////////////////////////
void Button::setString(std::string const& t_string)
{
	m_text.setString(t_string);
}

///////////////////////////////////////////////////////////////////////////////
void Button::centerText()
{
	// CENTERS THE TEXT TO THE BUTTON.
	sf::FloatRect textRect = m_text.getLocalBounds();
	sf::FloatRect textBounds = m_text.getGlobalBounds();

	m_text.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);

	sf::FloatRect rectBounds = m_body.getGlobalBounds();
	/*m_body.setScale((textBounds.width / rectBounds.width * 1.5f), (textBounds.height / rectBounds.height * 1.75f));
	rectBounds = m_body.getGlobalBounds();*/

	m_text.setPosition(
		rectBounds.left + (rectBounds.width / 2),
		rectBounds.top + (rectBounds.height / 2)
	);
}

///////////////////////////////////////////////////////////////////////////////
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
	else if (sf::Event::MouseMoved == t_event.type)
	{
		// On/Off focus effect when the mouse is over a button.
		sf::Vector2f mousePos = Window::getWindow().mapPixelToCoords(sf::Mouse::getPosition(Window::getWindow()));
		if (m_body.getGlobalBounds().contains(mousePos))
		{
			m_body.setFillColor(sf::Color{ m_body.getFillColor().r, m_body.getFillColor().g, m_body.getFillColor().b, 100 });
		}
		else
		{
			m_body.setFillColor(sf::Color::Red);
		}
	}
}

///////////////////////////////////////////////////////////////////////////////