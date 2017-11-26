#pragma once
#include <string>

using FString = std::string;
using int32 = int;


// alle Variablen sind mit 0 initialisiert
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame
{
public:
	FBullCowGame();// Constructor
	
	int32 GetMaxTries()const;
	int32 GetCurrentTry()const;
	bool IsGameWon()const;

	void Reset(); // ToDo
	bool CheckGuessValitity(FString);//ToDo einen besseren Rückgabewert finden
	// Methode BullCowCount Zählt Bulls und Cows erhöht die Anzahl der Versuche vorrausgesetzt der Versuch war gültig
	FBullCowCount SubmitGuess(FString);
private:
	// werden im Constructor initialisiert
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	
};