#include "../include/Timer.h"



//using clock = std::chrono::high_resolution_clock;


void Timer::startTimer(Colour c)
{
	if(c == Colour::White)
	{
		m_timeLeft[0] += clock::now() - std::get<0>(m_pauseAt[0]);
		std::get<bool>(m_pauseAt[0]) = false;
	}
	else if(c == Colour::Black)
	{
		m_timeLeft[1] += clock::now() - std::get<0>(m_pauseAt[0]);
		std::get<bool>(m_pauseAt[1]) = false;
	}

}


void Timer::stopTimer(Colour c)
{
	if(c == Colour::White)
		m_pauseAt[0] = std::make_pair<clock::time_point, bool>(clock::now(), true);
	else if(c == Colour::Black)
		m_pauseAt[1] = std::make_pair<clock::time_point, bool>(clock::now(), true);
}



void Timer::draw() const
{
	std::array<clock::time_point, 2> t = {{m_timeLeft[0] + (std::get<bool>(m_pauseAt[0]) ? clock::now() - std::get<0>(m_pauseAt[0]) : std::chrono::minutes(0) ),
										 m_timeLeft[1] + (std::get<bool>(m_pauseAt[1]) ? clock::now() - std::get<0>(m_pauseAt[1]) : std::chrono::minutes(0)) }};
	mp_Imp->drawTimer(t);
}