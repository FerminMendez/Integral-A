Ordenamiento de cartas del juego King of Tokyo

Este proyecto está basado en el juego de mesa king of tokyo. Un juego de hasta 6 jugadores donde se enfrentan los jugadores tratando de eliminar a los demás o conseguir puntos para ganar.

Para esta implementación digital se espera tener un dierectorio de cartas y poder ordenarlos por costo y nombre.

El programa recupera los nombres y costos de las cartas desde un archivo csv y los acomoda por costo y nombre.

SICT0302B: Toma decisiones
Selecciona y usa una estructura lineal adecuada al problema.

Considerando que el mazo consta de 66 cartas podemos decidir que se trata de un arreglo pequeño, por lo que el tiempo de ejecución no será una gran diferencia entre un algoritmo y otro. Por esta razón opté por implementar algo que no ocupe mucha memoria y sea fácil de implementar. Un insertion sort. En la línea 73 y 78 se muestra un swap auxiliar y el sort respectivamente.

SICT0301B: Evalúa los componentes
Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa,
los casos de pruebas para todas las funciones se encuentran pruebas.cpp donde se prueban las funciones de:

En este caso, ya hablamos que usaremos un insertion sort con O(n^2) como es conocido. Debidoa a que el orden en el que se llenó el archivo es aleatorio no nos encontraremos con el peor caso. Por otra parte, en el main se muestra la ejecución de el ordenamiento por costo y alfabeto.

SICT0303B: Implementa acciones científicas

Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa. Usar de manera
En este caso los datos se recuperan directamente desde un archivo csv.


