#include <stdio.h>
#include <stdlib.h>
#include "arma.h"
#include "jugador.h"

int main(int argc, char const *argv[])
{
    struct ar15* arma = nuevaArma();
    create(arma);
    
    struct jugador* yo = jugadorNuevo();
    createJ(yo,"Esteban");

    pikUpA(yo,arma);
    
    shootSemiJ(yo);
    shootOneJ(yo);
    shootAutoJ(yo);

    dropA(yo);

    destroyJ(yo);

    return 0;
}
