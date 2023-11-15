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

int main()
{
	

	std::cout << "The word is: " << Words::getRandomWord();
	return 0;
}
