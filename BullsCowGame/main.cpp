/*
Das ist die Consolenanwendung die die BullCow Class nutzt.
Diese fungiert als View in einem Model View Controller-Pattern und ist für die gesamte Benutzerinteraktion verantwortlich.
Spiellogik befindet sich in der FBullCowGame Class
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetString();
bool AskToPlayAgain();

FBullCowGame BCGame;  // SpielInstanz

//Einstiegspunkt in die Applikation

int main ()
{
	bool bPlayAgain = false;
	do
	{ 
		BCGame.Reset();
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	return 0;
}

void PrintIntro() {
	//Vorstellung des Spieles
	constexpr int32 WORLD_LENGTH = 5;
	std::cout << "Willkommen zu Bulls und Cows, ein lustiges Wortspiel\n";
	std::cout << "kannst du das Isogramm aus " << WORLD_LENGTH;
	std::cout << " Buchstaben erraten??\n";
	std::cout << std::endl;
	return;
}
void PlayGame()
{
	int32 MaxTries = BCGame.GetMaxTries();
	//Loop entsprechend der Anzahl der Wiederholungen
	for (int32 i = 1; i <= MaxTries; i++)
	{   
		FText Tip = GetString();
		FBullCowCount FBullCowCount = BCGame.SubmitGuess(Tip);
		std::cout << "Bulls:" << FBullCowCount.Bulls;
		std::cout << ". Cows:" << FBullCowCount.Cows;
		std::cout << std::endl;
		std::cout << std::endl;
	};
}
FText GetString()
{   //Spieler raten lassen
	int32 aktuellerVersuch = BCGame.GetCurrentTry();
	std::cout << "Tip:" << aktuellerVersuch << std::endl << " " << "Gib hier bitte deinen Tip an\n";
	FText Tip = "";
	std::getline(std::cin, Tip);
	return Tip;
}
bool AskToPlayAgain()
{
	std::cout << "Moechtest du nochmal spielen? (J/N)\n";
	FText Antwort = "";
	std::getline(std::cin, Antwort);
	switch (Antwort[0])
	{
	case 'j':
	case 'J':
		return true;
	default:
		return false;
	}	
}


