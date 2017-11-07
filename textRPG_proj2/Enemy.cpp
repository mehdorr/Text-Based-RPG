#include <string>
#include "Windows.h"
#include <mmsystem.h>
#include "stdafx.h"
#include "Enemy.h"
#include "Character.h"
#include <ctime>
#include <random>
#include <Windows.h>
#include <iostream>
#include <locale>

using namespace std;

void whiteText();
void greenText();
void blueText();


//enemy's values
enemy::enemy() {
	totalHealth = (rand() % 50) + 1;
	currentHealth = totalHealth;
	totalMana = 0;
	currentMana = totalMana;
	givenExp = totalHealth * 10;
	givenGold = totalHealth / 3;
	enemyDamage = totalHealth / 5;
}



//method for fighting
void enemy::fightEnemy(character& player) {
	string enemyNameArr[] = {
		"Zombie",
		"Bandit",
		"Ghoul",
		"Rat",
		"Ghost"
	};
	int enemyNameArrLength = (sizeof(enemyNameArr) / sizeof(*enemyNameArr));
	string enemyName = enemyNameArr[rand() % enemyNameArrLength];
	cout << "You're facing a(n) " << enemyName << endl;
	bool fight = true;
	while (fight) {
		blueText();
		cout << "Player                        Enemy" << endl;
		cout << player.currentHealth << "/" << player.totalHealth << "        Health         " << currentHealth << "/" << totalHealth << endl;
		cout << player.currentMana << "/" << player.totalMana << "           Mana            " << currentMana << "/" << totalMana << endl;
		cout << player.damage << "         Damage per hit          " << enemyDamage << endl;
		cout << "1. Attack" << "                    " << "2. Run" << endl;
		string playerChoice;
		whiteText();
		cout << "> ";
		getline(cin, playerChoice);
		if ((playerChoice == "1") || (playerChoice == "2")) {
			int playerChosen = stoi(playerChoice);
			switch (playerChosen) {
			case 1: {
				greenText();
				cout << "You hit the enemy for " << player.damage << ".\n";
				currentHealth = currentHealth - player.damage;
				cout << "The " << enemyName << " hit you for " << enemyDamage << ".\n\n";
				player.currentHealth = player.currentHealth - enemyDamage;
				player.isAlive();
				if (currentHealth <= 0) {
					blueText();
					cout << "You won the fight!\n\n";
					cout << "You recieved +" << givenExp << "XP" << " and +" << givenGold << " Gold.\n\n";
					player.currentGold = player.currentGold + givenGold;
					player.currentExp = player.currentExp + givenExp;
					fight = false;
					player.checkExp();
					player.travel();
					break;
				}
				break;
			}
			case 2: {
				blueText();
				cout << "You attempt to run away from the " << enemyName << ".\n";
				cout << "And you... \n\n";
				int runChance = (rand() % 2) + 1;
				if (runChance == 1) {
					cout << "Fail! The " << enemyName << " catches up to you, making you fight.\n";
					cout << "The " << enemyName << " hit you for " << enemyDamage << ".\n\n";
					player.currentHealth -= enemyDamage;
					player.isAlive();
					break;
				}
				else {
					cout << "Succeed! You ran away!\n\n";
					player.travel();
				}
			}
			default:
				cout << "Not a valid option!\n";
				cout << "Please select a valid option!\n\n";
				break;
			}
		}
		else {
			blueText();
			cout << "Not a valid option!\n";
			cout << "Please select a valid option!\n\n";
		}
	}
}