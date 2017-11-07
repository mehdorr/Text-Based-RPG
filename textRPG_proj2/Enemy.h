#pragma once

#include <stdlib.h>
#include <iostream>
#include <string>

class enemy {
public:
	enemy();
	//stats
	static int currentHealth;
	static int totalHealth;
	static int currentMana;
	static int totalMana;
	static int givenExp;
	static int enemyDamage;
	static int givenGold;

	//functions
	void fightEnemy(character&);
};