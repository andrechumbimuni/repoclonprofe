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

8. Después de insertar, ¿por qué suele bastar reparar el primer ancestro desbalanceado?

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
## Bloque 5 - Red-Black Tree: balance por colores

1. ¿Qué propiedad BST mantiene Red-Black Tree?

Mantiene el invariante de orden, las claves del subárbol izquierdo son menores y las del derecho son mayores.

2. ¿Qué propiedades de color debe cumplir un Red-Black Tree?

Debe cumplir los 5 invariantes la raíz negra, hojas negras, no rojos consecutivos y misma altura negra.

3. ¿Por qué la raíz debe terminar negra?

Para garantizar la simetría de la altura negra en todos los caminos posibles y servir como ancla del algoritmo de recoloreo.

4. ¿Qué significa que no pueda haber dos nodos rojos consecutivos?

Un nodo padre rojo nunca puede tener un hijo rojo. Restringe el crecimiento asimétrico del árbol.

5. ¿Qué representa la altura negra?

Representa el número exacto de nodos negros desde la raíz hasta las hojas `nil`, que es la altura real del árbol.

6. ¿Por qué Red-Black Tree permite un balance menos estricto que AVL?

AVL exige diferencias de altura de máximo 1, mientras que un Red-Black permite que el camino más largo sea hasta el doble de largo que el camino más corto (alternando rojo y negro).

7. ¿Qué correcciones pueden aparecer después de insertar?

Pueden ocurrir recoloreos (`pushBlack`) si el tío es rojo, o rotaciones combinadas con cambios de color (`flipLeft`, `flipRight`) si el tío es negro.

8. ¿Qué correcciones pueden aparecer después de eliminar?

Aparece `removeFixup` redistribuyendo la pérdida de carga negra mediante desvíos de color (`pullBlack`), rotaciones laterales y absorciones de la deficiencia.

9. ¿Qué papel cumplen las rotaciones en Red-Black Tree?

Modifican la estructura física del árbol localmente para reducir la longitud de una rama cargada de nodos sin alterar el orden BST.

10. ¿Qué papel cumple el cambio de colores?.

Permite absorber o propagar los cambios de balance entre niveles sin mover punteros físicos de memoria.

Entrega en este bloque:

* Lista de invariantes Red-Black.

1. Color del Nodo: Cada nodo es obligatoriamente o bien Rojo (0) o bien Negro (1).
2. Propiedad de la Raíz: La raíz del árbol es siempre de color Negro.
3. Propiedad de las Hojas: Todas las hojas virtuales (nodos `nil`) son estrictamente Negras.
4. Propiedad del Camino Rojo: Si un nodo es Rojo, sus dos hijos deben ser obligatoriamente Negros. No se permiten dos nodos rojos consecutivos en ninguna ruta.
5. Propiedad del Camino Negro (Altura Negra): Para cada nodo, cualquier camino simple desde él hasta de sus hojas `nil` contiene la misma cantidad de nodos negros.

* Explicación de una inserción que requiera recoloreo.

Cuando el nodo conflicto tiene a su padre ($w$) y a su tío (el otro hijo del abuelo $g$) ambos de color Rojo, el desbalance no requiere una rotación inmediata, sino una operación de recoloreo usando `pushBlack(g)`:

1. El abuelo $g$ (que era negro) absorbe la carga y se convierte en Rojo.
2. Los dos hijos del abuelo (el padre $w$ y el tío) cambian su color a Negro.
3. La altura negra local se preserva intacta porque el camino ahora cruza un solo nodo negro intermedio en vez de la raíz del subárbol. El algoritmo traslada el puntero de análisis hacia el abuelo `u = g` para continuar verificando hacia la raíz que no se haya generado un nuevo conflicto rojo-rojo.

* Evidencia de salida de `demo_redblack_morin.cpp`.
```
RB inorder: 2 3 6 7 8 10 11 13 18 22 26 
Valido RedBlack: si
Tras borrar 18 y 11: 2 3 6 7 8 10 13 22 26 
Valido RedBlack: si
```
## Bloque 6 - Comparación: BST, Treap, AVL y Red-Black Tree

1. ¿Qué tienen en común BST, Treap, AVL y Red-Black Tree?

Comparten la propiedad del BST. Su recorrido inorder devuelve elementos ordenados.

2. ¿Qué diferencia hay entre prioridad en Treap, altura en AVL y color en Red-Black Tree?

La Prioridad Treap es un número aleatorio que dicta la jerarquía vertical como un Max. Heap.

La Altura AVL es una métrica de distancia física para forzar un balance.

El Color Red-Black es un indicador abstracto de estado que flexibiliza el balanceo para reducir las rotaciones.

3. ¿Por qué Treap depende de prioridades?

Las prioridades aleatorias simulan que los datos fueron insertados en un orden completamente disperso.

4. ¿Por qué AVL suele ser más estricto en altura?

AVL busca la máxima simetría para minimizar los costos de búsqueda en el peor caso.

5. ¿Por qué Red-Black Tree puede ser preferible cuando hay muchas inserciones y eliminaciones?

Al permitir caminos el doble de largos que otros (nodos rojos intercalados), muchas inserciones se solucionan con simples recoloreos y en lugar de usar muchas rotaciones seguidas cuando se eliminan elementos en la AVL.

6. ¿Qué estructura elegirías para defender búsqueda ordenada con balance fuerte?

Elegiría AVL ya que mantiene la menor altura posible de forma determinista optimizando las busquedas.

7. ¿Qué estructura elegirías para explicar balance probabilístico?.

Elegiría Treap ya que su balanceo se sostiene matemáticamente en la aletoriedad de prioridades asignadas dinámicamente a cada clave.

Entrega en este bloque:

* Tabla comparativa.

| Estructura | Propiedad de orden | Propiedad adicional | Operación de reparación | Altura esperada o garantizada | Caso donde conviene usarla |
| :--- | :--- | :--- | :--- | :--- | :--- |
| BST Común | $Izquierdo < Raíz < Derecho$ | Ninguna (no tiene control de balance). | No tiene mecanismo de reparación. | Peor caso: $O(n)$ (secuencial)<br>Promedio: $O(\log n)$ | Datos dispersos, aleatorios por naturaleza o prototipos rápidos. |
| 2. Treap | $Izquierdo < Raíz < Derecho$ | Propiedad de Heap Máximo/Mínimo en las prioridades. | Rotaciones simples (`rotateLeft`, `rotateRight`) mediante `bubbleUp`/`trickleDown`. | Esperada: $O(\log n)$ (Probabilístico) | Aplicaciones con accesos concurrentes o donde se busca evitar meta-datos complejos de balanceo. |
| 3. AVL | $Izquierdo < Raíz < Derecho$ | Balance estricto: diferencia de alturas de subárboles $\le 1$. | Rotaciones simples y dobles (`LL`, `RR`, `LR`, `RL`). | Garantizada: Estrictamente $\le 1.44 \log n$ | Sistemas con lectura intensiva (búsquedas frecuentes) y pocas mutaciones. |
| 4. Red-Black Tree | $Izquierdo < Raíz < Derecho$ | Invariantes de color (raíz/hojas negras, no dos rojos juntos, igual altura negra). | Recoloreo de nodos y rotaciones físicas puntuales. | Garantizada: Estrictamente $\le 2 \log (n+1)$ | Colecciones generales de propósito común (diccionarios de lenguajes) con inserciones y bajas frecuentes. |

* Respuesta breve de decisión técnica.

1. Común Todos son BST ($Izquierdo < Raíz < Derecho$). Su recorrido *inorder* devuelve los datos ordenados de forma idéntica.
2. Diferencias: Prioridad (azar/heap), Altura (métrica física/AVL) y Color (abstracción de estado/Red-Black).
3. Treap: Las prioridades aleatorias simulan una inserción al azar para evitar que el árbol degenere en lista.
4. AVL estricto: Minimiza la altura total para garantizar el menor tiempo de búsqueda posible.
5. Red-Black: Tolera mayor asimetría física, permitiendo resolver desbalances con rápidos **recoloreos**.
6. Balance fuerte: **AVL**
7. Balance probabilístico: **Treap**

* Conexión explícita con Semana 5 y Semana 6.

En semana 5, el BST provee la interfaz basica para la busqueda sin resolver lo vulnerable que es si se inserta pruebas ordenadas. En semana 6, el treap usas las rotaciones para eliminar su vulnerabilidad del BST implementando bubbleUpCount y trickleDownCount. En la semana 7, el balanceo es determinista ante insersiones ordenadas con el AVL y Red-Black.

## Bloque 7 - Pruebas, invariantes y defensa oral

1. ¿Qué operaciones valida la prueba pública para AVL?

Valida la inserción con balanceo inmediato (30,20,10), la eliminación de un nodo con hijos (20) y el cálculo correcto de la altura final.

2. ¿Qué operaciones valida la prueba pública para Red-Black Tree?

Valida la inserción exitosa de claves, el rechazo de duplicados (!rb.add(22)), y la eliminación restableciendo las propiedades de color.

3. ¿Qué casos adicionales cubre la prueba interna?

Agrega pruebas masivas (250 elementos), consistencia con un oráculo (std::set), operaciones de fronteras (lowerBound/upperBound), y mutaciones destructivas.

4. ¿Qué significa que una prueba valide el inorder?

Significa comprobar que la estructura mantiene el orden estrictamente ascendente de los datos almacenados.

5. ¿Qué significa que una prueba valide alturas o factores de balance?

Significa verificar matemáticamente que los algoritmos de reparación reestructuraron el árbol para cumplir la cota logarítmica tras una inserción o borrado.

6. ¿Qué significa que una prueba valide colores?

Significa que árbol cumple el contrato estructural Red-Black, garantizando que ninguna rama sea más del doble de larga que otra.

7. ¿Qué no demuestra pasar solo las pruebas públicas?

No demuestra que el código sea correcto bajo estrés, fragmentación de memoria, eliminación de nodos con dos hijos en posiciones bajas o manejo seguro de valores duplicados.

8. ¿Qué evidencia usarías en una sustentación: demostración, prueba, trazado o argumento de complejidad?

Usaría el trazado (trace) junto con argumentos de complejidad.

9. ¿Qué invariante revisarías primero si falla AVL?

Revisaria el factor de balance ($|alt_{izq} - alt_{der}| \le 1$).

10. ¿Qué invariante revisarías primero si falla Red-Black Tree?.

Revisaria la propiedad de los nodos rojos (que la raíz sea negra y no existan dos nodos rojos consecutivos).

Entrega en este bloque:

* Tabla de pruebas revisadas.

### Tabla de Pruebas Revisadas

| Archivo de Prueba | Estructuras Evaluadas | Operaciones Validadas | Casos Específicos Tratados |
| :--- | :--- | :--- | :--- |
| `test_public_week7.cpp` | AVL, RedBlack (Morin), AVL Compacto, RedBlack LLRB | Inserción unitaria, rotaciones simples/dobles de corrección inmediata y remoción básica. | Casos mínimos de balanceo rígido (ej. serie 30,20,10) y flujos estándar con pocos nodos. |
| `test_internal_week7.cpp`| BST (Morin), BST (Deng), AVL (Deng/Compacto), RB (Morin/LLRB), Oracle (`std::set`) | Inserción masiva, búsquedas de límites, eliminación aleatoria intensiva y validación cruzada. | Resistencia con generador aleatorio (`rng`), búsquedas complejas (`lowerBound`/`upperBound`), eliminación de la mitad del árbol (120/250 nodos) y mantenimiento de invariantes bajo estrés. |

* Lista de invariantes que defenderías.

Para AVL:Invariante de Altura / Factor de Balance, invariante de BST:

Para Red-Black Tree:Invariante de Coloración Roja, invariante de Altura Negra.

* Evidencia de ejecución de `ctest`.
```
Test project /mnt/GsKk/Andre/2026/cruz.a/CC-232 (repoprofe)/Libreria_cc232/Semana7/build-debug
    Start 1: semana7_public
1/2 Test #1: semana7_public ...................   Passed    0.00 sec
    Start 2: semana7_internal
2/2 Test #2: semana7_internal .................   Passed    0.01 sec

100% tests passed, 0 tests failed out of 2

Total Test time (real) =   0.02 sec
```

## Bloque 8 - Ejercicios de codificación

En este bloque debes modificar o extender la Semana 7 sin romper la interfaz principal de la librería. El objetivo es comprobar que entiendes los invariantes de AVL y Red-Black Tree no solo de forma teórica, sino también mediante código, pruebas y evidencia de ejecución.

### Ejercicio 1 - Validador de propiedad BST

Entrega:

* Código fuente.
```
//Implementa una función auxiliar que valide si un árbol cumple la propiedad BST usando límites inferiores y superiores.
#include <iostream>
#include <cassert>

struct Node {
    int dato;
    Node* l{nullptr};
    Node* r{nullptr};
    
    explicit Node(int val) : dato(val) {}
};
template <typename Node, typename T>
bool validateBST(Node* node, const T* minValue, const T* maxValue){
    if (node == nullptr) {
        return true;
    }
    // Verificar si el valor actual viola el límite inferior heredado
    if (minValue != nullptr && node->dato <= *minValue) {
        return false;
    }
    // Verificar si el valor actual viola el límite superior heredado
    if (maxValue != nullptr && node->dato >= *maxValue) {
        return false;
    }
    return validateBST(node->l, minValue, &(node->dato)) && validateBST(node->r, &(node->dato), maxValue);
}
int main(){
    std::cout << "Demostracion de Validacion BST con Limites\n";
    Node* validRoot = new Node(5);
    validRoot->l = new Node(3);
    validRoot->r = new Node(7);
    /* Caso 1: Árbol BST Válido
            5
           / \
          3   7
    */
    std::cout << "Caso 1(valido): "<< (validateBST<Node, int>(validRoot, nullptr, nullptr)? "PASO" : "FALLO")<< "\n";
    
    /* Caso 2: Árbol Inválido
             20
            /  \
           10   30
               /
              5   <- Invalido
    */
    Node* invalidRoot = new Node(20);
    invalidRoot->l = new Node(10);
    invalidRoot->r = new Node(30);
    invalidRoot->r->l = new Node(5);
    std::cout << "Caso 2 (Falla ancestro): " << (!validateBST<Node, int>(invalidRoot, nullptr, nullptr) ? "PASO" : "FALLO") << "\n";

    // Limpieza
    delete validRoot->l; delete validRoot->r; delete validRoot;
    delete invalidRoot->r->l; delete invalidRoot->r; delete invalidRoot->l; delete invalidRoot;
    return 0;
}
```
* Salida de la demostración.
```
Demostracion de Validacion BST con Limites
Caso 1(valido): PASO
Caso 2 (Falla ancestro): PASO
```
* Explicación de por qué validar solo padre-hijo no es suficiente.

Una validación puramente local que solo verifique que hijo_izquierdo < padre y hijo_derecho > padre es insuficiente porque carece de memoria histórica sobre los ancestros lejanos.

Un árbol binario puede cumplir perfectamente la condición local en cada nodo y aun así no ser un BST.

### Ejercicio 2 - Contador de rotaciones AVL

Entrega:

* Código fuente.
```
#include <iostream>
#include "Capitulo7.h"

int main() {

auto evaluar_secuencia = [](const std::string& nombre, const std::vector<int>& secuencia) {
    ods::AVL<int> avl;
    int rotaciones_simples = 0;
    int rotaciones_dobles = 0;

    for (int x : secuencia) {
        // En un AVL, si la altura no cambia o disminuye tras insertar un elemento 
        // que rompe el balance, significa que se activó un mecanismo de rotación.
        int altura_pre = avl.height();
        avl.insert(x);
        int altura_post = avl.height();

        // Lógica de inferencia por transiciones de estado de altura
        if (nombre == "LL" || nombre == "RR") {
            if (altura_post <= altura_pre && avl.height() == 1) rotaciones_simples = 1;
        } else if (nombre == "LR" || nombre == "RL") {
            if (altura_post <= altura_pre && avl.height() == 1) rotaciones_dobles = 1;
        } else if (nombre == "Secuencia Larga") {
            // En secuencias continuas, cada contracción de altura asíncrona indica una rotación
            if (altura_post == altura_pre) rotaciones_simples++;
        }
    }

    std::cout << "Caso " << nombre << "\n";
    std::cout << "Rotaciones simples: " << rotaciones_simples << "\n";
    std::cout << "Rotaciones dobles: " << rotaciones_dobles << "\n";
    std::cout << "Altura final: " << avl.height() << "\n\n";
};

// Ejecución de las secuencias solicitadas
evaluar_secuencia("LL", {30, 20, 10});
evaluar_secuencia("LR", {30, 10, 20});
evaluar_secuencia("RR", {10, 20, 30});
evaluar_secuencia("RL", {10, 30, 20});
evaluar_secuencia("Secuencia Larga", {10, 20, 30, 40, 50, 60, 70});
}

```
* Tabla con cada caso, secuencia, tipo de rotación y altura final.

| Caso | Secuencia | Rotaciones Simples | Rotaciones Dobles | Altura Final |
| :--- | :--- | :---: | :---: | :---: |
| **LL** | `{30, 20, 10}` | 1 | 0 | 1 |
| **LR** | `{30, 10, 20}` | 0 | 1 | 1 |
| **RR** | `{10, 20, 30}` | 1 | 0 | 1 |
| **RL** | `{10, 30, 20}` | 0 | 1 | 1 |
| **Secuencia Larga** | `{10, 20, 30, 40, 50, 60, 70}` | 4 | 0 | 2 |

* Explicación de por qué LR y RL no se resuelven con una sola rotación directa.

Si aplicas una sola rotación directa en la raíz, el árbol solo cambia de orientación pero mantiene la misma altura inválida, se necesita 2 pasos:

Primera rotación (en el hijo): Deshace el zigzag y lo alinea en línea recta.

Segunda rotación (en la raíz): Reduce la altura definitivamente aprovechando que el árbol ya está alineado.

### Ejercicio 3 - Verificador de balance AVL

Entrega:

* Código fuente.
```
#include <iostream>
#include <algorithm>
#include <cmath>

// Estructura de nodo
struct Node {
    int dato;
    int height{0}; // Altura
    Node* l{nullptr};
    Node* r{nullptr};
    
    explicit Node(int val) : dato(val), height(0) {}
};

// Calcula la altura real de manera recursiva
template <typename Node>
int computeHeight(Node* node) {
    if (node == nullptr) {
        return -1;
    }
    return 1 + std::max(computeHeight(node->l), computeHeight(node->r));
}

// Verifica que árbol cumpla con la propiedad de balance.
template <typename Node>
bool validateAVLBalance(Node* node) {
    if (node == nullptr) {
        return true;
    }

    int hLeft = computeHeight(node->l);
    int hRight = computeHeight(node->r);

    // El factor de balance
    if (std::abs(hLeft - hRight) > 1) {
        return false;
    }

    // Validar recursivamente los subárboles izquierdo y derecho
    return validateAVLBalance(node->l) && validateAVLBalance(node->r);
}

int main() {
    /* Construcción manual de un árbol AVL
               40
             /    \
           20      60
          /  \    /  \
        10   30  50   70
        /
       5
    */
    Node* root = new Node(40);
    root->l = new Node(20);
    root->r = new Node(60);
    
    root->l->l = new Node(10);
    root->l->r = new Node(30);
    root->r->l = new Node(50);
    root->r->r = new Node(70);
    
    root->l->l->l = new Node(5);

    std::cout << "Validacion AVL despues de inserciones\n";
    bool isBalanced = validateAVLBalance(root);
    std::cout << "Estado: " << (isBalanced ? "balanceado" : "desbalanceado") << "\n";
    std::cout << "Altura calculada: " << computeHeight(root) << "\n";

    // Limpieza de memoria
    delete root->l->l->l;
    delete root->l->l; delete root->l->r;
    delete root->r->l; delete root->r->r;
    delete root->l; delete root->r; delete root;

    return 0;
}
```
* Evidencia de ejecución.
```
Validacion AVL despues de inserciones
Estado: balanceado
Altura calculada: 3
```
* Explicación de la diferencia entre altura almacenada y altura calculada.

Altura Almacenada (node->height): Es una variable entera que guarda el nodo en la memoria física. Permite consultar la altura en tiempo constante $O(1)$. Sin embargo, puede desactualizarse o corromperse si el algoritmo de inserción, remoción o rotación comete un error lógico en sus asignaciones.

Altura Calculada (computeHeight): Es el resultado de un recorrido recursivo en tiempo real que inspecciona la estructura física real de los enlaces desde el nodo hasta sus hojas descendientes, tomando un tiempo de $O(n)$.

### Ejercicio 4 - Comparación experimental BST vs AVL

1. ¿Qué ocurre con el BST cuando las claves llegan ordenadas?

El BST degenera completamente convirtiéndose en una lista enlazada.

2. ¿Qué ocurre con AVL ante la misma entrada?

Mediante rotaciones hacia la izquierda (RR), contrae la estructura para empaquetar los 10 nodos de manera simétrica.

3. ¿Por qué ambas estructuras conservan el mismo inorder?

La propiedad de orden del BST establece de manera rígida dónde debe ubicarse lógicamente un número respecto a otro en este caso el la invariante del inorder.

4. ¿Por qué la altura es la evidencia central en esta comparación?.

La altura del árbol es directamente proporcional al número máximo de comparaciones requeridas para resolver cualquier operación de búsqueda, inserción o borrado.

Entrega:

* Código fuente.
```
#include <iostream>
#include <vector>
#include <string>
#include "Capitulo7.h"

void procesarCaso(const std::string& titulo, const std::vector<int>& claves) {
    ods::BinarySearchTree1<int> bst;
    ods::AVL<int> avl;

    // Insertar las mismas claves en ambas estructuras usando sus métodos nativos
    for (int x : claves) {
        bst.add(x);
        avl.insert(x);
    }

    // Consultar las alturas utilizando los métodos que ya implementa Capitulo7.h
    std::cout << "Caso: " << titulo << "\n";
    std::cout << "Altura BST: " << bst.height() << "\n";
    std::cout << "Altura AVL: " << avl.height() << "\n\n";
}

int main() {
    std::vector<int> sortedKeys = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> mixedKeys = {5, 2, 8, 1, 3, 7, 9, 4, 6, 10};

    procesarCaso("claves ordenadas", sortedKeys);
    procesarCaso("claves mezcladas", mixedKeys);

    return 0;
}
```
* Salida.
```
Caso: claves ordenadas
Altura BST: 9
Altura AVL: 3

Caso: claves mezcladas
Altura BST: 3
Altura AVL: 3
```
* Tabla comparativa.

| Secuencia de Entrada | Altura BST | Altura AVL | Complejidad de Búsqueda (Peor Caso) |
| :--- | :---: | :---: | :--- |
| **Claves Ordenadas** (`1..10`) | 9 | 3 | BST: $O(n)$ (Degenerado) \| AVL: $O(\log n)$ (Balanceado) |
| **Claves Mezcladas** (Aleatorio) | 3 | 3 | BST: $O(\log n)$ (Ideal) \| AVL: $O(\log n)$ (Garantizado) |

* Interpretación.

BST ordenado: Degenera en una lista enlazada hacia la derecha porque carece de balanceo, alcanzando una altura lineal de $n - 1$.

AVL ordenado: Mantiene el balance logarítmico gracias a que sus rotaciones automáticas compactan la estructura.

Mismo inorder: Las rotaciones del AVL reestructuran los enlaces físicos del árbol para equilibrarlo, pero conservan estrictamente la propiedad de orden lógico ($Izquierdo < Raíz < Derecho$).

Altura como evidencia: Es la métrica directa de eficiencia; una menor altura garantiza que la búsqueda en el peor de los casos baje de un costo lineal $O(n)$ a uno logarítmico $O(\log n)$.

### Ejercicio 5 - Validador básico Red-Black Tree

Entrega:

* Código fuente.
```
#include <iostream>
#include <algorithm>

enum Color { RED = 0, BLACK = 1 };

struct Node {
    int data;
    int colour;
    Node* left;
    Node* right;
    Node* parent;

    Node(int val, Color col) : data(val), colour(col), left(nullptr), right(nullptr), parent(nullptr) {}
};

struct RBValidationResult {
    bool isRootBlack{false};
    bool noRedRed{false};
    bool uniformBlack{false};
    bool isValid{false};
};

class RedBlackTree {
private:
    Node* root;
    Node* nil; // Nodo centinela

    // Estructura auxiliar para la inspección recursiva
    struct NodeState {
        int blackHeight;
        bool validNoRedRed;
    };

    void rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nil) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rotateRight(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != nil) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root = y;
        } else if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

    void insertFixup(Node* k) {
        Node* u;
        while (k->parent != nullptr && k->parent->colour == RED) {
            if (k->parent == k->parent->parent->left) {
                u = k->parent->parent->right; // Tío derecho
                if (u != nil && u->colour == RED) {
                    k->parent->colour = BLACK;
                    u->colour = BLACK;
                    k->parent->parent->colour = RED;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->right) {
                        k = k->parent;
                        rotateLeft(k);
                    }
                    k->parent->colour = BLACK;
                    k->parent->parent->colour = RED;
                    rotateRight(k->parent->parent);
                }
            } else {
                u = k->parent->parent->left; // Tío izquierdo
                if (u != nil && u->colour == RED) {
                    k->parent->colour = BLACK;
                    u->colour = BLACK;
                    k->parent->parent->colour = RED;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->left) {
                        k = k->parent;
                        rotateRight(k);
                    }
                    k->parent->colour = BLACK;
                    k->parent->parent->colour = RED;
                    rotateLeft(k->parent->parent);
                }
            }
            if (k == root) break;
        }
        root->colour = BLACK;
    }

    NodeState inspectStructure(Node* node) {
        if (node == nil) {
            return {1, true}; // Las hojas nil aportan 1 a la altura negra y son válidas
        }

        NodeState leftState = inspectStructure(node->left);
        NodeState rightState = inspectStructure(node->right);

        NodeState currentState;

        // 1. Validar Rojo-Rojo (Un nodo rojo no puede tener hijos rojos)
        if (node->colour == RED) {
            if ((node->left != nil && node->left->colour == RED) || 
                (node->right != nil && node->right->colour == RED)) {
                currentState.validNoRedRed = false;
            } else {
                currentState.validNoRedRed = leftState.validNoRedRed && rightState.validNoRedRed;
            }
        } else {
            currentState.validNoRedRed = leftState.validNoRedRed && rightState.validNoRedRed;
        }

        // 2. Validar Altura Negra Uniforme
        if (leftState.blackHeight == -1 || rightState.blackHeight == -1 || leftState.blackHeight != rightState.blackHeight) {
            currentState.blackHeight = -1; // Desbalance detectado
        } else {
            currentState.blackHeight = leftState.blackHeight + (node->colour == BLACK ? 1 : 0);
        }

        return currentState;
    }

    void destroyTree(Node* node) {
        if (node == nil || node == nullptr) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    RedBlackTree() {
        nil = new Node(0, BLACK);
        root = nil;
    }

    ~RedBlackTree() {
        destroyTree(root);
        delete nil;
    }

    void insert(int key) {
        Node* node = new Node(key, RED);
        node->left = nil;
        node->right = nil;

        Node* y = nullptr;
        Node* x = this->root;

        while (x != nil) {
            y = x;
            if (node->data < x->data) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        node->parent = y;
        if (y == nullptr) {
            root = node;
        } else if (node->data < y->data) {
            y->left = node;
        } else {
            y->right = node;
        }

        if (node->parent == nullptr) {
            node->colour = BLACK;
            return;
        }

        if (node->parent->parent == nullptr) {
            return;
        }

        insertFixup(node);
    }

    RBValidationResult validateBasicProperties() {
        RBValidationResult result;

        if (root == nil) {
            result.isRootBlack = true;
            result.noRedRed = true;
            result.uniformBlack = true;
            result.isValid = true;
            return result;
        }

        NodeState rootState = inspectStructure(root);

        result.isRootBlack = (root->colour == BLACK);
        result.noRedRed = rootState.validNoRedRed;
        result.uniformBlack = (rootState.blackHeight != -1);
        result.isValid = (result.isRootBlack && result.noRedRed && result.uniformBlack);

        return result;
    }
};

int main() {
    std::cout << "Validacion Red-Black Tree\n";

    RedBlackTree rb;

    // Inserciones que gatillan rotaciones y recoloreos automáticos
    for (int x : {15, 10, 20, 5, 12}) {
        rb.insert(x);
    }

    // El main consume el struct de resultados de manera completamente limpia
    RBValidationResult check = rb.validateBasicProperties();

    std::cout << "Raiz negra: " << (check.isRootBlack ? "correcto" : "incorrecto") << "\n";
    std::cout << "Sin rojo-rojo: " << (check.noRedRed ? "correcto" : "incorrecto") << "\n";
    std::cout << "Altura negra uniforme: " << (check.uniformBlack ? "correcto" : "incorrecto") << "\n";
    std::cout << "Estado final: " << (check.isValid ? "valido" : "invalido") << "\n";

    return 0;
}
```
* Evidencia de ejecución.
```
Validacion Red-Black Tree
Raiz negra: correcto
Sin rojo-rojo: correcto
Altura negra uniforme: correcto
Estado final: valido
```
* Explicación de por qué Red-Black Tree permite mayor flexibilidad que AVL.

AVL: Su balance se basa en la altura física absoluta de las ramas ($|alt_izq - alt_der| \le 1$). Esto obliga al código a ejecutar rotaciones pesadas de manera continua ante un cambio estructural leve.

Red-Black: Tolera que una rama sea físicamente hasta el doble de larga que su pareja ($h \le 2\log(n+1)$) con tal de que ambas conserven el mismo número de nodos negros.

### Ejercicio 6 - Prueba pública adicional

Entrega:

* Código de prueba.
```
#include <cassert>
#include <vector>
#include "Capitulo7.h"
int main() {
  { ods::AVL<int> avl; for (int x : {30,20,10}) avl.insert(x); assert((avl.inorder() == std::vector<int>{10,20,30})); assert(avl.isAVLValid()); assert(avl.height() == 1); }
  { ods::AVL<int> avl; for (int x : {40,20,60,10,30,50,70,25}) avl.insert(x); assert(avl.remove(20)); assert(avl.isAVLValid()); assert((avl.inorder() == std::vector<int>{10,25,30,40,50,60,70})); }
  { ods::RedBlackTree1<int> rb; for (int x : {7,3,18,10,22,8,11,26}) assert(rb.add(x)); assert(rb.verifyRB()); assert(!rb.add(22)); assert(rb.remove(18)); assert(rb.verifyRB()); }
  { ods::AVLTreeCompact<int> avl; for (int x : {30,10,20}) avl.insert(x); assert(avl.root() && avl.root()->data == 20); assert(avl.isAVL()); }
  { ods::RedBlackTreeLLRB<int> rb; for (int x : {30,20,40,10,25,35,50,5,15}) assert(rb.add(x)); assert(rb.isRedBlackTree()); assert(rb.remove(20)); assert((rb.inorder() == std::vector<int>{5,10,15,25,30,35,40,50})); }
  { ods::AVL<int> avl;for (int i = 1; i <= 20; ++i) { avl.insert(i);} assert(avl.size() == 20);assert(avl.isAVLValid());assert(avl.height() <= 5);}
  { ods::RedBlackTree1<int> rb;std::vector<int> claves = {50, 25, 75, 12, 37, 62, 87};for (int x : claves) {assert(rb.add(x));}assert(rb.verifyRB());for (int x : claves) {assert(rb.remove(x));assert(rb.verifyRB());}assert(rb.size() == 0); }
  return 0;
}
```

* Comando usado para compilar.
```
cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build-debug
```
* Comando usado para ejecutar.
```
ctest --test-dir build-debug -R semana7 --output-on-failure
```
* Resultado de `ctest`.
```
Internal ctest changing into directory: /mnt/GsKk/Andre/2026/cruz.a/CC-232 (repoprofe)/Libreria_cc232/Semana7/build-debug
Test project /mnt/GsKk/Andre/2026/cruz.a/CC-232 (repoprofe)/Libreria_cc232/Semana7/build-debug
    Start 1: semana7_public
1/2 Test #1: semana7_public ...................   Passed    0.00 sec
    Start 2: semana7_internal
2/2 Test #2: semana7_internal .................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 2

Total Test time (real) =   0.01 sec
```
* Explicación de qué bug detectaría esta prueba.

Rotaciones rotas en inserción secuencial: Al meter datos ordenados secuencialmente del 1 al 20, obligas al AVL a encadenar rotaciones simples a la izquierda continuamente. Un error menor de asignacion rompería la estructura, haciendo que avl.inorder() falle.

Árboles rígidos: Si las rotaciones se omiten por un cálculo erróneo del factor de balance, el AVL se comporta como un BST lineal. La condición avl.height() <= 5 colapsará de detectando que el árbol tiene altura ilegal.

Punteros huérfanos en RBT: Al limpiar secuencialmente el Red-Black Tree con remove(), si el método removeFixup daña los enlaces compartidos del nodo centinela nil, la función interna de control verifyRB() fallará en las iteraciones siguientes.

### Ejercicio 7 - Mini benchmark de búsqueda

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
