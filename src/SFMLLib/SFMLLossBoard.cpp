#include "../../include/SFMLLib/SFMLLossBoard.h"


SFMLLib::SFMLLossBoard::SFMLLossBoard()
{
	this->newGame();
}


bool SFMLLib::SFMLLossBoard::load(const std::string& tileset, const std::array<std::array<int,6>, 2>& lb)
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

    auto lossB = convertLossBoard(lb);

    for (unsigned int i = 0; i < 5; ++i)
    {
        for (unsigned int j = 0; j < 2; ++j)
        {
            //get the current tile number
            int tileNumber = lossB[j][i+1];

            m_numLost[i * 2 + j].setString(std::to_string(tileNumber));

            // find its position in the tileset texture


            auto tileSizex =  m_text.getSize().x / 6;
            auto tileSizey = m_text.getSize().y / 2;


            // get a pointer to the current tile's quad
            sf::Vertex* quad = &m_board[(i * 2 + j ) * 4];

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
            quad[0].texCoords = sf::Vector2f((i + 1) * tileSizex, j * tileSizey);
            quad[1].texCoords = sf::Vector2f((i + 2) * tileSizex, j * tileSizey);
            quad[2].texCoords = sf::Vector2f((i + 2) * tileSizex, (j + 1) * tileSizey);
            quad[3].texCoords = sf::Vector2f((i + 1) * tileSizex, (j + 1) * tileSizey);
        }
    }

    return true;

}

void SFMLLib::SFMLLossBoard::newGame()
{

	
	m_board.resize(10 * 4);
	m_board.setPrimitiveType(sf::Quads);

 	for(int i = 0 ; i < 5; ++i){
 		
 		for(int j = 0; j < 2; ++j){

 			sf::Vertex* square = &m_board[((i * 2) + j) * 4];

 			square[0].position = sf::Vector2f(600.f + 50.f * j, 100.f + 50.f * i);
 			square[1].position = sf::Vector2f(600.f + 50.f * (j + 1), 100.f + 50.f * i);
 			square[2].position = sf::Vector2f(600.f + 50.f * (j + 1), 100.f + 50.f * (i+1));
 			square[3].position = sf::Vector2f(600.f + 50.f * j , 100.f + 50.f * (i + 1));
 			
			square[0].color = sf::Color::White;
			square[1].color = sf::Color::White; 
			square[2].color = sf::Color::White; 
			square[3].color = sf::Color::White; 


 		}
 	}


 	m_frame.resize(16 + 20);
 	m_frame.setPrimitiveType(sf::Quads);

 	for(int i = 0; i < 2; ++i)
 	{

		sf::Vertex* square = &m_frame[i* 4];

	 	square[0].position = sf::Vector2f(590.f + 110.f * i, 90.f);
		square[1].position = sf::Vector2f(600.f + 110.f * i, 90.f);
		square[2].position = sf::Vector2f(600.f + 110.f * i, 360.f );
		square[3].position = sf::Vector2f(590.f + 110.f * i, 360.f);

		square[0].color = sf::Color(165, 42, 42);
		square[1].color = sf::Color(165, 42, 42);
		square[2].color = sf::Color(165, 42, 42); 
		square[3].color = sf::Color(165, 42, 42);

 	} 

	for(int i = 0; i < 2; ++i)
 	{


		sf::Vertex* square = &m_frame[8 + i* 4];

	 	square[0].position = sf::Vector2f(600.f , 90.f + 260.f * i);
		square[1].position = sf::Vector2f(700.f , 90.f + 260.f * i);
		square[2].position = sf::Vector2f(700.f, 100.f + 260.f * i);
		square[3].position = sf::Vector2f(600.f, 100.f+ 260.f * i);

		square[0].color = sf::Color(165, 42, 42);
		square[1].color = sf::Color(165, 42, 42);
		square[2].color = sf::Color(165, 42, 42); 
		square[3].color = sf::Color(165, 42, 42);

 	}

 	for(int i = 0; i < 4; ++i)
 	{

		sf::Vertex* square = &m_frame[16 + i* 4];

	 	square[0].position = sf::Vector2f(600.f , 148.f + 50.f * i);
		square[1].position = sf::Vector2f(700.f , 148.f + 50.f * i);
		square[2].position = sf::Vector2f(700.f, 152.f + 50.f * i);
		square[3].position = sf::Vector2f(600.f, 152.f+ 50.f * i);


		square[0].color = sf::Color::Black;
		square[1].color = sf::Color::Black;
		square[2].color = sf::Color::Black; 
		square[3].color = sf::Color::Black;

 	}

	sf::Vertex* square = &m_frame[32];

 	square[0].position = sf::Vector2f(648.f , 100.f );
	square[1].position = sf::Vector2f(652.f , 100.f );
	square[2].position = sf::Vector2f(652.f, 350.f );
	square[3].position = sf::Vector2f(648.f, 350.f);


	square[0].color = sf::Color::Black;
	square[1].color = sf::Color::Black;
	square[2].color = sf::Color::Black; 
	square[3].color = sf::Color::Black;

	// m_numLost.reserve(12);

	// for(int i = 0; i < 6; ++i)
	// {
	// 	for(int j = 0; j < 2; ++j)
	// 	{
			
	// 		m_numLost[i * 2 + j].setCharacterSize(20);
	// 		m_numLost[i * 2 + j].setPosition(650.f + 50.f * j, 150.f + 50.f * i);
	// 		m_numLost[i * 2 + j].setString("0");
	// 	}

	// }
	if(!m_font.loadFromFile("Fonts/Lato-Regular.ttf"))
		throw;
	for(int i = 0; i < 5; ++i)
	{
		for(int j =0; j < 2; ++j)
		{
			m_numLost[i * 2 + j].setFont(m_font);
			m_numLost[i * 2 + j].setCharacterSize(20);
			m_numLost[i * 2 + j].setPosition(635.f + 50.f * j, 126.f + 50.f * i);
			m_numLost[i * 2 + j].setString("0");
			m_numLost[i * 2 + j].setColor(sf::Color::Black);
			m_numLost[i * 2 + j].setStyle(sf::Text::Bold);
		}
	}

}


void SFMLLib::SFMLLossBoard::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

    // apply the tileset texture
    states.texture = &m_text;


    // draw the vertex array
    target.draw(m_board, states);
    target.draw(m_frame, states);
    for(auto& i : m_numLost)
    {
    	target.draw(i, states);
    }
    //target.draw(m_numLost, states);
}


std::array<std::array<int, 6>, 2> SFMLLib::convertLossBoard(const std::array<std::array<int,6>, 2>& lb)
{
	
	std::array<std::array<int, 6>, 2> temp;
	for(int i = 0; i < 2; ++i)
	{
		temp[i][0] = lb[i][5];
		temp[i][1] = lb[i][2];
		temp[i][2] = lb[i][3];
		temp[i][3] = lb[i][1];
		temp[i][4] = lb[i][4];
		temp[i][5] = lb[i][0];
	}

	return temp;

}

