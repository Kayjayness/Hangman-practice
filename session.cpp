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

bool Session::getAlreadyUsed() const
{
	return m_alreadyUsed;
}

char Session::getUserInput() const
{
	return m_userLetter;
}

void Session::setAmountWrongGuess(int userChoice)
{
	m_amountWrongGuess = userChoice;
}

bool Session::getGameOver() const
{
	return m_gameOver;
}

// Other member functions
void Session::printDisplayVector() const
{
	for (auto& value : m_displayWord)
	{
		std::cout << value << ' ';
	}
}

void Session::printTrackedLetters() const
{
	for (auto& index : m_alreadyUsedLetters)
	{
		std::cout << index << ' ';
	}
}

void Session::printWrongGuess() const
{
	std::cout << "   ";
	for (auto& value : m_displayWrongGuess)
	{
		std::cout << value << ' ';
	}
}

void Session::convertWordtoVector()
{
	for (auto index{ 1 }; index <= std::ssize(m_randomWord); ++index)
	{
		m_displayWord.emplace_back('_');
	}
}

void Session::convertLivestoVector()
{
	for (int fillLives{ 1 }; fillLives <= m_amountWrongGuess; ++fillLives)
	{
		m_displayWrongGuess.emplace_back('#');
	}
}

void Session::trackUsedLetters()
{
	m_alreadyUsedLetters.emplace_back(m_userLetter);
}

void Session::trackWinLoseCondition()
{
	m_winCondition = true;
	m_loseCondition = true;
	for (auto& value : m_displayWord)
	{
		if (value == '_')
		{
			m_winCondition = false;
		}
	}
	for (auto& value : m_displayWrongGuess)
	{
		if (value == '#')
		{
			m_loseCondition = false;
		}
	}
	if(m_winCondition)
	{
		std::cout << "The word: ";
		printDisplayVector();
		std::cout << "  Lives ";
		printWrongGuess();
		std::cout << '\n';
		std::cout << "You guessed the word, Congratulations!\n";
		m_gameOver = true;
	}
	if(m_loseCondition)
	{
		std::cout << "The word: ";
		printDisplayVector();
		std::cout << "  Lives ";
		printWrongGuess();
		std::cout << '\n';
		std::cout << "You lose! The word was: " << m_randomWord;
		m_gameOver = true;
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
			break;
		}
	}
}

void Session::addGuessToDisplay()
{
	bool anyMatch{ false };
	auto indexCounter{ 0 };
	for (auto& value : m_randomWord)
	{
		if (m_userLetter == value)
		{
			m_displayWord[indexCounter] = m_userLetter;
			anyMatch = true;
		}
		++indexCounter;
	}
	if (!anyMatch)
	{
		auto indexWrongCounter{ 0 };
		for (auto& value : m_displayWrongGuess)
		{
			if (value == '#')
			{
				m_displayWrongGuess[indexWrongCounter] = m_userLetter;
				break;
			}
			++indexWrongCounter;
		}
	}
}

void Session::denyUsedLetters()
{
	m_alreadyUsed = false;
	for (auto& value : m_alreadyUsedLetters)
	{
		if (m_userLetter == value)
		{
			m_alreadyUsed = true;
			break;
		}
	}
}
