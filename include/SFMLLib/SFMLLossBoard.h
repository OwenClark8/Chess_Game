#ifndef SFMLLOSSBOARDDEF
#define SFMLLOSSBOARDDEF


#include <chrono>
#include <array>
#include <vector>
#include <memory>
#include <string>

#include <SFML/Graphics.hpp>

namespace SFMLLib
{


class SFMLLossBoard : public sf::Drawable, public sf::Transformable
{
public:
	SFMLLossBoard();

	~SFMLLossBoard() = default;

	bool load(const std::string& tileset, const std::array<std::array<int,6>, 2>& lb);

	void newGame();

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	sf::VertexArray m_board;
	sf::Texture     m_text;
	sf::VertexArray m_frame;

	std::array<sf::Text, 10> m_numLost = {{ {}, {}, {}, {}, {}, {}, {}, {}, {}, {}}};
	sf::Font m_font;


};

std::array<std::array<int, 6>, 2> convertLossBoard(const std::array<std::array<int,6>, 2>& lb);

}


#endif