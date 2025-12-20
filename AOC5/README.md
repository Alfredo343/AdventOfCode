## **DÍA 5** 

### Estructuras de Árboles 

Este problema corresponde a la PRIMERA parte del ejercicio 5 del Advent of Code. 

Elegimos este problema porque nos permite trabajar con rangos y técnicas de búsqueda eficientes. Esto nos ayuda a gestionar de forma rápida y precisa la identificación de ingredientes frescos en una lista grande de identificadores. 

### Explicación General del Problema 

En este ejercicio, tenemos dos tipos de información. Por un lado, hay una lista de rangos de identificadores de ingredientes frescos. Por otro lado, hay una lista de identificadores de ingredientes que están disponibles. Cada rango de identificadores de ingredientes frescos indica cuales de los alimentos son frescos. Es importante mencionar que estos rangos pueden superponerse entre sí. Un identificador de ingrediente se considera fresco si pertenece a al menos uno de los rangos que se han dado. 

Nuestro objetivo es contar cuántos de los IDs disponibles son frescos. 

Para hacerlo de forma eficiente, primero leemos y limpiamos los rangos. Luego, fusionamos los rangos que se superponen para reducir la cantidad de intervalos que debemos comprobar. 

Finalmente, usamos búsqueda binaria para determinar si cada ID disponible se encuentra dentro de algún rango fusionado y saber sin son o no frescos. 

### Explicación del Código 

Primero definimos una función para validar que una cadena representa un número válido: 

```cpp
bool isNumber(const string &s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (!isdigit(c) && c != '-') return false;
    }
    return true;
}
```
Luego, la función readRanges lee los rangos desde la entrada estándar, primero elimina los espacios en blanco, luego verifica que sean números y finalmente los almacena como pares de números, es decir, como pares de inicio y fin, por ello usamos un vector

```cpp
vector<pair<long long, long long>> readRanges()
```
La función mergeRanges combina rangos que se cruzan. Esto hace que la búsqueda sea más fácil, porque reduce la cantidad de intervalos que hay que verificar y evita contar el mismo ID varias veces. 

```cpp
vector<pair<long long, long long>> mergeRanges(const vector<pair<long long, long long>> &ranges); 
```
La función countFreshIDs pasa por cada ID disponible y hace una búsqueda binaria en los rangos fusionados para ver si el ID está dentro de alguno de ellos. Si el ID está dentro de un rango, entonces se suma uno al contador. 

```cpp
long long countFreshIDs(const vector<pair<long long, long long>> &merged); 
```

Ya en main, combinamos todas estas funciones para conseguir saber cuantos son frescos.
Primero leemos y fusionamos los rangos, luego contamos los IDs frescos y finalmente mostramos el resultado: 

```cpp
ios::sync_with_stdio(false);
cin.tie(nullptr);

auto ranges = readRanges();
auto merged = mergeRanges(ranges);
long long freshCount = countFreshIDs(merged);
```

### Comentarios 

Hemos aprendido a procesar y limpiar datos de entrada de manera segura con esta implementación. También hemos visto cómo fusionar rangos superpuestos para optimizar el análisis. Además, aplicamos la búsqueda binaria para determinar la pertenencia de manera eficiente. Todo esto nos permite trabajar con listas grandes de datos sin que el rendimiento se vea afectado. 

### Valoración del Problema 

Gracias a este código hemos comprendido la importancia de elegir algoritmos adecuados según el problema. Fusionando rangos y usando búsqueda binaria podemos resolver problemas de pertenencia en listas grandes de forma rápida y escalable, mientras aplicamos conceptos prácticos de validación de datos y eficiencia en el manejo de información estructurada. 
