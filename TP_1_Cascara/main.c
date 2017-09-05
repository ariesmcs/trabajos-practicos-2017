#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int numero1= 0,numero2 = 0, resultado;
    float resultadoD;
    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A= %d)\n",numero1);
        printf("2- Ingresar 2do operando (B= %d)\n",numero2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                numero1 = entrada(numero1);


                break;
            case 2:

               numero2 = entrada2(numero2);

                break;
            case 3:
                resultado=suma(numero1,numero2);
                printf("la suma es: %i \n" ,resultado);
                break;
            case 4:
                resultado=resta(numero1,numero2);
                printf("la resta es: %i \n" ,resultado);

                break;
            case 5:
                resultadoD=division(numero1,numero2);
                printf("la division es: %.2f\n" ,resultadoD);

                break;
            case 6:
                resultado=multiplicsion(numero1,numero2);
                printf("la multiplicsion es: %i \n" ,resultado);

                break;
            case 7:
                resultado=factorial(numero1);
                printf("la factorial es: %i \n" ,resultado);

                break;
            case 8:
                resultado=suma(numero1,numero2);
                printf("la suma es: %i \n" ,resultado);
                resultado=resta(numero1,numero2);
                printf("la resta es: %i \n" ,resultado);
                resultado=division(numero1,numero2);
                printf("la division es: %.2f\n" ,resultadoD);
                resultadoD=multiplicsion(numero1,numero2);
                printf("la multiplicsion es: %i \n" ,resultado);
                resultado=factorial(numero1);
                printf("la factorial es: %i \n" ,resultado);
                break;
            case 9:
                seguir = 'n';
                break;
            default:
                  printf("\nNO ESISTE EL NUMERO EN LA LISTA DE LA CALCULADORA\n");


        }




}

    return 0;
}
