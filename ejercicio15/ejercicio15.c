#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[40];
    printf("What's your name? ");
    if (fgets(name, 40, stdin))
    {
        name[strcspn(name, "\n")] = 0; //Saca el ENTER del flujo y así queda el ! al lado del string
        printf("Hello %s!\n", name);
    }
}