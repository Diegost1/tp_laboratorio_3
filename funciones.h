#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    int estado;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
}eMovie;


int agregarPelicula(eMovie movie);

int ModificarPelicula(eMovie movie);

int borrarPelicula(eMovie movie);

void generarPagina(eMovie movie);

#endif // FUNCIONES_H_INCLUDED
