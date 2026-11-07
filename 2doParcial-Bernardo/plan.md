# Plan de Trabajo - Reto PMC09

* **Matrícula:** 2026-0268
* **Correo:** 20260268@itla.edu.do
* **Asignatura:** Mecatrónica (ITLA)

## Descripción del Modelo
El sistema procesa celdas mecatrónicas independientes. La energía inicial se calcula como `10 * p`. Si el modo es `1` y la muestra `x <= 20`, la batería se recarga sumando `x` unidades sin límite. En cualquier otro caso, se consume `x`: si la energía es menor que `x`, el estado se fija en `1` y se interrumpe el procesamiento de la unidad actual de inmediato.

## Pseudocódigo General
```text
INICIO
  Leer n, m, q
  SI parámetros fuera de rango ENTONCES
    Imprimir "ERROR" y terminar
  FIN SI

  PARA cada unidad i desde 0 hasta n-1 HACER
    Leer id, nombre, tipo, p
    Validar dominios y unicidad de ID
    PARA cada muestra j desde 0 hasta m-1 HACER
      Leer muestras[i][j] (0 a 100)
    FIN PARA
    Ejecutar calcular() para obtener score y estado
  FIN PARA

  Validar ausencia de tokens extra.
  Imprimir resultados por unidad en orden original.
  Calcular TOTAL mediante función recursiva total_rec().
  Ordenar unidades y mostrar ORDER.
  Ejecutar búsqueda binaria con buscar() y mostrar FIND.
FIN