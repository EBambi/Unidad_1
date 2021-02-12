#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int *pArray, int size);

int main(void){

    int tam = 0;

    printf("Ingrese el tamaño del arreglo:\n");
    scanf("%d",&tam);

    int array[tam];
    int val=0;

    for (int i = 0; i < tam; i++)
    {
        printf("Ingrese el valor #%d del arreglo:\n",i+1);
        scanf("%d",&array[i]);
    }
    
    printArray(array,tam);

    int p = 0;
    printf("¿Qué posición del arreglo desea cambiar?\n");
    scanf("%d",&p);
    printf("Ingrese el nuevo valor:\n");
    scanf("%d",&val);

    array[p-1] = val;
    printArray(array,tam);

    return 0;
}

void printArray(int *pArray, int size){
    for (int i = 0; i < size; i++)
    {
        printf("#%d - %d\n",i+1,*(pArray+i));
    }
    
}