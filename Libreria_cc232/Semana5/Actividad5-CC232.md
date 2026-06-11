## Actividad 5 - CC232

### Estudiante

- Nombre: Chumbimuni Ricci Andre Dylan

### Bloque 1 - Núcleo conceptual de la semana

1. Explica con tus palabras qué diferencia hay entre un árbol binario enlazado y un árbol binario almacenado implícitamente en un arreglo.

Un arbol binario enlazado es una estructura que esta hecha por BinNode que guarda punteros padre y 2 hijos, es creada dinamicamente con nodos enlazados; un arbol binario tiene nodos que almacenan un vector, es compacto y buena con la localidad(sus punteros se calculan los indices).

2. Explica qué información guarda un `BinNode`: dato, padre, hijo izquierdo, hijo derecho y altura.

Guarda los datos del nodo al que apunta, el nodo parent, left , right y la altura del subarreglo sino fuera la raiz.

3. Explica por qué el puntero `parent` permite implementar operaciones como `succ()`, `pred()` y actualización ascendente de alturas.

El puntero parent rompe la limitación unidireccional del árbol proporcionando una vía de regreso hacia arriba.

Para succ() (Sucesor inorden): Si el nodo actual no tiene un subárbol derecho, su sucesor matemático se encuentra arriba. El puntero parent permite ascender por la rama hasta encontrar el primer ancestro del cual somos un descendiente izquierdo.

Para pred() (Predecesor inorden): Funciona bajo la misma lógica inversa; si no hay subárbol izquierdo, parent permite subir por el árbol para buscar el ancestro inmediato anterior en orden numérico.

Para la actualización ascendente de alturas (updateHeightAbove): Cada vez que insertas o eliminas un nodo, la altura de sus ancestros puede cambiar. El puntero parent permite disparar un bucle while que viaja en reversa hacia la raíz, recalculando y corrigiendo las alturas nivel por nivel de forma quirúrgica, afectando únicamente a la rama modificada sin tener que recalcular todo el árbol.

4. Explica qué responsabilidad tiene `BinTree` frente a `BinNode`.

BinNode maneja la estructura local del nodo (punteros y datos). BinTree asume el control global de la estructura: administra la raíz, el tamaño total (size_), la memoria (destrucción de nodos) y la consistencia de las alturas al insertar o remover subárboles.

5. Explica qué agrega `BinaryTree` sobre la infraestructura base de `BinTree`.

Agrega la capacidad de navegación avanzada e iteración: provee iteradores estándar (begin, end), cálculo de profundidades (depth), dibujo en consola (asciiArt) y recorridos ordenados por sucesores o predecesores usando los punteros del nodo.

6. Explica qué propiedad adicional convierte un árbol binario en un `BinarySearchTree`.

La propiedad de orden simétrico: para cada nodo, todos los valores de su subárbol izquierdo deben ser estrictamente menores que él, y todos los de su subárbol derecho deben ser mayores o iguales.

7. Explica qué propiedad adicional convierte un arreglo en un `BinaryHeap` mínimo.

La propiedad del heap mínimo: el valor de cualquier nodo debe ser menor o igual que el de sus hijos (left y right), manteniendo el árbol perfectamente completo y compacto en memoria (sin huecos en el arreglo).

8. Compara la propiedad de orden de un BST con la propiedad de prioridad de un heap.

BST (Orden Izquierda-Derecha): Divide horizontalmente. Permite búsquedas rápidas de cualquier elemento ($O(\log n)$) porque mantiene un ordenamiento total.

Heap (Orden Arriba-Abajo): Divide verticalmente por niveles. Solo garantiza que el mínimo está en la raíz, optimizando el acceso exclusivo al elemento prioritario ($O(1)$).

9. Explica por qué un recorrido inorden de un BST produce una secuencia ordenada.

Porque sigue el patrón Izquierda $\rightarrow$ Raíz $\rightarrow$ Derecha. Por la propiedad del BST, este orden procesa de forma matemática primero los elementos menores, luego el nodo actual y al final los elementos mayores.

10. Explica por qué un heap no permite, por sí solo, recorrer los elementos en orden sin destruir o copiar la estructura.

Porque el heap no es una estructura totalmente ordenada; solo garantiza prioridad local entre padres e hijos. No existe ninguna relación de orden fija entre hermanos (izquierdo y derecho) ni entre ramas distintas, obligando a extraer la raíz repetidamente (destruyendo el heap) para conocer el orden real.

### Bloque 2 - Navegación, altura, profundidad y tamaño

1. En `BinNode`, explica qué significan `hasLeft()`, `hasRight()`, `isRoot()`, `isLeaf()`, `isLeftChild()` e `isRightChild()`.

Inspeccionan las estructuras de nodo como: hasLeft(tiene hijo izquierdo), hasRight(tiene hijo derecho), isRoot(es la raiz), isLeaf(es hoja), isLeftChild(el hijo izquierdo de mi padre), isRightChild(el hijo derecho de padre).

2. Explica el caso en que `succ()` baja al subárbol derecho y luego busca el nodo más a la izquierda.

Si el nodo tiene hijo derecho, baja al subarbol  derecho(s=right) y busca el mas a la izquierda(s=s->left)

3. Explica el caso en que `succ()` sube por los ancestros hasta encontrar el primer giro hacia la izquierda.

Ocurre cuando el nodo no tiene hijo derecho. El algoritmo sube usando parent mientras el nodo actual sea el hijo derecho de su padre (ya que esa rama ya fue procesada). Se detiene al llegar al primer ancestro del cual somos descendientes por la izquierda; ese padre es el sucesor.

4. Explica simétricamente cómo debe funcionar `pred()`.

Si tiene hijo izquierdo: Baja un paso a la izquierda (s = left) y busca el nodo más a la derecha de ese subárbol (s = s->right).

Si no tiene hijo izquierdo: Sube por los ancestros usando parent mientras sea hijo izquierdo. El primer padre del cual sea hijo derecho será su predecesor.

5. Dibuja un árbol de al menos 7 nodos y marca el sucesor y predecesor inorden de tres nodos distintos.
```
Arbol:
│       ┌── 12
│   ┌── 10
│   │   └── 8
└── 7
    │       ┌── 6
    │   ┌── 5
    │   │   └── 4
    └── 3
        └── 1
```
Para el Nodo 5 (Caso con dos hijos):

Predecesor (4): Es el nodo más a la derecha de su subárbol izquierdo.

Sucesor (6): Es el nodo más a la izquierda de su subárbol derecho.

Para el Nodo 1 (Caso Nodo Hoja Extremo):

Predecesor (No tiene / nullptr): Al ser el Primer nodo inorden, no existe ningún elemento menor que él.

Sucesor (3): Al no tener hijo derecho, sube por su parent directo.

Para el Nodo 8 (Caso Hoja Intermedia):

Predecesor (7): No tiene hijo izquierdo, sube por los ancestros. Como 8 es hijo izquierdo de 10, sigue subiendo. Al llegar a 10, este es hijo derecho de 7, por lo que el giro a la derecha determina que 7 es su predecesor.

Sucesor (10): Al no tener hijo derecho, sube hacia su parent. Como 8 es el hijo izquierdo de 10, el giro se completa en un solo paso hacia arriba.

6. Explica qué calcula `depth(u)` y por qué puede implementarse subiendo por `parent`.

Calcula la profundidad del nodo (la distancia desde la raíz hasta u). Se implementa subiendo por parent porque existe un único camino directo y lineal desde cualquier nodo hacia la raíz, bastando un bucle que cuente los pasos hacia arriba hasta que parent == nullptr.

7. Explica qué calcula `height(u)` y por qué suele implementarse bajando recursivamente por los hijos.

Calcula la altura del nodo (la distancia desde u hasta la hoja más profunda de su subárbol). Requiere bajar recursivamente porque un nodo puede tener múltiples ramificaciones hacia abajo y se debe explorar cada camino para encontrar el máximo entre la altura izquierda y derecha: $1 + max$(altura_izq, altura_der).

8. Explica qué calcula `subtreeSize(u)`.

Calcula el tamaño del subárbol que nace en u (es decir, la cantidad total de nodos que dependen de él, incluyéndose a sí mismo). Se obtiene sumando el tamaño del subárbol izquierdo, el del derecho, más $1$ por el nodo actual.

9. Demuestra que para todo nodo `u` se cumple `depth(u) + height(u) <= height(T)`.

Por definición, depth(u) es la longitud del camino desde la raíz hasta u, y height(u) es el camino más largo desde u hasta una hoja. La suma de ambos representa la longitud de un camino completo de raíz a hoja que pasa obligatoriamente por u. Como height(T) es, por definición, el camino absoluto más largo posible de todo el árbol de raíz a hoja, cualquier otro camino que pase por un nodo u cualquiera será menor o igual a este máximo global.

10. Indica la condición necesaria y suficiente para que se alcance la igualdad anterior.

La igualdad $depth(u) + height(u) = height(T)$ se cumple si y solo si el nodo u pertenece al camino más largo que define la altura máxima de $T$.

### Bloque 3 - Recorridos y trazado guiado

| Recorrido | Versión Revisada | Estructura Auxiliar | Secuencia Producida (Árbol de Prueba) | Argumento de Correctitud y Costo |
| :--- | :--- | :---: | :--- | :--- |
| **Preorden** | `travPre` (Recursivo) | Pila de llamadas | `7 3 1 5 4 6 10 8 12` | **Correctitud:** Visita la raíz y delega los hijos. Costo temporal $O(n)$ y espacial $O(h)$ por la pila del sistema. |
| **Preorden** | `travPreIterative2` | `std::stack` | `7 3 1 5 4 6 10 8 12` | **Correctitud:** Procesa la raíz y apila primero el hijo derecho para asegurar extraer el izquierdo antes. Costo: $O(n)$ tiempo, $O(h)$ espacio. |
| **Inorden** | `travInRecursive` | Pila de llamadas | `1 3 4 5 6 7 8 10 12` | **Correctitud:** Explora al extremo izquierdo, procesa la raíz y pasa a la derecha. Genera secuencia ordenada si es BST. Costo: $O(n)$ tiempo, $O(h)$ espacio. |
| **Inorden** | `travInIterative1` | `std::stack` | `1 3 4 5 6 7 8 10 12` | **Correctitud:** Emula la recursión guardando los ancestros izquierdos en una pila explícita antes de procesarlos. Costo: $O(n)$ tiempo, $O(h)$ espacio. |
| **Inorden** | `travInIterative2` | Ninguna (Punteros) | `1 3 4 5 6 7 8 10 12` | **Correctitud:** Decide la ruta comparando los punteros `prev` y `curr` sin estructuras auxiliares. Costo: $O(n)$ tiempo, $O(1)$ espacio auxiliar (Óptimo). |
| **Inorden** | `travInIterative3` | Ninguna (Punteros) | `1 3 4 5 6 7 8 10 12` | **Correctitud:** Empieza en el nodo `leftmost()` y salta secuencialmente usando `succ()`. Costo: $O(n)$ tiempo total (cada enlace se cruza máximo 2 veces), $O(1)$ espacio. |
| **Postorden** | `travPost` (Recursivo) | Pila de llamadas | `1 4 6 5 3 8 12 10 7` | **Correctitud:** Procesa primero ambos hijos por completo antes de realizar el `visit()` sobre la raíz. Costo: $O(n)$ tiempo, $O(h)$ espacio. |
| **Postorden** | `travPostIterative` | Dos `std::stack` | `1 4 6 5 3 8 12 10 7` | **Correctitud:** La primera pila invierte un preorden modificado (Raíz, Derecha, Izquierda) pasándolo a la segunda pila para su salida. Costo: $O(n)$ tiempo y $O(n)$ espacio. |
| **Por Niveles** | `travLevel` | `std::queue` | `7 3 10 1 5 8 12 4 6` | **Correctitud:** Estrategia BFS. Procesa celdas horizontalmente metiendo los hijos directos en una cola FIFO. Costo: $O(n)$ tiempo, $O(w)$ espacio ($w = \text{ancho máximo}$). |

1. ¿Qué significa visitar un nodo en preorden?

El nodo que esta siendo visitado en preorden cuando se esta ejecutando el visit(), visitar a la raiz antes que a los hijos

2. ¿Qué significa visitar un nodo en inorden?

Esto visita primero al hijo por la izquierda luego la raiz  para luego la derecha.

3. ¿Qué significa visitar un nodo en postorden?

Significa procesar de forma completa e íntegra todos los descendientes del nodo antes de efectuar la acción sobre el nodo mismo. El orden estricto es: Subárbol Izquierdo $\rightarrow$ Subárbol Derecho $\rightarrow$ Raíz. Es ideal para tareas destructivas (como liberar la memoria del árbol) porque no puedes borrar un padre sin haber borrado sus hijos primero.

4. ¿Qué significa visitar un árbol por niveles?

Significa recorrer la estructura horizontalmente de manera secuencial (estrategia BFS), procesando primero todos los nodos de profundidad $d$ antes de pasar a cualquiera de profundidad $d+1$, avanzando siempre de izquierda a derecha en cada nivel.

5. ¿Por qué los recorridos recursivos tienen tiempo `O(n)`?

Porque la definición estructural garantiza que cada nodo del árbol es alcanzado exactamente una única vez por cada llamada o bifurcación del método. No existen ciclos internos repetitivos ni evaluaciones redundantes sobre nodos previamente procesados.

6. ¿Por qué las versiones iterativas también tienen tiempo `O(n)`?

Porque aunque utilicen estructuras de control lineales (stack o queue), cada nodo individual del árbol se inserta y se remueve de dichas colecciones exactamente una sola vez. En los algoritmos basados puramente en punteros (Iterative2 e Iterative3), los enlaces entre nodos vecinos se cruzan un número constante de veces (máximo 2 o 3 pasadas por arista), manteniendo la linealidad.

7. ¿Cuál es la memoria auxiliar de un recorrido recursivo en un árbol balanceado?

La memoria auxiliar es logarítmica: $O(\log n)$. Al estar el árbol perfectamente equilibrado, la altura del árbol ($h$) está acotada por $\log_2(n)$, lo que implica que la pila de llamadas del procesador nunca acumulará más de $\log(n)$ marcos de función activos en simultáneo.

8. ¿Cuál es la memoria auxiliar de un recorrido recursivo en un árbol degenerado?

La memoria auxiliar es lineal: $O(n)$. En un árbol degenerado (que tiene forma de lista enlazada o "zig-zag"), la altura es igual al número total de nodos ($h = n$). La recursión se ve obligada a apilar todas las funciones en memoria al mismo tiempo, lo que arriesga al sistema operativo a sufrir un colapso por Stack Overflow.

9. ¿Qué diferencia hay entre usar una pila explícita y usar la pila de llamadas?

Pila explícita (std::stack): Se gestiona de forma directa dentro de la memoria dinámica (Heap de datos) de nuestra aplicación. Nosotros controlamos su ciclo de vida y tamaño sin peligro inmediato de colapso crítico del sistema.

Pila de llamadas: Es administrada de forma implícita por el hardware y el compilador en un espacio de memoria restringido y pequeño. Un error de diseño o una profundidad excesiva en los datos gatilla un fallo catastrófico de segmentación (Stack Overflow).

10. ¿Por qué la cola del recorrido por niveles puede crecer mucho más en un árbol completo que en un árbol degenerado?.

Porque en un árbol degenerado el ancho máximo en cualquier nivel es siempre $1$. Por el contrario, en un árbol completo, el último nivel concentra de forma exponencial a la mitad de todos los elementos de la estructura ($\approx n/2$). Al avanzar horizontalmente, la cola debe retener de golpe a todos los nodos de ese nivel masivo antes de poder despacharlos, provocando que la memoria consumida por la cola explote de manera lineal con respecto al tamaño global del árbol.

### Bloque 4 - Demostración: evidencia observable

| Archivo | Salida u Observable Importante | Idea Estructural | Argumento de Costo, Espacio o Diseño |
| :--- | :--- | :--- | :--- |
| `demo_binary_tree.cpp` | Listas de secuencias idénticas para los inórdenes (`1 3 4 5 6 7 8 10 12`). `Sucesor de 5: 6`. | Árbol binario enlazado clásico donde cada nodo conoce a sus hijos y a su padre (`parent`). | El costo temporal de los recorridos es lineal $O(n)$. Las versiones iterativas `#2` y `#3` logran costo espacial óptimo $O(1)$ eliminando la pila. |
| `demo_bst.cpp` | `lowerBound(9): 10`. Impresión del árbol balanceado desde un vector ordenado. `isBST: si`. | Árbol de búsqueda binaria que mantiene la propiedad de orden simétrico (izquierda $<$ raíz $\le$ derecha). | Las búsquedas toman tiempo logarítmico $O(\log n)$ si el árbol está balanceado. El método `buildBalancedFromSorted` lo garantiza en $O(n)$. |
| `demo_heap.cpp` | El primer elemento del arreglo tras `heapify` o `add(0)` es siempre el mínimo absoluto (`0`). | Árbol binario completo empaquetado de forma implícita y contigua dentro de un `std::vector`. | El acceso al mínimo es constante $O(1)$. `heapify()` reestructura todo el vector de forma óptima en tiempo lineal $O(n)$ en vez de $O(n \log n)$. |
| `demo_capitulo5_panorama.cpp`| Coexistencia de `BinaryHeap`, `BinarySearchTree` e iteración estilo contenedores STL (`for (int x : bst)`). | Integración de las estructuras no lineales en el espacio de nombres de la librería (`ods`). | Muestra que el diseño orientado a objetos encapsula la complejidad interna, exponiendo interfaces uniformes, reutilizables y seguras para el usuario. |

1. En `demo_binary_tree.cpp`, ¿qué salida permite verificar que los recorridos visitan los nodos en el orden esperado?

La comparación directa de las secuencias impresas en la consola. Que los métodos recursivos e iterativos (como Inorden recursivo, e Iterativos #1, #2 y #3) impriman exactamente los mismos elementos y en el mismo orden (1 3 4 5 6 7 8 10 12) valida empíricamente que la lógica de ruteo es correcta.

2. ¿Qué parte de la demo permite defender que `succ()` y `pred()` respetan el orden inorden?

Las impresiones de los vecinos del nodo 5 (Sucesor de 5: 6 y Predecesor de 5: 4), junto con la secuencia de Iteracion por sucesor. Al verificar la cadena ordenada del inorden, se observa que el 4 está inmediatamente antes y el 6 inmediatamente después del 5, demostrando que los saltos por punteros respetan la secuencia lineal matemática.

3. ¿Qué evidencia produce la representación ASCII del árbol?

Produce evidencia topológica y visual de la estructura real guardada en memoria. Permite verificar de forma directa qué nodo quedó asignado como hijo izquierdo o derecho (a través de las ramas ┌── y └──) y validar visualmente si el árbol se encuentra balanceado o si tiene ramas degeneradas.

4. En `demo_bst.cpp`, ¿qué observable permite defender que el inorden del BST queda ordenado?

La línea BST inorden: 1 3 4 5 6 7 8 10 12. Al insertar los elementos de forma desordenada en el bucle (7, 3, 10, 1...) y obtener una salida perfectamente ordenada de menor a mayor en el inorden, se constata que la estructura reorganizó internamente los nodos bajo la propiedad de búsqueda binaria.

5. ¿Qué operaciones de búsqueda se distinguen mejor en la demo del BST: `find`, `findEQ`, `lowerBound` o `upperBound`?

Se distinguen mejor lowerBound y upperBound al buscar valores inexistentes o límites. Por ejemplo, al ejecutar lowerBound(9) el árbol no encuentra el 9 pero retorna el 10 (el menor elemento que es $\ge 9$), mientras que upperBound(8) retorna el 10 (el primer elemento estrictamente $> 8$), marcando la sutil diferencia matemática entre ambos.

6. En `demo_heap.cpp`, ¿qué salida permite defender que el mínimo queda en la raíz?

La salida de la función heap.remove() y las impresiones del vector base. Al invocar remove() el sistema extrae un 0 (el menor de todos), y en la línea de Heapify, la primera posición del vector (data()[0]) contiene de forma consistente al valor más pequeño del conjunto actual.

7. ¿Qué evidencia permite distinguir entre insertar con `add()` y construir con `heapify()`?

La disposición interna del vector resultante. Si insertas elementos uno por uno con add(), el árbol sufre reajustes locales sucesivos (bubbleUp) costando $O(n \log n)$ en total. heapify() toma el vector desordenado completo y aplica trickleDown desde la mitad hacia atrás, lo cual se evidencia en la consola porque reorganiza los datos en una sola pasada masiva y eficiente de costo lineal $O(n)$.

8. En `demo_capitulo5_panorama.cpp`, ¿qué comparación resume mejor la semana: árbol enlazado, BST o heap?.

El Árbol Enlazado provee la infraestructura física pura y libre (punteros y conectividad).

El BST restringe esa infraestructura imponiendo un orden horizontal estricto (ideal para buscar cualquier elemento).

El Heap sacrifica los punteros por un arreglo implícito y restringe el orden de forma vertical (prioridad arriba-abajo), ideal para despachar solo el elemento mínimo de forma óptima.

#### Bloque 5 - Pruebas públicas, pruebas internas e invariantes

1. ¿Qué operaciones del BST valida la prueba pública?

Valida el ciclo de operaciones esenciales de un árbol de búsqueda binaria: inserción ordenada mediante add(), rechazo de claves duplicadas, búsquedas especializadas (findEQ(), find(), lowerBound(), upperBound()), extracción de extremos (minNode(), maxNode()), eliminación de nodos intermedios (remove()), validación de consistencia estructural (isBST()), soporte para iteración estándar STL y construcción optimizada con balanceo desde vectores ordenados (buildBalancedFromSorted()).

2. ¿Qué casos validan que el BST no acepta duplicados?

Lo valida explícitamente la línea expect(!bst.add(5), "BST no debe aceptar duplicados");. Al intentar insertar un segundo 5 en un árbol que ya posee esa clave, el método add() intercepta la colisión y retorna false, confirmando que el árbol mantiene estrictamente un conjunto de elementos únicos.

3. ¿Qué se verifica al comparar el inorden recursivo con las versiones iterativas?

Se verifica la equivalencia funcional absoluta y la consistencia del ordenamiento simétrico. Al forzar que el inorden recursivo y los tres métodos iterativos (Iterative1, Iterative2, Iterative3) devuelvan exactamente el mismo vector ordenado ({1, 3, 4, 5, 6, 7, 8, 10, 12}), se demuestra que la optimización de código y la sustitución de la pila de llamadas del sistema por bucles o punteros no alteran el resultado matemático esperado.

4. ¿Qué se espera de `findEQ(8)` en la prueba pública?

Se espera que localice de forma exacta el nodo que contiene la clave 8 y devuelva un puntero válido hacia él (findEQ(8) != nullptr), permitiendo comprobar que la información recuperada coincide con el valor de búsqueda (->data == 8).

5. ¿Qué se espera de `lowerBound(9)` y `upperBound(8)`?

De lowerBound(9) se espera que devuelva el nodo con valor 10, ya que el 9 no existe y 10 es el menor elemento que es mayor o igual ($\ge 9$).De upperBound(8) se espera que devuelva el nodo con valor 10, pues busca el primer elemento estrictamente mayor ($> 8$), ignorando la existencia exacta del 8.

6. ¿Qué propiedad se valida con `isBST()`?

Valida de forma exhaustiva el orden simétrico global del árbol. Inspecciona recursivamente que para cada nodo del árbol se cumpla el invariante de que todas las claves en su subárbol izquierdo sean menores y todas las de su subárbol derecho sean mayores.

7. ¿Qué se valida después de eliminar un nodo con `remove()`?

Que la función devuelva éxito (true).

Que la propiedad de orden no se haya roto (el inorden resulta en {1, 4, 5, 6, 7, 8, 10, 12}).

Que una búsqueda posterior confirme la ausencia del elemento (!bst.contains(3)).

8. ¿Qué valida `checkParentLinks()` después de borrar, separar o adjuntar subárboles?

Valida la integridad bidireccional del grafo. Asegura que después de cualquier reestructuración destructiva o de movimiento de memoria, cada enlace hijo-padre concuerde perfectamente. Es decir, que si el nodo $A$ apunta al nodo $B$ como su hijo, el nodo $B$ apunte obligatoriamente al nodo $A$ como su parent.

9. ¿Qué operaciones del heap valida la prueba pública?

Valida la construcción masiva y lineal en lote (heapify), el invariante de prioridad superior (isHeap() e isHeapArray()) y el proceso de extracción ordenada mediante reajuste descendente (remove()).

10. ¿Qué demuestra extraer repetidamente de un min-heap hasta vaciarlo?

Demuestra el principio operativo del ordenamiento por montículos (Heapsort). Al vaciar el heap y almacenar cada elemento extraído con remove(), se comprueba empíricamente que los elementos emergen en una secuencia perfectamente ordenada de menor a mayor ({1, 2, 3, 5, 7, 8, 10}), confirmando que la raíz siempre retuvo al mínimo absoluto del conjunto.

11. ¿Qué operaciones de `BinTree` se validan con `attachAsRC`, `secede` y `removeSubtree`?

attachAsRC: Conecta un árbol externo como hijo derecho, absorbiendo su tamaño y vaciando el contenedor original.

secede: Separa un subárbol entero transformándolo en un nuevo objeto independiente y recalculando las alturas de la rama afectada.

removeSubtree: Borra físicamente un subárbol completo de la memoria y ajusta el tamaño global del árbol anfitrión.

12. ¿Qué agregan las pruebas internas respecto a rotaciones, `bubbleUp`, `trickleDown`, profundidad, altura, sucesor y predecesor?

Agregan la validación de los mecanismos internos de bajo nivel que las pruebas públicas solo miden indirectamente:

Evalúan la correctitud matemática de rotateLeft y rotateRight para alterar la topología sin romper el orden del BST.

Verifican de forma aislada el comportamiento de bubbleUp y trickleDown al insertar o remover elementos en el heap.

Inspeccionan la precisión de las funciones de cálculo métrico métricas (depth ascendente, height estructural y subtreeSize).

Garantizan el correcto ruteo por punteros de succ() y pred() en sus extremos e inversiones de flujo.

13. ¿Qué sí demuestra pasar las pruebas públicas?

Demuestra que la interfaz externa de tu librería es funcionalmente correcta bajo los escenarios estándar de evaluación. Confirma que los algoritmos resuelven los casos de prueba previstos, que respetan los contratos de las firmas de funciones y que no presentan fugas de memoria o fallos catastróficos evidentes en condiciones normales de ejecución.

14. ¿Qué no demuestra pasar las pruebas públicas?

No demuestra la eficiencia asintótica real ni la resiliencia ante casos patológicos o maliciosos. Pasar las pruebas no asegura que tu código se ejecute en tiempo logarítmico $O(\log n)$ (podría estar ejecutándose en $O(n)$ si el árbol se desbalancea), ni garantiza la ausencia de desbordamientos de pila (Stack Overflow) ante datos masivos degenerados, ni que el código esté libre de condiciones de carrera o comportamientos indefinidos bajo otras configuraciones de compilación.

15. ¿Por qué una defensa correcta debe mencionar invariantes y complejidad además de resultados observables?.

Los invariantes (como el orden simétrico en un BST o la prioridad en un heap) prueban que el código es lógicamente correcto en cualquier estado intermedio y ante cualquier volumen de datos.

La complejidad asintótica ($O(n)$, $O(\log n)$) defiende que el software fue construido bajo criterios de ingeniería de rendimiento, garantizando que el sistema será escalable, predecible y óptimo en entornos de producción reales.

#### Bloque 6 - Lectura cercana: `BinNode`, `BinTree` y `BinaryTree`

Revisa:

- `Semana5/include/BinNode.h`
- `Semana5/include/BinTree.h`
- `Semana5/include/BinaryTree.h`

Responde:

1. En `BinNode`, ¿qué invariantes deben mantenerse entre `parent`, `left` y `right`?
2. ¿Por qué `insertAsLC` e `insertAsRC` deben rechazar una inserción cuando el hijo correspondiente ya existe?
3. Explica cómo `size()` de `BinNode` recorre el subárbol.
4. Explica cómo funcionan `leftmost()` y `rightmost()`.
5. Explica paso a paso cómo funciona `succ()`.
6. Explica paso a paso cómo funciona `pred()`.
7. En `BinTree`, ¿qué papel cumplen `root_` y `size_`?
8. Explica qué hace `updateHeight(Node*)`.
9. Explica qué hace `updateHeightAbove(Node*)` y por qué sube hacia la raíz.
10. Explica cómo `attachAsLC` o `attachAsRC` transfieren un subárbol desde un árbol hacia otro.
11. Explica qué diferencia hay entre `removeSubtree` y `secede`.
12. Explica por qué `secede` no debe destruir los nodos desprendidos.
13. Explica por qué `removeSubtree` sí debe liberar nodos.
14. Explica qué verifica `checkParentLinks()`.
15. En `BinaryTree`, explica cómo se implementan `firstNode`, `lastNode`, `nextNode` y `prevNode`.
16. Explica por qué un iterador basado en `succ()` produce recorrido inorden.
17. Explica qué aporta `asciiArt()` para depuración y sustentación.


#### Bloque 7 - Árbol binario de búsqueda: búsqueda, eliminación y rotaciones

Revisa:

- `Semana5/include/BinarySearchTree.h`
- `Semana5/demos/demo_bst.cpp`
- `Semana5/pruebas_publicas/test_public_week5.cpp`
- `Semana5/pruebas_internas/test_internal_week5.cpp`

Responde:

1. Define formalmente la propiedad BST.
2. Explica por qué el recorrido inorden de un BST debe producir una secuencia no decreciente.
3. Explica la diferencia entre `find`, `findEQ`, `lowerBound` y `upperBound`.
4. Explica por qué `findEQ(x)` puede fallar aunque `lowerBound(x)` no falle.
5. Construye manualmente el BST que se obtiene al insertar: `7, 3, 10, 1, 5, 8, 12, 4, 6`.
6. Escribe el inorden, preorden, postorden y recorrido por niveles de ese árbol.
7. Simula `lowerBound(9)` y `upperBound(8)` paso a paso.
8. Explica qué casos de eliminación existen en un BST: hoja, un hijo, dos hijos.
9. Explica qué papel cumple `splice` durante una eliminación.
10. Después de eliminar una clave, ¿qué invariantes deben seguir siendo ciertos?
11. Explica por qué `remove(3)` en las pruebas debe conservar el inorden ordenado.
12. Explica qué hace `rotateLeft`.
13. Explica qué hace `rotateRight`.
14. Demuestra que una rotación local preserva la propiedad BST.
15. Explica para qué sirve construir un BST balanceado desde un arreglo ordenado.
16. Compara el costo de búsqueda en un BST balanceado y en un BST degenerado.


#### Bloque 8 - Heap binario y representación implícita

Revisa:

- `Semana5/include/BinaryHeap.h`
- `Semana5/demos/demo_heap.cpp`
- `Semana5/pruebas_publicas/test_public_week5.cpp`
- `Semana5/pruebas_internas/test_internal_week5.cpp`

Responde:

1. Explica por qué un heap binario puede almacenarse en un `std::vector` sin punteros.
2. Demuestra las fórmulas:

   ```cpp
   left(i) = 2*i + 1
   right(i) = 2*i + 2
   parent(i) = (i - 1) / 2
   ```

3. Define la propiedad de min-heap.
4. Explica por qué `top()` devuelve el mínimo.
5. Explica paso a paso cómo `bubbleUp(i)` restaura la propiedad de heap después de insertar.
6. Explica paso a paso cómo `trickleDown(i)` restaura la propiedad de heap después de eliminar la raíz.
7. Explica por qué `remove()` debe mover el último elemento a la raíz antes de aplicar `trickleDown(0)`.
8. Explica qué verifica `isHeap()`.
9. Compara construir un heap insertando `n` elementos con construirlo usando `heapify()`.
10. Justifica por qué insertar `n` elementos uno por uno cuesta `O(n log n)` en el peor caso.
11. Justifica por qué `heapify()` puede ejecutarse en `O(n)`.
12. Ejecuta una extracción completa del heap construido con `{7, 3, 10, 1, 5, 8, 2}` y explica por qué la secuencia extraída sale ordenada.
13. Compara el heap con el BST: ¿cuál estructura conviene para consultar mínimo repetidamente y cuál conviene para búsquedas ordenadas?.


#### Bloque 9 - Cierre comparativo y preparación de sustentación

Responde esta pregunta final:

¿Qué cambia cuando pasamos de estudiar listas, pilas y colas a diseñar árboles binarios, heaps y árboles binarios de búsqueda?

La respuesta debe incluir obligatoriamente:

- Una afirmación sobre representación enlazada con nodos y punteros.
- Una afirmación sobre representación implícita en arreglo.
- Una afirmación sobre la diferencia entre propiedad estructural y propiedad de orden.
- Una afirmación sobre recorridos y por qué son una forma de convertir un árbol en una secuencia.
- Una afirmación sobre mantenimiento de alturas y enlaces `parent`.
- Una afirmación sobre BST, búsqueda ordenada y recorrido inorden.
- Una afirmación sobre heap, prioridad y costo de `add`, `remove` y `heapify`.
- Una afirmación sobre qué evidencia usarías para defender correctitud: pruebas, demos, invariantes, trazados y complejidad.

#### Formato sugerido de entrega

```markdown


### Bloque 1 - Núcleo conceptual

[Respuestas]

### Bloque 2 - Navegación, altura, profundidad y tamaño

[Respuestas y dibujos]

### Bloque 3 - Recorridos y trazado guiado

[Tabla y respuestas]

### Bloque 4 - Demos

[Tabla y respuestas]

### Bloque 5 - Pruebas e invariantes

[Respuestas]

### Bloque 6 - Lectura cercana de código

[Respuestas]

### Bloque 7 - BST

[Respuestas, trazados y argumentos]

### Bloque 8 - Heap

[Respuestas, trazados y argumentos]

### Bloque 9 - Cierre comparativo

[Respuesta final]

### Autoevaluación breve

- Qué puedo defender con seguridad:
- Qué todavía confundo:
- Qué evidencia usaría en una sustentación:
- Qué parte del código me parece más importante para revisar otra vez:
```

#### Criterio general de trabajo

Se espera lectura real de los archivos, respuestas breves pero justificadas, tablas con evidencia observable, trazados manuales y conexión explícita entre código, correctitud, costo, representación e invariantes.

No basta con ejecutar el programa: debes poder explicar por qué funciona, qué punteros se actualizan, qué propiedad mantiene cada estructura, qué costo tiene cada operación y qué evidencia usarías para defenderlo oralmente.
