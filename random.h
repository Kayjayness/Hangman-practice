#ifndef RANDOM_H
#define RANDOM_H

#include <chrono>
#include <random>

namespace Random
{
	inline std::random_device rDevice{};
	inline std::seed_seq rSeed{ rDevice(), rDevice(), rDevice(), rDevice(), rDevice(), };
	inline std::mt19937 rmt{ rSeed };
	template <typename T, typename U>
	inline T getRandomNumber(U min, T max)
	{
		return std::uniform_int_distribution<T> {min, max}(rmt);
	}
}

#endif

