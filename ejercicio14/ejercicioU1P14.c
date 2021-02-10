#include <stdio.h>

int main(void)
{
    char name[40];
    printf("What's your name? ");
    //scanf("%39[^\n]", name);
    scanf("%39[a-z]", name);
    printf("Hello %s!\n", name);
}