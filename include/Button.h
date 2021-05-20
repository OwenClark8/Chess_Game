#ifndef BUTTONDEF
#define BUTTONDEF

#include "Command.h"
#include <memory>
#include <string>

#include <SFML/Graphics.hpp>



class Button : public sf::Drawable, public sf::Transformable
{
public:
	Button(std::unique_ptr<CommandClass> com,  float x, float y,
		float sizex, float sizey, const std::string& text, 
			const std::string& font = "Fonts/Lato-Regular.ttf");

	~Button() = default;

	//void resize();

	std::string click(float x, float y) const;

	Button& operator=(Button&&) = default;
	Button(Button&&) = default; 


protected:
	std::unique_ptr<CommandClass> mp_com;
	sf::Rect<float> m_rect;
	sf::VertexArray m_button;
	sf::Color       m_color;
	sf::Font 		m_font;
	sf::Text 		m_text;

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};


#endif