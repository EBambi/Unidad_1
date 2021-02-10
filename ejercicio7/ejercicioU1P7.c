#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

    int num;
    char key;
    printf("Prueba a scanf. Ingrese el numero 325 y presione ENTER:\n");
    scanf("%d",&num);
    scanf("%c",&key); //Saca del flujo el ENTER
    printf("Ingrese cualquier tecla para terminar y presione ENTER:\n");
    scanf("%c",&key);   

    return 0;
}