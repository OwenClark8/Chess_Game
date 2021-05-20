#include "../../include/SFMLLib/ImageBoard.h"


using namespace SFMLLib;

ImageBoard::ImageBoard(const std::string& font)
{
	this->newGame(font);
}


bool ImageBoard::load(const std::string& tileset, const std::array<std::array<int, 8>, 8> tiles)
{
	sf::Image im;

	// load the tileset texture
	if (!im.loadFromFile(tileset))
        return false;

    //im.createMaskFromColor(im.getPixel(0,0));
    im.createMaskFromColor(sf::Color::White, 0);

    auto co = im.getPixel(0,0);
    m_text.loadFromImage(im);
    // populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < 8; ++i)
    {
        for (unsigned int j = 0; j < 8; ++j)
        {
            //get the current tile number
            int tileNumber = tiles[i][j];

            // find its position in the tileset texture


            auto tileSizex =  m_text.getSize().x / 6;
            auto tileSizey = m_text.getSize().y / 2;


            int tu = (tileNumber % 6);
            int tv = (tileNumber / 6);

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &m_board[(i * 8 + j ) * 4];

            if(tileNumber == -1)
            {
            	quad[0].texCoords = sf::Vector2f(0, 0);
	            quad[1].texCoords = sf::Vector2f(0, 0);
	            quad[2].texCoords = sf::Vector2f(0, 0);
	            quad[3].texCoords = sf::Vector2f(0, 0);
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


void ImageBoard::newGame(std::string font)
{
	m_checkBoard.reserve(64);
	m_board.resize(64 * 4);
	m_board.setPrimitiveType(sf::Quads);

 	for(int i = 0 ; i < 8; ++i){
 		
 		for(int j = 0; j < 8; ++j){

 			sf::Vertex* square = &m_board[((i * 8) + j) * 4];

 			square[0].position = sf::Vector2f(100.f + 50.f * i, 100.f + 50.f * j);
 			square[1].position = sf::Vector2f(100.f + 50.f * (i + 1), 100.f + 50.f * j);
 			square[2].position = sf::Vector2f(100.f + 50.f * (i + 1), 100.f + 50.f * (j+1));
 			square[3].position = sf::Vector2f(100.f + 50.f * i , 100.f + 50.f * (j + 1));

 			m_checkBoard.push_back(sf::Rect<float>(sf::Vector2f(100.f + 50.f * i, 100.f + 50.f * j), 
 												sf::Vector2f(50.f, 50.f)));

 		}
 	}
 	std::array<std::array<bool, 8>, 8> temp;
 	//temp.fill(false);
 	for(auto& i : temp)
 	{
 		i.fill(false);
 	}
 	this->setColour(temp);

 	m_frame.resize(16);
 	m_frame.setPrimitiveType(sf::Quads);

 	for(int i = 0; i < 2; ++i)
 	{
 

		sf::Vertex* square = &m_frame[i* 4];

	 	square[0].position = sf::Vector2f(90.f + 410.f * i, 90.f);
		square[1].position = sf::Vector2f(100.f + 410.f * i, 90.f);
		square[2].position = sf::Vector2f(100.f + 410.f * i, 510.f );
		square[3].position = sf::Vector2f(90.f + 410.f * i, 510.f);

		square[0].color = sf::Color(165, 42, 42);
		square[1].color = sf::Color(165, 42, 42);
		square[2].color = sf::Color(165, 42, 42); 
		square[3].color = sf::Color(165, 42, 42);

 	
 		
 	} 

	for(int i = 0; i < 2; ++i)
 	{


		sf::Vertex* square = &m_frame[8 + i* 4];

	 	square[0].position = sf::Vector2f(100.f , 90.f + 410.f * i);
		square[1].position = sf::Vector2f(500.f , 90.f + 410.f * i);
		square[2].position = sf::Vector2f(500.f, 100.f + 410.f * i);
		square[3].position = sf::Vector2f(100.f, 100.f+ 410.f * i);

		square[0].color = sf::Color(165, 42, 42);
		square[1].color = sf::Color(165, 42, 42);
		square[2].color = sf::Color(165, 42, 42); 
		square[3].color = sf::Color(165, 42, 42);



 	}

 	if(!m_font.loadFromFile("Fonts/Lato-Regular.ttf"))
		throw;


	m_turnInfo[0].setFont(m_font);
	m_turnInfo[0].setCharacterSize(12);
	m_turnInfo[0].setPosition(95.f, 75.f );
	m_turnInfo[0].setString("Current Player Turn:       ");
	m_turnInfo[0].setColor(sf::Color::Black);
	m_turnInfo[0].setStyle(sf::Text::Bold);

	m_turnInfo[1].setFont(m_font);
	m_turnInfo[1].setCharacterSize(12);
	m_turnInfo[1].setPosition(325.f, 75.f );
	m_turnInfo[1].setString("Turn Number: #");
	m_turnInfo[1].setColor(sf::Color::Black);
	m_turnInfo[1].setStyle(sf::Text::Bold);

	std::get<sf::Text>(m_checkInfo).setFont(m_font);
	std::get<sf::Text>(m_checkInfo).setCharacterSize(12);
	std::get<sf::Text>(m_checkInfo).setPosition(595.f, 575.f );
	std::get<sf::Text>(m_checkInfo).setColor(sf::Color::Black);
	std::get<sf::Text>(m_checkInfo).setStyle(sf::Text::Bold);
	std::get<bool>(m_checkInfo) = false;

	std::get<sf::Text>(m_lossMessage).setFont(m_font);
	std::get<sf::Text>(m_lossMessage).setCharacterSize(12);
	std::get<sf::Text>(m_lossMessage).setPosition(595.f, 575.f );
	std::get<sf::Text>(m_lossMessage).setColor(sf::Color::Black);
	std::get<sf::Text>(m_lossMessage).setStyle(sf::Text::Bold);
	std::get<bool>(m_lossMessage) = false;

}

void ImageBoard::setColour(const std::array<std::array<bool, 8>, 8> tiles)
{

	bool black = false;

 	for(int i = 0 ; i < 8; ++i){
 		
 		for(int j = 0; j < 8; ++j){

 			sf::Vertex* square = &m_board[((i * 8) + j) * 4];


 			if(tiles[i][j])
 			{
				square[0].color = sf::Color(101, 151, 151);
				square[1].color = sf::Color(101, 151, 151);
				square[2].color = sf::Color(101, 151, 151); 
				square[3].color = sf::Color(101, 151, 151);

				black = !black;

				continue;
 			}
 			
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

 		}
 		black = !black;
 	}

}

std::string ImageBoard::clickSquare(float x, float y) const
{
	for(int i = 0; i < 8; ++i)
	{
		for(int j = 0; j < 8; ++j)
		{
			if(m_checkBoard[i * 8 + j].contains(x, y))
			{
				std::string alphabet = "ABCDEFGH";
				std::string out = alphabet[i] + std::to_string(j + 1);
				return out;
			}
		}
	}
	return "N";
}

void ImageBoard::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

    // apply the tileset texture
    states.texture = &m_text;
    //states.blendMode = sf::BlendMode::BlendAlpha;

    // draw the vertex array
    target.draw(m_board, states);
    target.draw(m_frame, states);
    target.draw(m_turnInfo[0], states);
    target.draw(m_turnInfo[1], states);
    if(std::get<bool>(m_checkInfo))
    {
    	target.draw(std::get<sf::Text>(m_checkInfo), states);
    }

    if(std::get<bool>(m_lossMessage))
    {
    	target.draw(std::get<sf::Text>(m_lossMessage), states);
    }
}

void ImageBoard::updatePlayerTurn(int i)
{
	if(i == 0)
		m_turnInfo[0].setString("Current Player Turn: White");
	else if(i == 1)
		m_turnInfo[0].setString("Current Player Turn: Black");
	else
		throw "invalid int";
}

void ImageBoard::updateTurnNo(int i)
{
	std::string str = "Turn Number: ";
	m_turnInfo[1].setString(str + std::to_string(i));

}

void ImageBoard::updateCheck(Colour c, bool b)
{
	if(b)
	{
		std::string str = " in check";
		auto col = (c == Colour::White) ? "White" : "Black";
		std::get<sf::Text>(m_checkInfo).setString(col + str);
	}
	std::get<bool>(m_checkInfo) = b;
}

void ImageBoard::lossMessage(Colour c)
{
	std::string str = " wins";
	auto col = (c == Colour::White) ? "White" : "Black";
	std::get<sf::Text>(m_lossMessage).setString(col + str);
	std::get<bool>(m_lossMessage) = true;
}