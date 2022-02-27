#include "herostatistics.h"
#include "battlefile.h"

int heroheal(herostats *hero)
{
    if(hero->curenergy<10+(hero->intellect/4))
    {
        printf("Not enough mana!\n");
        return 1;
    }
    hero->curenergy-=10+(hero->intellect/4);
    hero->curhealth+=hero->intellect;
    if(hero->curhealth>hero->maxhealth)
        hero->curhealth=hero->maxhealth;
    return 0;
}

void heroturn(int enemies[], herostats *hero)
{
    char userinput;
    printf("%s%d%s%d%s\n", inttext[38], hero->curhealth, inttext[67], hero->curenergy, inttext[39]);
    printf("%s\n%s%d)\n%s\n", inttext[40], inttext[41],(10+(hero->intellect/4)),  inttext[68]);
    scanf(" %c", &userinput);
    switch(userinput){
    case 49: heroattack(hero, enemies); break;
    case 50:
        {
            if(heroheal(hero)==1)
                heroturn(enemies, hero);
            break;
        }
    case 51: break;
    default: heroturn(enemies, hero); break;
    }
    return;
}

void enemyturn(int enemies[], int maxindeks, herostats *hero)
{
    int temp=0, healcheck=0, damage;
    switch(enemies[11*maxindeks])
    {
        case 1:
            {
                damage=calculatedamage(enemies, maxindeks);
                if(damage<=0)
                    printf("%s\n", inttext[71]);
                else
                {
                    hero->curhealth-=damage;
                    printf("%s%d%s\n", inttext[36], damage, inttext[37]);
                }
                break;
            }
        case 2:
            {
                damage=calculatedamage(enemies, maxindeks);
                if(damage<=0)
                    printf("%s\n", inttext[71]);
                else
                {
                    hero->curhealth-=damage;
                    printf("%s%d%s\n", inttext[36], damage, inttext[37]);
                }
                break;
            }
        case 3:
            {
                damage=calculatedamage(enemies, maxindeks);
                if(damage<=0)
                    printf("%s\n", inttext[71]);
                else
                {
                    hero->curhealth-=damage;
                    printf("%s%d%s\n", inttext[36], damage, inttext[37]);
                }
                break;
            }
        case 4:
            {
                while(temp<15)
                {
                    if(enemies[11*maxindeks+9]>enemies[11*maxindeks+4]&&enemies[temp*11+8]>0&&enemies[temp*11+8]<(enemies[temp*11+6]/2))
                    {
                        enemies[temp*11+8]+=enemies[11*maxindeks+4];
                        if(enemies[temp*11+8]>enemies[temp*11+6])
                            enemies[temp*11+8]=enemies[temp*11+6];
                        temp=15;
                        healcheck=1;
                    }
                    temp+=1;
                }
                if(healcheck!=1)
                {
                    damage=calculatedamage(enemies, maxindeks);
                    if(damage<=0)
                        printf("%s\n", inttext[71]);
                    else
                    {
                        hero->curhealth-=damage;
                        printf("%s%d%s\n", inttext[36], damage, inttext[37]);
                    }
                }
                break;
            }
        default: break;
    }
    return;
}

void dideveryonemove(int whomoved[])
{
    int temp=0, yes=1;
    while(temp<16&&yes==1)
    {
        if(whomoved[temp]==0)
            yes=0;
        temp+=1;
    }
    if(yes==1)
    {
        temp=0;
        while(temp<16)
        {
            whomoved[temp]=0;
            temp+=1;
        }
    }
    return;
}

int battle(herostats *hero, int enemies[], int livetargets[])
{
    int whomoved[16];
    int temp=0;
    while(temp<16)
    {
        whomoved[temp]=0;
        temp+=1;
    }
    int maxindeks, max=-1;
    while(whosalive(enemies, livetargets)>0&&(hero->curhealth)>0)
    {
        dideveryonemove(whomoved);
        temp=0;
        max=-1;
        while(temp<15)
        {
            if(whomoved[temp]==0&&enemies[(11*temp)+3]>max)
            {
                max=enemies[11*temp+3];
                maxindeks=temp;
            }
            temp+=1;
        }
        if(whomoved[15]==0)
        {
            if(hero->agility>max)
                {
                    heroturn(enemies, hero);
                    whomoved[15]=1;
                }
            else
                {
                    if(enemies[(11*maxindeks)+8]>0)
                        enemyturn(enemies, maxindeks, hero);
                    whomoved[maxindeks]=1;
                }
        }
        else
        {
            if(enemies[(11*maxindeks)+8]>0)
                enemyturn(enemies, maxindeks, hero);
            whomoved[maxindeks]=1;
        }
    }
    return whosalive(enemies, livetargets);
}

int whosalive(int enemies[], int livetargets[])
{
    int temp=0, theliving=0;
    while(temp<15)
    {
        if(enemies[(temp*11)+8]>0)
        {
            livetargets[temp]=1;
            theliving+=1;
        }
        else
            livetargets[temp]=0;
        temp+=1;
    }
    return theliving;
}

void validlivetargets(int enemies[], int targets[])
{
    int temp = 0;
    while(temp<15)
    {
        if(enemies[(temp*11)+8]>0)
        {
            switch(enemies[temp*11]){
                case 1: printf("%d%s\n", temp, inttext[31]); break;
                case 2: printf("%d%s\n", temp, inttext[32]); break;
                case 3: printf("%d%s\n", temp, inttext[33]); break;
                case 4: printf("%d%s\n", temp, inttext[34]); break;
                default: printf("%d%s\n", temp, inttext[35]); break;
            }
            targets[temp]=1;
        }
        else
            targets[temp]=0;
        temp+=1;
    }
    return;
}

void heroattack(herostats *hero, int enemies[])
{
    int temp=0, temp1=0, critroll=1;
    int targets[15];
    char userinput;
    validlivetargets(enemies, targets);
    //The function checks which enemies are alive so that the player can only attack valid targets
    printf("%s\n", inttext[29]);
    scanf(" %c", &userinput);
    userinput-=48;
    if(targets[userinput]==1)
    {
        critroll+=(rand()%20)+(rand()%((hero->agility/8)+1));
        if(critroll>20)
            critroll=20;
        if(critroll==1)
        {
            printf("%s\n", inttext[70]);
            return;
        }
        else if(critroll==20)
        {
            enemies[(userinput*11)+8]-=(hero->strength*hero->level)+(rand()%(1+hero->strength*hero->level));
        }
        else
        {
            enemies[(userinput*11)+8]-=((hero->strength*hero->level)/2)+((rand()%(1+hero->strength*hero->level))/2);
        }
        enemies[(userinput*11)+8]-=hero->strength*hero->level;
        if(enemies[(userinput*11)+8]<0)
            enemies[(userinput*11)+8]=0;
        if(enemies[(userinput*11)+8]<=0)
        {
            hero->experience+=enemies[(userinput*11)+2]+enemies[(userinput*11)+3]+enemies[(userinput*11)+4]+enemies[(userinput*11)+5];
            printf("%s\n", inttext[69]);
        }
            hero->experience+=enemies[(userinput*11)+2]+enemies[(userinput*11)+3]+enemies[(userinput*11)+4]+enemies[(userinput*11)+5];
        //The amount of experience hero gets for defeating an enemy is equal to strength, agility, intelect and endurance of the enemy combined
    }
    else
    {
        printf("%s\n", inttext[30]);
        heroattack(hero, enemies);
    }
    return;
}

int calculatedamage(int enemies[], int maxindeks)
{
    int critroll=1, damage=0;
    critroll+=(rand()%20)+(rand()%(1+(enemies[maxindeks*11+3]/8)));
    if(critroll>20)
        critroll=20;
    if(critroll==1)
        return 0;
    if(critroll==20)
        return enemies[maxindeks*11+2]+rand()%(1+enemies[maxindeks*11+2]);
    else
        return (enemies[maxindeks*11+2]/2)+rand()%(1+(enemies[maxindeks*11+2]/2));
}
