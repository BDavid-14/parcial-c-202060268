
# Parcial de algoritmos en C

- Estudiante: Bernardo David Batista Tapia
- Matrícula: 20260268
- Reto asignado: Reto 16 - Asistencia: jornadas por debajo del promedio propio

## Descripción
El programa analiza matrices de asistencia en jornadas ($N \times M$). Evalúa qué posiciones cumplen con la condición de evento del Reto 16 (asistencia $x \le U$ y estar al menos $L$ unidades por debajo del promedio de la fila). Para cada fila calcula la cantidad de eventos, el impacto acumulado, la racha más larga de eventos consecutivos y el índice de inicio de la primera racha máxima. Finalmente, consolida la cantidad de eventos por columna y determina la fila prioritaria y la columna destacada según las reglas de desempate del reto.

/* 
 * RESULTADOS DE LOS CASOS DE PRUEBA INCLUIDOS:
 * 
 * caso_01.in = Se obtuvo la salida esperada
 * caso_02.in = Se obtuvo la salida esperada
 * caso_03.in = Se obtuvo la salida esperada
 * caso_04.in = Se obtuvo la salida esperada
 * caso_05.in = Se obtuvo la salida esperada
 * caso_06.in = Se obtuvo la salida esperada
 * caso_07.in = Se obtuvo la salida esperada
 * caso_08.in = Se obtuvo la salida esperada
 * caso_09.in = Se obtuvo la salida esperada
 * caso_10.in = Se obtuvo la salida esperada
 * caso_11.in = Se obtuvo la salida esperada
 * caso_12.in = Se obtuvo la salida esperada
 * caso_13.in = Se obtuvo la salida esperada
 * caso_14.in = Se obtuvo la salida esperada
 * caso_15.in = Se obtuvo la salida esperada
 * caso_16.in = Se obtuvo la salida esperada
 * caso_17.in = Se obtuvo la salida esperada

 * caso_propio1.in = Se obtuvo la salida esperada
 * caso_propio2.in = Se obtuvo la salida esperada
 */

 /*
 *                             JUSTIFICACIONES
 * 
 * Prueba Propia 1: Desempate por mayor impacto
 * - Justificación: Verifica que cuando dos filas empatan en racha y en cantidad de eventos,
 *   el algoritmo elija como fila prioritaria la que tenga el mayor impacto acumulado.
 * 
 * Prueba Propia 2: Validación de limites invertidos (L > U)
 * - Justificación: Comprueba que si se ingresa un límite inferior mayor que el superior (L > U),
 *   el programa detenga la ejecución e imprima únicamente ERROR.
 */

## Compilación y ejecución
- Sistema operativo: Windows 11 (VS Code / CMD / Git Bash)
- Compilador: GCC (MinGW)

Comandos utilizados:
```cmd
gcc -std=c11 -Wall -Wextra 20260268.c -o reto.exe
reto.exe < pruebas\caso_01.in