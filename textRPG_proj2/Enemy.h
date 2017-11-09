#pragma once

#include <stdlib.h>
#include <iostream>
#include <string>

class enemy;
class character;

class enemy {
public:
	enemy();
	//stats
	int currentHealth;
	int totalHealth;
	int currentMana;
	int totalMana;
	int givenExp;
	int enemyDamage;
	int givenGold;

	//functions
	void fightEnemy(character& player);
};