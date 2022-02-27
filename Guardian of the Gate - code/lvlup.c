#include "herostatistics.h"
#include "lvlup.h"

void levelup(herostats *hero)
{
    hero->experience-=(100*(hero->level)*(hero->level)*(hero->level));
    hero->level+=1;
    printf("%s\n", inttext[42]);
    int temp = 10;
    char loopinput;
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
        default: printf("%s\n", inttext[6]); break;
        }
    }
    hero->resistance=((hero->agility)/5)+((hero->endurance)/10);
    hero->maxhealth=50+(5*(hero->endurance))+(hero->strength);
    hero->maxenergy=20+(hero->intellect*2)+((hero->endurance)/3);
    hero->curenergy=(hero->maxenergy);
    hero->curhealth=(hero->maxhealth);
    if(hero->experience>=(100*(hero->level)*(hero->level)*(hero->level)))
        levelup(hero);
    return;
}

