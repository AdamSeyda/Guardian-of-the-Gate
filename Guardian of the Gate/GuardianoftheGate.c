#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"herostatistics.h"
#include"battlefile.h"
#include"start.h"
#include"enemyfile.h"
#include"optionsfile.h"
#include"end.h"
#include"lvlup.h"

int main()
{
    srand( time( NULL ) );
    // inicjalizacja generatora liczb pseudolosowych
    int temp;
    // userinput - int var for user input to control the game
    // temp - int var used in various functions and loops, changing its value to fit the current needs of the program
    bool switchloop = true, gameloop = true, villageloop = true, battleloop, waveloop, breakloop;
    // switchloop - bool var used in loops to make sure user input consists of valid options
    // gameloop - bool var used in the loop which runs the game, must be set to true as long as the game is supposed to be playing
    // villageloop - bool var used in a loop when player is in the village
    // battleloop - bool var used in a loop when player is fighting against waves of enemies
    // waveloop - bool var used in a loop when player is fighting against a specific wave
    // breakloop - bool var used in a loop when player has a short break between waves of enemies
    int day = 1, wavesleft, enemiesleft, barrierdurability = 100;
    // day - int var counting the ingame days
    // wavesleft - int var counting how many waves of enemies are left during current day
    // enemies left - int var counting how many enemies are left in the wave. Also used before starting the wave to generate enemy stats.
    // barrierdurability - int var representing the current durability of the barrier. It drops by 1 for each undefeated enemy in a wave and once it drops to 0 it's gameover
    int livetargets[15], turnorder[16];
    // livetargets - int array keeping track of which enemies are alive
    // turnorder - int array keeping track of when each enemy moves
    int enemies[165];
    // enemies - array int which contains the statistics of enemies.
    // the stats appear in a sequence of 11 and repeat up to 15 times for maximum amount of enemies in a wave
    // stats in first square brackets: 0 - type, 1 - subtype, 2 - strength, 3 - agility, 4 - intelect, 5 - endurance, 6 - maxhealth, 7 - maxenergy, 8 - currenthealth, 9 - currentenergy, 10 - resistance
    FILE *fptr;
    // fptr - file pointer
    char c, userinput;
    // c - char var for reading chars from files
    // userinput - char var for reading chars from keyboard



    fptr=fopen("lang.txt", "r");
    fscanf(fptr, "%d", &temp);
    fclose(fptr);
    loadlanguage(temp);
    temp=0;
    printf("\n\n%s\n\n", inttext[0]);
    herostats hero;
    while(switchloop==true)
    {
        //this loop always appear when you turn on the game and it controls the main menu
        printf("%s\n%s\n%s\n%s\n%s\n", inttext[1], inttext[2], inttext[3], inttext[4], inttext[5]);
        //getchar();
        scanf(" %c", &userinput);
        switch(userinput){
            case 49: newgame(&hero); switchloop=false; break;
            case 50: loadgame(&hero, &day, &wavesleft, &barrierdurability, &temp); setbools(temp, &switchloop, &villageloop, &battleloop, &waveloop, &breakloop); temp=0; break;
            case 51: instructions(); break;
            case 52: changelanguage(); break;
            case 53: gameloop=false; switchloop=false; break;
            default: printf("%s\n", inttext[6]); break;
        }
    }
    while(gameloop==true)
    {
        //this is one big loop which contains the main part of the game
        //the game follows the pattern: village - battles (wave of enemies - short break - wave of enemies - ...) - village - battles - ...
        while(gameloop==true&&villageloop==true)
        {
            printf("%s%d.\n\n", inttext[7], day);
            printf("%s\n%s\n", inttext[8], inttext[9]);
            scanf(" %c", &userinput);
            switch(userinput){
                case 49: options(&gameloop, &hero, 1, day, wavesleft, barrierdurability); break;
                case 50:{
                    printf("%s\n", inttext[10]);
                    switchloop=true;
                    while(switchloop==true)
                    {
                        printf("%s\n%s\n", inttext[55], inttext[56]);
                        scanf(" %c", &userinput);
                        switch(userinput){
                            case 49: newbattle(&switchloop, &villageloop, &battleloop, &waveloop, &wavesleft, &hero, day); enemiestablereset(enemies); wavegenerator(enemies, &enemiesleft, day, &hero); break;
                            case 50: switchloop=false; break;
                            default: printf("%s\n", inttext[6]); break;
                        }
                    }
                } break;

            }
        }

        while(gameloop==true&&battleloop==true)
        {
            while(gameloop==true&&battleloop==true&&waveloop==true)
            {
                barrierdurability-=battle(&hero, enemies, livetargets);
                hero.curhealth=hero.maxhealth;
                hero.curenergy=hero.maxenergy;
                wavesleft-=1;
                if(barrierdurability<=0)
                {
                    gameloop=false;
                    gameover(&hero, day);
                }
                else
                {
                    if(wavesleft<1)
                    {
                        battleloop=false;
                        villageloop=true;
                        day+=1;
                        if(day>100)
                        {
                            gameloop=false;
                            victory(&hero);
                        }
                    }
                    else
                    {
                        waveloop=false;
                        breakloop=true;
                    }
                }

            }
            while(gameloop==true&&battleloop==true&&breakloop==true)
            {
                enemiestablereset(enemies);
                if(hero.experience>=(100*(hero.level)*(hero.level)*(hero.level)))
                    levelup(&hero);
                printf("%s%d\n%s%d\n", inttext[11], hero.experience, inttext[12], hero.level);
                printf("%s\n", inttext[58]);
                printf("%s\n%s\n", inttext[13], inttext[14]);
                scanf(" %c", &userinput);
                switch(userinput){
                case 49: breakloop=false; waveloop=true; wavegenerator(enemies, &enemiesleft, day, &hero); break;
                case 50: options(&gameloop, &hero, 0, day, wavesleft, barrierdurability); break;
                default: printf("%s\n", inttext[6]); break;
                }
            }
        }
    }
    return 0;
}
