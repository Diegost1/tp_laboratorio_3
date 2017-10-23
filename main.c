#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"




int main()
{
    eMovie Pelicula;
    int opcion=1;

    while(opcion>=1 && opcion<5)
    {
        system("cls");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir.\n\n");
        printf("Opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                {
                    if(agregarPelicula(Pelicula)!=1)
                    {
                        printf("No se puso cargar la pelicula.");

                    }
                    else{
                        printf("\n\nPelicula Cargada con exito.");
                    }
                }
                    getch();
                    break;
            case 2:
                {

                    if(borrarPelicula(Pelicula)!=0)
                    {
                        printf("\n\nPelicula Borrada.");

                    }
                    else{
                        printf("\n\nBorrado Cancelado.");
                    }
                }
                    getch();
                    break;
            case 3:
                {

                    if(ModificarPelicula(Pelicula)!=0)
                    {
                        printf("\n\nPelicula Modificada.");

                    }
                    else{
                        printf("\n\nModificacion Cancelada.");
                    }
                    getch();
                    break;
                }
            case 4:
                {
                    //Lo muestro por consola...
                    if(Pelicula.estado!=1)
                    {
                        printf("No hay pelicula para mostrar.");

                    }
                    else{
                         generarPagina(Pelicula);
                    }

                    getch();
                    break;
                }
            case 5:
                break;

        }
    }

    return 0;
}
