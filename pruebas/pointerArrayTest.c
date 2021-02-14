#include <stdio.h>
#include <stdlib.h>

int main(void){

    int array[5] = {1, 2, 3, 4, 5};
    int array2[6] = {3, 5, 1, 8, 7, 6};
    int* pArray;
    int* pArray2;
    pArray = array;
    pArray2 = array2;

    for (int i = 0; i < 6; i++)
    {
        printf("%d %d\n",*(pArray+i),*(pArray2+i));
        if (*(pArray+i) == *(pArray2+i)) //COMPARA CON 2 == CUANDO ES CON POINTERS ¡HP VIDA!
        {
            printf("Valor igual\n");
        }
        else
            printf("Valor no igual");
        
    }
    

    return 0;
}