#include "stdafx.h"
#include <iostream>
#include <string>

void PrintIntro();
void PlayGame();
std::string GetString();
bool AskToPlayAgain();

//Einstiegspunkt in die Applikation

int main ()
{
	bool bPlayAgain = false;
	do
	{ 
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	return 0;
}

void PrintIntro() {
	//Vorstellung des Spieles
	constexpr int WORLD_LENGTH = 5;
	std::cout << "Willkommen zu Bulls und Cows, ein lustiges Wortspiel\n";
	std::cout << "kannst du das Isogramm aus " << WORLD_LENGTH;
	std::cout << " Buchstaben erraten??\n";
	std::cout << std::endl;
	return;
}
void PlayGame()
{
	//Loop entsprechend der Anzahl der Wiederholungen
	constexpr int ANZAHL_DER_WIEDERHOLUNGEN = 5;
	for (int i = 1; i <= ANZAHL_DER_WIEDERHOLUNGEN; i++)
	{
		std::string Versuch = GetString();
		std::cout << "Dein Tip war: " << Versuch << std::endl;
		std::cout << std::endl;
	};
}
std::string GetString()
{   //Lassen Spiel deer raten
	std::cout << "Gib hier bitte deinen Tip an\n";
	std::string Tip = "";
	std::getline(std::cin, Tip);
	return Tip;
}
bool AskToPlayAgain()
{
	std::cout << "Moechtest du nochmal spielen? (J/N)\n";
	std::string Antwort = "";
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


