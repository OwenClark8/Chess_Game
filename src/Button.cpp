#include "../include/Button.h"


Button::Button(std::unique_ptr<CommandClass> com,  float x, float y,
		float sizex, float sizey, const std::string& text, 
			const std::string& font): mp_com(std::move(com)),
			m_rect(sf::Vector2f(x, y), sf::Vector2f(sizex, sizey))
{
	if(!m_font.loadFromFile("Fonts/Lato-Regular.ttf"))
		throw;
	m_text.setFont(m_font);
	m_text.setCharacterSize((12 *sizex /6) /  (float)(text.size() + 2));
	m_text.setPosition(x + (sizex / (text.size() + 2)), y + sizey / 2 - sizex / (text.size() + 2));
	m_text.setString(text);
	m_text.setColor(sf::Color::White);
	m_text.setStyle(sf::Text::Bold);

	m_button.resize(4);

	m_button.setPrimitiveType(sf::Quads);

	m_button[0].position = sf::Vector2f(x, y);
	m_button[1].position = sf::Vector2f(x + sizex, y);
	m_button[3].position = sf::Vector2f(x, y + sizey);
	m_button[2].position = sf::Vector2f(x + sizex, y + sizey);


	m_button[0].color = sf::Color::Black;
	m_button[1].color = sf::Color::Black;
	m_button[2].color = sf::Color::Black; 
	m_button[3].color = sf::Color::Black;

}


void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

    // draw the vertex array

    target.draw(m_button, states);

   target.draw(m_text, states);
}

std::string Button::click(float x, float y) const 
{
	if(m_rect.contains(x, y))
		return mp_com->Execute();
	else
		return "N";
}