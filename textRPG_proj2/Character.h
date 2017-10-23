#pragma once

#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class character {
public:
	character();
	//attributes
	int currentHealth;
	int totalHealth;
	int currentMana;
	int totalMana;
	int currentExp;
	int neededExp;
	int level;

	//...
	int posX;
	int posY;
	bool isAlive();

	//functions

	void useHealthPotion();
	void useManaPotion();
	void setPlayerName();
	void setPlayerClass();
	void setPlayerRace();

	//strings

	string playerName;
	string playerClass;
	string playerRace;

};