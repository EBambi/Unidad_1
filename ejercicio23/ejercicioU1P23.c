#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint8_t encXor(uint8_t data) { return data ^ 0xFF; }

uint8_t encNot(uint8_t data) { return ~data;}

int main(int argc, char *argv[]) {
    char input[50];
    char inFile[20];
    char outFile[20];
    char funcion[10];
    uint8_t (*encFuntion)(uint8_t) = NULL;

    //printf("Ingrese el archivo de entrada, el archivo salida y la función para encriptar:\n");
    fgets(input, sizeof(input), stdin);
    inFile[20] = *argv[0];
    outFile[20] = *argv[1];
    funcion[10] = *argv[2];
    //sscanf(input, "%s %s %s", inFile, outFile, function);

    FILE *fin = fopen(inFile, "r");
    if (fin == NULL) {
        perror("Error: ");
        return EXIT_FAILURE;
    }

    if (strncmp("xor", funcion, 3) == 0) {
        encFuntion = &encXor;
    }

    if (strncmp("not", funcion, 3) == 0) {
        encFuntion = &encNot;
    }

    FILE *fout = fopen(outFile, "w");
    if (fout == NULL) {
        perror("Error: ");
        return EXIT_FAILURE;
    }

    while ( fgets(input, sizeof(input), fin) != NULL) {

        int n = strlen(input);

        for (int i = 0; i < n; i++) {
            input[i] = (*encFuntion)(input[i]);
        }
        fputs(input, fout);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}