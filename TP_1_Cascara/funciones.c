#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int  entrada(int num1 )
{
    printf("digite dato: ");
    scanf("%d",&num1);
return num1;
}
int  entrada2(int num2 )
{
    printf("digite dato: ");
    scanf("%d",&num2);
return num2;
}
int  suma( int num1 ,int num2 )
{
    int resultado;

    resultado= num1 +  num2;

     return resultado;

}


int  resta( int num1 ,int num2 )
{
    int resultado;

    resultado= num1 - num2;

    return resultado;


}
int  multiplicsion( int num1 ,int num2 )
{
    int resultado;

    resultado= num1 * num2;

    return resultado;
}
float  division( float num1 ,float num2 )

{
    float resultado;

    if( num2 !=0)
    {
    resultado= num1 / num2;

    }
    else
    {
    printf("no se puede divivir entre 0 ");
    }
  return resultado;
}

int  factorial( int num1  )
{
    int i;
    int factorial=num1;
    if (num1 !=0)
    {
        for(i=1;i<num1;i++)
        {
            factorial=factorial*i;
        }
    }
        else
        {
            printf("nose pude hacer factorial de 0\n");
        }
return factorial;
}

