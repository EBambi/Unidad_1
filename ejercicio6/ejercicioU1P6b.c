#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*#define LITTLE_ENDIAN 0
#define BIG_ENDIAN 1

int machineEndianness() {
    int i = 1;
    char *p = (char *) &i;
if (p[0] == 1) // Lowest address contains the least significant byte
    return LITTLE_ENDIAN;
else
    return BIG_ENDIAN;
}*/

/*struct cdsMusica
{
    char titulo[30];
    char artista[30];
    char genero[20];
    int numCanciones;
    int lanzamiento;
    float precio;
} cd1;

struct point
{
    int x;
    int y;
} pt1, pt2;

struct rect
{
    struct point pt1;
    struct point pt2;
} rect1;*/

/*struct estudiante{
    char Nombre[40];
    int numEstudiante;
    int annoMatricula;
    float nota;
} estud1;*/

const char FILE_NAME[] = "input.txt";

int main() {

    //*************************Ejercicio para saber si es Little Endian o Big Endian
    /*if(machineEndianness())
        printf("Big endian\n");
    else
        printf("Little endian\n");*/
    
    //*************************Ejercicio de la creación de un objeto
    /*struct cdsMusica cd1 = {"Brindo con el alma.","Diomedes Díaz (El cacique)","Vallenato",11,1986,19900};
    printf("El artista %s creó %s en %d \n", cd1.artista, cd1.titulo, cd1.lanzamiento);*/

    //*************************Ejercicio del área de un rectángulo por medio de objetos
    /*struct point pt1 = {2,3};
    struct point pt2 = {4,6};

    struct rect rect1 = {pt1,pt2};
    
    int areaRect=0;
    int base=0;
    int altura=0;

    base = rect1.pt2.x-rect1.pt1.x;
    altura = rect1.pt2.y-rect1.pt1.y;
    areaRect = base*altura;
    printf("El área del rectandulo es %d\n",areaRect);*/

    //*************************Ejercicio actualización datos de un objeto después de presionar la tecla r
    /*struct estudiante estud1 = {"Esteban", 4, 2009, 4.5};
    struct estudiante *ptrEstruct;
    ptrEstruct = &estud1;

    printf("La nota de la variable estud1 es %.2f (con pointer)\n",ptrEstruct->nota);
    printf("La nota de la variable estud1 es %.2f (sin pointer)\n",estud1.nota);
    printf("*******\n");
    printf("El nombre de la variable estud1 es %s (con pointer)\n",ptrEstruct->Nombre);
    printf("El nombre de la variable estud1 es %s (sin pointer)\n",estud1.Nombre);
    printf("*******\n");
    printf("El número de la variable estud1 es %d (con pointer)\n",ptrEstruct->numEstudiante);
    printf("El número de la variable estud1 es %d (sin pointer)\n",estud1.numEstudiante);
    printf("*******\n");
    printf("El año matrícula de la variable estud1 es %d (con pointer)\n",ptrEstruct->annoMatricula);
    printf("El año matrícula de la variable estud1 es %d (sin pointer)\n",estud1.annoMatricula);

    char tmp;
    tmp = getchar();
    if (tmp == 'r')
    {
        printf("Actualización datos\n");
        printf("Ingrese el nombre:\n");
        scanf("%s",estud1.Nombre);
        printf("Ingrese el número:\n");
        scanf("%d",&ptrEstruct->numEstudiante);
        printf("Ingrese el año:\n");
        scanf("%d",&estud1.annoMatricula);
        printf("Ingrese la nota:\n");
        scanf("%2f",&ptrEstruct->nota);
    }
    printf("La nota de la variable estud1 es %.2f (con pointer)\n",ptrEstruct->nota);
    printf("La nota de la variable estud1 es %.2f (sin pointer)\n",estud1.nota);
    printf("*******\n");
    printf("El nombre de la variable estud1 es %s (con pointer)\n",ptrEstruct->Nombre);
    printf("El nombre de la variable estud1 es %s (sin pointer)\n",estud1.Nombre);
    printf("*******\n");
    printf("El número de la variable estud1 es %d (con pointer)\n",ptrEstruct->numEstudiante);
    printf("El número de la variable estud1 es %d (sin pointer)\n",estud1.numEstudiante);
    printf("*******\n");
    printf("El año matrícula de la variable estud1 es %d (con pointer)\n",ptrEstruct->annoMatricula);
    printf("El año matrícula de la variable estud1 es %d (sin pointer)\n",estud1.annoMatricula);*/

    //*************************Todo sobre las funciones de archivos
    /*int count = 0; //Número de caracteres vistos
    FILE *in_file; //Archivo de entrada

    int ch; //Caracter o bandera de EOF de la entrada
    in_file = fopen(FILE_NAME,"r");
    if (in_file == NULL){
        printf("No se puede abrir %s\n", FILE_NAME);
        exit(8);
    }
    while (1)
    {
        ch = fgetc(in_file);
        if (ch == EOF)
            break;
        ++count;
    }
    printf("Número de caracteres en %s es %d\n",FILE_NAME,count);
    fclose(in_file);*/

    

    return 0;
}
