#include <stdio.h>
#include <stdlib.h>

int main(void){

    int array[5] = {1, 2, 3, 4, 5};
    int *pArray;
    pArray = array;

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n",*(pArray+i));
    }
    

    return 0;
}