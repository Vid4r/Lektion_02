#pragma once
#include <string>

class FBullCowGame
{
public:
	void Reset(); // ToDo
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValitity(std::string);//ToDo einen besseren Rückgabewert finden
private:
	int MyCurrentTry();
	int MyMaxTries();
};