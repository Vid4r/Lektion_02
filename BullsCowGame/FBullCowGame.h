#pragma once
#include <string>

class FBullCowGame
{
public:
	FBullCowGame();// Constructor
	int GetMaxTries()const;
	int GetCurrentTry()const;
	bool IsGameWon()const;

	void Reset(); // ToDo
	bool CheckGuessValitity(std::string);//ToDo einen besseren Rückgabewert finden
private:
	// werden im Constructor initialisiert
	int MyCurrentTry;
	int MyMaxTries;
};