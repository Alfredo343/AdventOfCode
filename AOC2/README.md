## **DÍA 2**

### Programación Dinámica
Este problema corresponde con la PRIMERA parte del ejercicio 2 del Advent of Code.

Seleccionamos este problema ya que debido a la técnica utilizada, mencionada en el título, era bastante adecuada.

### Explicaión General del Problema

Para la resolución de este ejercicio se ha hecho uso de programación dinámica, un método que consiste en introducir el resultado de las funciones en una memoria dinámica para almacenarlo y usarlo más adelante. El problema principalmente se basa en una entrada compuesta por una lista de IDs y se trata de comprobar cuales son válidos y cuales inválidos. Para ello hay ciertos condiciones que deben cumplir para ser inválidos y así que el programa los almacene en una variable y los vaya contando y así devolver la suma de todos ellos como un numero entero y sin signo. Para ello lo que hemos ido haciendo es almacenar la cadena, usando una memoria dinámica, e ir sumando en esta el nuevo ID inválido encontrado.

### Explicación del Código

Primeramente hemos implementado una función para pasar las cadenas de números a strings y asi facilitar la tarea de separación entre números y guiones, además de crear a su vez la memoría dinámica para almacenar los inválidos

```cpp
char* numToStr(long long n)
```
Esto se corresponde con la cabecera de la función de conversión

```cpp
char* s = new char[len + 1];
```
Y este fragmento es la memoría dinámica

Ahora vamos a pasar con la segunda función implementada, una función que identifica si un ID es válido o no, que es lo que se basa el problema.

```cpp
bool Invalido(long long n)
```
Esto se corresponde con la respectiva cabecera de la función que tiene como entrada n, el ID:

```cpp
bool esInvalido = (strncmp(s + half, bloque, half) == 0);
```
Con esta línea de codigo conprobamos si se cumplen las condiciones, al comparar la primera y segunda parte del ID, para ser o no inválido

Ya en el main hacemos uso de las funciones anteriores para poder dar solución al problema.
Para ello creamos una variable llamda suma:

```cpp
unsigned long long suma = 0;
```
En ella almacenaremos la suma de los ID inválidos.
Más adelante comprobamos donde esta el guión:

```cpp
size_t pos = rango.find('-');
```
Y según la longitud del ID les asignamos un inicio y un fin:

```cpp
long long inicio = atoll(rango.substr(0, pos).c_str());
long long fin    = atoll(rango.substr(pos + 1).c_str());
```
Para luego comprobar si son o no invalidos mediante la llamada a la funcion 'Invalido' dentro de un for:

```cpp
for (long long i = inicio; i <= fin; ++i) {
            if (Invalido(i))
                suma += i;
        }
```

Y finalmente imprimir por pantalla el resultado con un cout:

```cpp
cout << suma << "\n";
```

### Comentarios

En un inicio, este código habíamos pensado hacerlo con divide y vencerás ya que la idea de dividir el ID para su posterior análisis nos parecía buena, pero después de implementarlo nos dimos cuenta que en realidad este método no cumplía su función ya que no reducía el código. Con una programación dinámica o con fuerza bruta se podía llegar a la misma cantidad de tiempo , por tanto, decidimos usar una memoria dinámica para almacenar de forma más segura todos los datos de los ID y así hacerlo de una forma más profesional.

### Valoración del Problema

Gracias a este código hemos aprendido que no siempre vas a resolverlo todo con el primer método que se te ocurre, además de la forma de implementar la memoria dinámica fuera del entorno de un examen sabiendo como hacerlo en un caso de un problema real.





















