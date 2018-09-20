// BullCowGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
FText GetGuess();

FBullCowGame BCGame; // instatiate a new game

// the entry point for our application
int main()
{
	bool bWantsToPlayAgain = false;
	do 
	{
		PrintIntro();
		PlayGame();
		bWantsToPlayAgain = AskToPlayAgain();
	} while (bWantsToPlayAgain);
		
	return 0;
}

void PrintIntro()
{
	// introduce the game
	constexpr int32 WORD_LENGTH = 6;
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking about?" << std::endl;
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	// loop for the number of turns asking for guesses
	// TODO change from for to while loop once we are validating tries
	for (int32 count = 1; count <= MaxTries; count++)
	{
		FText Guess = GetGuess(); // TODO make loop checking valid

		// submit valid guess to the game, and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		// print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows <<std::endl;

		std::cout << std::endl;
	}
	// TODO summarise game
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	std::cout << std::endl;
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}

FText GetGuess()
{
	int32 MyCurrentTry = BCGame.GetCurrentTry();
	// get a guess from the player
	std::cout << "Try " << MyCurrentTry << ". Please type your word: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}