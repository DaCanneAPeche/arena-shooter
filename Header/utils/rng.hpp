#pragma once

#include <random>

class Rng {
public:
	Rng() : dist(0, 1), engine(rd()) {}

	int operator()(int min, int max) {
		max++; // so number can = max
		return dist(engine) * (max - min) + min;
	}

private:
	std::uniform_real_distribution<double> dist;
	std::random_device rd;
	std::default_random_engine engine;

};
