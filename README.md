Calculadora de dosis por gramaje para medicamentos sin prescipción médica
Este proyecto se basa en la siguiente página web calculadora donde para usarse se sigue el siguiente comporamiento:

Ejemplo 1: Augmentine "125" suspensión, (125/31,25 mg/5 ml)

Paso 1: Introducir el peso del paciente. Por ejemplo: 8 kg. Paso 2: Introducir la posología deseada. Por ejemplo: 40 mg/kg/día. Paso 3: Introducir la presentación. Suspensión.

Con estos datos se obtiene la dosis al día: 320 mg/día.

Paso 4: Elegir el número de dosis al día: 3 dosis = cada 8 horas. Paso 5: Introducir los mg que contiene la unidad (en este caso el ml). Si la concentración es de 125 mg/5 ml. Los mg/ml = 125/5 = 25 mg/ml. Para resolver este cálculo tenemos a la derecha otra calculadora.

Obtenemos: 106,67 mg/dosis = 4,28 ml cada 8 horas.

Adicionalmente incluyo las funciones para registrar nuevo medicamentos y ver los medicamentos registrados por orden alfabético o por cantidad de gramaje

SICT0302B: Toma decisiones
Selecciona y usa una estructura lineal adecuada al problema
Uso una lista doblemente encadenada para regristrar las medicinas porque quiero acceder rápidamente a la registrada más recientemente (head), pero también necesito consultar cuál fue la primera que se agrego (tail), cada medicina es un objeto que contiene (... ) los elementos se pueden insertar y eliminar usando la lista como se muestra en el código en las funciones agrega medicina, elimina medicina, y obten gramaje, que se encuentran en el archivo medicinas.h en las líneas 55, 80 y 124 respectivamente.

Selecciona un algoritmo de ordenamiento adecuado al problema
Para este problema utilice un algoritmo de tipo merge sort, para poder organizar las medicinas por orden alfabético ascendente y despues descendente use merge sort porque es rápido en la mayoría de los casos y porque es poco probable que me encuentre son su peor caso, ya que las lista inicial siempre está desordenada. Las fuciones donde se puede ver es en ordena medicinas ascendente y ordena medicina descendente en el archivo reportes.h las líneas 50 y 78.

Usa un árbol adecuado para resolver un problema
Usé un BST para ordenar las medicinas por su gramaje y poder encontrar rápidamente medicinas con gramaje similar. Usé un BST porque mi lista incial viene desordenada, por lo que es poco probable que el BST se degenere.

Las funciones donde lo uso es en obten medicina por gramaje y medicinas con mismo gramaje que se encuentran en reportes.h en las líneas 100 y 130

SICT0301B: Evalúa los componentes
Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa,
los casos de pruebas para todas las funciones se encuentran pruebas.cpp donde se prueban las funciones de:

la lista doblemente ligada de medicinas

el ordenamiento sobre la lista ligada de medicinas

el acceso al BST por gramaje

Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes,
lista de medicinas
función de acceso por valor: O(n) por que para llegar a la medicina tengor que recorrer la listay comparar cada valor.

funcion de inserción: O(1) siempre uso insert first.

función de borrado: O(n/2 + b) porque para borrarla tengo que buscar la posición y uso head o tail y ya que la encuentro me toma b pasos constantes borrarla

ordenamiento de medicinas
ordenamiento con merge sort: ...

uso de árbol
crear árbol de gramaje: ...

agregar nodo a árbol gramaje: ...

econtrar nodo en árbol gramaje: ...

SICT0303B: Implementa acciones científicas
Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa.
El programa tiene la opción de buscar medicinas por nombre direcamente en la lista (opción 3 en el menú) El programa muestra resportes ordenados de medicinas (opción 4 en el menú) El programa permite obtener medidas de gramaje del árbol (opción 5 en el menú)

Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa. Usar de manera
Las medicinas están registradas en el archivo medicinas.csv de donde se leen al iniciar el programa.

Implementa mecanismos de escritura de archivos correctos y útiles dentro de un programa. Usar de manera
Las medicinas agregadas se guardan al final del archivo medicinas.csv, con la función agrega nueva medicina, para que no tengan que ser recapturadas cada que vez que se corre el programa.
