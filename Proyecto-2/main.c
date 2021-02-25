#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct estudiante
{
    int cedula;
    char nombre[30];
    int semestre;
};

struct baseDatos
{
    int size;
    char nombre[20];
    struct estudiante* ptrRegistros;
};


struct estudiante *bufferDB;
struct baseDatos *bufferBaseDatos;
struct baseDatos *ptrBaseActiva;
FILE *inFile, *outFile;
int ch, numRegis = 0;
char linea[50];

void mkdb_nombre_tamanno(char nombre[20], int cantRegis, int i);

void loadbl_nombre(char fileName[30]);

void savedb_nombre(char fileName[30]);

void readall(struct estudiante *buffer);

int readSize(struct estudiante *buffer);

void mkreg_cedula_nombre_semestre(int cedulaNR, char nombreNR[30], int semestreNR);

void readreg_cedula(int cedulaBuscar);

void lsdbs();

void gdb(struct baseDatos *buffer);

void sdb_nombre(char nombre[20]);

void svdb();

void radb();

void rsdb();

void mreg_cedula_nombre_semestre(int cedulaN, char nombreN[20], int semestre);

void rr_cedula(int cedulaN);

void exitD(char fileName[30]);

int main(void){

    char nombreBaseDatos[30], nombreArchivo[30], nombreNuevo[30], comando[10], c, nombreDBActiva[20];
    int cedulaNuevo, semestreNuevo, cedulaBusc, dec=0, numDB=0;

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
            mkdb_nombre_tamanno(nombreBaseDatos, numRegis, numDB);
            numDB++;
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
        else if (strcmp(comando,"lsdbs") == 0)
        {
            lsdbs();
        }
        else if (strcmp(comando,"gdb") == 0)
        {
            gdb(ptrBaseActiva);
        }
        else if (strcmp(comando,"sdb") == 0)
        {
            printf("Ingrese el nombre de la base de datos que desea cambiar:\n");
            scanf("%s",nombreDBActiva);
            sdb_nombre(nombreDBActiva);
        }
        else if (strcmp(comando,"svdb") == 0)
        {
            svdb();
            printf("Se guardó la base de datos %s en un archivo\n",ptrBaseActiva->nombre);
        }
        else if (strcmp(comando,"radb") == 0)
        {
            radb();
        }
        else if (strcmp(comando,"rsdb") == 0)
        {
            rsdb();
        }
        else if (strcmp(comando,"mreg") == 0)
        {
            printf("Ingrese la cédula del nuevo registro:\n");
            scanf("%d",&cedulaNuevo);
            printf("Ingrese el nombre del nuevo registro:\n");
            scanf("%s",nombreNuevo);
            printf("Ingrese el semestre del nuevo registro:\n");
            scanf("%d",&semestreNuevo);
            mreg_cedula_nombre_semestre(cedulaNuevo, nombreNuevo, semestreNuevo);
        }
        else if (strcmp(comando,"rr") == 0)
        {
            printf("Ingrese la cédula del estudiante que busca:\n");
            scanf("%d",&cedulaBusc);
            rr_cedula(cedulaBusc);
        }
        
        else if (strcmp(comando,"exit") == 0)
        {
            printf("¿Desea guardar la base de datos antes de salir?\n(Sí = 1 --- No = 2)\n");
            scanf("%d", &dec);
            if (dec == 1)
            {
                printf("Ingrese el nombre del archivo de salida:\n");
                scanf("%s", nombreArchivo);
                savedb_nombre(nombreArchivo);
            }
            else break;
        }

    } while (dec != 1 && dec != 2);

    return 0;
}

void mkdb_nombre_tamanno(char nombre[20], int cantRegis, int i){ 
    if (i == 0){
        bufferDB = malloc(sizeof(struct estudiante)*cantRegis);
        bufferBaseDatos = malloc(sizeof(struct baseDatos)*10);
        bufferBaseDatos->size = cantRegis;
        strcpy(bufferBaseDatos->nombre,nombre);
        bufferBaseDatos->ptrRegistros = bufferDB;
        ptrBaseActiva = bufferBaseDatos;
        printf("%s fue creada correctamente\n", (bufferBaseDatos+i)->nombre);
    }
    else{
        bufferDB = malloc(sizeof(struct estudiante)*cantRegis);
        (bufferBaseDatos+i)->size = cantRegis;
        strcpy((bufferBaseDatos+i)->nombre,nombre);
        (bufferBaseDatos+i)->ptrRegistros = bufferDB;
        ptrBaseActiva = (bufferBaseDatos+i);
        printf("%s fue creada correctamente\n", (bufferBaseDatos+i)->nombre);        
    }
}

void loadbl_nombre(char fileName[30]){

    int contLinea = 0;

    inFile = fopen(fileName, "r");
    if (inFile == NULL){
        printf("No se puede abrir %s\n", fileName);
        exit(8);
    }
    while (!feof(inFile))
    {
        if (ch != EOF)
        {
            fscanf(inFile, "%d %s %d", &((ptrBaseActiva->ptrRegistros)+contLinea)->cedula, ((ptrBaseActiva->ptrRegistros)+contLinea)->nombre, &((ptrBaseActiva->ptrRegistros)+contLinea)->semestre);
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

void lsdbs(){
    int i = 0;
    printf("---Bases Cargadas en Memoria---\n");
    while ((bufferBaseDatos+i)->size != 0)
    {
        printf("%s\n",(bufferBaseDatos+i)->nombre);
        i++;
    }
}

void gdb(struct baseDatos *buffer){
    int cantFull = 0, cont = 0;
    printf("---Base de Datos Activa---\n");
    printf("Nombre: %s\nTamaño: %d\n",buffer->nombre,buffer->size);
    while (((buffer->ptrRegistros)+cantFull)->cedula != 0)
    {
        cantFull++;
    }
    printf("Registros Disponibles: %d\n",buffer->size - cantFull);
}

void sdb_nombre(char nombre[20]){
    int i = 0;
    while ((bufferBaseDatos+i)->size != 0)
    {
        if (strcmp((bufferBaseDatos+i)->nombre, nombre) == 0){
            ptrBaseActiva = (bufferBaseDatos+i);
            printf("La base de datos activa ahora es: %s\n",ptrBaseActiva->nombre);
        }
        i++;
    }    
}

void svdb(){

    char fileName[20];
    strcpy(fileName,ptrBaseActiva->nombre);
    outFile = fopen(fileName,"w");
    for (int i = 0; i < ptrBaseActiva->size; i++)
    {
        fprintf(outFile, "%d %s %d\n", (bufferDB+i)->cedula, (bufferDB+i)->nombre, (bufferDB+i)->semestre);
    }

    fclose(outFile);
}

void radb(){
    for (int i = 0; i < ptrBaseActiva->size; i++)
    {
        printf("%s %d %d\n", ((ptrBaseActiva->ptrRegistros)+i)->nombre, ((ptrBaseActiva->ptrRegistros)+i)->cedula, ((ptrBaseActiva->ptrRegistros)+i)->semestre);
    }
}

void rsdb(){
    printf("La cantidad de registros es %d\n",ptrBaseActiva->size);
}

void mreg_cedula_nombre_semestre(int cedulaN, char nombreN[20], int semestre){
    for (int i = 0; i < ptrBaseActiva->size; i++)
    {
        if(((ptrBaseActiva->ptrRegistros)+i)->cedula == 0){
            ((ptrBaseActiva->ptrRegistros)+i)->cedula = cedulaN;
            strcpy(((ptrBaseActiva->ptrRegistros)+i)->nombre,nombreN);
            ((ptrBaseActiva->ptrRegistros)+i)->semestre = semestre;
            break;
        }
    }
}

void rr_cedula(int cedulaN){
    for (int i = 0; i < ptrBaseActiva->size; i++)
    {
        if(((ptrBaseActiva->ptrRegistros)+i)->cedula == cedulaN){
            printf("Nombre: %s\nCédula: %d\nSemestre: %d\n",((ptrBaseActiva->ptrRegistros)+i)->nombre, ((ptrBaseActiva->ptrRegistros)+i)->cedula, ((ptrBaseActiva->ptrRegistros)+i)->semestre);
            break;
        }
    }
}

void exitD(char fileName[30]){
    savedb_nombre(fileName);
}

