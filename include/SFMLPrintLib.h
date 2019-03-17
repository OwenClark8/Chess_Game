#ifndef SFMLPRINTLIB
#define SFMLPRINTLIB


#include <SFML/Graphics.hpp>


class ImageBoard : public sf::Drawable, public sf::Transformable
{
public:

	ImageBoard()
	{
		this->newGame();
	}


	bool load(const std::string& tileset, const std::array<std::array<int, 8>, 8> tiles)
	{
		sf::Image im;

		// load the tileset texture
        if (!im.loadFromFile(tileset))
            return false;

        //im.createMaskFromColor(im.getPixel(0,0));
        im.createMaskFromColor(sf::Color::Cyan, 200);
        m_text.loadFromImage(im);
        // populate the vertex array, with one quad per tile
        for (unsigned int i = 0; i < 8; ++i)
        {
            for (unsigned int j = 0; j < 8; ++j)
            {
                //get the current tile number
                int tileNumber = tiles[j][i];

                // find its position in the tileset texture


                auto tileSizex =  m_text.getSize().x / 6;
                auto tileSizey = m_text.getSize().y / 2;


                int tu = (tileNumber % 6);
                int tv = (tileNumber / 6);

                // get a pointer to the current tile's quad
                sf::Vertex* quad = &m_board[(i * 8 + j ) * 4];

                if(tileNumber == -1)
                {
                	continue;
                }
                else if(tileNumber > 12 || tileNumber < -1)
                	throw "invalid tile board";
                // define its 4 texture coordinates
                quad[0].texCoords = sf::Vector2f(tu * tileSizex, tv * tileSizey);
                quad[1].texCoords = sf::Vector2f((tu + 1) * tileSizex, tv * tileSizey);
                quad[2].texCoords = sf::Vector2f((tu + 1) * tileSizex, (tv + 1) * tileSizey);
                quad[3].texCoords = sf::Vector2f(tu * tileSizex, (tv + 1) * tileSizey);
            }
        }

        return true;


	}

	void newGame()
	{
		m_checkBoard.reserve(64);
		m_board.resize(64 * 4);
 		m_board.setPrimitiveType(sf::Quads);

 		bool black = false;

	 	for(int i = 0 ; i < 8; ++i){
	 		
	 		for(int j = 0; j < 8; ++j){

	 			sf::Vertex* square = &m_board[((i * 8) + j) * 4];

	 			square[0].position = sf::Vector2f(100.f + 50.f * i, 100.f + 50.f * j);
	 			square[1].position = sf::Vector2f(100.f + 50.f * (i + 1), 100.f + 50.f * j);
	 			square[2].position = sf::Vector2f(100.f + 50.f * (i + 1), 100.f + 50.f * (j+1));
	 			square[3].position = sf::Vector2f(100.f + 50.f * i , 100.f + 50.f * (j + 1));

	 			if(black)
	 			{
					square[0].color = sf::Color(151, 151, 151);
					square[1].color = sf::Color(151, 151, 151);
					square[2].color = sf::Color(151, 151, 151); 
					square[3].color = sf::Color(151, 151, 151);
	 			}
	 			else
	 			{
					square[0].color = sf::Color::White;
	 				square[1].color = sf::Color::White; 
	 				square[2].color = sf::Color::White; 
	 				square[3].color = sf::Color::White; 
	 			}
	 			black = !black;

	 			m_checkBoard.push_back(sf::Rect<float>(sf::Vector2f(100.f + 50.f * i, 100.f + 50.f * j), 
	 												sf::Vector2f(50.f, 50.f)));

	 		}
	 		black = !black;
	 	}
	}


	std::string clickSquare(float x, float y)
	{
		for(int i = 0; i < 8; ++i)
		{
			for(int j = 0; j < 8; ++j)
			{
				if(m_checkBoard[i * 8 + j].contains(x, y))
				{
					std::string alphabet = "ABCDEFGH";
					std::string out = alphabet[j] + std::to_string(i);
					return out;
				}
			}
		}
		return "N";
	}



private:

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		states.transform *= getTransform();

        // apply the tileset texture
        states.texture = &m_text;
        //states.blendMode = sf::BlendMode::BlendAlpha;

        // draw the vertex array
        target.draw(m_board, states);
	}

	sf::VertexArray m_board;
	sf::Texture     m_text;

	std::vector<sf::Rect<float>> m_checkBoard;


};

#endif