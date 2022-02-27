#include "herostatistics.h"
#include "optionsfile.h"
#include<stdio.h>

void options(bool *gameloop, herostats *hero, int ifinbattle, int day, int wavesleft, int barrierhealth)
{
    char userinput;
    printf("%s\n%s\n%s\n", inttext[26], inttext[27], inttext[28]);
    scanf(" %c", &userinput);
    switch(userinput){
        case 49: return; break;
        case 50: savegame(hero, ifinbattle, day, wavesleft, barrierhealth); return; break;
        case 51: *gameloop=false; return; break;
        default: printf("%s\n", inttext[6]); options(gameloop, hero, ifinbattle, day, wavesleft, barrierhealth); break; //6
    }
}

void savegame(herostats* hero, int ifinbattle, int day, int wavesleft, int barrierhealth)
{
    char stringinput[16], savefile[20];
    int temp;
    printf("%s\n", inttext[59]);
    scanf("%s", &stringinput);
    sprintf(savefile, "%s.bin", stringinput);
    FILE *fptr;
    fptr=fopen(savefile, "rb");
    if(fptr==NULL)
    {
        fclose(fptr);
        fptr=fopen(savefile, "wb");
        fwrite(hero, sizeof(herostats), 1, fptr);
        fwrite(&ifinbattle, sizeof(ifinbattle), 1, fptr);
        fwrite(&day, sizeof(day), 1, fptr);
        fwrite(&wavesleft, sizeof(wavesleft), 1, fptr);
        fwrite(&barrierhealth, sizeof(barrierhealth), 1, fptr);
        fclose(fptr);
    }
    else
    {
        fclose(fptr);
        printf("%s\n%s\n", inttext[60], inttext[61]);
        printf("%s\n%s\n", inttext[55], inttext[56]);
        scanf("%d", &temp);
        if(temp==1)
        {
            fopen(savefile, "wb");
            fwrite(hero, sizeof(herostats), 1, fptr);
            fwrite(&ifinbattle, sizeof(ifinbattle), 1, fptr);
            fwrite(&day, sizeof(day), 1, fptr);
            fwrite(&wavesleft, sizeof(wavesleft), 1, fptr);
            fwrite(&barrierhealth, sizeof(barrierhealth), 1, fptr);
            fclose(fptr);
        }
    }
    return;
}

