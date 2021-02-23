#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int balas;
} ar15;

struct ar15* nuevaArma(){
    return malloc(sizeof(ar15));
}

void create(ar15* arma){
    arma->balas = 25;
}

void destroy(ar15* arma){
    free(arma);
}

void reload(ar15* arma){
    arma->balas = 25;
    printf("Recargada para matar.\n");
}

void shootOne(ar15* arma){
    printf("¡PA!\n");
    arma->balas--;
}

void shootSemi(ar15* arma){
    printf("¡RA TATATA!\n");
    arma->balas--;
    arma->balas--;
    arma->balas--;
}

void shootAuto(ar15* arma){
    for (int i = 0; i < arma->balas; i++)
    {
        printf("¡TA!\n");
        arma->balas--;        
    }
}