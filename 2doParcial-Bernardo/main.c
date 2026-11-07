#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "reto.h"

// Función calcular: procesa las muestras y devuelve el score, pasando el estado por referencia
int calcular(int muestras[], int m, int tipo, int p, int *estado) {
    int energia = 10 * p;
    int score = 0;
    *estado = 0;

    for (int i = 0; i < m; i++) {
        int x = muestras[i];
        if (tipo == 1 && x <= 20) {
            energia += x;
            score++;
        } else {
            if (energia < x) {
                *estado = 1;
                break;
            } else {
                energia -= x;
                score++;
            }
        }
    }
    return score;
}

// Función recursiva para sumar scores (caso base n == 0)
int total_rec(Unidad unidades[], int n) {
    if (n <= 0) {
        return 0;
    }
    return unidades[n - 1].score + total_rec(unidades, n - 1);
}

// Ordenamiento por selección/burbuja: score descendente, id ascendente en caso de empate
void ordenar(Unidad unidades[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (unidades[j].score < unidades[j + 1].score ||
                (unidades[j].score == unidades[j + 1].score && unidades[j].id > unidades[j + 1].id)) {
                Unidad temp = unidades[j];
                unidades[j] = unidades[j + 1];
                unidades[j + 1] = temp;
            }
        }
    }
}

// Búsqueda binaria sobre una copia ordenada por ID ascendente
int buscar(Unidad unidades[], int n, int q) {
    Unidad copia[MAX_UNIDADES];
    for (int i = 0; i < n; i++) {
        copia[i] = unidades[i];
    }

    // Ordenar copia por id ascendente para la búsqueda binaria
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (copia[j].id > copia[j + 1].id) {
                Unidad temp = copia[j];
                copia[j] = copia[j + 1];
                copia[j + 1] = temp;
            }
        }
    }

    int inicio = 0;
    int fin = n - 1;
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        if (copia[medio].id == q) {
            return copia[medio].score;
        } else if (copia[medio].id < q) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    return -1;
}

int main(void) {
    int n, m, q;
    if (scanf("%d %d %d", &n, &m, &q) != 3) {
        printf("ERROR\n");
        return 0;
    }

    if (n < 1 || n > MAX_UNIDADES || m < 1 || m > MAX_MUESTRAS || q < 1 || q > 9999) {
        printf("ERROR\n");
        return 0;
    }

    Unidad unidades[MAX_UNIDADES];
    int matriz_muestras[MAX_UNIDADES][MAX_MUESTRAS];
    int ids_vistos[MAX_UNIDADES];

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &unidades[i].id) != 1) {
            printf("ERROR\n");
            return 0;
        }
        if (unidades[i].id < 1 || unidades[i].id > 9999) {
            printf("ERROR\n");
            return 0;
        }

        // Validar unicidad del ID
        for (int j = 0; j < i; j++) {
            if (ids_vistos[j] == unidades[i].id) {
                printf("ERROR\n");
                return 0;
            }
        }
        ids_vistos[i] = unidades[i].id;

        if (scanf("%15s", unidades[i].nombre) != 1) {
            printf("ERROR\n");
            return 0;
        }

        int len = strlen(unidades[i].nombre);
        if (len < 1 || len > 15) {
            printf("ERROR\n");
            return 0;
        }
        for (int k = 0; k < len; k++) {
            char c = unidades[i].nombre[k];
            if (!isalnum((unsigned char)c) && c != '_') {
                printf("ERROR\n");
                return 0;
            }
        }

        if (scanf("%d %d", &unidades[i].config.tipo, &unidades[i].config.p) != 2) {
            printf("ERROR\n");
            return 0;
        }

        if ((unidades[i].config.tipo != 0 && unidades[i].config.tipo != 1) ||
            (unidades[i].config.p < 0 || unidades[i].config.p > 100)) {
            printf("ERROR\n");
            return 0;
        }

        for (int j = 0; j < m; j++) {
            if (scanf("%d", &matriz_muestras[i][j]) != 1) {
                printf("ERROR\n");
                return 0;
            }
            if (matriz_muestras[i][j] < 0 || matriz_muestras[i][j] > 100) {
                printf("ERROR\n");
                return 0;
            }
        }

        unidades[i].score = calcular(matriz_muestras[i], m, unidades[i].config.tipo, unidades[i].config.p, &unidades[i].estado);
    }

    // Comprobar tokens extra en la entrada
    char extra;
    if (scanf(" %c", &extra) == 1) {
        printf("ERROR\n");
        return 0;
    }

    // 1. Resultados en orden original
    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", unidades[i].id, unidades[i].score, unidades[i].estado);
    }

    // 2. TOTAL
    int total_score = total_rec(unidades, n);
    printf("TOTAL %d\n", total_score);

    // 3. ORDER
    Unidad copia_orden[MAX_UNIDADES];
    for (int i = 0; i < n; i++) {
        copia_orden[i] = unidades[i];
    }
    ordenar(copia_orden, n);
    printf("ORDER");
    for (int i = 0; i < n; i++) {
        printf(" %d", copia_orden[i].id);
    }
    printf("\n");

    // 4. FIND
    int resultado_busqueda = buscar(unidades, n, q);
    printf("FIND %d %d\n", q, resultado_busqueda);

    return 0;
}