#ifndef TIMERDEF
#define TIMERDEF

#include <chrono>
#include "Component.h"


class Timer: public Component
{

using clock = std::chrono::high_resolution_clock;

protected:
	std::array<clock::time_point, 2> m_timeLeft;

	std::array<std::pair<clock::time_point, bool>, 2> m_pauseAt = {{std::make_pair<clock::time_point, bool>(clock::now(), true),
		 std::make_pair<clock::time_point, bool>(clock::now(), true)}};


public:

	Timer(PrintImpl* pi, const std::chrono::minutes& min, const std::chrono::seconds& sec) :
		Component(pi), m_timeLeft{clock::now() + min + sec, clock::now() + min + sec}
	{

	};

	~Timer() = default;

	void stopTimer(Colour c);

	void startTimer(Colour c);

	void draw() const override;

};


#endif