#ifndef WORDLIST_H
#define WORDLIST_H

#include "random.h"
#include <vector>
#include <string>

namespace Words
{
	using namespace std::string_view_literals;
	inline std::vector list{ "Galaxy"sv, "Trading"sv, "Woodcutting"sv, "Exchange"sv
	,"Combat"sv, "Dungeon"sv, "Diamond"sv };

	inline std::string_view getRandomWord()
	{
		return list[Random::getRandomNumber(0, std::ssize(list) - 1)];
	}
}

#endif