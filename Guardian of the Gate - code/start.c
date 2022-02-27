#include "herostatistics.h"
#include "start.h"
#include<stdio.h>

void instructions()
{
    int temp=0;
    while(temp<15)
    {
        printf("%s\n", instrtext[temp]);
        temp+=1;
    }
    return;
}

void newgame(herostats *hero)
{
    char tempname[7];
    int temp=0;
    char loopinput;
    while(temp<6)
    {
        printf("%s\n", storytext[temp]);
        temp+=1;
    }
    scanf("%s", &tempname);
    temp = 0;
    while(temp<7)
    {
        hero->heroname[temp]=tempname[temp];
        temp+=1;
    }
    printf("%s%s\n", hero->heroname, storytext[6]);
    hero->level = 1;
    hero->experience = 0;
    hero->strength = 5;
    hero->agility = 5;
    hero->intellect = 5;
    hero->endurance = 5;
    printf("%s\n", inttext[15]); //15
    temp = 10;
    while(temp>0)
    {
        printf("%s%d%s%d%s%d%s%d\n", inttext[16], hero->strength, inttext[17], hero->agility, inttext[18], hero->intellect, inttext[19], hero->endurance);
        printf("%s%d%s\n", inttext[20], temp, inttext[21]);
        printf("%s\n%s\n%s\n%s\n", inttext[22], inttext[23], inttext[24], inttext[25]);
        scanf(" %c", &loopinput);
        switch(loopinput){
        case 49: hero->strength+=1; temp-=1; break;
        case 50: hero->agility+=1; temp-=1; break;
        case 51: hero->intellect+=1; temp-=1; break;
        case 52: hero->endurance+=1; temp-=1; break;
        default: printf("%s\n", inttext[6]); break; //6
        }
    }
    hero->resistance=((hero->agility)/5)+((hero->endurance)/10);
    hero->maxhealth=50+(5*(hero->endurance))+(hero->strength);
    hero->maxenergy=20+(hero->intellect*2)+((hero->endurance)/3);
    hero->curenergy=(hero->maxenergy);
    hero->curhealth=(hero->maxhealth);
    return;
}

void loadlanguage(int a)
{
    FILE *fptr;
    char c=0;
    int temp=0, temp1=0, language;
    language=a;
    switch(language)
    {
        case 0:{
        fptr=fopen("interfacepol.txt", "r");
        while(c!=EOF)
        {
            c=getc(fptr);
            if(c==64)
            {
                while(temp<100)
                {
                    inttext[temp1][temp]=0;
                    temp+=1;
                }
                temp1+=1;
                temp=0;
            }
            else
            {
                inttext[temp1][temp]=c;
                temp+=1;
            }
        }
        fclose(fptr);
        c=0;
        temp=0;
        temp1=0;
        fptr=fopen("instrpol.txt", "r");
        while(c!=EOF)
        {
            c=getc(fptr);
            if(c==64)
            {
                while(temp<150)
                {
                    instrtext[temp1][temp]=0;
                    temp+=1;
                }
                temp1+=1;
                temp=0;
            }
            else
            {
                instrtext[temp1][temp]=c;
                temp+=1;
            }
        }
        fclose(fptr);
        c=0;
        temp=0;
        temp1=0;
        fptr=fopen("stpol.txt", "r");
        while(c!=EOF)
        {
            c=getc(fptr);
            if(c==64)
            {
                while(temp<100)
                {
                    storytext[temp1][temp]=0;
                    temp+=1;
                }
                temp1+=1;
                temp=0;
            }
            else
            {
                storytext[temp1][temp]=c;
                temp+=1;
            }
        }
        fclose(fptr);
        return;
        }break;
        case 1:{
        fptr=fopen("interfaceeng.txt", "r");
        while(c!=EOF)
        {
            c=getc(fptr);
            if(c==64)
            {
                while(temp<100)
                {
                    inttext[temp1][temp]=0;
                    temp+=1;
                }
                temp1+=1;
                temp=0;
            }
            else
            {
                inttext[temp1][temp]=c;
                temp+=1;
            }
        }
        fclose(fptr);
        c=0;
        temp=0;
        temp1=0;
        fptr=fopen("instreng.txt", "r");
        while(c!=EOF)
        {
            c=getc(fptr);
            if(c==64)
            {
                while(temp<150)
                {
                    instrtext[temp1][temp]=0;
                    temp+=1;
                }
                temp1+=1;
                temp=0;
            }
            else
            {
                instrtext[temp1][temp]=c;
                temp+=1;
            }
        }
        fclose(fptr);
        c=0;
        temp=0;
        temp1=0;
        fptr=fopen("steng.txt", "r");
        while(c!=EOF)
        {
            c=getc(fptr);
            if(c==64)
            {
                while(temp<100)
                {
                    storytext[temp1][temp]=0;
                    temp+=1;
                }
                temp1+=1;
                temp=0;
            }
            else
            {
                storytext[temp1][temp]=c;
                temp+=1;
            }
        }
        fclose(fptr);
        return;
        }break;
        default: printf("Error! Invalid value received! Couldn't load text!"); return; break;
    }
}

void changelanguage()
{
    FILE *fptr;
    char userinput;
    printf("1 - Polish/Polski\n2 - English/Angielski\n%s\n", inttext[57]);
    scanf(" %c", &userinput);
    switch(userinput)
    {
        case 49:{
        loadlanguage(0);
        fptr=fopen("lang.txt", "w");
        fprintf(fptr, "0");
        fclose(fptr);
        return;
        }break;
        case 50:{
        loadlanguage(1);
        fptr=fopen("lang.txt", "w");
        fprintf(fptr, "1");
        fclose(fptr);
        return;
        }break;
        case 51: return; break;
        default: printf("%s\n", inttext[6]); changelanguage(); break;
    }
}

void loadgame(herostats* hero, int *day, int *wavesleft, int *barrierhealth, int *inbattle)
{
    printf("%s\n%s\n", inttext[62], inttext[63]);
    char stringinput[16], savefile[20];
    scanf("%s", &stringinput);
    sprintf(savefile, "%s.bin", stringinput);
    FILE *fptr;
    fptr=fopen(savefile, "rb");
    if(fptr==NULL)
    {
        printf("%s\n", inttext[64]);
        printf("%s\n", inttext[65]);
        fclose(fptr);
    }
    else
    {
        fread(&(*hero), sizeof(herostats), 1, fptr);
        fread(&inbattle, sizeof(inbattle), 1, fptr);
        fread(&day, sizeof(day), 1, fptr);
        fread(&wavesleft, sizeof(wavesleft), 1, fptr);
        fread(&barrierhealth, sizeof(barrierhealth), 1, fptr);
        fclose(fptr);
    }
    return;
}

void setbools(int inbattle, bool *switchloop, bool *villageloop, bool *battleloop, bool *waveloop, bool *breakloop)
{
    if(inbattle==1)
    {
        *waveloop=false;
        *breakloop=false;
        (*switchloop)=waveloop;
        (*villageloop)=true;
        (*battleloop)=false;
    }
    else if(inbattle==0)
    {
        *switchloop=false;
        *villageloop=false;
        *battleloop=true;
        *waveloop=false;
        *breakloop=true;
    }
    else
        printf("%s\n", inttext[66]);
    return;
}
