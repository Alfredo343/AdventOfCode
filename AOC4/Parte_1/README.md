## **DÍA 4**

### Grafos

Este problema corresponde con la PRIMERA parte del ejercicio 4 del Advent of Code. 

Elegimos este problema porque resolverlo implica seguir una cuadrícula y contar vecinos, lo cual es muy útil para problemas como este que implican simulación. 

### Explicación General del Problema 

El problema se basa en un diagrama que indica la ubicación de rollos de papel (@) en un gran almacén. Cada rollo puede ser accedido por una carretilla elevadora solo si tiene menos de 4 rollos en sus 8 posiciones adyacentes. 

El objetivo del programa es determinar cuántos rollos de papel pueden ser accedidos directamente por las carretillas. Para ello, se recorre toda la cuadrícula, se comprueban las condiciones para cada rollo y se acumula el conteo de los accesibles. 

### Explicación del Código 

Primero, se leen todas las líneas de la entrada y se almacenan en un vector<string>: 

```cpp
vector<string> grid; 
string linea; 
while (cin >> linea) { 
  grid.push_back(linea); 
}
```
Aquí grid representa la cuadrícula completa de rollos y cada elemento del vector corresponde a una de las filas de la cuadrícula. 

Tras esto, se deciden las dimensiones que  va a tener la cuadrícula y se prepara la variable donde se va a guardar el resultado. 

```cpp
int filas = grid.size(); 
int columnas = grid[0].size(); 
int resultado = 0; 
```
Filas y columnas permiten recorrer la cuadrícula de forma segura. En la variable resultado almacenará el número total de rollos accesibles. 

El siguiente bloque recorre toda la cuadrícula y verifica para cada rollo si puede ser accedido: 

```cpp
for (int i = 0; i < filas; i++) { 
    for (int j = 0; j < columnas; j++) { 
        if (grid[i][j] != '@') continue; 
        int vecinos = 0; 
        for (int di = -1; di <= 1; di++) { 
            for (int dj = -1; dj <= 1; dj++) { 
```
Si 'di' es cero y 'dj' también es cero, entonces continúa con la siguiente iteración. 

```cpp
int ni = i + di; 
int nj = j + dj; 
if (ni >= 0 && ni < filas && nj >= 0 && nj < columnas) { 
    if (grid[ni][nj] == '@') vecinos++; 

} 
} 
} 
if (vecinos < 4) resultado++; 
} 
} 
```
No se tienen en cuenta las posiciones vacías (.). 
Vecinos lo que alamcena son los rollos adyacentes(i,j) donde unicamente se cuenta lo que esté dentro de la cuandrícula.

En caso de haber menos de 4 vecinos, el rollo es accesible y se incrementa resultado. 

### Comentarios 

Este código es directo y sencillo, adecuado para inputs moderados. 

No modifica la cuadrícula ni hace iteraciones adicionales; simplemente cuenta los rollos accesibles en una pasada. 

En comparación con métodos más complejos como tablas hash o simulaciones iterativas, este enfoque es suficiente para resolver la primera parte del problema y permite comprobar rápidamente los rollos accesibles. 

### Valoración del Problema 

Gracias a este código hemos aprendido que: 

Recorrer la cuadrícula y contar vecinos es una técnica eficiente y clara para problemas de accesibilidad. 

No siempre es necesario complicarse con estructuras avanzadas; un enfoque directo puede ser suficiente para la primera parte de un problema. 

La validación de condiciones de acceso en entornos con vecinos adyacentes es una herramienta útil para muchos tipos de simulación o puzzles de cuadrícula. 
