#include "herostatistics.h"
#include "enemyfile.h"
#include<stdbool.h>

int waveamountgenerator(int day)
{
    int wavesleft=3+(day/10)+(rand()%5);
    return wavesleft;
}

void newbattle(bool *switchloop, bool *villageloop, bool *battleloop, bool *waveloop, int *wavesleft, herostats *hero, int day)
{
    *switchloop=false;
    *villageloop=false;
    *battleloop=true;
    *waveloop=true;
    *wavesleft=waveamountgenerator(day);
    return;
}

void wavegenerator(int enemies[], int *enemiesleft, int day, herostats *hero)
{
    *enemiesleft=2+(rand()%4)+(rand()%((day/10)+1));
    int temp = 0;
    while(temp<*enemiesleft)
    {
        enemies[(temp*11)+0]=1+(rand()%4);
        switch(enemies[(temp*11)+0]){
        case 1: enemies[(temp*11)+2]=3*(1+(day/3))+(rand()%(1+hero->level+(day/5))); break;
        case 2: enemies[(temp*11)+2]=2*(1+(day/3))+(rand()%(1+hero->level+(day/5))); break;
        case 3: enemies[(temp*11)+2]=5*(1+(day/3))+(rand()%(1+hero->level+(day/5))); break;
        case 4: enemies[(temp*11)+2]=1*(1+(day/3))+(rand()%(1+hero->level+(day/5))); break;
        default: enemies[(temp*11)+2]=0; break;
        }
        switch(enemies[(temp*11)+0]){
        case 1: enemies[(temp*11)+3]=3*(1+(day/3))+(rand()%(1+hero->level+(day/5))); break;
        case 2: enemies[(temp*11)+3]=5*(1+(day/3))+(rand()%(1+hero->level+(day/5))); break;
        case 3: enemies[(temp*11)+3]=3*(1+(day/3))+(rand()%(1+hero->level+(day/5))); break;
        case 4: enemies[(temp*11)+3]=3*(1+(day/3))+(rand()%(1+hero->level+(day/5))); break;
        default: enemies[(temp*11)+3]=0; break;
        }
        switch(enemies[(temp*11)+0]){
        case 1: enemies[(temp*11)+4]=3*(1+(day/3))+(rand()%(1+hero->level+(day/5))); break;
        case 2: enemies[(temp*11)+4]=2*(1+(day/3))+(rand()%(1+hero->level+(day/5))); break;
        case 3: enemies[(temp*11)+4]=1*(1+(day/3))+(rand()%(1+hero->level+(day/5))); break;
        case 4: enemies[(temp*11)+4]=7*(1+(day/3))+(rand()%(1+hero->level+(day/5))); break;
        default: enemies[(temp*11)+4]=0; break;
        }
        switch(enemies[(temp*11)+0]){
        case 1: enemies[(temp*11)+5]=3*(1+(day/3))+(rand()%(1+hero->level+(day/5))); break;
        case 2: enemies[(temp*11)+5]=3*(1+(day/3))+(rand()%(1+hero->level+(day/5))); break;
        case 3: enemies[(temp*11)+5]=4*(1+(day/3))+(rand()%(1+hero->level+(day/5))); break;
        case 4: enemies[(temp*11)+5]=2*(1+(day/3))+(rand()%(1+hero->level+(day/5))); break;
        default: enemies[(temp*11)+0]=0; break;
        }
        enemies[(temp*11)+6]=5+(5*enemies[(temp*11)+5])+(enemies[(temp*11)+2]);
        enemies[(temp*11)+7]=day+(1+(day/5))*enemies[(temp*11)+4]+(enemies[(temp*11)+5]/3);
        enemies[(temp*11)+8]=enemies[(temp*11)+6];
        enemies[(temp*11)+9]=enemies[(temp*11)+7];
        enemies[(temp*11)+10]=(enemies[(temp*11)+3]/5)+(enemies[(temp*11)+5]/10);
        temp+=1;
    }
    return;
}

void enemiestablereset(int enemies[])
{
    int temp=0;
    while(temp<165)
    {
        enemies[temp]=0;
        temp+=1;
    }
    return;
}

