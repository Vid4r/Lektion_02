#pragma once


class FBullCowgame
{
public:
	void Reset(); // ToDo
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValitity(string);//ToDo einen besseren R�ckgabewert finden


private:
	int MyCurrentTry();
	int MyMaxTries();
};