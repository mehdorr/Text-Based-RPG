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
void enemy::fightEnemy() {
	string enemyNameArr[] = {
		"Zombie",
		"Bandit",
		"Ghoul",
		"Rat",
		"Ghost"
	};
	auto enemyNameArrLength = (sizeof(enemyNameArr) / sizeof(*enemyNameArr));
	string enemyName = enemyNameArr[rand() % enemyNameArrLength];
	character player;
	auto playerHealth = player.currentHealth;
	auto playerMaxHealth = player.totalHealth;
	auto playerMana = player.currentMana;
	auto playerMaxMana = player.totalMana;
	auto playerDamage = player.damage;
	auto playerExp = player.currentExp;
	auto playerGold = player.currentGold;
	cout << "You're facing a(n) " << enemyName << endl;
	auto fight = true;
	while (fight) {
		blueText();
		cout << "||===================================||" << endl;
		cout << "||Player                        Enemy||" << endl;
		cout << "||" << playerHealth << "/" << playerMaxHealth << "        Health         " << currentHealth << "/" << totalHealth << "||" << endl;
		cout << "||" << playerMana << "/" << playerMaxMana << "           Mana            " << currentMana << "/" << totalMana << "||" << endl;
		cout << "||" << playerDamage << "         Damage per hit          " << enemyDamage << "||" << endl;
		cout << "||" << "1. Attack" << "                    " << "2. Run" << "||" << endl;
		cout << "||===================================||" << endl;
		string playerChoice;
		whiteText();
		cout << "> ";
		getline(cin, playerChoice);
		if ((playerChoice == "1") || (playerChoice == "2")) {
			int playerChosen = stoi(playerChoice);
			switch (playerChosen) {
			case 1: {
				greenText();
				cout << "You hit the enemy for " << playerDamage << ".\n";
				currentHealth = currentHealth - playerDamage;
				cout << "The " << enemyName << " hit you for " << enemyDamage << ".\n\n";
				playerHealth = playerHealth - enemyDamage;
				player.isAlive();
				if (currentHealth <= 0) {
					blueText();
					cout << "You won the fight!\n\n";
					cout << "You recieved +" << givenExp << "XP" << " and +" << givenGold << " Gold.\n\n";
					playerGold = playerGold + givenGold;
					playerExp = playerExp + givenExp;
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
					playerHealth = playerHealth - enemyDamage;
					player.isAlive();
					break;
				}
				else {
					cout << "Success! You ran away!\n\n";
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
