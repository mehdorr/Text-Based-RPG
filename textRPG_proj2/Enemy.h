#pragma once

#include <stdlib.h>
#include <iostream>
#include <string>

class enemy 
{
	//stats
	int currentHealth;
	int totalHealth;
	int currentMana;
	int totalMana;
	int givenExp;
	int enemyDamage;
	int givenGold;
public:
	enemy();
	//functions
	void fightEnemy();
};
