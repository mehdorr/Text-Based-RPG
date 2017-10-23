#pragma once

#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class character {
public:
	character();
	//stats
	int currentHealth;
	int totalHealth;
	int currentMana;
	int totalMana;
	int currentExp;
	int neededExp;
	int level;
	int currentGold;

	//attributes
	int wisdom;
	int strength;
	int dexterity;

	//...
	int posX;
	int posY;
	int hpPotions;
	int mpPotions;

	//functions

	void useHealthPotion();
	void useManaPotion();
	void setPlayerName();
	void setPlayerClass();
	void setPlayerRace();
	void isAlive();
	void endInit();
	void inventory();
	void travel();
	void getPlayerChoice();
	void lookAround();

	//strings

	string playerName;
	string playerClass;
	string playerRace;
	string playerChoice;

};