#ifndef IMAGEBOARDDEF
#define IMAGEBOARDDEF


#include <chrono>
#include <array>
#include <vector>
#include <memory>
#include <string>

#include <SFML/Graphics.hpp>


namespace SFMLLib
{

class ImageBoard : public sf::Drawable, public sf::Transformable
{
public:

	ImageBoard(const std::string& font = "Fonts/Lato-Regular.ttf");

	bool load(const std::string& tileset, const std::array<std::array<int, 8>, 8> tiles);
	
	void newGame(std::string font);

	void setColour(const std::array<std::array<bool, 8>, 8> tiles);
	
	std::string clickSquare(float x, float y) const;

	void updatePlayerTurn(int i);

	void updateTurnNo(int i);
	
private:

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	sf::VertexArray m_board;
	sf::Texture     m_text;
	sf::VertexArray m_frame;

	std::vector<sf::Rect<float>> m_checkBoard;

	sf::Font m_font;

	std::array<sf::Text, 2> m_turnInfo = {{ {}, {} }};


};

}


#endif