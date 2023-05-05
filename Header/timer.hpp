#ifndef TIMER_H
#define TIMER_H

#include "SFML/System/Clock.hpp"

class Timer
{
private:
	void (*func)();
	float time;

	sf::Clock clock;

public:
	Timer();
	void setTimer(void(*_func)(), float _time);

	bool checkTime();
};

#endif /* TIMER_H */
