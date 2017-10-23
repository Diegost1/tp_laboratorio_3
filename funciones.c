#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOV "C:\\Archivos\\miPelicula.bin"
#define MOVH "C:\\Archivos\\miPelicula.html"

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    int estado;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
}eMovie;


/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(eMovie movie)
{
    FILE *miPelicula;
    int indice=1;
    if ((miPelicula = fopen(MOV, "rb+")) == NULL)
        if((miPelicula = fopen(MOV, "wb+")) == NULL)
        {
            printf("\nNo se pudo abrir el archivo\n");
            indice = 0;
            return indice;
        }

            printf("\nTitulo de la pelicula: ");
            fflush(stdin);
            fgets(movie.titulo, 30, stdin);

            printf("\nGenero: ");
            fflush(stdin);
            fgets(movie.genero, 30, stdin);

            printf("\nDuracion: ");
            fflush(stdin);
            scanf("%d",&movie.duracion);

            printf("\nDescripcion: ");
            fflush(stdin);
            fgets(movie.descripcion, 30, stdin);

            printf("\nPuntaje: ");
            fflush(stdin);
            scanf("%d",&movie.puntaje);

            printf("\nURL de la imagen : ");
            fflush(stdin);
            fgets(movie.linkImagen, 30, stdin);

            movie.estado=1;
            fseek(miPelicula, 0L, SEEK_END);
            fflush(stdin);
            fwrite(&movie, sizeof(eMovie), 1, miPelicula);
            fclose(miPelicula);

            return indice;

}
/**
 *  Modifica una pelicula del archivo binario
 *  @param movie la estructura a ser modificada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int ModificarPelicula(eMovie movie)
{
    int indice=0;
    int resultado;
    char movieAux[30];
    FILE *miPelicula;

    printf("Ingrese el nombre de la pelicula a modificar: ");
    fflush(stdin);
    fgets(movieAux, 30, stdin);

    if ((miPelicula = fopen(MOV, "rb+")) == NULL)
        if((miPelicula = fopen(MOV, "wb+")) == NULL)
        {
        printf("\nNo se pudo abrir el archivo.");
        exit(1);
        }

    while (!feof(miPelicula))
    {
        resultado = fread(&movie, sizeof(eMovie), 1, miPelicula);
       if(resultado!=1)
            {
                if(movie.estado!=0)
                {
                    if (feof(miPelicula))
                        {
                            if(!strcmp(movie.titulo,movieAux))
                                {
                                    printf("Pelicula: ");
                                    fflush(stdin);
                                    fgets(movie.titulo, 30, stdin);

                                    printf("Genero: ");
                                    fflush(stdin);
                                    fgets(movie.genero, 30, stdin);

                                    printf("Duracion: ");
                                    fflush(stdin);
                                    scanf("%d",&movie.duracion);

                                    printf("Descripcion: ");
                                    fflush(stdin);
                                    fgets(movie.descripcion, 30, stdin);

                                    printf("Puntaje: ");
                                    fflush(stdin);
                                    scanf("%d",&movie.puntaje);

                                    printf("URL de la imagen : ");
                                    fflush(stdin);
                                    fgets(movie.linkImagen, 30, stdin);
                                    movie.estado=1;
                                    indice=1;

                                    break;
                                 }
                            else
                            {
                            printf("\nNo se encontro la pelicula.\n");
                            break;
                            }
                       }
                 }
                       indice=1;
                return indice;
            }
    }
    fseek(miPelicula,(long) (-1)*sizeof(eMovie), SEEK_CUR);
    fwrite(&movie, sizeof(eMovie), 1, miPelicula);
    fclose(miPelicula);
    return indice;
}

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(eMovie movie)
{
    int indice=0;
    int resultado;
    char movieAux[30];
    FILE *miPelicula;

    printf("Ingrese el nombre de la pelicula a eliminar: ");
    fflush(stdin);
    fgets(movieAux, 30, stdin);

    if ((miPelicula = fopen(MOV, "rb+")) == NULL)
        if((miPelicula = fopen(MOV, "wb+")) == NULL)
        {
        printf("\nNo se pudo abrir el archivo.");
        exit(1);
        }

    while (!feof(miPelicula))
    {
       resultado = fread(&movie, sizeof(eMovie), 1, miPelicula);
       if(resultado!=1)
            {
                if (feof(miPelicula))
                {
                    if(!strcmp(movie.titulo,movieAux))
                        {
                            movie.estado=0;
                            indice=1;


                            break;
                        }
                    else
                        {
                            printf("\nNo se encontro la pelicula.\n");
                        }
                    return indice;
                }

            }
    }
    fseek(miPelicula,(long) (-1)*sizeof(eMovie), SEEK_CUR);
    fwrite(&movie, sizeof(eMovie), 1, miPelicula);
    fclose(miPelicula);
    return indice;
}

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(eMovie movie)
{

    FILE* miPelicula;
    int resultado;
    miPelicula = fopen(MOV, "rb");
    rewind(miPelicula);
    while (!feof(miPelicula))
    {
        if ((resultado = fread(&movie, sizeof(eMovie), 1, miPelicula)) == 1)
        {
            if(movie.estado != 1)
                {
                    printf("\n-- Titulo: %s-- Duracion: %d\n-- Genero: %s-- Puntaje:  %d\n-- Descripcion: %s\n", movie.titulo, movie.duracion , movie.genero, movie.puntaje, movie.descripcion);
                }
        }

    }
    fclose(miPelicula);

}


#endif // FUNCIONES_H_INCLUDED

