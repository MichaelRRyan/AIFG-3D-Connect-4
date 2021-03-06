#include "Label.h"

///////////////////////////////////////////////////////////////////////////////
Label::Label(sf::Font const& t_font, std::string t_string, sf::Vector2f t_position) :
	m_text{ t_string, t_font }
{
	m_text.setPosition(t_position);
}

///////////////////////////////////////////////////////////////////////////////
void Label::update(float t_deltaTime)
{
}

///////////////////////////////////////////////////////////////////////////////
void Label::draw(sf::RenderWindow& t_window) const
{
	t_window.draw(m_text);
}

///////////////////////////////////////////////////////////////////////////////
void Label::centerText()
{
	sf::FloatRect bounds = m_text.getGlobalBounds();
	m_text.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
}

///////////////////////////////////////////////////////////////////////////////
void Label::processEvents(sf::Event t_event)
{
}

///////////////////////////////////////////////////////////////////////////////
void Label::setPosition(sf::Vector2f t_pos)
{
	m_text.setPosition(t_pos);
}

///////////////////////////////////////////////////////////////////////////////
void Label::setString(std::string t_string)
{
	m_text.setString(t_string);
}

///////////////////////////////////////////////////////////////////////////////