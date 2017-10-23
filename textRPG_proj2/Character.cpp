#include <string>
#include <iostream>
#include "Windows.h"
#include <mmsystem.h>
#include "stdafx.h"
#include "Character.h"
#include <algorithm>
#include <Windows.h>

using namespace std;

//...
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void greenText() {
	SetConsoleTextAttribute(hConsole, 10);
}
void whiteText() {
	SetConsoleTextAttribute(hConsole, 7);
}
void blueText() {
	SetConsoleTextAttribute(hConsole, 9);
}

//players travel method
void character::travel() {

}

//players inventory method
void character::inventory() {
	blueText();
	cout << "You look into your backpack and find:\n";
	whiteText();
}

//attempt to use a hp/mp potion - remove one from the inventory and restore hp/mp respectively
void character::useHealthPotion() {

}
void character::useManaPotion() {

}

//everything else that happens after initial prompts
void character::endInit() {
	greenText();
	cout << "What would you like to do?\n\n";
	cout << "[H]elp\n";
	cout << "[T]ravel\n";
	cout << "[C]heck your Inventory\n";
	cout << "placeholder\n";
	cout << endl << "[Q]uit\n";
	whiteText();
	cout << "> ";
	getline(cin, playerChoice);
	cout << endl;
	transform(playerChoice.begin(), playerChoice.end(), playerChoice.begin(), tolower);
	if (playerChoice == "cs") {
		blueText();
		cout << "Current Health: " << currentHealth << "/" << totalHealth << endl;
		cout << "Current Mana: " << currentMana << "/" << totalMana << endl;
		cout << "Current amount of Gold: " << currentGold << endl;
		cout << "Experience: " << currentExp << "/" << neededExp << endl;
		cout << "Level: " << level << endl;
		cout << "Stats (Wisdom/Strength/Dexterity): " << wisdom << " WIS " << strength << " STR " << dexterity << " DEX " << endl;
		cout << "Character (Name/Profession/Race): " << "You are " << playerName << ", the " << playerClass << ". You are a(n) " << playerRace << "." << endl << endl;
		cout << "Current Location (X/Y coordinates): " << " X " << posX << " Y " << posY << endl << endl;
		whiteText();
		endInit();
	}
	else if (playerChoice == "q") {
		greenText();
		cout << "Goodbye!\n\n";
		whiteText();
		exit(0);
	}
	else if (playerChoice == "h") {
		blueText();
		cout << "Available commands (use aliases to invoke commands):\n\n";
		cout << "Command name (alias)\n";
		cout << "currentStatus (cs) - prints all available character information.\n\n";
		whiteText();
		endInit();
	}
	else if (playerChoice == "c") {
		inventory();
	}
	else if (playerChoice == "t") {
		travel();
	}
	else {
		blueText();
		cout << "Not a valid option!\n";
		cout << "Please select a valid option!\n\n";
		whiteText();
		endInit();
	}
}

//initial values for the main character
character::character() {
	totalHealth = 100;
	currentHealth = 100;
	totalMana = 50;
	currentMana = 50;
	currentExp = 0;
	neededExp = 100;
	currentGold = 50;
	level = 1;
	wisdom = 5;
	strength = 5;
	dexterity = 5;
	posX = 1;
	posY = 1;
	hpPotions = 3;
	mpPotions = 3;
}

//checks if the player is still alive
void character::isAlive() {
	if (currentHealth <= 0) {
		greenText();
		cout << "You died! Game Over!\n";
		blueText();
		printf(R"EOF(
		||=========================================================||
		|| ______________________________________________________  ||
		||/                                                      \ ||
		|||                      You died!                        |||
		||\_________              _______________________________/ ||
		||          \_         __/    ___---------__               ||
		||            \      _/      /              \_             ||
		||             \    /       /                 \            ||
		||              |  /       | _    _ \          \           ||
		||              | |       / / \  / \ |          \          ||
		||              | |       ||   ||   ||           |         ||
		||              | |       | \_//\\_/ |           |         ||
		||              | |       |_| (||)   |_______|   |         ||
		||              | |         |  ||     | _  / /   |         ||
		||               \ \        |_________|| \/ /   /          ||
		||                \ \_       |_|_|_|_|/|  _/___/           ||
		||                 \__>       _ _/_ _ /  |                 ||
		||                          .|_|_|_|_|   |                 ||
		||                          |           /                  ||
		||                          |__________/                   ||
		||=========================================================||
		)EOF");
		whiteText();
	}
}

//sets the players name
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

//sets the players profession (class)
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
			playerClass = "Warrior";
			setPlayerRace();
		}
		else if (playerClass == "mage") {
			cout << endl;
			greenText();
			cout << "You are " << playerName << ", the Mage.\n\n";
			whiteText();
			validClass = true;
			playerClass = "Mage";
			setPlayerRace();
		}
		else if (playerClass == "archer") {
			cout << endl;
			greenText();
			cout << "You are " << playerName << ", the Archer.\n\n";
			whiteText();
			validClass = true;
			playerClass = "Archer";
			setPlayerRace();
		}
		else if (playerClass == "thief") {
			cout << endl;
			greenText();
			cout << "You are " << playerName << ", the Thief.\n\n";
			whiteText();
			validClass = true;
			playerClass = "Thief";
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

//sets the players race
void character::setPlayerRace() {
	greenText();
	bool validRace = false;
	cout << "The world awaits you, " << playerName << ".\n";
	cout << "What is your race?\n";
	cout << ">> Human (+1 to all Stats)\n";
	cout << ">> Elf (+3 to Wisdom)\n";
	cout << ">> Orc (+3 to Strength)\n";
	cout << ">> Dwarf (+3 to Dexterity)\n";
	whiteText();
	cout << "> ";
	getline(cin, playerRace);
	transform(playerRace.begin(), playerRace.end(), playerRace.begin(), tolower);
	if (!validRace) {
		if (playerRace == "human") {
			cout << endl;
			greenText();
			cout << "You are " << playerName << ", the " << playerClass << ". You are a Human.\n\n";
			whiteText();
			validRace = true;
			wisdom += 1;
			strength += 1;
			dexterity += 1;
			playerRace = "Human";
			SetConsoleTextAttribute(hConsole, 9);
			cout << "You've chosen your destiny.\n";
			whiteText();
			endInit();
		}
		else if (playerRace == "elf") {
			cout << endl;
			greenText();
			cout << "You are " << playerName << ", the " << playerClass << ". You are an Elf.\n\n";
			whiteText();
			validRace = true;
			wisdom += 3;
			playerRace = "Elf";
			SetConsoleTextAttribute(hConsole, 9);
			cout << "You've chosen your destiny.\n";
			whiteText();
			endInit();
		}
		else if (playerRace == "orc") {
			cout << endl;
			greenText();
			cout << "You are " << playerName << ", the " << playerClass << ". You are an Orc.\n\n";
			whiteText();
			validRace = true;
			strength += 3;
			playerRace = "Orc";
			SetConsoleTextAttribute(hConsole, 9);
			cout << "You've chosen your destiny.\n";
			whiteText();
			endInit();
		}
		else if (playerRace == "dwarf") {
			cout << endl;
			greenText();
			cout << "You are " << playerName << ", the " << playerClass << ". You are a Dwarf.\n\n";
			whiteText();
			validRace = true;
			dexterity += 3;
			playerRace = "Dwarf";
			SetConsoleTextAttribute(hConsole, 9);
			cout << "You've chosen your destiny.\n";
			whiteText();
			endInit();
		}
		else {
			greenText();
			cout << endl;
			cout << playerRace << " isn't a valid race!\n";
			cout << "Please select a valid race!\n\n";
			whiteText();
			setPlayerRace();
		}
	}
	else {
		greenText();
		cout << "ERR @ !validRace if statement\n";
		whiteText();
	}
}