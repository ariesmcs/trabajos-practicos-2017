#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "validar.h"

int Client_EniciarArray( sCliente arrayCliente[], int lon   )
{
    int i;
    for(i=0;i<lon;i++)
    {
        arrayCliente[i].estado = 0;
    }
    return 0;
}
int Cliente_BuscarLugarLibre(sCliente arrayCliente[],int lon)
{
    int i;
    int retorno=-1;
    for(i=0;i<lon;i++)
    {
        if(arrayCliente[i].estado==0)
        {
            retorno=i;
            break;
        }

    }
    return retorno;
}







int Cliente_alta(sCliente arrayCliente[],int idiceDeLugarLibre , int  lon)
{
    char bAuxNombre[51];
    char bAuxdni[51];
    char bAuxedad[51];
   int auxedad;
   int auxdni;
    if(arrayCliente !=NULL && idiceDeLugarLibre >=0 && idiceDeLugarLibre < lon )
    {


                if(Val_GetString(bAuxNombre,"NOMBRE: ","\nERROR SOLO LETRAS! ",3,51)!=-1)
                {

                    if(Val_GetStringNumeros(bAuxdni,"-DNI. ","\nERROR SOLO NUMEROS! ",3,51)!=-1)
                    {


                        if(Val_GetStringNumeros(bAuxedad,"-EDAD. ","\nERROR SOLO NUMEROS! ",3,51)!=-1)
                            {
                                auxdni=atoi(bAuxdni);
                                auxedad=atoi(bAuxedad);
                                strncpy(arrayCliente[idiceDeLugarLibre].nombre,bAuxNombre,51);
                                arrayCliente[idiceDeLugarLibre].dni=auxdni;
                                arrayCliente[idiceDeLugarLibre].edad=auxedad;
                                arrayCliente[idiceDeLugarLibre].estado=1;

                            }
                    }

                }



        }

      return 0;
}






int cliente_modificacion(sCliente arrayCliente[],int idiceDelDNI ,int lon)
{

    char bAuxdni[51];
    char bAuxNombre[51];
    char bAuxedad[51];
     int auxdni;
     int auxedad;

     if(arrayCliente !=NULL  )

     {

         while(Val_GetStringNumeros(bAuxdni,"-INGRESE DNI PARA MODIFICAR:  ","\nERROR SOLO NUMEROS! ",3,51)!=-1)

         {
            auxdni=atoi(bAuxdni);
            idiceDelDNI= buscarPorDni(arrayCliente,auxdni,lon);
            if(idiceDelDNI== -1)
            {
                printf("\n ERROR NO SE ECONTRO EL DNI ");
                break;
            }

             if(Val_GetString(bAuxNombre,"NOMBRE: ","\nERROR SOLO LETRAS! ",3,51)==-1)
              {
                  printf("\n INTENTELO OTRA VES.");
                  break;
              }
              if(Val_GetStringNumeros(bAuxedad,"-EDAD. ","\nERROR SOLO NUMEROS! ",3,51)==-1)
              {
                   printf("\n INTENTELO OTRA VES.");
                   break;
              }
              auxedad=atoi(bAuxedad);
                                                    strncpy(arrayCliente[idiceDelDNI].nombre,bAuxNombre,51);
                                                    arrayCliente[idiceDelDNI].edad=auxedad;
                                                          arrayCliente[idiceDelDNI].dni=auxdni;
                                                        arrayCliente[idiceDelDNI].estado=1;




                break;
         }
              printf("\nLA MODIFICACION  A SIDO EXISTOSA\n");
 }

 return 0;
}

int cliente_borrar(sCliente arraycliente[],int IndiceDniAborrar,int lon)
{
      char bAuxdni[51];
           int auxdni;

      if(arraycliente != NULL)
      {


               while(Val_GetStringNumeros(bAuxdni,"-INGRESE DNI PARA DAR DE BAJA: ","\nERROR SOLO NUMEROS! ",3,51)!=-1)
               {
                        auxdni=atoi(bAuxdni);
                        IndiceDniAborrar= buscarPorDni(arraycliente,auxdni,lon);
                        if(IndiceDniAborrar== -1)
                        {
                            printf("\n ERROR NO SE EL  DNI \n");
                            break;
                        }
                        else
                        {


                         arraycliente[IndiceDniAborrar].estado=0;

                         printf("\nLA BAJA A SIDO EXISTOSA\n");
                         break;
                        }


               }


      }
     return 0;

}




int buscarPorDni(sCliente  arraycliente[], int dni_aux,int lon)
{
    int i;
    int retorno=-1;
    for(i=0;i<lon;i++)
    {
        if(arraycliente[i].estado == 1&& arraycliente[i].dni==dni_aux)
        {
            retorno=i;
            break;
        }
    }

    return retorno;
}




void graficar (sCliente     Persona[], int C)
{
    int M18=0, E19Y35=0, M35=0;
    int i, mayor;

    for(i = 0 ; i < C ; i++)
    {
        if (Persona[i].estado == 1)
        {
            if(Persona[i].edad <= 18)
                {
                    M18++;
                }
            else if(Persona[i].edad >18 && Persona[i].edad <= 35)
                {
                    E19Y35++;
                }
            else
                {
                    M35++;
                }
        }
    }

    if (M18 > E19Y35 && M18 > M35)
    {
        mayor = M18;

    }
     if ( E19Y35 > M35 && E19Y35 > M18)
    {
        mayor = E19Y35;
    }
    else
    {
        mayor = M35;
    }



    for(i = mayor ; i > 0 ; i--)

    {
        if(M18 == i)
        {
            printf("*\t");
            M18--;

        }
        else
        {
            printf(" \t\t");
        }

        if(E19Y35 == i)
        {
            printf("*\t");
            E19Y35--;

        }
        else
        {
            printf(" \t");
        }

        if(M35 == i)
        {
            printf("*\t\n");
            M35--;

        }
        else
        {
            printf(" \t\n");
        }
    }
    printf("<18\t18-35\t>35\n");
}



int cliente_ordenar(sCliente arrayCliente[],int lon)
{
   int i, j;
sCliente aux;


      for(i=0;i<lon-1;i++)
      {
          for(j=1;j<lon;j++)
          {
              if(arrayCliente[i].estado==1)
              {
                  if(strcmp(arrayCliente[i].nombre,arrayCliente[j].nombre)<0)
                  {
                      aux=arrayCliente[i];
                      arrayCliente[i]=arrayCliente[j];
                      arrayCliente[j]=aux;

                  }
                  else
                  {
                      if(strcmp(arrayCliente[i].nombre,arrayCliente[j].nombre)==0)

                          if(arrayCliente[i].dni<arrayCliente[j].dni)
                          {
                              aux=arrayCliente[i];
                              arrayCliente[i]=arrayCliente[j];
                              arrayCliente[j]=aux;
                          }
                      }
                  }

              }

          }
          for(i=0;i<lon;i++)
          {
              if(arrayCliente[i].estado==1)
              {
                  printf(":::DATOS DE LA PERSONA:::\n");
                  printf("D.N.I: %d\nNombre:%s\nEdad:%d\n",arrayCliente[i].dni,arrayCliente[i].nombre,arrayCliente[i].edad);
              }

          }

return 0;
}


