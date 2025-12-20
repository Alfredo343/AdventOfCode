## **DÍA 3**

### Programación Dinámica
Este problema corresponde con la PRIMERA parte del ejercicio 3 del Advent of Code.

Seleccionamos este problema ya que debido a la técnica utilizada, mencionada en el título, era bastante adecuada.

### Explicaión General del Problema

Para la resolución de este ejercicio se ha hecho uso de programación dinámica, un método que consiste en introducir el resultado de las funciones en una memoria dinámica para almacenarlo y usarlo más adelante. El problema principalmente se basa en saber el mayor número de sacudidas posibles que puede realizarse en cada banco según el número que resulta al juntar 2 baterias de las que componen cada banco, que se iran sumando para dar el máximo total de sacudidas del conjunto de los bancos. Para ello usamos una memoría dinámica que se encarga de ir guardando el valor mas grande de cada banco para poder ir sumandolo al siguiente valor.

### Explicación del Código

Primeramente hemos implementado una función para encontrar el valor maximo que pueden formar dos baterias de un banco:

```cpp
long long maxJoltage(const string &bank)
```
Esto se corresponde con la cabecera de la función de busqueda.

```cpp
dp[0][0] = 0;
```
Y este fragmento es la inicialización de la memoría dinámica, posteriormente, haciendo uso de for e if, comprobamos si despreciamos el digito:

```cpp
dp[i + 1][k] = max(dp[i + 1][k], dp[i][k]);
```
O lo cogemos:

```cpp
 dp[i + 1][k + 1] = max(dp[i + 1][k + 1], dp[i][k] * 10 + digit);
```
Y finalmente devolvemos la memoria:

```cpp
return dp[n][2];
```
Ahora vamos a pasar con la segunda función implementada, una función que lee una linea entera de baterias que correspanden a un banco.

```cpp
vector<string> leerBancos()
```
Esto se corresponde con la respectiva cabecera de la función que crea un string para cada cadena de números:

```cpp
vector<string> bancos;
```
Esta función consta de un while que se encarga de leer cada linea.

Por ultimo tenemos otra función que recorre todos los bancos haciendo uso de funciones anteriores y calcula el total de carga:

```cpp
long long totalJoltage(const vector<string> &bancos)
```
En ella recorremos todo un banco con un for y vamos añadiendo los valores para sumarlos.

Ya en el main hacemos uso de las funciones anteriores para poder dar solución al problema.
Creamos una variable 'bancos' para almacenar una función:

```cpp
auto bancos = leerBancos();
```
Y un total para almacenar la salida de la carga total:

```cpp
long long total = totalJoltage(bancos);
```

### Comentarios

En un inicio, este código habíamos pensado hacerlo con divide y vencerás ya que la idea de dividir las baterias de banco para su posterior análisis nos parecía buena, pero después de implementarlo nos dimos cuenta que en realidad este método no cumplía su función ya que no reducía el código. Con una programación dinámica o con fuerza bruta se podía llegar a la misma cantidad de tiempo , por tanto, decidimos usar una memoria dinámica para almacenar de forma más segura todos los datos de las baterias y así hacerlo de una forma más profesional.

### Valoración del Problema

Gracias a este código hemos aprendido que no siempre vas a resolverlo todo con el primer método que se te ocurre, además de la forma de implementar la memoria dinámica fuera del entorno de un examen sabiendo como hacerlo en un caso de un problema real.
