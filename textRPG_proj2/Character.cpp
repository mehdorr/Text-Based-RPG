#include <string>
#include <iostream>
#include "Windows.h"
#include <mmsystem.h>
#include "stdafx.h"
#include "Character.h"
#include <algorithm>
#include <Windows.h>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void greenText() {
	SetConsoleTextAttribute(hConsole, 10);
}
void whiteText() {
	SetConsoleTextAttribute(hConsole, 7);
}

character::character() {
	totalHealth = 100;
	totalMana = 50;
	currentExp = 0;
	neededExp = 100;
	level = 1;
}

void character::setPlayerName() {
	greenText();
	cout << "What's your name?\n";
	whiteText();
	cout << "> ";
	getline(cin, playerName);
	cout << endl;
	if (playerName.length() != 0) {
		setPlayerClass();
	}
	else {
		greenText();
		cout << "A name can't have zero characters! Please enter a valid name.\n\n";
		whiteText();
		setPlayerName();
	}
}

void character::setPlayerClass() {
	greenText();
	cout << "Alright, " << playerName << ", what's your profession?\n";
	bool validClass = false;
	cout << ">> Warrior\n";
	cout << ">> Mage\n";
	cout << ">> Archer\n";
	cout << ">> Thief\n";
	whiteText();
	cout << "> ";
	getline(cin, playerClass);
	transform(playerClass.begin(), playerClass.end(), playerClass.begin(), tolower);
	if (!validClass) {
		if (playerClass == "warrior") {
			cout << endl;
			greenText();
			cout << "You are " << playerName << ", the Warrior.\n\n";
			whiteText();
			validClass = true;
			setPlayerRace();
		}
		else if (playerClass == "mage") {
			cout << endl;
			greenText();
			cout << "You are " << playerName << ", the Mage.\n\n";
			whiteText();
			validClass = true;
			setPlayerRace();
		}
		else if (playerClass == "archer") {
			cout << endl;
			greenText();
			cout << "You are " << playerName << ", the Archer.\n\n";
			whiteText();
			validClass = true;
			setPlayerRace();
		}
		else if (playerClass == "thief") {
			cout << endl;
			greenText();
			cout << "You are " << playerName << ", the Thief.\n\n";
			whiteText();
			validClass = true;
			setPlayerRace();
		}
		else {
			greenText();
			cout << endl;
			cout << playerClass << " isn't a valid profession!\n";
			cout << "Please select a valid profession!\n\n";
			whiteText();
			setPlayerClass();
		}
	}
	else {
		greenText();
		cout << "ERR @ !validClass if statement\n";
		whiteText();
	}
}

void character::setPlayerRace() {
	greenText();
	cout << "The world awaits you, " << playerName << ".\n";
	cout << "What is your race?\n";
	whiteText();
	cout << "> ";
	getline(cin, playerRace);
	cout << endl;
}