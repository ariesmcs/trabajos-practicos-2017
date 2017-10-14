#ifndef CLIENTE_H
#define CLIENTE_H
typedef struct{
        char nombre[20];
        int dni;
        int edad;
        int estado;
}sCliente;


#endif // CLIENTE_H_INCLUDED
#define PRODUCTO_LIBRE 0
#define PRODUCTO_OCUPADO 1
int Cliente_alta(sCliente arrayCliente[],int idiceDeLugarLibre , int  lon);
int Client_EniciarArray( sCliente arrayCliente[], int lon   );
int buscarPorDni(sCliente  arraycliente[], int dni_aux,int lon);
//int cliente_printf(sCliente arraycliente[],int lon);

int cliente_modificacion(sCliente arrayCliente[],int idiceDelDNI ,int lon);

int Cliente_BuscarLugarLibre(sCliente arrayCliente[],int lon);
void graficar (sCliente     Persona[], int C);
int cliente_borrar(sCliente arraycliente[],int IndiceDniAborrar,int lon);
int cliente_ordenar(sCliente arrayCliente[],int lon);
