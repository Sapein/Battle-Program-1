#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  A basic little battle game, where you fight a bunch of enemies. 
 *
 *        Version:  1.0
 *        Created:  11/7/2014 5:36:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sapein (CC), 
 *   Organization:  
 *
 * =====================================================================================
 */
int main(){
	int x; 
	int playerHP, playerDef, playerAtk;
	int enemyHP, enemyDef, enemyAtk;
	int gameOn, battleOn;
	int playerDamage, enemyDamage;
	char playerName[200]; 

	gameOn = 1;	
	while(gameOn == 1){
		printf("BattleArena v1.0 alpha  ----- Sapein\n");
		printf("Welcome to the Battle Arena!\n");
		printf("Please insert your name to get started\n"); 
		fgets(playerName, 200, stdin);
		for(x = 0; x <= sizeof(playerName); x++){
			if(playerName[x] == '\n'){
				playerName[x] = '\0';
			}
		}
		printf("Hello %s\n", playerName);
		printf("Beggining Game...\n");
		enemyDamage = enemyHP - playerAtk;
		battleOn = 1;
		while(battleOn == 1){
			char playerInput[40];
			playerInput == ""; 
			printf("///////////////////////////////////////\n");
			printf("%s - HP: %d Atk: %d Def: %d\n", playerName, playerHP, playerAtk, playerDef);
			printf("Enemy = HP: %d Atk: %d Def %d\n", enemyHP, enemyAtk, enemyDef);
			printf("//////////////////////////////////////\n");
			printf("\n");
			printf("What would you like to do?\n");
			printf("1. Attack\n");
			/* printf("2. Defend\n"); */
			printf("2. Exit\n");
			for(x = 0; x <= sizeof(playerInput) + 1; x++){
				if(playerInput[x] == '\n'){
					playerInput[x] = '\0';
				}
			}
			fgets(playerInput, 40, stdin);
			if(strcmp(playerInput, "1\n") == 0 || strcmp(playerInput, "Attk\n") == 0 || strcmp(playerInput, "Attack\n") == 0 || strcmp(playerInput, "attack\n") || strcmp(playerInput, "atk") == 0 || strcmp(playerInput, "atk\n") == 0 || strcmp(playerInput, "Atk\n")){ 
				enemyHP = enemyDamage;
				printf("You attacked the Enemy!\n");
				if(enemyHP <= 0){
					enemyHP = 0;
					printf("You Win! Summoning next Monster!\n"); 
				}
			}
			/* else if(playerInput == ("2\n" || "Def\n" || "Defense\n" || "Defend\n" || "def\n" || "defense\n" || "defend\n")){ */
			/* 	printf("You Defend!\n"); */
			/* } */
			else if(strcmp(playerInput, "2\n") == 0 || strcmp(playerInput, "exit\n") == 0 || strcmp(playerInput, "Exit\n") == 0 || strcmp(playerInput, "ext\n") == 0){
				battleOn = 0;
				gameOn = 0; 
			}
			else{
				printf("Input Unknown!\n");
			}
		}
	}

	return 0;
}


