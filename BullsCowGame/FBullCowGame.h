#pragma once
#include <string>

class FBullCowgame
{
public:
	void Reset(); // ToDo
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValitity(std::string);//ToDo einen besseren R�ckgabewert finden

private:
	int MyCurrentTry();
	int MyMaxTries();
};