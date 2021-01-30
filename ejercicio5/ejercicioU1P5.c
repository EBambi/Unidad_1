#include <stdio.h>
#include <stdlib.h>

int main(void){

    /*int i, j, k = 5;
    k++;
    printf("Valores: %d %d %d\n", i, j ,k);
    --k;
    printf("Valores: %d %d %d\n", i, j ,k);
    k = 5;
    printf("Valores: %d %d %d\n", i, j ,k);
    i = 4*k++;
    printf("Valores: %d %d %d\n", i, j ,k);
    k = 5;
    printf("Valores: %d %d %d\n", i, j ,k);
    j = 4*++k;*/

    /*char c;
    printf("Digíte cualquier caracter, X=Terminar Programa\n");
    do{
        c = getchar();
        putchar(c);
        putchar('\n');
    }while (c!='X');
    printf("\nFin del Programa.\n");*/

    /*char lett = 'w';
    int i = 1;
    int j = 29;

    printf("%c\n", lett);
    printf("%4c\n", lett);
    printf("%d\n",i);
    printf("%d\n",j);
    printf("%10d\n",j);
    printf("%010d\n",j);
    printf("%-10d%c\n",j, lett);
    printf("%2o\n",j);
    printf("%2x\n",j);*/

    /*float x = 333.123456;
    double y = 333.1234567890123456;
    char lett = 'w';

    printf("%f\n",x);
    printf("%.1f\n",x);
    printf("%20.3f\n",x);
    printf("%-20.3f%c\n",x,lett);
    printf("%020.3f\n",x);
    printf("%.9f\n",y);
    printf("%.20f\n",y);
    printf("%20.4f\n",y);*/

    /*char s[] = "an evil presence";
    printf("%s\n", s);
    printf("%7s\n", s);
    printf("%20s\n", s);
    printf("%-20s\n", s);
    printf("%.5s\n", s);
    printf("%.12s\n", s);
    printf("%15.12s\n", s);
    printf("%-15.12s\n", s);
    printf("%3.12s\n", s);*/

    /*printf("%%");
    printf("%c",'%');
    printf("%s","%");*/

    int a;
    int b;
    int s;
    char op;
    
    do{
        printf("Ingrese el caracter de la operación (+,-,*) o Q para salir:\n");
        scanf("%s",&op);
        printf("Ingrese el primer operador:\n");
        scanf("%d",&a);
        printf("Ingrese el segundo operador:\n");
        scanf("%d",&b);

        switch (op)
        {
        case '+':
            s = a+b;
            printf("Resultado: %d\n",s);
            break;
        
        case '-':
            s = a-b;
            printf("Resultado: %d\n",s);
            break;

        case '*':
            s = a*b;
            printf("Resultado: %d\n",s);
            break;

        default:
            printf("Operador Inválido\n");
            break;
        }
    }while (op!='q');
    printf("\nFin del Programa.\n");

    return EXIT_SUCCESS;
}