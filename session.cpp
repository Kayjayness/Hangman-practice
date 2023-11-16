#include "session.h"
#include <iostream>

// Constructors

Session::Session(std::string_view randomWord)
	: m_randomWord{ randomWord }
{
}

// Getters and setter functions

std::string_view Session::getRandomWord() const
{
	return m_randomWord;
}
std::vector<char> Session::getDisplayWord() const
{
	return m_displayWord;
}
std::vector<char> Session::getTrackedLetters() const
{
	return m_alreadyUsedLetters;
}
char Session::getUserInput() const
{
	return m_userLetter;
}

// Other member functions
void Session::printDisplayVector() const
{
	for (auto& value : m_displayWord)
	{
		std::cout << value << ' ';
	}
	std::cout << '\n';
}
void Session::convertWordtoVector()
{
	for (auto index{ 0 }; index < std::ssize(m_randomWord); ++index)
	{
		m_displayWord.emplace_back('_');
	}
}
void Session::askUserInput()
{
	std::cout << "Enter your guess: ";
	while (true)
	{
		std::cin >> m_userLetter;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		if (m_userLetter < 'a' || m_userLetter > 'z')
		{
			std::cout << "Invalid input, Please try again: ";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			std::cout << "You entered: " << m_userLetter << '\n';
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			trackUsedLetters();
			break;
		}
	}
}
void Session::trackUsedLetters()
{
	m_alreadyUsedLetters.emplace_back(m_userLetter);
}
void Session::printTrackedLetters() const
{
	for (auto& index : m_alreadyUsedLetters)
	{
		std::cout << index << ' ';
	}
}
