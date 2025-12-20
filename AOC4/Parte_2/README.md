## **DÍA 4**

### Tablas Hash

Este problema corresponde con la SEGUNDA parte del ejercicio del Día 4 del Advent of Code. 

Elegimos este problema porque nos permite usar estructuras de datos avanzadas, como una tabla hash, para gestionar mejor los rollos de papel en la cuadrícula y encontrar los accesibles de manera más eficiente. 

### Explicación General del Problema 

En esta parte del problema tenemos una cuadrícula con rollos de papel (@) al igual que en la parte 1 y cuanta con la misma condición, una carretilla puede acceder a un rollo si tiene menos de 4 rollos en las 8 posiciones adyacentes. 

Ahora nuestro objetivo es calcular cuántos rollos están disponibles, pero ahora el cambio es que se recorrera la cuadrícula la cantidad de veces necesarias para sacar todos los rollos que puedan ser accesibles, lo que hace que rollos que no podían ser sacados en pimera inatancia, en la siguiente pasada si que puedan seer sacados.

### Explicación del Código 

Para la resolución primero definimos una estructura para representar la posición de un rollo (generar la tabla). Esta estructura nos ayudará a almacenar información importante sobre el rollo como la posición del rollo ya que esta es fundamental para saber dónde se encuentra y cómo se puede utilizar. Al definir esta estructura, podemos empezar a trabajar con los rollos de manera más efectiva. 

Generamos la clave:

```cpp
 struct Key {
    int x, y;
    bool operator==(Key const& o) const {
        return x == o.x && y == o.y;
    }
};
```
Y luego definimos el hasher:

```cpp
struct Hasher {
    size_t operator()(Key const& k) const {
        return ((long long)k.x << 32) ^ (long long)k.y;
    }
};
```
A continuación se crea la clase RollsHash, que implementa una nueva tabla hash con sus métodos y constructores utilizando los datos de primera, esto para usarla como tabla auxiliar:

```cpp
class RollsHash
``` 
Ya en el main ceamos una tabla con la clase llamada rolls y leemos la cuadrícula línea por línea, almacenando los rollos en la tabla hash: 

```cpp
RollsHash rolls; 
string line; 
int y = 0; 
while (getline(cin, line)) { 
    for (int x = 0; x < (int)line.size(); x++) { 
        if (line[x] == '@') rolls.insert({x,y}); 
    } 
    y++; 
}
```
Definimos las posiciones adyacentes que establecen los valores de las posiciones adyacentes:

```cpp
const int dx[8] = {-1,-1,-1, 0,0, 1,1,1}; 
const int dy[8] = {-1, 0, 1,-1,1,-1,0,1};
```
Y por último mediante un while realizamos el mismo código que en la parte 1 pero ahora borrando y volviendo a recorrer hasta que no se puedan sacar más rollos.

### Comentarios 

Con esta implementación hemos aprendido que usar una tabla hash permite consultar, insertar y eliminar rollos en tiempo constante promedio, lo que optimiza el proceso frente a recorrer toda la cuadrícula en cada iteración. 

### Valoración del Problema 

Gracias a este código hemos visto la importancia de elegir la estructura de datos adecuada: usando hashing podemos resolver el mismo problema de forma más eficiente y escalable, y además practicar conceptos como colisiones y encadenamiento. 
