### Actividad 7 - CC232

## Bloque 1 - Diagnóstico inicial de la Semana 7

1. ¿Qué targets de demostración aparecen para Semana 7?

Aparecen las demos de avl(deng y la de rotaciones compactas), red-black(morin y llrb), panorama , compare con semana 5.

2. ¿Qué pruebas públicas e internas aparecen?

Aparece el test public y internal de la semana 7.

3. ¿Qué archivos incluye `Capitulo7.h`?

Incluye Entry.h, BinNode.h, BinTree.h, BST.h, AVL.h, BinaryTree.h, BinarySearchTree.h, RedBlackTree.h, AVLTreeCompact.h y RedBlackTreeLLRB.h

4. ¿Qué relación conceptual hay entre Semana 5, Semana 6 y Semana 7?

En la semana 5 (Árboles Binarios y BST Básicos) introducen una estructura jerarquica y con ordenamiento horizontal, en la semana 6 usamos las prioridades y con la semana 5 aparece el treap, la semana 7 usas rotaciones para que la altura se mantenga estrictamente acotada a $O(\log n)$.

5. ¿Por qué no es correcto decir que una carpeta "hereda" de otra carpeta?

Porque una carpeta contiene otra carpeta, no hereda ya que no es una instancia de especialidad de la carpeta en la que la contienen. 

6. ¿Qué clases sí usan herencia dentro del código?

El BST hereda BinTree<T>, el AVL hereda BST<T, Compare>, BinarySearchTree hereda BinaryTree<Node>, BSTNode hereda de BTNode<Node>, BinarySearchTree hereda de BinarySearchTree<BSTNode1<T>, T, Compare>.

7. ¿Qué evidencia inicial obtuviste al ejecutar las pruebas sin modificar nada?.
El sistema aprobó el 100% de las pruebas sin fallos en un tiempo de ejecución real de apenas 0.02 segundos.

Demostrando que tanto la suite pública como la interna pasaron, confirmando la estabilidad del código base y sus rotaciones.
Entrega en este bloque:

* Una tabla con comando ejecutado, resultado, error si hubo e interpretación.

| Comando Ejecutado | Resultado | Error | Interpretación |
| :--- | :--- | :--- | :--- |
| `cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug` | Generación exitosa de los archivos de construcción (0.1s). | Ninguno | Se detectó la configuración del compilador y se preparó correctamente el entorno de depuración para la Semana 7. |
| `cmake --build build-debug` | Compilación al 100%. Generación de 8 ejecutables de demos y 2 de pruebas. | Ninguno | Todo el código de los árboles binarios balanceados (AVL, Red-Black) y sus controladores compilaron sin errores de sintaxis. |
| `ctest --test-dir build-debug -R semana7 --output-on-failure` | 100% tests passed (2/2 pasados en 0.02 segundos). | Ninguno | Las pruebas públicas e internas validaron con éxito los invariantes y la estabilidad algorítmica de las estructuras de datos. |

* Una lista breve de los archivos que revisaste primero.

AVL.h (Estructura del árbol balanceado y bucles de rotación).

BST.h (Clase base que implementa las funciones de búsqueda y el método connect34).

BinNode.h (Estructura de los nodos con punteros, alturas y métodos updateHeight).

## Bloque 2 - BST como punto de partida

1. Define formalmente la propiedad BST.

Para cualquier nodo b en un arbol binario de busqueda con una funcion de comparacion estricta x < y:

Si existe un nodo b en el subarbol izquierdo de x, entonces b < x.

Si existe un nodo a en el subarbol derecho de x, entonces x < a.

2. Explica por qué el recorrido inorder de un BST produce una secuencia ordenada.

Como el recorrido inorder visita recursivamente primero el subarbol izquierdo luego el nodo actual y al ultimo el derecho. Por la propiedad del BST sabemos que todos elementos a la izquierda son menores a la raiz actual y todos los elementos de la derecha seran mayores generando una ejecucion de elemento en orden secuencial. 

3. Explica por qué insertar claves ordenadas puede producir un BST degenerado.

Como tomamos a el primer elemento insertado como la raiz si insertamos elementos de forma creciente o decreciente, el nodo insertado sera insertara siempre en el lado derecho o izquierdo, sin elementos en el subarbol derecho o izquierdo de la raiz, la estructura balanceada pasa a ser un camino lineal.

4. Construye manualmente el BST resultante de insertar:

```
10, 20, 30, 40, 50, 60, 70

10 (Raíz) 
  \
   20
     \
     30
       \
       40
         \
         50
           \
           60
             \
             70
```
5. Indica la altura del árbol anterior si no hay balanceo.

La altura del arbol es el camino mas largo (max. longitud) : 7

6. Explica por qué una búsqueda en ese árbol puede costar `O(n)`.

La busqueda binaria tendra que pasar por cada nodo en el peor caso.

7. Explica qué problema intenta resolver AVL.

El AVL resuelve el problema de balanceo usando (rotateAt) para reestructurar localmente garantizando que la altura se mantenga de $O(\log n)$.

8. Explica qué problema intenta resolver Red-Black Tree.

Reducir la cantidad rotaciones necesarias cuando se inserten y eliminen nodos, lo hace por coloracion probabilistica (usa nodos rojos y negros) que asegura la altura maxima de $2\log_2(n+1)$.

Entrega en este bloque:

* Explicación breve de costo.

Árbol Balanceado: $O(\log n)$ La busqueda de un elemento es rápido porque en cada paso descartas la mitad de los datos restantes.

Árbol Desbalanceado: $O(n)$ Si los datos se insertan en orden, el BST degenera en una lista enlazada hacia un solo lado. La busqueda lo hara recorrer todos los nodos.

* Relación con Semana 5.

La implementacion del BinarySearchTree de la semana 5, en la semana 7 donde ejecuta operaciones de reestructuracion para compactar el arbol de manera optima.

## Bloque 3 - AVL: balance por altura

1. ¿Qué significa que un nodo esté balanceado en un AVL?

Que la diferencia entre el nivel de altura en su subarbol izquierdo y derecho sea como maximo 1.

2. ¿Cómo se calcula el factor de balance?

El factor de balance es la altura del subarbol izquierdo es menos la altura del subarbol derecho.

3. ¿Qué información de altura debe mantenerse después de insertar o eliminar?

El height se debe recalcular y actualizar en cada insercion o eliminacion.

4. ¿Qué representa `_hot` dentro de la implementación estilo Deng?

Representa un puntero al nodo padre del nodo que se está buscando, insertando o eliminando en ese momento.

5. ¿Por qué AVL puede heredar de `BST<T, Compare>`?

El AVL es como un BST especializado que resuelve el problema de balanceo que sufre el BST no balanceado.

6. ¿Qué operación restaura localmente la forma del árbol?

Usamos rotateAt(v), que usa el algoritmo connect34, esta funcion reasigna los apunteros de un abuelo, padre y hijo para hacerlo simetrico.

7. ¿Por qué una rotación no destruye la propiedad BST?

Las rotaciones respetan el orden inorden ya que la secuencia ordenada de 3 elementos reubica punteros manteniendo intacto que el primero siempre este a la derecha del segundo y este a la izuierda del tercero.  

8. Después de insertar, ¿por qué suele bastar reparar el primer ancestro 
desbalanceado?

Porque cuando la altura aumente en 1, cuando rotamos ese ancestro, la subestructura reduce la altura en 1, regresando a la misma altura antes de la insercion.

9. Después de eliminar, ¿por qué puede ser necesario seguir revisando hacia la raíz?.

Porque la eliminacion puede disminuir la altura en 1, provocando que un nodo padre se desbalancee, generando que los abuelos tambien lo hagan, lo que obliga a revisar nodo por nodo y rebalancearlos hasta la raiz.

Entrega en este bloque:

* Una explicación de los invariantes AVL.

Invariante de Orden (Propiedad BST): Para cualquier nodo $padre$, todos los elementos de su subárbol izquierdo son estrictamente menores que la clave de $padre$ ($hijo.izquierdo < padre < hijo.derecho$).
Invariante de Balance (Propiedad AVL): Para cada nodo $x$ en el árbol, la diferencia de altura absoluta entre su hijo izquierdo y su hijo derecho no puede ser mayor a 1.

* Un trazado de inserción con al menos una rotación.
A`30`, `20` y `10`, la invariante de balance en la raíz y una rotación simple a la derecha (`rotateAt` / `connect34`).

Paso 1: Inserción de 30, 20 y 10.
```
g -> 30 (H: 2, BF: 2)  Desbalance en el ancestro
           /
     p -> 20 (H: 1, BF: 1)
         /
   v -> 10 (H: 0, BF: 0)
```
Paso 2: rotateAt(v)
```
    20 (H: 1, BF: 0) Altura del subárbol reducida a 1
    /  \
  10    30 (H: 0, BF: 0)
```
* Evidencia de salida de `demo_avl_deng_core.cpp`.
```
AVL inorder: 10 20 22 25 27 30 40 50 
AVL level-order: 30 20 40 10 25 50 22 27 
Valido AVL: si
Tras borrar 20 y 40: 10 22 25 27 30 50 
Valido AVL: si
```
## Bloque 4 - Rotaciones AVL: casos LL, RR, LR y RL

1. ¿Qué diferencia hay entre una rotación simple y una rotación doble?

La rotacion simple es cuando usas al 3 nodos(abuelo, padre y hijo), la rotacion doble usa primero 2 nodos (hijo y padre) y luego otra rotacion con 3 nodos (abuelo, padre y hijo).

2. ¿Por qué LL y RR se corrigen con una sola rotación?

Porque los nodos se encuentran alineados (solo hijos izquiedos o solo hijos derechos) solo necesita una rotacion para distrubuir las los nodos locales equitativamente.

3. ¿Por qué LR y RL requieren dos pasos?

Porque los nodos estan en zig-zag, necesitas uno para que los alinees y otro para restablecer la altura.

4. ¿Qué parte del árbol cambia y qué parte permanece igual?

Cambian las conexiones de punteros entre el abuelo, el padre y el nieto(las raíces de sus 4 subárboles).El resto de la estructura superior del arbol permanece igual.

5. ¿Por qué el inorder debe ser el mismo antes y después de reestructurar?.

Porque el arbol es un BST valido, cambiar el orden inorder romperia la propiedad de busqueda.

Entrega en este bloque:

* Tabla de rotaciones.

| Caso | Secuencia Insertada | Nodo Desbalanceado ($g$) | Rotación Aplicada | Inorder Antes | Inorder Después | Altura Final |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **LL** *(Zig-Zig)* | `30, 20, 10` | `30` | Simple a la Derecha (`connect34`) | `10 20 30` | `10 20 30` | 1 |
| **RR** *(Zag-Zag)* | `10, 20, 30` | `10` | Simple a la Izquierda (`connect34`) | `10 20 30` | `10 20 30` | 1 |
| **LR** *(Zig-Zag)* | `30, 10, 20` | `30` | Doble Izquierda-Derecha | `10 20 30` | `10 20 30` | 1 |
| **RL** *(Zag-Zig)* | `10, 30, 20` | `10` | Doble Derecha-Izquierda | `10 20 30` | `10 20 30` | 1 |

* Cuatro dibujos pequeños.

Caso LL:
```
        30                 20
       /                  /  \
     20      ->         10    30
     /
   10
```
Caso RR:
```
  10                 20
   \                /  \
    20    ->      10    30 
     \
     30
```
Caso LR:
```
   30              30           20
   /              /            /  \
 10      ->      20     ->    10   30
   \             /
    20          10
```
Caso RL:
```
 10            10               20
  \             \              /  \
  30    ->      20     ->    10    30
  /              \
 20              30
```
* Argumento de preservación del orden BST.

El algoritmo connect34 garantiza de forma matemática la preservación del orden BST porque mapea de manera fija e invariable los tres nodos (a, b, c) y sus cuatro subárboles ($T_0, T_1, T_2, T_3$).
```
         (b)
       /     \
     (a)     (c)
    /   \   /   \
   T0   T1 T2   T3
```
#### Bloque 5 - Red-Black Tree: balance por colores

Revisa:

* `Semana7/include/RedBlackTree.h`
* `Semana7/include/BinarySearchTree.h`
* `Semana7/include/BinaryTree.h`
* `Semana7/demos/demo_redblack_morin.cpp`

Responde:

1. ¿Qué propiedad BST mantiene Red-Black Tree?
2. ¿Qué propiedades de color debe cumplir un Red-Black Tree?
3. ¿Por qué la raíz debe terminar negra?
4. ¿Qué significa que no pueda haber dos nodos rojos consecutivos?
5. ¿Qué representa la altura negra?
6. ¿Por qué Red-Black Tree permite un balance menos estricto que AVL?
7. ¿Qué correcciones pueden aparecer después de insertar?
8. ¿Qué correcciones pueden aparecer después de eliminar?
9. ¿Qué papel cumplen las rotaciones en Red-Black Tree?
10. ¿Qué papel cumple el cambio de colores?.

Entrega en este bloque:

* Lista de invariantes Red-Black.
* Explicación de una inserción que requiera recoloreo.
* Evidencia de salida de `demo_redblack_morin.cpp`.

#### Bloque 6 - Comparación: BST, Treap, AVL y Red-Black Tree

Revisa:

* `Semana6/include/Treap.h`
* `Semana7/demos/demo_compare_avl_vs_redblack.cpp`
* `Semana7/demos/demo_compare_with_semana5.cpp`
* `Semana7/demos/demo_capitulo7_panorama.cpp`

Construye una tabla con estas columnas:

* Estructura
* Propiedad de orden
* Propiedad adicional
* Operación de reparación
* Altura esperada o garantizada
* Caso donde conviene usarla

Incluye:

1. BST común
2. Treap
3. AVL
4. Red-Black Tree

Responde:

1. ¿Qué tienen en común BST, Treap, AVL y Red-Black Tree?
2. ¿Qué diferencia hay entre prioridad en Treap, altura en AVL y color en Red-Black Tree?
3. ¿Por qué Treap depende de prioridades?
4. ¿Por qué AVL suele ser más estricto en altura?
5. ¿Por qué Red-Black Tree puede ser preferible cuando hay muchas inserciones y eliminaciones?
6. ¿Qué estructura elegirías para defender búsqueda ordenada con balance fuerte?
7. ¿Qué estructura elegirías para explicar balance probabilístico?.

Entrega en este bloque:

* Tabla comparativa.
* Respuesta breve de decisión técnica.
* Conexión explícita con Semana 5 y Semana 6.

#### Bloque 7 - Pruebas, invariantes y defensa oral

Revisa:

* `Semana7/pruebas_publicas/test_public_week7.cpp`
* `Semana7/pruebas_internas/test_internal_week7.cpp`

Responde:

1. ¿Qué operaciones valida la prueba pública para AVL?
2. ¿Qué operaciones valida la prueba pública para Red-Black Tree?
3. ¿Qué casos adicionales cubre la prueba interna?
4. ¿Qué significa que una prueba valide el inorder?
5. ¿Qué significa que una prueba valide alturas o factores de balance?
6. ¿Qué significa que una prueba valide colores?
7. ¿Qué no demuestra pasar solo las pruebas públicas?
8. ¿Qué evidencia usarías en una sustentación: demostración, prueba, trazado o argumento de complejidad?
9. ¿Qué invariante revisarías primero si falla AVL?
10. ¿Qué invariante revisarías primero si falla Red-Black Tree?.

Entrega en este bloque:

* Tabla de pruebas revisadas.
* Lista de invariantes que defenderías.
* Evidencia de ejecución de `ctest`.

#### Bloque 8 - Ejercicios de codificación

En este bloque debes modificar o extender la Semana 7 sin romper la interfaz principal de la librería. El objetivo es comprobar que entiendes los invariantes de AVL y Red-Black Tree no solo de forma teórica, sino también mediante código, pruebas y evidencia de ejecución.

#### Ejercicio 1 - Validador de propiedad BST

Crea un archivo:

```bash
Semana7/demos/demo_validate_bst_property.cpp
```

Implementa una función auxiliar que valide si un árbol cumple la propiedad BST usando límites inferiores y superiores.

Firma sugerida:

```cpp
template <typename Node, typename T>
bool validateBST(Node* node, const T* minValue, const T* maxValue);
```

Reglas:

* Si `node == nullptr`, retorna `true`.
* Si existe `minValue`, entonces `node->data` debe ser mayor que `*minValue`.
* Si existe `maxValue`, entonces `node->data` debe ser menor que `*maxValue`.
* Valida recursivamente el subárbol izquierdo y derecho.
* No uses recorrido inorder como única validación.

Incluye comentarios en español:

```cpp
// Valida que cada nodo respete los limites heredados desde sus ancestros.
```

Entrega:

* Código fuente.
* Salida de la demostración.
* Explicación de por qué validar solo padre-hijo no es suficiente.

#### Ejercicio 2 - Contador de rotaciones AVL

Extiende una demostración o crea una nueva:

```bash
Semana7/demos/demo_avl_rotation_counter.cpp
```

El programa debe insertar varias secuencias y contar cuántas rotaciones aparecen en cada caso.

Secuencias mínimas:

```cpp
{30, 20, 10} // LL
{10, 20, 30} // RR
{30, 10, 20} // LR
{10, 30, 20} // RL
{10, 20, 30, 40, 50, 60, 70}
```

Salida esperada en formato similar:

```text
Caso LL
Rotaciones simples: 1
Rotaciones dobles: 0
Altura final: 1

Caso LR
Rotaciones simples: 0
Rotaciones dobles: 1
Altura final: 1
```

Entrega:

* Código fuente.
* Tabla con cada caso, secuencia, tipo de rotación y altura final.
* Explicación de por qué LR y RL no se resuelven con una sola rotación directa.

#### Ejercicio 3 - Verificador de balance AVL

Crea un archivo:

```bash
Semana7/demos/demo_validate_avl_balance.cpp
```

Implementa una función que verifique que todo nodo cumpla:

```text
|height(left) - height(right)| <= 1
```

Firma sugerida:

```cpp
template <typename Node>
bool validateAVLBalance(Node* node);
```

También implementa una función auxiliar:

```cpp
template <typename Node>
int computeHeight(Node* node);
```

Reglas:

* La altura de un árbol vacío debe ser `-1`.
* La altura de una hoja debe ser `0`.
* Debes validar todos los nodos, no solo la raíz.
* El programa debe imprimir si el árbol está balanceado o no.

Salida esperada:

```text
Validacion AVL despues de inserciones
Estado: balanceado
Altura calculada: 3
```

Entrega:

* Código fuente.
* Evidencia de ejecución.
* Explicación de la diferencia entre altura almacenada y altura calculada.

#### Ejercicio 4 - Comparación experimental BST vs AVL

Crea una demostración:

```bash
Semana7/demos/demo_compare_bst_avl_height.cpp
```

Inserta las mismas claves en un BST común y en un AVL.

Casos mínimos:

```cpp
std::vector<int> sortedKeys = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
std::vector<int> mixedKeys = {5, 2, 8, 1, 3, 7, 9, 4, 6, 10};
```

El programa debe imprimir:

```text
Caso: claves ordenadas
Altura BST: 9
Altura AVL: 3

Caso: claves mezcladas
Altura BST: ...
Altura AVL: ...
```

Responde:

1. ¿Qué ocurre con el BST cuando las claves llegan ordenadas?
2. ¿Qué ocurre con AVL ante la misma entrada?
3. ¿Por qué ambas estructuras conservan el mismo inorder?
4. ¿Por qué la altura es la evidencia central en esta comparación?.

Entrega:

* Código fuente.
* Salida.
* Tabla comparativa.
* Interpretación.

#### Ejercicio 5 - Validador básico Red-Black Tree

Crea una demostración:

```bash
Semana7/demos/demo_validate_redblack_basic.cpp
```

Implementa validaciones básicas para Red-Black Tree:

1. La raíz debe ser negra.
2. No debe existir un nodo rojo con hijo rojo.
3. Todos los caminos desde un nodo hasta hojas nulas deben tener la misma altura negra.

Firmas sugeridas:

```cpp
template <typename Node>
bool validateNoRedRed(Node* node);

template <typename Node>
int computeBlackHeight(Node* node);

template <typename Node>
bool validateBlackHeight(Node* node);
```

Reglas:

* Considera las hojas nulas como negras.
* Si detectas violación, imprime un mensaje en español.
* No basta con imprimir el inorder.
* La validación debe revisar estructura y colores.

Salida esperada:

```text
Validacion Red-Black Tree
Raiz negra: correcto
Sin rojo-rojo: correcto
Altura negra uniforme: correcto
Estado final: valido
```

Entrega:

* Código fuente.
* Evidencia de ejecución.
* Explicación de por qué Red-Black Tree permite mayor flexibilidad que AVL.

#### Ejercicio 6 - Prueba pública adicional

Agrega una prueba pública en:

```bash
Semana7/pruebas_publicas/test_public_week7_extra.cpp
```

La prueba debe cubrir al menos:

1. Inserción ordenada en AVL.
2. Validación de inorder.
3. Validación de altura máxima razonable.
4. Inserción en Red-Black Tree.
5. Validación de búsqueda después de varias inserciones.

Ejemplo de intención:

```cpp
// Verifica que AVL no se degrade cuando recibe claves ordenadas.
```

No copies exactamente este pseudocódigo. Adáptalo a la interfaz real de la librería.

Entrega:

* Código de prueba.
* Comando usado para compilar.
* Comando usado para ejecutar.
* Resultado de `ctest`.
* Explicación de qué bug detectaría esta prueba.

#### Ejercicio 7 - Mini benchmark de búsqueda

Crea una demostración:

```bash
Semana7/demos/demo_search_benchmark_week7.cpp
```

Inserta `n` claves en:

1. BST común
2. AVL
3. Red-Black Tree

Usa al menos:

```cpp
n = 1000
n = 5000
n = 10000
```

Mide búsquedas exitosas y fallidas.

Reglas:

* Usa `std::chrono`.
* No imprimas cada búsqueda individual.
* Imprime tiempo total por estructura.
* Usa las mismas claves para todas las estructuras.
* Separa el caso ordenado del caso aleatorio.

Salida sugerida:

```text
n = 10000
Caso ordenado
BST search time: ...
AVL search time: ...
RedBlack search time: ...

Caso aleatorio
BST search time: ...
AVL search time: ...
RedBlack search time: ...
```

Entrega:

* Código fuente.
* Tabla de resultados.
* Interpretación.
* Conclusión sobre altura y costo de búsqueda.

#### Ejercicio 8 - Integración al CMake

Agrega tus demostraciones al `CMakeLists.txt` de Semana 7.

Debes poder compilar con:

```bash
cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build-debug
ctest --test-dir build-debug -R semana7 --output-on-failure
```

Entrega:

* Fragmento modificado de `CMakeLists.txt`.
* Evidencia de compilación.
* Evidencia de pruebas.
* Explicación de por qué una demostración no necesariamente es una prueba automatizada.

#### Entrega mínima de codificación

Para considerar completo este bloque, debes entregar como mínimo:

1. Dos demostraciones nuevas.
2. Una prueba pública adicional.
3. Una tabla de resultados.
4. Una explicación de invariantes.
5. Evidencia de compilación.
6. Evidencia de ejecución.
7. Evidencia de `ctest`.

#### Pregunta final del bloque

Después de implementar los ejercicios, responde:

¿Por qué en estructuras balanceadas no basta con probar que el inorder está ordenado?

Tu respuesta debe mencionar:

* Propiedad BST.
* Altura.
* Rotaciones.
* Invariante AVL.
* Invariante Red-Black.
* Diferencia entre correctitud funcional y correctitud estructural.

#### Bloque 9 - Cierre comparativo

Responde esta pregunta final:

¿Qué cambia cuando pasamos de un BST común a estructuras balanceadas como AVL y Red-Black Tree?

La respuesta debe incluir obligatoriamente:

* Una afirmación sobre degeneración lineal del BST.
* Una afirmación sobre rotaciones y preservación del inorder.
* Una afirmación sobre balance por altura en AVL.
* Una afirmación sobre balance por colores en Red-Black Tree.
* Una afirmación sobre la diferencia entre balance estricto y balance flexible.
* Una afirmación sobre el costo esperado o garantizado de búsqueda, inserción y eliminación.
* Una afirmación sobre cómo esta semana continúa Semana 5 y Semana 6.
* Una afirmación sobre qué evidencia usarías para defender correctitud: pruebas, demostraciones, invariantes, trazados y complejidad.

#### Formato sugerido de entrega

```markdown
### Actividad 7 - CC232

#### Estudiante

- Nombre:

#### Bloque 1 - Diagnóstico inicial

[Tabla de comandos, resultados e interpretación]

#### Bloque 2 - BST como punto de partida

[Respuestas, dibujo y complejidad]

#### Bloque 3 - AVL

[Invariantes, trazado y evidencia]

#### Bloque 4 - Rotaciones AVL

[Tabla LL, RR, LR, RL y dibujos]

#### Bloque 5 - Red-Black Tree

[Invariantes, recoloreo, rotaciones y evidencia]

#### Bloque 6 - Comparación

[Tabla BST, Treap, AVL y Red-Black Tree]

#### Bloque 7 - Pruebas e invariantes

[Tabla de pruebas y defensa]

#### Bloque 8 - Ejercicios de codificación

[Código, evidencias, pruebas e interpretación]

#### Bloque 9 - Cierre comparativo

[Respuesta final]

#### Autoevaluación breve

- Qué puedo defender con seguridad:
- Qué todavía confundo:
- Qué evidencia usaría en una sustentación:
- Qué parte del código debo revisar otra vez:
```

#### Criterio general de trabajo

Se espera lectura real de los archivos, respuestas breves pero justificadas, tablas con evidencia observable, trazados manuales y conexión explícita entre código, correctitud, costo, representación e invariantes.

No basta con ejecutar el programa: debes poder explicar qué propiedad mantiene cada estructura, qué rotación se aplica, qué color o altura se actualiza, qué caso borde aparece y por qué la operación conserva búsqueda ordenada eficiente.
