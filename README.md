# Optimización de Red de Fibra Óptica

## Descripción
Este proyecto implementa algoritmos para optimizar una red de fibra óptica, incluyendo el cálculo del árbol de expansión mínima (MST), la resolución del problema del viajero (TSP), la determinación de caminos más cortos entre centrales, y la conexión de nuevas colonias.

## Repositorio GitHub
[https://github.com/Ricardo-HJ/Evidencia2-Algoritmos2](https://github.com/Ricardo-HJ/Evidencia2-Algoritmos2)

## Archivos del Proyecto
- `Evidencia2.cpp`: Archivo principal que contiene la función `main()`.
- `MST.h`: Implementa el algoritmo de Kruskal para el árbol de expansión mínima.
- `TSP.h`: Contiene funciones para resolver el problema del viajero.
- `utils.h`: Define estructuras de datos y funciones auxiliares.

## Funcionalidades
1. **Cálculo del Árbol de Expansión Mínima (MST)**: 
   - Determina el cableado óptimo para nuevas conexiones.

2. **Resolución del Problema del Viajero (TSP)**: 
   - Calcula la ruta óptima para visitar todas las ubicaciones no centrales.

3. **Caminos más Cortos entre Centrales**: 
   - Encuentra las rutas más eficientes entre las ubicaciones centrales.

4. **Conexión de Nuevas Colonias**: 
   - Determina la mejor forma de conectar nuevas ubicaciones a la red existente.

## Cómo Usar
1. Clone el repositorio:
   ```
   git clone https://github.com/Ricardo-HJ/Evidencia2-Algoritmos2.git
   ```

2. Compile el programa:  g++ Evidencia2.cpp -o Evidencia2

3. Ejecute el programa: ./Evidencia2

4. El programa leerá los datos de entrada desde la entrada estándar y generará un archivo de salida llamado `checking2.txt` con los resultados del análisis.

## Formato de Entrada
El programa espera la siguiente entrada:
- Número de nodos, aristas existentes, aristas nuevas y nodos nuevos.
- Información de cada nodo: nombre, coordenadas x e y, y si es central.
- Información de las aristas existentes: nodos conectados y peso.
- Información de las aristas nuevas: nodos a conectar.
- Información de los nuevos nodos: nombre y coordenadas.

## Complejidad Temporal
- MST (Kruskal): O(E log E), donde E es el número de aristas.
- TSP: O(n^2), donde n es el número de nodos.
- Caminos más Cortos (Floyd-Warshall): O(n^3).
- Conexión de Nuevas Colonias: O(n), donde n es el número de nodos existentes.

## Reflexión sobre los Algoritmos Utilizados

### 1. Árbol de Expansión Mínima (Kruskal)
- **Complejidad**: O(E log E)
- **Explicación**: Eficiente para grafos dispersos. Utiliza un conjunto disjunto para detectar ciclos.

### 2. Problema del Viajero (TSP)
- **Complejidad**: O(n^2)
- **Explicación**: Implementa una heurística de vecino más cercano. No garantiza la solución óptima, pero es eficiente para problemas de tamaño moderado.

### 3. Caminos más Cortos (Floyd-Warshall)
- **Complejidad**: O(n^3)
- **Explicación**: Encuentra los caminos más cortos entre todos los pares de nodos. Eficaz para grafos densos y cuando se necesitan todos los pares de caminos.

### 4. Conexión de Nuevas Colonias
- **Complejidad**: O(n)
- **Explicación**: Utiliza un enfoque de vecino más cercano para conectar nuevos nodos. Simple y eficiente para este propósito específico.

## Autor
Ricardo Hernandez - A00837337

## Última Edición
18/11/24

## Notas Adicionales
- El proyecto utiliza estructuras de datos eficientes como vectores y matrices para representar el grafo y almacenar resultados intermedios.
- Se implementan varias optimizaciones para mejorar el rendimiento en el análisis de redes de gran escala.
- La modularización del código en diferentes archivos de encabezado mejora la legibilidad y mantenibilidad.