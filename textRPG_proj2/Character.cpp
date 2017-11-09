#include <string>
#include <iostream>
#include "Windows.h"
#include <mmsystem.h>
#include "stdafx.h"
#include "Character.h"
#include <algorithm>
#include <Windows.h>
#include <random>
#include <ctime>
#include "Enemy.h"

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

//get players choice method
void character::getPlayerChoice() {
	cout << "> ";
	getline(cin, playerChoice);
	cout << endl;
	transform(playerChoice.begin(), playerChoice.end(), playerChoice.begin(), tolower);
}

//used for randoming objects when looking around
string randObj(string rObj) {
	string object[] = {
		"Door",
		"Corridor"
	};
	int objLength = (sizeof(object) / sizeof(*object));
	rObj = object[rand() % objLength];
	return rObj;
}

//method used for >looking around<
void character::lookAround() {
	string object;
	greenText();
	cout << "You look around.\n";
	cout << "To the North you see a(n) " << randObj(object) << ".\n";
	cout << "To the East you see a(n) " << randObj(object) << ".\n";
	cout << "To the South you see a(n) " << randObj(object) << ".\n";
	cout << "To the West you see a(n) " << randObj(object) << ".\n\n";
	whiteText();
	travel();
}

//method to make the player >attacked< (40% chance)
void character::getAttacked() {
	int attackedChance = (rand() % 10) + 1;
	if (attackedChance >= 7) {
		blueText();
		cout << "You've been attacked!\n\n";
		enemy fight;
		fight.fightEnemy(*this);
	}
	else {
		travel();
	}
}

//attempt to use a hp/mp potion - remove one from the inventory and restore hp/mp respectively
void character::useHealthPotion() {
	if (currentHealth != totalHealth) {
		hpPotions--;
		currentHealth += 15;
		cout << "You drank a Health Potion. +15HP\n\n";
		if (currentHealth > totalHealth) {
			currentHealth = totalHealth;
		}
		travel();
	}
	else {
		blueText();
		cout << "Your Health is already full!\n\n";
		travel();
	}
}
void character::useManaPotion() {
	if (currentMana != totalMana) {
		mpPotions--;
		currentMana += 15;
		cout << "You drank a Mana Potion. +15MP\n\n";
		if (currentMana > totalMana) {
			currentMana = totalMana;
		}
		travel();
	}
	else {
		blueText();
		cout << "Your Mana is already full!\n\n";
		travel();
	}
}

//players travel method
void character::travel() {
	greenText();
	cout << "What do you want to do?\n\n";
	cout << "[L]ook around\n\n";
	cout << "Go [W]est\n";
	cout << "Go [E]ast\n";
	cout << "Go [S]outh\n";
	cout << "Go [N]orth\n";
	cout << endl << "Drink a [H]ealth Potion\n";
	cout << "Drink a [M]ana Potion\n";
	cout << endl <<"[B]ack\n";
	whiteText();
	getPlayerChoice();
	if (playerChoice == "w") {
		posX -= 1;
		greenText();
		cout << "You go West.\n";
		getAttacked();
		whiteText();
	}
	else if (playerChoice == "e") {
		posX += 1;
		greenText();
		cout << "You go East.\n";
		getAttacked();
		whiteText();
	}
	else if (playerChoice == "s") {
		posY -= 1;
		greenText();
		cout << "You go South.\n";
		getAttacked();
		whiteText();
	}
	else if (playerChoice == "n") {
		posY += 1;
		greenText();
		cout << "You go North.\n";
		getAttacked();
		whiteText();
	}
	else if (playerChoice == "l") {
		lookAround();
	}
	else if (playerChoice == "cs") {
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
		travel();
	}
	else if (playerChoice == "h") {
		useHealthPotion();
	}
	else if (playerChoice == "m") {
		useManaPotion();
	}
	else if (playerChoice == "b") {
		endInit();
	}
	else {
		blueText();
		cout << "Not a valid option!\n";
		cout << "Please select a valid option!\n\n";
		whiteText();
		travel();
	}
}

//players inventory method
void character::inventory() {
	blueText();
	cout << "You look into your backpack and find:\n";
	cout << hpPotions << " Health Potions\n";
	cout << mpPotions << " Mana Potions\n\n";
	cout << currentGold << " Gold Coins\n\n";
	whiteText();
	endInit();
}

//everything else that happens after initial prompts
void character::endInit() {
	greenText();
	cout << "What would you like to do?\n\n";
	cout << "[H]elp\n";
	cout << "[T]ravel\n";
	cout << "[C]heck your Inventory\n";
	cout << endl << "[Q]uit\n";
	whiteText();
	getPlayerChoice();
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
		blueText();
		cout << "You decide to travel.\n\n";
		whiteText();
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
		exit(0);
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
			cout << "You wake up in a dirty, old cell, located as it would seem in a large dungeon.\n";
			cout << "It's weird, but it seems like the terrain around you is constantly shifting! Traverse carefully.\n\n";
			cout << "You hear voices whispering: get to level 10 to get out of here.\n\n";
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
			cout << "You wake up in a dirty, old cell, located as it would seem in a large dungeon.\n";
			cout << "It's weird, but it seems like the terrain around you is constantly shifting! Traverse carefully.\n\n";
			cout << "You hear voices whispering: get to level 10 to get out of here.\n\n";
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
			cout << "You wake up in a dirty, old cell, located as it would seem in a large dungeon.\n";
			cout << "It's weird, but it seems like the terrain around you is constantly shifting! Traverse carefully.\n\n";
			cout << "You hear voices whispering: get to level 10 to get out of here.\n\n";
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
			cout << "You wake up in a dirty, old cell, located as it would seem in a large dungeon.\n";
			cout << "It's weird, but it seems like the terrain around you is constantly shifting! Traverse carefully.\n\n";
			cout << "You hear voices whispering: get to level 10 to get out of here.\n\n";
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

//used to check if the player's leveled up
void character::checkExp() {
	if (currentExp >= neededExp) {
		level++;
		cout << "Level Up! You are now level " << level << ".\n\n";
		neededExp = neededExp * 1.5;
		currentExp = 0;
		if (level == 10) {
			blueText();
			cout << "You reached Level 10.\n\n";
			cout << "You won the game, congratulations!\n";
			printf(R"EOF(
*******************************************************************************
          |                   |                  |                     |       
 _________|________________.=""_;=.______________|_____________________|_______
|                   |  ,-"_,=""     `"=.|                  |                   
|___________________|__"=._o`"-._        `"=.______________|___________________
          |                `"=._o`"=._      _`"=._                     |       
 _________|_____________________:=._o "=._."_.-="'"=.__________________|_______
|                   |    __.--" , ; `"=._o." ,-"""-._ ".   |                   
|___________________|_._"  ,. .` ` `` ,  `"-._"-._   ". '__|___________________
          |           |o`"=._` , "` `; .". ,  "-._"-._; ;              |       
 _________|___________| ;`-.o`"=._; ." ` '`."\` . "-._ /_______________|_______
|                   | |o;    `"-.o`"=._``  '` " ,__.--o;   |                   
|___________________|_| ;     (#) `-.o `"=.`_.--"_o.-; ;___|___________________
____/______/______/___|o;._    "      `".o|o_.--"    ;o;____/______/______/____
/______/______/______/_"=._o--._        ; | ;        ; ;/______/______/______/_
____/______/______/______/__"=._o--._   ;o|o;     _._;o;____/______/______/____
/______/______/______/______/____"=._o._; | ;_.--"o.--"_/______/______/______/_
____/______/______/______/______/_____"=.o|o_.--""___/______/______/______/____
/______/______/______/______/______/______/______/______/______/______/______/_
*******************************************************************************
)EOF");
			exit(0);
		}
	}
}

//initial values for the main character
character::character() {
	totalHealth = 100 + (strength * 10);
	currentHealth = totalHealth;
	totalMana = 50 + (wisdom * 10);
	currentMana = totalMana;
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
	damage = (int)(5 + (dexterity * 2) + wisdom + (strength * 1.5));
}