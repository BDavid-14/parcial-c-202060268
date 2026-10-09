/*
 * Reto 16: Asistencia: jornadas por debajo del promedio propio
 * Estudiante: Bernardo David Batista Tapia
 * Matrícula: 20260268
 * Correo: 20260268@itla.edu.do
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_DIM 30

int main(void) {
    int N, M, L, U;

    // Lectura de dimensiones y parámetros de límites
    if (scanf("%d %d %d %d", &N, &M, &L, &U) != 4) {
        printf("ERROR\n");
        return 0;
    }

    // Validación de restricciones para N, M, L, U
    if (N < 1 || N > MAX_DIM || M < 1 || M > MAX_DIM || L < 0 || U > 1000 || L > U) {
        printf("ERROR\n");
        return 0;
    }

    int A[MAX_DIM][MAX_DIM];

    // Lectura y validación de los valores de la matriz
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (scanf("%d", &A[i][j]) != 1) {
                printf("ERROR\n");
                return 0;
            }
            if (A[i][j] < 0 || A[i][j] > 1000) {
                printf("ERROR\n");
                return 0;
            }
        }
    }

    int col_eventos[MAX_DIM] = {0};
    int fila_eventos[MAX_DIM] = {0};
    long fila_impacto[MAX_DIM] = {0};
    int fila_racha[MAX_DIM] = {0};
    int fila_inicio[MAX_DIM] = {0};
    int total_eventos_matriz = 0;

    // Procesamiento por cada fila
    for (int i = 0; i < N; i++) {
        long SF = 0;
        for (int j = 0; j < M; j++) {
            SF += A[i][j];
        }

        int eventos = 0;
        long impacto_acum = 0;
        int max_racha = 0;
        int inicio_max_racha = 0;
        int racha_actual = 0;
        int inicio_actual = 0;

        for (int j = 0; j < M; j++) {
            int x = A[i][j];

            // Evaluar la regla particular del Reto 16
            if ((SF - (long)M * x >= (long)M * L) && (x <= U)) {
                eventos++;
                col_eventos[j]++;
                total_eventos_matriz++;

                long impacto_pos = SF - (long)M * x + 1;
                impacto_acum += impacto_pos;

                if (racha_actual == 0) {
                    inicio_actual = j + 1; // 1-indexed
                }
                racha_actual++;

                if (racha_actual > max_racha) {
                    max_racha = racha_actual;
                    inicio_max_racha = inicio_actual;
                }
            } else {
                racha_actual = 0;
            }
        }

        fila_eventos[i] = eventos;
        fila_impacto[i] = impacto_acum;
        fila_racha[i] = max_racha;
        fila_inicio[i] = (max_racha > 0) ? inicio_max_racha : 0;
    }

    // Determinación de la Fila Prioritaria y Columna Destacada
    int fila_prioritaria = 0;
    int columna_destacada = 0;

    if (total_eventos_matriz > 0) {
        // Criterios de desempate para la fila prioritaria
        fila_prioritaria = 1;
        for (int i = 1; i < N; i++) {
            int prev = fila_prioritaria - 1;

            if (fila_racha[i] > fila_racha[prev]) {
                fila_prioritaria = i + 1;
            } else if (fila_racha[i] == fila_racha[prev]) {
                if (fila_impacto[i] > fila_impacto[prev]) {
                    fila_prioritaria = i + 1;
                } else if (fila_impacto[i] == fila_impacto[prev]) {
                    if (fila_eventos[i] > fila_eventos[prev]) {
                        fila_prioritaria = i + 1;
                    }
                }
            }
        }

        // Criterios para la columna destacada (mayor eventos, menor número de columna)
        columna_destacada = 1;
        int max_ev_col = col_eventos[0];
        for (int j = 1; j < M; j++) {
            if (col_eventos[j] > max_ev_col) {
                max_ev_col = col_eventos[j];
                columna_destacada = j + 1;
            }
        }
    }

    // Formato de Salida Exigido
    for (int i = 0; i < N; i++) {
        printf("FILA %d EVENTOS %d IMPACTO %ld RACHA %d INICIO %d\n",
               i + 1, fila_eventos[i], fila_impacto[i], fila_racha[i], fila_inicio[i]);
    }

    printf("COLUMNAS");
    for (int j = 0; j < M; j++) {
        printf(" %d", col_eventos[j]);
    }
    printf("\n");

    printf("PRIORIDAD %d\n", fila_prioritaria);
    printf("COLUMNA %d\n", columna_destacada);

    return 0;
}