#include <stdio.h>
#include <stdlib.h>

int main(void){

    char nombres[3][20] = {"Fulano", "Mengano", "Perano"};

    char i;
    char *a;
    char (*b)[20];

    //¿Qué es nombres? La dirección de memoria del primer elemento del arreglo
    //que es un arreglo de 20 chars. El tipo del primer elemento es char(*)[20]

    a = (char *)nombres; 
    //No compatibles, es lo mismo pero uno lo toma coma vector de chars y el otro solo como chars
    //Por eso necesitamos un cast para que tome el vector como solo chars

    return EXIT_SUCCESS;
}