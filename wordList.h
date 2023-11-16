#ifndef WORDLIST_H
#define WORDLIST_H

#include "random.h"
#include <vector>
#include <string>

namespace Words
{
	using namespace std::string_view_literals;
	inline std::vector list{ "galaxy"sv, "trading"sv, "woodcutting"sv, "exchange"sv
	,"combat"sv, "dungeon"sv, "diamond"sv };

	inline std::string_view getRandomWord()
	{
		return list[Random::getRandomNumber(0, std::ssize(list) - 1)];
	}
}

#endif