#include "timer.hpp"

Timer::Timer() {
	time = 0;
}

void Timer::setTimer(void (*_func)(), float _time) {
	func = _func;
	time = _time;

	clock.restart();
}

void Timer::setTimer(float _time) {
	time = _time;

	clock.restart();
}

void Timer::reset() {
	time = 0;
}


bool Timer::checkTime(bool hasCallback) {
	if (clock.getElapsedTime().asSeconds() >= time && time > 0) {
		time = 0;
		if (hasCallback) func();
		return true;
	}

	return false;
}
