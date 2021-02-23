#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "arma.h"

typedef struct
{
    char* nombre;
    struct ar15* arma;
} jugador;

jugador* jugadorNuevo(){
    return malloc(sizeof(jugador*));
}

void createJ(jugador* j, const char* nombre){
    j->nombre = malloc((strlen(nombre)+1)*sizeof(char));
    strcpy(j->nombre,nombre);
    j->arma = NULL;
}

void destroyJ(jugador* j){
    free(j->nombre);
    printf("Jugador muerto\n");
}

void pikUpA(jugador* j, struct ar15* g){
    j->arma = g;
    printf("Arma recogida\n");
}

void shootOneJ(jugador* j){
    if (j->arma)
    {
        shootOne(j->arma);
    }
    else{
        printf("No tiene arma\n");
        exit(1);
    }
}

void shootSemiJ(jugador* j){
    if (j->arma)
    {
        shootSemi(j->arma);
    }
    else{
        printf("No tiene arma\n");
        exit(1);
    }
}

void shootAutoJ(jugador* j){
    if (j->arma)
    {
        shootAuto(j->arma);
    }
    else{
        printf("No tiene arma\n");
        exit(1);
    }
}

void dropA(jugador* j){
    j->arma = NULL;
    printf("Arma tirada\n");
}