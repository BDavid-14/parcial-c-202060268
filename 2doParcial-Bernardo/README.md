# Documentación del Reto PMC09 - Autonomía de una batería virtual

* **Matrícula:** 2026-0268
* **Correo:** 20260268@itla.edu.do
* **Asignatura:** Mecatrónica (ITLA)

## 1. Descripción del Modelo y Decisiones de Diseño
Simulador desarrollado en C11 para evaluar celdas mecatrónicas. Se implementó una matriz estática de muestras `int muestras[20][8]` y un arreglo de registros estructurados con `typedef struct`, separando los prototipos en `reto.h`. Se integraron funciones recursivas para el cálculo del total, algoritmos de ordenamiento interno y búsqueda binaria propia.

## 2. Compilación y Ejecución
Compilar sin advertencias:
```bash
gcc -std=c11 -Wall -Wextra -Wpedantic main.c -o reto