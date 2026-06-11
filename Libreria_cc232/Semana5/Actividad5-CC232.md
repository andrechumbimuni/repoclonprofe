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

### Bloque 5 - Pruebas públicas, pruebas internas e invariantes

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

### Bloque 6 - Lectura cercana: `BinNode`, `BinTree` y `BinaryTree`

1. En `BinNode`, ¿qué invariantes deben mantenerse entre `parent`, `left` y `right`?

Debe mantenerse el invariante de consistencia bidireccional: si un nodo $U$ tiene un hijo izquierdo $L$ (u->left == l), entonces el padre de $L$ debe ser obligatoriamente $U$ (l->parent == u). Lo mismo aplica simétricamente para el hijo derecho $R$. Además, si isRoot() es verdadero, parent debe ser estrictamente nullptr.

2. ¿Por qué `insertAsLC` e `insertAsRC` deben rechazar una inserción cuando el hijo correspondiente ya existe?

Porque C++ maneja memoria dinámica manualmente. Si se permitiera sobreescribir el puntero left o right sin control, se perdería la dirección del hijo preexistente, provocando una fuga de memoria (memory leak) catastrófica al dejar huérfano e inaccesible a todo ese subárbol completo.

3. Explica cómo `size()` de `BinNode` recorre el subárbol.

Funciona mediante un recorrido postorden recursivo. Cada nodo calcula el tamaño del subárbol izquierdo (ls) y del derecho (rs), delegando las llamadas hacia abajo hasta llegar a las hojas (que retornan 0). Finalmente, consolida el total del subárbol devolviendo 1U + ls + rs.

4. Explica cómo funcionan `leftmost()` y `rightmost()`.

leftmost() ejecuta un bucle while que avanza exclusivamente a través de los punteros left hasta topar con un nodo donde left == nullptr. Ese extremo es el mínimo local del subárbol.

rightmost() funciona de manera simétrica, avanzando por los punteros right hasta encontrar un nullptr para ubicar el extremo derecho (máximo local).

5. Explica paso a paso cómo funciona `succ()`.

Paso 1 (¿Tiene hijo derecho?): Si right != nullptr, el sucesor está abajo. Salta al hijo derecho (s = right) y de ahí baja todo lo posible a la izquierda usando leftmost().

Paso 2 (¿No tiene hijo derecho?): Si right == nullptr, el sucesor está arriba. Entra en un bucle que sube por parent mientras el nodo actual sea un hijo derecho (isRightChild()). Se detiene al llegar al primer ancestro del cual somos descendientes por la izquierda; ese padre es el sucesor.

6. Explica paso a paso cómo funciona `pred()`.

Paso 1 (¿Tiene hijo izquierdo?): Si left != nullptr, salta al hijo izquierdo (s = left) y avanza todo lo posible a la derecha usando rightmost().

Paso 2 (¿No tiene hijo izquierdo?): Sube por parent mientras el nodo actual sea un hijo izquierdo (isLeftChild()). Al detenerse, el parent resultante es el predecesor.

7. En `BinTree`, ¿qué papel cumplen `root_` y `size_`?

Son los puntos de control globales del ADT. root_ almacena el puntero al nodo raíz (la única puerta de entrada para manipular o recorrer el árbol entero). size_ mantiene el conteo actualizado de nodos en tiempo real, permitiendo responder a empty() y size() en tiempo constante $O(1)$ sin tener que recontar el árbol.

8. Explica qué hace `updateHeight(Node*)`.

Calcula y actualiza localmente el miembro height del nodo recibido. Aplica la fórmula fundamental de árboles: el tamaño del camino más largo a una hoja es $1 + max(stature(left), stature(right))$. Si el nodo es nulo, la función auxiliar stature retorna $-1$.

9. Explica qué hace `updateHeightAbove(Node*)` y por qué sube hacia la raíz.

Recibe un nodo y dispara un bucle while que viaja de manera ascendente saltando por los punteros parent hasta superar la raíz. Sube hacia la raíz porque cualquier alteración en la estructura (inserción o borrado) genera un efecto dominó que solo puede alterar las alturas de sus ancestros directos, permitiendo corregir la rama afectada de forma quirúrgica en $O(h)$ sin tocar el resto del árbol.

10. Explica cómo `attachAsLC` o `attachAsRC` transfieren un subárbol desde un árbol hacia otro.

Conectan la raíz del subárbol entrante (subtree.root_) directamente al puntero left o right del nodo padre receptor.

Actualizan el parent de esa raíz para que apunte al nuevo padre.

Suman el size_ del subárbol al árbol anfitrión y recalculan las alturas hacia arriba (updateHeightAbove).

Paso clave de diseño: Colocan en nullptr la raíz de subtree y resetean su tamaño a 0 para vaciarlo y evitar que el destructor del objeto temporal borre los nodos recién transferidos.

11. Explica qué diferencia hay entre `removeSubtree` y `secede`.

removeSubtree es una operación destructiva: corta el enlace del padre hacia el subárbol y libera físicamente de la memoria todos sus nodos mediante un borrado recursivo.

secede es una operación de desprendimiento o amputación: corta el enlace con el padre, pero extrae el subárbol intacto y lo empaqueta dentro de un nuevo objeto contenedor BinTree<T> completamente válido y funcional que se devuelve al usuario.

12. Explica por qué `secede` no debe destruir los nodos desprendidos.

Porque su propósito de diseño no es eliminar la información, sino realizar una transferencia de propiedad. Los nodos deben preservarse intactos en la memoria dinámica (Heap) porque van a constituir el cuerpo y los datos del nuevo árbol que la función está retornando.

13. Explica por qué `removeSubtree` sí debe liberar nodos.

Porque es un método de eliminación explícita. Si se desconectara el subárbol sin llamar a un operador delete recursivo nodo por nodo (ejecutado en destroy), esos bloques de memoria se quedarían flotando en el Heap sin ningún puntero que los referencie, provocando fugas de memoria persistentes.

14. Explica qué verifica `checkParentLinks()`.

Recorre recursivamente toda la estructura validando que para cada nodo existente se cumpla estrictamente el invariante del puntero parent (detallado en la pregunta 1). Si detecta un solo enlace roto o cruzado, retorna false.

15. En `BinaryTree`, explica cómo se implementan `firstNode`, `lastNode`, `nextNode` y `prevNode`.

firstNode() invoca a root_->leftmost() (primer nodo procesado en inorden).

lastNode() invoca a root_->rightmost() (último nodo procesado en inorden).

nextNode(node) mapea directamente a node->succ().

prevNode(node) mapea directamente a node->pred().

16. Explica por qué un iterador basado en `succ()` produce recorrido inorden.

Al iniciar el iterador en el nodo extremo izquierdo (firstNode()) y avanzar saltando estrictamente a través de succ(), el flujo del programa emula exactamente el orden Izquierda $\rightarrow$ Raíz $\rightarrow$ Derecha de forma secuencial y lineal.

17. Explica qué aporta `asciiArt()` para depuración y sustentación.

Al renderizar el árbol de forma gráfica con conectores (├──, └──), el desarrollador o evaluador puede verificar instantáneamente si un algoritmo de rotación, inserción o borrado alteró la forma física esperada del árbol, permitiendo identificar errores de ruteo que las secuencias planas de texto a veces ocultan.

### Bloque 7 - Árbol binario de búsqueda: búsqueda, eliminación y rotaciones

1. Define formalmente la propiedad BST.

Si $v$ es un nodo perteneciente al subárbol izquierdo de $u$ ($v \in u.left$), entonces $data(v) < data(u)$.Si $v$ es un nodo perteneciente al subárbol derecho de $u$ ($v \in u.right$), entonces $data(u) < data(v)$.

2. Explica por qué el recorrido inorden de un BST debe producir una secuencia no decreciente.

El recorrido inorden procesa los nodos en el patrón matemático fijo: Izquierda $\rightarrow$ Raíz $\rightarrow$ Derecha. Debido a la propiedad BST, todos los elementos en el subárbol izquierdo son menores que la raíz, y todos los del derecho son mayores. Al aplicar esta regla de forma recursiva en cada nivel, el algoritmo se ve forzado a procesar los elementos en su orden posicional numérico estricto, generando una secuencia perfectamente ordenada de menor a mayor.

3. Explica la diferencia entre `find`, `findEQ`, `lowerBound` y `upperBound`.

findEQ(x): Busca una coincidencia exacta. Si la clave $x$ existe, devuelve su nodo; si no existe, retorna nullptr.

lowerBound(x): Busca el límite inferior. Devuelve el primer nodo cuyo valor sea $\ge x$. Si $x$ no existe, retorna el inmediato mayor.

upperBound(x): Busca el límite superior. Devuelve el primer nodo cuyo valor sea estrictamente $> x$, ignorando si existe una coincidencia exacta con $x$.

find(x): En la implementación de tu librería, está mapeado directamente como un alias de lowerBound(x).

4. Explica por qué `findEQ(x)` puede fallar aunque `lowerBound(x)` no falle.

findEQ(x) retornará nullptr porque exige una igualdad estricta.

lowerBound(x) avanzará de forma óptima por las ramas y terminará retornando un puntero al menor elemento que sea mayor que $x$. El método no falla mientras existan elementos mayores en el árbol.

5. Construye manualmente el BST que se obtiene al insertar: `7, 3, 10, 1, 5, 8, 12, 4, 6`.
```
            [7]
           /   \
        [3]     [10]
       /   \    /   \
     [1]   [5] [8]  [12]
           / \
         [4] [6]
```
6. Escribe el inorden, preorden, postorden y recorrido por niveles de ese árbol.

Inorden: 1 3 4 5 6 7 8 10 12

Preorden: 7 3 1 5 4 6 10 8 12

Postorden: 1 4 6 5 3 8 12 10 7

Niveles (BFS): 7 3 10 1 5 8 12 4 6

7. Simula `lowerBound(9)` y `upperBound(8)` paso a paso.

Simulación de lowerBound(9):

Compara $9$ con la raíz 7. Como $7 < 9$, va a la derecha (curr = 10). 

No guarda candidato.Compara $9$ con 10. Como $9 < 10$, va a la izquierda (curr = 8). Guarda a 10 como candidate.

Compara $9$ con 8. Como $8 < 9$, va a la derecha (curr = nullptr). No guarda candidato.

El bucle termina. Retorna candidate $\rightarrow$ Nodo 10.

Simulación de upperBound(8):

Compara $8$ con la raíz 7. Como $7 \le 8$, va a la derecha (curr = 10).

Compara $8$ con 10. Como $8 < 10$, guarda a 10 como candidate y va a la izquierda (curr = 8).

Compara $8$ con 8. Al aplicar la condición del método ($8 \le 8$), se decide ir a la derecha (curr = nullptr). No altera el candidato.

El bucle termina. Retorna candidate $\rightarrow$ Nodo 10.

8. Explica qué casos de eliminación existen en un BST: hoja, un hijo, dos hijos.

Caso 1 (Nodo Hoja): El nodo no tiene hijos (como el 1). Se desconecta el enlace de su padre colocándolo en nullptr y se libera su memoria.

Caso 2 (Un solo hijo): El nodo tiene un hijo izquierdo o derecho (como el 10 tras borrar otros elementos). El hijo hereda la posición del nodo eliminado, conectándose directamente con el abuelo.

Caso 3 (Dos hijos): El nodo tiene ambos descendientes activos (como el 3). No se puede remover directamente. Se localiza su sucesor inorden (el nodo más a la izquierda de su subárbol derecho), se copia el dato del sucesor en el nodo actual, y se procede a eliminar físicamente al sucesor (el cual cae obligatoriamente en el Caso 1 o Caso 2).

9. Explica qué papel cumple `splice` durante una eliminación.

splice es el motor de reajuste físico de enlaces. Recibe un nodo que tiene máximo un hijo y se encarga de puentearlo: conecta el hijo (si existe) directamente con el padre del nodo que se va a eliminar, alterando los punteros del padre y del hijo de forma limpia, restando el tamaño y disparando la actualización ascendente de alturas.

10. Después de eliminar una clave, ¿qué invariantes deben seguir siendo ciertos?

Invariante BST: La propiedad de orden simétrico de todas las claves remanentes debe mantenerse intacta (isBST() == true).

Conectividad Bidireccional: Los punteros de retorno (parent) deben reconfigurarse y quedar completamente válidos hacia sus nuevos contenedores superiores (checkParentLinks()).

Métricas Estructurales: Los valores de size_ y height de los nodos ancestros afectados deben recalcularse y reflejar el estado actual del árbol.

11. Explica por qué `remove(3)` en las pruebas debe conservar el inorden ordenado.

El nodo 3 tiene dos hijos (1 y 5). Al llamar a remove(3), el algoritmo busca su sucesor inorden, que es el 4. Copia el valor 4 en la posición donde estaba el 3, y luego hace un splice sobre la posición original del 4 (que era una hoja) para borrarlo. La estructura se reorganiza internamente, haciendo que la secuencia inorden resultante (1 4 5 6 7 8 10 12) mantenga la consistencia ordenada y sin saltos conceptuales.

12. Explica qué hace `rotateLeft`.

Aplica una reestructuración topológica local que eleva al hijo derecho $W$ a la posición de su padre $U$, transformando a $U$ en el nuevo hijo izquierdo de $W$. El subárbol izquierdo de $W$ pasa a ser el nuevo subárbol derecho de $U$. Se preserva el orden inorden mientras disminuye la altura de la rama derecha.

13. Explica qué hace `rotateRight`.

Es la acción simétrica inversa a la anterior. Eleva al hijo izquierdo $W$ a la posición de su padre $U$, convirtiendo a $U$ en el nuevo hijo derecho de $W$. El subárbol derecho original de $W$ pasa a colgar como el nuevo subárbol izquierdo de $U$, ayudando a reducir la altura de la rama izquierda.

14. Demuestra que una rotación local preserva la propiedad BST.

Tomemos una rotación derecha sobre un nodo $U$ que tiene un hijo izquierdo $W$. Los tres subárboles involucrados son $A$ (izquierdo de $W$), $B$ (derecho de $W$) y $C$ (derecho de $U$).

Antes de la rotación: Por propiedad BST, se cumple el orden estricto: $keys(A) < W < keys(B) < U < keys(C)$.

Durante la rotación: $W$ pasa a ser la nueva raíz local. Su hijo izquierdo sigue siendo $A$, su hijo derecho pasa a ser $U$, y el subárbol $B$ se transfiere al lado izquierdo de $U$.

Después de la rotación: Al revisar la nueva disposición, el hijo izquierdo de $W$ es $A$ ($keys(A) < W$), y su lado derecho es el subárbol de $U$, el cual contiene a $B$ a su izquierda y a $C$ a su derecha ($keys(B) < U < keys(C)$).La cadena de desigualdades relativas $keys(A) < W < keys(B) < U < keys(C)$ se mantiene idéntica, demostrando matemáticamente que la propiedad BST permanece inalterada tras la operación.

15. Explica para qué sirve construir un BST balanceado desde un arreglo ordenado.

Sirve para construir un árbol con la mínima altura posible ($h = \log_2 n$) a partir de datos estáticos en un tiempo óptimo de $O(n)$. Al tomar el elemento del medio como raíz e iterar recursivamente con las mitades izquierda y derecha, se evita que el árbol sufra deformaciones o inclinaciones severas, garantizando que todas las operaciones de búsqueda posteriores operen en su máximo rendimiento teórico.

16. Compara el costo de búsqueda en un BST balanceado y en un BST degenerado.

La complejidad temporal de un BST balanceado $O(\log n)$ (Óptimo) y en un BST degenerado es de $O(n)$ (Ineficiente), la razon es que el BST balanceado en elimina la mitad de las opciones en cada descarte, al contrario de BST degenerado que tiene que pasar por cada nodo secuencialmente.

### Bloque 8 - Heap binario y representación implícita

1. Explica por qué un heap binario puede almacenarse en un `std::vector` sin punteros.

Un heap binario es por diseño un árbol perfectamente completo (todos sus niveles están llenos, excepto posiblemente el último, que se llena estrictamente de izquierda a derecha). Esta regularidad geométrica elimina la necesidad de almacenar punteros físicos (left, right, parent); basta con mapear los nodos secuencialmente nivel por nivel en las posiciones continuas de un arreglo.s

2. Demuestra las fórmulas:

   ```cpp
   left(i) = 2*i + 1
   right(i) = 2*i + 2
   parent(i) = (i - 1) / 2
   ```
   Asumiendo un arreglo indexado en base $0$ y modelando el crecimiento del árbol completo por niveles:
   
   El nivel $0$ tiene $1$ nodo (índice $0$).
   
   El nivel $1$ tiene $2$ nodos (índices $1, 2$).
   
   El nivel $2$ tiene $4$ nodos (índices $3, 4, 5, 6$).
   
   Matemáticamente, cada nivel $k$ aloja un rango de nodos. Para cualquier nodo en la posición $i$, su hijo izquierdo se ubicará exactamente desplazando el doble de su índice más el desfase del primer elemento del siguiente bloque:
   
   $left(i) = 2i + 1$: El primer hijo disponible del nodo $i$.
   
   $right(i) = 2i + 2$: El elemento contiguo inmediato al hijo izquierdo.
   
   $parent(i) = (i - 1) / 2$: La operación inversa. Despejando $i$ desde la fórmula del hijo izquierdo: $i = (L - 1) / 2$. La división entera de C++ trunca los decimales, haciendo que la fórmula devuelva exactamente el mismo índice paterno.

3. Define la propiedad de min-heap.

Establece un orden jerárquico vertical: para todo nodo con índice $i$ dentro del arreglo (que no sea la raíz), el valor almacenado en su posición debe ser mayor o igual que el valor almacenado en la posición de su padre: $data[i] \ge data[parent(i)]$

No existe ninguna restricción ni relación de orden obligatoria entre nodos hermanos del mismo nivel.

4. Explica por qué `top()` devuelve el mínimo.

Por transitividad de la propiedad del min-heap. Si cada hijo es mayor o igual que su respectivo padre, el elemento en el nivel superior de cualquier subárbol es el menor de ese bloque. Aplicando esta lógica en cascada hacia arriba, la raíz absoluta de toda la estructura—ubicada invariablemente en la celda data_[0]—contiene obligatoriamente al elemento mínimo de todo el conjunto.

5. Explica paso a paso cómo `bubbleUp(i)` restaura la propiedad de heap después de insertar.

Paso 1: Identifica al padre del nodo actual empleando la fórmula $p = (i - 1) / 2$.

Paso 2 (Condición): Si $i > 0$ y el valor en el nodo $i$ es menor que el de su padre ($data[i] < data[p]$), se viola el invariante.

Paso 3 (Intercambio): Intercambia los valores de las posiciones $i$ y $p$.

Paso 4 (Ascenso): Actualiza el índice bajo análisis haciendo $i = p$ y repite desde el Paso 1. El proceso se detiene cuando el elemento llega a la raíz o encuentra un padre menor.

6. Explica paso a paso cómo `trickleDown(i)` restaura la propiedad de heap después de eliminar la raíz.

Paso 1: Calcula las posiciones de sus hijos directos: $l = 2i + 1$ y $r = 2i + 2$.

Paso 2 (Selección): Compara el valor del nodo actual $i$ con el de sus hijos válidos (dentro de los límites del vector) para identificar cuál de los tres almacena el valor mínimo absoluto.

Paso 3 (Decisión): Si el menor de todos ya es el propio nodo $i$, la propiedad se cumple y el algoritmo termina de forma exitosa.

Paso 4 (Descenso): Si el menor es uno de los hijos, intercambia el valor de $i$ con ese hijo óptimo, actualiza el índice $i$ a la posición de dicho hijo y vuelve al Paso 1.

7. Explica por qué `remove()` debe mover el último elemento a la raíz antes de aplicar `trickleDown(0)`.

Porque la estructura interna del heap debe seguir siendo un árbol completo compacto. Si se borrara la raíz directamente o se extrajera un elemento intermedio, se generaría un hueco en el arreglo difícil de rellenar sin romper la contigüidad. Al tomar el último elemento del std::vector (el extremo inferior derecho), reescribir la raíz con él y encoger el arreglo con pop_back(), garantizamos que la forma del árbol completo se mantiene perfecta en $O(1)$, delegando la corrección del orden al posterior trickleDown(0).

8. Explica qué verifica `isHeap()`.

Verifica el cumplimiento de la prioridad en todo el arreglo. Recorre secuencialmente cada celda y corrobora que, si el nodo posee hijos dentro del tamaño actual del vector, ninguno de ellos (left o right) sea menor que el padre. Si encuentra una sola violación, el método dictamina falso.

9. Compara construir un heap insertando `n` elementos con construirlo usando `heapify()`.

Inserciones sucesivas: Comienza con un heap vacío y agrega los $n$ elementos uno por uno llamando a add(). Cada inserción procesa un elemento desde el fondo y lo fuerza a subir.

heapify(): Toma un arreglo que ya contiene los $n$ elementos completamente desordenados y procesa los nodos de abajo hacia arriba. Empieza desde la mitad del arreglo ($\lfloor n/2 \rfloor - 1$, el primer nodo interno que tiene hijos) y avanza en reversa hacia el índice $0$, aplicando trickleDown en cada paso.

10. Justifica por qué insertar `n` elementos uno por uno cuesta `O(n log n)` en el peor caso.

Al insertar uno por uno, los elementos se añaden en las hojas (el nivel más profundo del árbol). En el peor caso, cada elemento insertado puede verse obligado a escalar todo el trayecto desde el último nivel hasta la raíz con bubbleUp. Como la altura del árbol en cualquier punto es de escala $\log_2 k$, la sumatoria del esfuerzo total de inserción está acotada por:  $\sum_{k=1}^{n} \log k \approx \log(n!) = \Theta(n \log n)$

11. Justifica por qué `heapify()` puede ejecutarse en `O(n)`.

La genialidad de heapify() radica en que la gran mayoría de los nodos se concentran en la base del árbol. Las hojas que tienen altura $0$ (tienen el $50\%$) y no requieren ningún trabajo. Los nodos inmediatamente superiores (altura $1$) son el $25\%$ y solo pueden bajar un nivel.La función del costo total se define multiplicando la cantidad de nodos en cada nivel por la altura máxima que pueden descender de forma efectiva con trickleDown:  $Costo = \sum_{h=0}^{\log n} \frac{n}{2^{h+1}} \cdot O(h) = n \cdot \sum_{h=0}^{\log n} \frac{h}{2^{h+1}}$

Como la serie geométrica $\sum \frac{h}{2^h}$ converge a una constante finita (2), la expresión se simplifica a $O(n)$.

12. Ejecuta una extracción completa del heap construido con `{7, 3, 10, 1, 5, 8, 2}` y explica por qué la secuencia extraída sale ordenada.

EL vector inicial tras el heapify óptimo arranca en: [1, 3, 2, 7, 5, 8, 10]

Extracción 1: Retorna la raíz 1. El último elemento del vector (10) sube temporalmente al tope. El arreglo queda como [10, 3, 2, 7, 5, 8]. Al aplicar trickleDown(0), el 10 se compara con sus hijos 3 y 2. Como 2 es el mínimo, se intercambian. Tras estabilizarse, el arreglo queda como [2, 3, 8, 7, 5, 10].

Extracción 2: Retorna la raíz 2. El último elemento (10) sube. Tras el reajuste por el camino mínimo de descendientes, la nueva raíz pasa a ser 3 y el arreglo se acomoda.

Extracción 3: Retorna la raíz 3. El último elemento sube a la raíz y el proceso de descenso corona al 5 como el nuevo líder del tope.

Extracción 4: Retorna la raíz 5. Tras el reajuste estructural descendente, el mínimo del tope pasa a ser el 7.

Extracción 5: Retorna la raíz 7. El árbol se reduce y la nueva raíz del heap pasa a ser el 8.

Extracción 6: Retorna la raíz 8. Solo queda un elemento en la estructura, que es el 10.

Extracción 7: Retorna el último elemento 10. El heap queda completamente vacío.

La secuencia final extraída es 1 2 3 5 7 8 10. Esto demuestra empíricamente que, sin importar cómo se reacomoden los elementos internos en el vector intermedio, el invariante del min-heap es indestructible: la raíz siempre garantizará contener al menor elemento disponible antes de cada extracción.

13. Compara el heap con el BST: ¿cuál estructura conviene para consultar mínimo repetidamente y cuál conviene para búsquedas ordenadas?.

Para consultar el mínimo repetidamente: Conviene el Heap. Provee acceso inmediato al valor mínimo en tiempo constante $O(1)$ a través de top(), y permite extraerlo y reajustar la estructura en un tiempo garantizado de $O(\log n)$ sin penalizaciones por desbalanceo de memoria.

Para búsquedas ordenadas generales: Conviene el BST. El heap solo conoce la prioridad de la raíz; no sirve para buscar un elemento intermedio de forma rápida (requeriría una búsqueda secuencial de $O(n)$). El BST (siempre que se mantenga balanceado) permite buscar, verificar existencias (contains), y acotar rangos (lowerBound, upperBound) de cualquier clave del universo de datos en un tiempo eficiente de $O(\log n)$, además de permitir volcar la información ordenada en cualquier instante mediante un recorrido inorden.

### Bloque 9 - Cierre comparativo y preparación de sustentación

¿Qué cambia cuando pasamos de estudiar listas, pilas y colas a diseñar árboles binarios, heaps y árboles binarios de búsqueda?

El paso de estructuras lineales a estructuras no lineales representa un salto cualitativo en el diseño de software en:

Representación enlazada: Los punteros dejan de ser una cadena lineal (next) y se ramifican en múltiples direcciones (left, right) para construir una jerarquía.

Representación implícita: Estructuras como el heap eliminan los punteros físicos, usando un std::vector contiguo donde las relaciones familiares se calculan con fórmulas aritméticas sobre sus índices ($2i+1, 2i+2$).

Propiedad estructural vs. orden: En listas el orden lo da el tiempo de llegada (LIFO/FIFO). Aquí, la estructura dicta la forma del árbol (completo o balanceado) y el orden dicta la jerarquía de los datos (horizontal en BST, vertical en Heap).

Recorridos: Son el mecanismo para aplanar y convertir un árbol ramificado no lineal en una secuencia lineal unidimensional iterable.

Alturas y enlaces parent: Las mutaciones ya no son de costo constante local; exigen mantener enlaces parent para subir de forma quirúrgica recalculando alturas hacia la raíz tras un cambio.

BST: Restringe el orden horizontal para garantizar búsquedas en $O(\log n)$ y su recorrido inorden produce, por definición, los datos ordenados de menor a mayor.

Heap: Restringe el orden verticalmente para dar acceso al mínimo en $O(1)$, con costos de $O(\log n)$ en add y remove, y permitiendo una construcción masiva en $O(n)$ con heapify.

Evidencia de correctitud: La validez no se demuestra con un resultado casual; requiere verificar invariantes matemáticos, complejidad asintótica, trazados de punteros, renders ASCII y pruebas unitarias integrales.

### Autoevaluación breve
- Qué puedo defender con seguridad: La mecánica y diferencias de los recorridos (por qué inorden da un BST ordenado y niveles usa BFS), las fórmulas de indexación del Heap en un vector, y la lógica de ruteo de succ() y pred() subiendo o bajando por el árbol.
- Qué todavía confundo: La diferencia fina entre cómo se comportan lowerBound(x) y upperBound(x) cuando la clave buscada no existe en el BST, y el rastreo exacto de punteros en las rotaciones locales (rotateLeft/rotateRight).
- Qué evidencia usaría en una sustentación: El reporte de éxito de las pruebas unitarias (test_public y test_internal), el renderizado topológico en consola con asciiArt(), y la demostración matemática de por qué heapify() es $O(n)$ mientras que insertar uno a uno es $O(n \log n)$.
- Qué parte del código me parece más importante para revisar otra vez: El método remove(x) del BST junto con la función splice(), para dominar con precisión cómo se reconectan los punteros de los padres y abuelos cuando el nodo a eliminar tiene dos hijos.