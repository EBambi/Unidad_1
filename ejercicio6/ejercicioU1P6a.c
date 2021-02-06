#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*void swap(int *d1, int *d2);
int x;
int y;

void f1(int ,int *,int *);

int prom(int A[]);

char nombres[3][20] = {"Fulano", "Mengano", "Perano"};*/

char (*bufferNombre)[20];
float *bufferNota;
int *bufferCredito; 

int main(void){

    /*char nombres[3][20] = {"Fulano", "Mengano", "Perano"};

    char i;
    char *a;
    char (*b)[20];

    //¿Qué es nombres? La dirección de memoria del primer elemento del arreglo
    //que es un arreglo de 20 chars. El tipo del primer elemento es char(*)[20]

    a = (char *)nombres; */
    //No compatibles, es lo mismo pero uno lo toma coma vector de chars y el otro solo como chars
    //Por eso necesitamos un cast para que tome el vector como solo chars

    //*******************************************************************************************************

    /*int var1 = 5;
    int var2 = 11;
    int *pvar1;
    int *pvar2;

    pvar2 = &var2;
    printf("La dirección de %d es: %d\n", var2, pvar2);

    pvar1 = &var1;
    *pvar1 = 4;
    printf("\nSe cambió el valor por su pointer: %d\n",var1);*/

    /*int x = 1;
    int *px;

    px=&x;
    printf("La dirección de x=%d es:%d\n ",x, px);
    px=px+1;
    *px=5;
    printf("La dirección de x=%d es:%d\n ",x, px);*/

    /*int a,b=3,c=8,d;
    int *p1=&a,*p2,*p3=&c;
    *p1=2;
    p2=p3;
    *p2=*p1-b;
    d=(*p2)*(*p1);
    p3=&d;
    b=a+b+c;
    printf("Valor de a=%d, b=%d, c=%d, d=%d\n",a,b,c,d);*/

    /*x=1;
    y=2;
    int *p = &y;
    printf("Valor de x=%d y y=%d\n",x,y);
    swap(&x,p);
    printf("Valor de x=%d y y=%d\n",x,y);*/

    /*int d1=3, d2=1, d3=4;
    printf("d1=%d, d2=%d, d3=%d\n",d1,d2,d3);
    f1(--d2,&d3,&d1);
    printf("d1=%d, d2=%d, d3=%d\n",d1,d2,d3);*/

    /*int vec[4] = {1, 2, 3, 4};
    int a = vec[0];
    printf("Valor a = %d\n", a);
    a = *(vec + 1);
    int b = *vec + 1;
    printf("Valor a = %d, b = %d\n", a, b);*/

    /*int A[6] = {2,3,1,0,9,6};
    int *ptr1;
    int *ptr2=&A[5];
    ptr1 = A;
    ptr1 += 2;
    *ptr1 = 5;
    ptr2--;
    *ptr2=*ptr1+*(ptr2-1)+*(ptr2+1);
    for (int i = 0; i < 6; i++)
    {
        printf("Valor = %d\n",A[i]);
    }*/
    
    /*int A[100];
    printf("El promedio es=%d\n",prom(A));*/

    /*char i;
    char *a;
    char (*b)[20];

    a = (char *)nombres;
    printf("El nombres es %s\n",a);

    b = (char (*)[20])nombres[0];
    for (i = 0; i < 3; i++)
    {
        printf("El nombre[%d] es %s\n",i,(char *)(b+i));
    }*/

    /*char *buffer;
    char *string1 = "Hola";
    buffer = malloc(sizeof(char)*30);
    strcpy(buffer, string1);
    strcat(buffer, " Mundo.");
    puts(buffer);
    free(buffer);*/

    
    int numMaterias=0;
    float promedio=0;
    int cantCreditos=0;

    printf("Ingrese la cantidad de materias que está viendo\n");
    scanf("%d", &numMaterias);
    
    bufferNombre = (char (*)[20])malloc(sizeof(char[20])*numMaterias);
    bufferNota = (float *)malloc(sizeof(float)*numMaterias);
    bufferCredito = (int *)malloc(sizeof(int)*numMaterias);

    for (int i = 0; i < numMaterias; i++)
    {
        printf("Ingrese el nombre de la materia #%d (Sin Espacios): \n", i+1);
        scanf("%s", (char *)(bufferNombre+i));
        printf("Ingrese la nota final de la materia #%d: \n", i+1);
        scanf("%f", (bufferNota+i));
        printf("Ingrese la cantidad de créditos de la materia #%d: \n", i+1);
        scanf("%d", (bufferCredito+i));
    }
    printf("Materia-Nota-Créditos\n");
    for (int i = 0; i < numMaterias; i++)
    {
        printf("%s---%.2f---%d \n",(char *)(bufferNombre+i),*(bufferNota+i),*(bufferCredito+i));
        promedio = promedio + *(bufferNota+i);
        cantCreditos = cantCreditos + *(bufferCredito+i);
    }

    printf("El promedio fue de %.2f\n",(promedio/numMaterias));
    printf("La cantidad de créditos fue de %d\n",cantCreditos);

    free(bufferNombre);
    free(bufferNota);
    free(bufferCredito);

    return EXIT_SUCCESS;
}

//Se pasan en la pila
/*void swap(int *d1, int *d2){
    int temp;
    temp = *d1;
    *d1 = *d2;
    *d2 = temp;
}*/

/*void f1(int x, int *y, int *z){
    *y= x+*z;
    *z= --(*y);
    x= *y-*z;
}*/

/*int prom(int A[]){
    int ale;
    int sol=0;
    for (int i = 0; i < 100; i++)
    {
        ale = rand()%50;
        A[i] = ale;
        sol = sol + A[i];
        //printf("%d\n",A[i]);
    }
    sol = sol/100;
    return sol;
}*/