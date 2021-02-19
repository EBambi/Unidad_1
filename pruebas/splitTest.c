#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

    char cadena[] = "Hola,esto,es,una,prueba",
    delimitador[] = ",";
    char *token = strtok(cadena, delimitador);
    if(token != NULL){
        while(token != NULL){
            // Sólo en la primera pasamos la cadena; en las siguientes pasamos NULL
            printf("Token: %s\n", token);
            token = strtok(NULL, delimitador);
        }
    }

    return 0;
}