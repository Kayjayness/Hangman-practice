#ifndef SESSION_H
#define SESSION_H

#include "wordList.h"

class Session
{
public: // Constructors
	Session(std::string_view randomWord = "default");
public:	// Getters and setters
	std::string_view getRandomWord() const;
	std::vector<char> getDisplayWord() const;
	std::vector<char> getTrackedLetters() const;
	char getUserInput() const;
public:	// Other member functions
	void printDisplayVector() const;
	void convertWordtoVector();
	void askUserInput();
	void trackUsedLetters();
	void printTrackedLetters() const;

private:
	std::string m_randomWord{"default"};
	std::vector<char> m_displayWord{};
	std::vector<char> m_alreadyUsedLetters{};
	char m_userLetter{};

};

#endif