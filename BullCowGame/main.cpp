// BullCowGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
string GetGuess();

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
	cout << "Welcome to Bulls and Cows, a fun word game." << endl;
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking about?" << endl;
	cout << endl;
	return;
}

void PlayGame()
{
	constexpr int NUMBER_OF_TURNS = 5;
	// loop for the number of turns asking for guesses
	for (int count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		string Guess = GetGuess();
		// repeat the guess back to them
		cout << "Your guess was: " << Guess << endl;
		cout << endl;
	}
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again? (y/n)";
	cout << endl;
	string Response = "";
	getline(cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}

string GetGuess()
{
	// get a guess from the player
	cout << "Please type your word: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}