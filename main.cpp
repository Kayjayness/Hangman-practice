#include "session.h"
#include "wordList.h"
#include <iostream>

// Hangman Practice assignment
//
// Implement a game of Hangman
// Computer picks random word and user "_" to highlight each letter
// Playerwins if they guess the word before making x amount of wrong guesses
// x guesses should be configurable
// Player shall guess 1 letter per turn
// If player has previously guessed the letter it doesn't count, game continues
// If player guesses correct letter, that "_" is replaced by the corresponding letter
// If player makes a wrong guess, player uses one of their x guesses
// Player should see their attempts
// Player should see their wrongly guessed letters

static int lifeAmount()
{
	while(true)
	{
		int amountOfLives{};
		std::cin >> amountOfLives;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		if (amountOfLives < 3 || amountOfLives > 6)
		{
			std::cout << "Invalid amount, please try again: ";
		}
		else
		{
			return amountOfLives;
		}
	}

}

int main()
{
	char playAgain{'y'};
	while (playAgain == 'y')
	{
		std::cout << "- - - This is Hangman Practice Game - - -\n\n";
		std::cout << "- Your goal is to guess the word (letter by letter) in a certain amount of attempts\n";
		std::cout << "- If you guess wrong you lose 1 life.\n\n";
	
		Session s1{ Words::getRandomWord() };
		std::cout << "How many lives would you like to play with (3 - 6): \n";
		s1.setAmountWrongGuess(lifeAmount());
		std::cout << '\n';

		s1.convertWordtoVector();
		s1.convertLivestoVector();

		while(!(s1.getGameOver()))
		{
			std::cout << "The word: ";
			s1.printDisplayVector();
			std::cout << "  Lives ";
			s1.printWrongGuess();
			std::cout << '\n';

			s1.askUserInput();
			s1.denyUsedLetters();
			if (s1.getAlreadyUsed())
			{
				std::cout << "You have already guessed the letter " << s1.getUserInput() << '\n';
			}
			else
			{
				s1.addGuessToDisplay();
				s1.trackUsedLetters();
			}
			std::cout << '\n';
			s1.trackWinLoseCondition();
		}
		std::cout << "\n\n";
		std::cout << "Would you like to play again? (y / n): ";
		std::cin >> playAgain;
		std::cout << '\n';
	}
	return 0;
}
