#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

uint8_t arrayCommon(int32_t* arr1, int32_t arr1Size,int32_t* arr2, int32_t arr2Size, int32_t* arrRes, int32_t arrResSize);


int main(void){

    int tam1 = 0;
    int tam2 = 0;

    printf("Ingrese el tamaño del arreglo 1:\n");
    scanf("%d",&tam1);

    int array1[tam1];
    int *pArray1=array1;

    for (int i = 0; i < tam1; i++)
    {
        printf("Ingrese el valor #%d del arreglo 1:\n",i+1);
        scanf("%d",&array1[i]);
    }
    
    printf("Ingrese el tamaño del arreglo 2:\n");
    scanf("%d",&tam2);

    int array2[tam2];
    int *pArray2=array2;    

    for (int i = 0; i < tam2; i++)
    {
        printf("Ingrese el valor #%d del arreglo 1:\n",i+1);
        scanf("%d",&array2[i]);
    }

    int tamR = 2;
    int arrayResultado[tamR];
    int *pArrayR=arrayResultado;

    printf("La cantidad de comunes es: %d\n",arrayCommon(pArray1,tam1,pArray2,tam2,pArrayR,tamR));

    return 0;
}

uint8_t arrayCommon(int32_t* arr1, int32_t arr1Size,int32_t* arr2, int32_t arr2Size, int32_t* arrRes, int32_t arrResSize){
    
    int comun = 0, pos = 0;
    int arrCom[arr1Size];

    for (int i = 0; i < arr1Size; i++)
    {
        for (int j = 0; j < arr2Size; j++)
        {
            if (*(arr1+i) = *(arr2+j))
            {
                arrCom[i] = *(arr1+i);
                comun++;
            }
            else{
                *(arrRes+i) = *(arr1+i);
                *(arrRes+i+1) = *(arr2+j);
                pos+=2;
            }   
        }
    }

    for (int i = pos; i < arrResSize; i++)
    {
        arrCom[i] = *(arrRes+i);
    }
    return comun;
}
