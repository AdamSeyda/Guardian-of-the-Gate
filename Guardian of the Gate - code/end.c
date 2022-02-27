#include "herostatistics.h"
#include "end.h"

void gameover(herostats *hero, int day)
{
    printf("\n\n    %s   \n\n", inttext[43]);
    printf("%s%d%s\n", inttext[44], day, inttext[45]);
    printf("%s%d%s\n", inttext[46], hero->level, inttext[47]);
    printf("\n%s\n", inttext[48]);
    char c;
    printf("==>%s\n", inttext[49]);
    scanf(" %c", &c);
    return;
}

void victory(herostats *hero)
{
    printf("\n\n    %s   \n\n", inttext[50]);
    printf("%s\n", inttext[51]);
    printf("%s%d%s\n", inttext[52], hero->level, inttext[53]);
    printf("\n%s\n", inttext[54]);
    char temp;
    printf("==>%s\n", inttext[49]);
    scanf(" %c", &temp);
    return;
}

