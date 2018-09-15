// BullCowGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
std::string GetGuess();

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
	constexpr int WORD_LENGTH = 6;
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking about?" << std::endl;
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	int MaxTries = BCGame.GetMaxTries();
	// loop for the number of turns asking for guesses
	for (int count = 1; count <= MaxTries; count++)
	{
		std::string Guess = GetGuess();
		// repeat the guess back to them
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	std::cout << std::endl;
	std::string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}

std::string GetGuess()
{
	int MyCurrentTry = BCGame.GetCurrentTry();
	// get a guess from the player
	std::cout << "Try " << MyCurrentTry << ". Please type your word: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}