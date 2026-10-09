# ============================================================================
ANÁLISIS SIMPLIFICADO DEL PROBLEMA - RETO 16: ASISTENCIA

1. ¿QUÉ RECIBE EL PROGRAMA? (ENTRADAS)

* 4 números iniciales: N (filas), M (columnas), L (mínimo de diferencia) y U (máximo valor permitido).
* Una tabla (matriz) de N filas por M columnas con los números de asistencia de cada día.

2. REGLAS Y ERRORES (VALIDACIONES)

* N y M deben estar entre 1 y 30.
* L y U deben estar entre 0 y 1000, cumpliendo que L <= U.
* Ningún número dentro de la tabla puede ser negativo ni mayor que 1000.
* Si alguna regla no se cumple, el programa debe mostrar "ERROR" y cerrarse de una vez.

3. ¿CÓMO SE DETECTA UN EVENTO Y SU IMPACTO?

* Para cada fila, se suma todo su contenido (Suma de Fila).
* Un número de la tabla "x" se considera EVENTO si:
1. Su valor no supera a U (x <= U).
2. La diferencia entre la Suma de la Fila y (M * x) es mayor o igual a (M * L).


* Si es evento, el IMPACTO de esa celda es: (Suma de Fila) - (M * x) + 1. Si no, su impacto es 0.

4. ¿QUÉ RESULTADOS DEBE MOSTRAR? (SALIDA)

* Por cada fila:
* Total de eventos encontrados.
* Suma total del impacto de sus eventos.
* La racha de eventos seguidos más larga.
* La posición de inicio de esa primera racha larga (1, 2, 3...).


* Por columnas:
* El total de eventos encontrados en cada columna.


* Al final:
* PRIORIDAD: La fila más importante (se elige por mayor racha; si empatan, por mayor impacto; si empatan, por más eventos; si empatan, la de menor número).
* COLUMNA: La columna con más eventos (si empatan, la de menor número).
============================================================================