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

void mkdb_nombre_tamanno(char nombre[20], int cantRegis);

int main(void){

    char nombreBaseDatos[30];
    int numRegis = 0;

    printf("Ingresar el nombre de la base de datos:\n");
    scanf("%s",nombreBaseDatos);
    printf("Ingrese la cantidad de registros de la base de datos:\n");
    scanf("%d",&numRegis);
    mkdb_nombre_tamanno(nombreBaseDatos,numRegis);
    printf("La B.D. %s se creó correctamente.\n",nombreBaseDatos);

    return 0;
}

void mkdb_nombre_tamanno(char nombre[20], int cantRegis){
    char nombreDB[20];
    nombreDB[20] = nombre[20];
    bufferDB = malloc(sizeof(struct estudiante)*cantRegis);
}