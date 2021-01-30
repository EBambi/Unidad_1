#include <stdio.h>
#include <stdlib.h>

void printArr(int *parr, int arrSize);
void printArr2(int arr[], int arrSize);

int main(void){

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    //Imprimir los valores del array
    //En tiempo de compilacion yo puedo saber el tamaño del arreglo (El Sizeof solo es en tiempo de compilación)

    int arrSizeBytes = sizeof(arr);
    int intSizeBytes = sizeof(int);

    int arrNumElements = arrSizeBytes/intSizeBytes;

    printArr(arr, arrNumElements);
    printArr2(arr, arrNumElements);

    return EXIT_SUCCESS;
}

void printArr(int *parr, int arrSize){
    for(int i = 0; i < arrSize; i++){
        printf("arr[%d]: %d\n", i, *(parr + i));
        //printf("arr[%d]: %d\n", i, parr[i]);
    }
}

void printArr2(int arr[], int arrSize){
    for(int i = 0; i < arrSize; i++){
        //printf("arr[%d]: %d\n", i, *(parr + i));
        printf("arr[%d]: %d\n", i, arr[i]);
    }
}