#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "validar.h"

int main()
{


    sCliente clientes[20];
    char bufferInt[40];
    int indiceDeDNI;

    Client_EniciarArray(clientes,20);
    do
    {

        //\n2-Listar\n3-Modificar\n4-Ordenar\n5-Grafica\n
        val_getUnsignedInt(bufferInt,
        "************************************************\n"
        "*                ELIJA UNA OPCION             **\n"
        "*                                             **\n"
        "************************************************\n"
        "** 1- Agregar persona                         **\n"
        "** 2- Borrar persona                          **\n"
        "** 3- Modificacion                            **\n"
        "** 4- Imprimir lista ordenada por  nombre     **\n"
        "** 5- Imprimir grafico de edades              **\n"
        "** 6- Salir                                   **\n"
        "************************************************\n"
        ,"\nSolo de 1 a 6\n",2,40);
        switch(atoi(bufferInt))
        {
            case 1:


            Cliente_alta(clientes , Cliente_BuscarLugarLibre(clientes,20),20);

            break;
            case 2:
                 cliente_borrar(clientes,indiceDeDNI,20);


            break;
            case 3:

                cliente_modificacion(clientes,indiceDeDNI,20);
                break;

            case 4:

                cliente_ordenar(clientes,20);



            case 5:
                 graficar (clientes, 20);
                break;


            default:

                break;


        }

    }while( atoi(bufferInt) != 6);
    return 0;
}
