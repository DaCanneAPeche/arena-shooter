#include "timer.hpp"

Timer::Timer() {
	time = 0;
}

void Timer::setTimer(void (*_func)(), float _time) {
	func = _func;
	time = _time;

	clock.restart();
}

bool Timer::checkTime() {
	if (clock.getElapsedTime().asSeconds() >= time && time > 0) {
		time = 0;
		func();
		return true;
	}

	return false;
}
