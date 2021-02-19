#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct estudiante
{
    int cedula;
    char nombre[30];
    int semestre;
};

struct estudiante *bufferDB;
FILE *inFile;
int ch;
char linea[50];

void mkdb_nombre_tamanno(char nombre[20], int cantRegis);

void loadbl_nombre(char fileName[30]);

int main(void){

    char nombreBaseDatos[30], nombreArchivo[30];
    int numRegis = 0;

    printf("Ingresar el nombre de la base de datos:\n");
    scanf("%s", nombreBaseDatos);
    printf("Ingrese la cantidad de registros de la base de datos:\n");
    scanf("%d", &numRegis);
    mkdb_nombre_tamanno(nombreBaseDatos, numRegis);
    printf("La B.D. %s se creó correctamente.\n", nombreBaseDatos);

    printf("Ingrese el nombre del archivo:\n");
    scanf("%s", nombreArchivo);
    loadbl_nombre(nombreArchivo);

    /*for (int i = 0; i < numRegis; i++)
    {
        printf("%d - %s - %d\n", (bufferDB+i)->cedula, (bufferDB+i)->nombre, (bufferDB+i)->semestre);
    }*/
    

    return 0;
}

void mkdb_nombre_tamanno(char nombre[20], int cantRegis){
    char nombreDB[20];
    nombreDB[20] = nombre[20];
    bufferDB = malloc(sizeof(struct estudiante)*cantRegis);
}

void loadbl_nombre(char fileName[30]){

    int cedulaLinea;
    char nombreLinea[30];
    int semestreLinea, contLinea = 0;

    inFile = fopen(fileName, "r");
    if (inFile == NULL){
        printf("No se puede abrir %s\n", fileName);
        exit(8);
    }
    while (!feof(inFile))
    {
        if (ch != EOF)
        {
            fscanf(inFile, "%d %s %d", &(bufferDB+contLinea)->cedula, (bufferDB+contLinea)->nombre, &(bufferDB+contLinea)->semestre);
            //printf("-%d\n-%s\n-%d\n", cedulaLinea, nombreLinea, semestreLinea);
            struct estudiante est = {cedulaLinea, nombreLinea[30], semestreLinea};
            contLinea++;
        }
    }
    
}