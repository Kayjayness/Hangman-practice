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
	bool getAlreadyUsed() const;
	char getUserInput() const;
	void setAmountWrongGuess(int userChoice);
	bool getGameOver() const;

public:	// Other member functions
	void printDisplayVector() const;
	void printTrackedLetters() const;
	void printWrongGuess() const;

	void convertWordtoVector();
	void convertLivestoVector();

	void trackUsedLetters();
	void trackWinLoseCondition();
	
	void askUserInput();
	void addGuessToDisplay();
	void denyUsedLetters();
	
private:
	std::string m_randomWord{"default"};
	std::vector<char> m_displayWord{};
	std::vector<char> m_alreadyUsedLetters{};
	std::vector<char> m_displayWrongGuess{};
	int m_amountWrongGuess{};
	bool m_winCondition{};
	bool m_loseCondition{};
	bool m_gameOver{false};
	bool m_alreadyUsed{};
	char m_userLetter{};
};

#endif