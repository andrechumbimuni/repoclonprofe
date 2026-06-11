## Actividad 5 - CC232

### Estudiante

- Nombre: Chumbimuni Ricci Andre Dylan

#### Bloque 1 - Núcleo conceptual de la semana

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

#### Bloque 2 - Navegación, altura, profundidad y tamaño

Revisa:

- `Semana5/include/BinNode.h`
- `Semana5/include/BinTree.h`
- `Semana5/include/BinaryTree.h`
- `Semana5/demos/demo_binary_tree.cpp`

Responde:

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

#### Bloque 3 - Recorridos y trazado guiado

Revisa:

- `Semana5/include/BinNode.h`
- `Semana5/include/BinTree.h`
- `Semana5/demos/demo_binary_tree.cpp`
- `Semana5/demos/demo_capitulo5_panorama.cpp`

Construye una tabla con cinco columnas:

- Recorrido
- Versión revisada
- Estructura auxiliar usada
- Secuencia producida en el árbol de prueba
- Argumento de correctitud y costo

Incluye en la tabla:

- preorden recursivo,
- preorden iterativo,
- inorden recursivo,
- inorden iterativo `#1`,
- inorden iterativo `#2`,
- inorden iterativo `#3`,
- postorden recursivo,
- postorden iterativo,
- recorrido por niveles.

Luego responde:

1. ¿Qué significa visitar un nodo en preorden?

El nodo que esta siendo visitado en preorden cuando se esta ejecutando el visit(), visitar a la raiz antes que a los hijos

2. ¿Qué significa visitar un nodo en inorden?

Esto visita primero al hijo por la izquierda luego la raiz  para luego la derecha.

3. ¿Qué significa visitar un nodo en postorden?
4. ¿Qué significa visitar un árbol por niveles?

Viajar por niveles: travlevel 

5. ¿Por qué los recorridos recursivos tienen tiempo `O(n)`?

6. ¿Por qué las versiones iterativas también tienen tiempo `O(n)`?
7. ¿Cuál es la memoria auxiliar de un recorrido recursivo en un árbol balanceado?
8. ¿Cuál es la memoria auxiliar de un recorrido recursivo en un árbol degenerado?
9. ¿Qué diferencia hay entre usar una pila explícita y usar la pila de llamadas?

Nosotros la controlamos (explicita) y en la pila de llamadas el computador usa sus propias formas de llamar pero puede causar overflow

10. ¿Por qué la cola del recorrido por niveles puede crecer mucho más en un árbol completo que en un árbol degenerado?.

#### Bloque 4 - Demostración: evidencia observable

Revisa y ejecuta:

- `Semana5/demos/demo_binary_tree.cpp`
- `Semana5/demos/demo_bst.cpp`
- `Semana5/demos/demo_heap.cpp`
- `Semana5/demos/demo_capitulo5_panorama.cpp`

Construye una tabla con cuatro columnas:

- Archivo
- Salida u observable importante
- Idea estructural
- Argumento de costo, espacio o diseño

Luego responde:

1. En `demo_binary_tree.cpp`, ¿qué salida permite verificar que los recorridos visitan los nodos en el orden esperado?
2. ¿Qué parte de la demo permite defender que `succ()` y `pred()` respetan el orden inorden?
3. ¿Qué evidencia produce la representación ASCII del árbol?
4. En `demo_bst.cpp`, ¿qué observable permite defender que el inorden del BST queda ordenado?
5. ¿Qué operaciones de búsqueda se distinguen mejor en la demo del BST: `find`, `findEQ`, `lowerBound` o `upperBound`?
6. En `demo_heap.cpp`, ¿qué salida permite defender que el mínimo queda en la raíz?
7. ¿Qué evidencia permite distinguir entre insertar con `add()` y construir con `heapify()`?
8. En `demo_capitulo5_panorama.cpp`, ¿qué comparación resume mejor la semana: árbol enlazado, BST o heap?.

#### Bloque 5 - Pruebas públicas, pruebas internas e invariantes

Revisa:

- `Semana5/pruebas_publicas/test_public_week5.cpp`
- `Semana5/pruebas_internas/test_internal_week5.cpp`

Responde:

1. ¿Qué operaciones del BST valida la prueba pública?
2. ¿Qué casos validan que el BST no acepta duplicados?
3. ¿Qué se verifica al comparar el inorden recursivo con las versiones iterativas?
4. ¿Qué se espera de `findEQ(8)` en la prueba pública?
5. ¿Qué se espera de `lowerBound(9)` y `upperBound(8)`?
6. ¿Qué propiedad se valida con `isBST()`?
7. ¿Qué se valida después de eliminar un nodo con `remove()`?
8. ¿Qué valida `checkParentLinks()` después de borrar, separar o adjuntar subárboles?
9. ¿Qué operaciones del heap valida la prueba pública?
10. ¿Qué demuestra extraer repetidamente de un min-heap hasta vaciarlo?
11. ¿Qué operaciones de `BinTree` se validan con `attachAsRC`, `secede` y `removeSubtree`?
12. ¿Qué agregan las pruebas internas respecto a rotaciones, `bubbleUp`, `trickleDown`, profundidad, altura, sucesor y predecesor?
13. ¿Qué sí demuestra pasar las pruebas públicas?
14. ¿Qué no demuestra pasar las pruebas públicas?
15. ¿Por qué una defensa correcta debe mencionar invariantes y complejidad además de resultados observables?.


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
