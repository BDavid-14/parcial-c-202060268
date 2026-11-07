#ifndef RETO_H
#define RETO_H

#define MAX_UNIDADES 20
#define MAX_MUESTRAS 8

// Configuración anidada
typedef struct {
    int tipo; // 0 o 1
    int p;    // 0 a 100
} Configuracion;

// Registro principal de la unidad
typedef struct {
    int id;
    char nombre[16];
    Configuracion config;
    int score;
    int estado;
} Unidad;

// Prototipos de funciones requeridos
int calcular(int muestras[], int m, int tipo, int p, int *estado);
int total_rec(Unidad unidades[], int n);
void ordenar(Unidad unidades[], int n);
int buscar(Unidad unidades[], int n, int q);

#endif