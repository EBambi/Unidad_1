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
FILE *inFile, *outFile;
int ch, numRegis = 0;
char linea[50];

void mkdb_nombre_tamanno(char nombre[20], int cantRegis);

void loadbl_nombre(char fileName[30]);

void savedb_nombre(char fileName[30]);

void readall(struct estudiante *buffer);

int readSize(struct estudiante *buffer);

void mkreg_cedula_nombre_semestre(int cedulaNR, char nombreNR[30], int semestreNR);

void readreg_cedula(int cedulaBuscar);

void exitD(char fileName[30]);

int main(void){

    char nombreBaseDatos[30], nombreArchivo[30], nombreNuevo[30], comando[10], c;
    int cedulaNuevo, semestreNuevo, cedulaBusc, dec=0;

    do
    {
        printf("-------Terminal-------\n");
        printf("Ingrese un comando válido:\n");
        scanf("%s",comando);
        while ( (c = getchar()) != '\n' && c != EOF ) { }
        if (strcmp(comando,"mkdb") == 0)
        {
            printf("Ingresar el nombre de la base de datos:\n");
            scanf("%s", nombreBaseDatos);
            printf("Ingrese la cantidad de registros de la base de datos:\n");
            scanf("%d", &numRegis);
            mkdb_nombre_tamanno(nombreBaseDatos, numRegis);
            printf("La B.D. %s se creó correctamente.\n", nombreBaseDatos);
        }
        else if (strcmp(comando,"loaddb") == 0)
        {
            printf("Ingrese el nombre del archivo:\n");
            scanf("%s", nombreArchivo);
            loadbl_nombre(nombreArchivo);
            printf("El archivo fue cargado correctamente\n");
        }
        else if (strcmp(comando,"savedb") == 0)
        {
            printf("Ingrese el nombre del archivo de salida:\n");
            scanf("%s", nombreArchivo);
            savedb_nombre(nombreArchivo);
            printf("El archivo fue guardado correctamente\n");
        }
        else if (strcmp(comando,"readall") == 0)
        {
            printf("-----------------------\n");
            readall(bufferDB);
            printf("-----------------------\n");
        }
        else if (strcmp(comando,"readsize") == 0)
        {
            printf("%d\n",readSize(bufferDB));
        }
        else if (strcmp(comando,"mkreg") == 0)
        {
            printf("Ingrese la cédula del nuevo registro:\n");
            scanf("%d",&cedulaNuevo);
            printf("Ingrese el nombre del nuevo registro:\n");
            scanf("%s",nombreNuevo);
            printf("Ingrese el semestre del nuevo registro:\n");
            scanf("%d",&semestreNuevo);
            mkreg_cedula_nombre_semestre(cedulaNuevo, nombreNuevo, semestreNuevo);
        }
        else if (strcmp(comando,"readreg") == 0)
        {
            printf("Ingrese la cédula del estudiante que busca:\n");
            scanf("%d",&cedulaBusc);
            readreg_cedula(cedulaBusc);
        }
        else if (strcmp(comando,"exit") == 0)
        {
            printf("¿Desea guardar la base de datos antes de salir?\n(Sí = 1 --- No = 2)\n");
            scanf("%d", &dec);
            if (dec == 1)
            {
                printf("Ingrese el nombre del archivo de salida:\n");
                scanf("%s", nombreArchivo);
                exitD(nombreArchivo);
            }
            else break;
        }

    } while (dec != 1 && dec != 2);

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
            //struct estudiante est = {cedulaLinea, nombreLinea[30], semestreLinea};
            contLinea++;
        }
    }
    fclose(inFile);
}

void savedb_nombre(char fileName[30]){

    outFile = fopen(fileName,"w");
    for (int i = 0; i < numRegis; i++)
    {
        fprintf(outFile, "%d %s %d\n", (bufferDB+i)->cedula, (bufferDB+i)->nombre, (bufferDB+i)->semestre);
    }

    fclose(outFile);
}

void readall(struct estudiante *buffer){

    int cont = 0;

    while ((buffer+cont)->cedula != 0)
    {
        printf("%d %s %d\n", (buffer+cont)->cedula, (buffer+cont)->nombre, (buffer+cont)->semestre);
        cont ++;
    }

    /*for (int i = 0; i < numRegis; i++)
    {
        printf("%d %s %d\n", (buffer+i)->cedula, (buffer+i)->nombre, (buffer+i)->semestre);        
    }*/

}

int readSize(struct estudiante *buffer){

    int cont = 0;

    while ((buffer+cont)->cedula != 0)
    {
        cont ++;
    }
    return cont;
}

void mkreg_cedula_nombre_semestre(int cedulaNR, char nombreNR[30], int semestreNR){

    for (int i = 0; i < numRegis; i++)
    {
        if ((bufferDB+i)->cedula == 0)
        {
            (bufferDB+i)->cedula = cedulaNR;
            strcpy((bufferDB+i)->nombre,nombreNR);
            (bufferDB+i)->semestre = semestreNR;
            break;
        }
    }
    //buffer = realloc(bufferDB,sizeof(struct estudiante)*numRegis);
}

void readreg_cedula(int cedulaBuscar){

    char nombre[30];

    for (int i = 0; i < numRegis; i++)
    {
        if ((bufferDB+i)->cedula == cedulaBuscar)
        {
            printf("La cédula: %d pertenece a el estudiante %s. semestre: %d\n", (bufferDB+i)->cedula, (bufferDB+i)->nombre, (bufferDB+i)->semestre);
        }
    }
}

void exitD(char fileName[30]){

    savedb_nombre(fileName);

}
