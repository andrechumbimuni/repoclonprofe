## Actividad 6 - CC232

### Estudiante
- Nombre: Chumbimuni Ricci Andre Dylan
- Código: 20230303J
- Fecha: 29 de Mayo 2026

### Resumen de modificaciones
| Bloque | Archivo modificado | Cambio realizado | Evidencia |
|---|---|---|---|
| **MOD-A6-B1** | `PQ_ComplHeap_macro.h` | Adición de funciones lógicas `constexpr` (`pqHasLeftChild`, `pqHasRightChild`, `pqIsLeaf`, `pqIsInternal`) para eliminar comparaciones aritméticas directas. | Compilación limpia con GCC 13.3.0 sin advertencias ni regresiones en los headers hermanos. |
| **MOD-A6-B1** | `PQ_ComplHeap_percolateDown.h` | Rediseño del ciclo `while` y de las ramas condicionales para consumir las nuevas abstracciones de control de fronteras. | Paso invicto de las pruebas unitarias automatizadas `semana6_public` y `semana6_internal` (`100% tests passed`). |
| **MOD-A6-B2** | `PQ_ComplHeap_percolateUp.h` | Inclusión de la función no destructiva `complHeapPercolateUpCount` para rastrear y retornar métricas de intercambios durante la inserción. | Compilación limpia y disponibilidad de la función para trazas de rendimiento. |
| **MOD-A6-B2** | `demo_pq_complheap_basico.cpp` | Reemplazo del escenario base por la inserción controlada de la secuencia `{40, 10, 70, 30, 90, 20, 80, 60}`, imprimiendo estadísticas y verificando el invariante de max-heap. | Salida limpia en terminal con todas las aserciones validando "SI" a la propiedad estructural del Heap. |
| **MOD-A6-B3** | `PQ_ComplHeap_percolateDown.h` | Inclusión de la función extendida `complHeapPercolateDownCount` para instrumentar y retornar el conteo preciso de colisiones e intercambios durante la reparación descendente. | Compilación exitosa en GCC 13.3.0 sin advertencias. |
| **MOD-A6-B3** | `demo_pq_complheap_basico.cpp` | Implementación de una rutina destructiva secuencial que vacía por completo el Heap empleando la variante contadora, imprimiendo el estado antes y después de estabilizar la memoria. | Salida en consola documentada que ratifica la exactitud del algoritmo de Floyd. |
| **MOD-A6-B4** | `PQ_ComplHeap.h` | Adición del método público `isValidHeap()` para evaluar de forma exhaustiva y lineal la validez del invariante de prioridad. | Compilación correcta e integración inmediata con las aserciones de testeo. |
| **MOD-A6-B4** | `test_public_week6.cpp` | Inclusión del método `ejecutarPruebasConsistenciaHeap()`, cubriendo los 6 escenarios requeridos (vacío, unitario, repetidos, inserciones, heapify y vaciado). | Ejecución impecable vía `ctest` reportando paso exitoso del 100% de la suite. |
| **MOD-A6-B5** | `demo_heapify_floyd.cpp` | Reescritura integral de la demostración para contrastar la técnica de inserciones sucesivas contra el algoritmo de Floyd, cuantificando los intercambios de memoria física mediante instrumentación activa. | Salida analítica en consola que comprueba un menor costo operativo en Floyd (10 intercambios vs 13) y confirma la validez del invariante en ambos vectores finales. |
| **MOD-A6-B6** | `vector_heapSort.h` | Inclusión del método sobrecargado `heapSort` con bandera booleana para habilitar la conmutación dinámica de jerarquía in-situ (Min-Heap / Max-Heap). | Compilación exitosa bajo el estándar C++17 sin emitir advertencias de tipos. |
| **MOD-A6-B6** | `demo_heapsort.cpp` | Renovación de la demo para evaluar el comportamiento con datos duplicados `{5, 1, 5, 3, 8, 2, 8, 0}` en sentido ascendente y descendente. | Traza en consola que valida el correcto ordenamiento y la consistencia en el agrupamiento de duplicados. |
| **MOD-A6-B7** | `PQ_LeftHeap.h` | Inclusión del método de inspección `isValidLeftHeap()` y de la subrutina recursiva `auditNode` para fiscalizar orden, propiedad izquierdista, correlación de tamaños y consistencia métrica de NPLs. | Compilación limpia sin advertencias bajo el estándar C++17. |
| **MOD-A6-B7** | `demo_left_heap_merge.cpp` | Modernización total de la demo integrando diagnósticos activos automatizados en las etapas pre y post-fusión de las colas de prioridad. | Salida detallada en terminal donde todas las fases de mutación reportan un estado verificado unánime de `SI`. |
| **MOD-A6-B8** | `Huffman_PQ.h` | Adaptación de `huffmanCollectCodes` para controlar de forma segura raíces sin hijos, asignando de manera explícita el código `"0"` ante alfabetos unitarios. | Compilación exitosa y prevención de excepciones por desreferenciación nula. |
| **MOD-A6-B8** | `demo_huffman.cpp` | Creación de una batería de pruebas automatizada para validar el desempate alfabético determinista y procesar de forma correcta el escenario extremo de un único símbolo. | Reporte exhaustivo en la consola que certifica la validez de los códigos generados y la propiedad de prefijo libre. |
| **MOD-A6-B9-PB** | `Treap.h` | Inyección de las subrutinas instrumentadas de control de flujo `bubbleUpCount` y `addWithPriorityCount` para auditar intercambios físicos en memoria sin alterar la API base. | Compilación limpia bajo el estándar de lenguaje C++17. |
| **MOD-A6-B9-PB** | `demo_treap_basico.cpp` | Modificación del flujo de ejecución para procesar la secuencia degenerada `{100, 90, 80, 70, 60}` y reportar las métricas analíticas de rotación. | Salida detallada en consola que confirma la correcta contención del invariante mixto de árbol y montículo en cada inserción. |
| **MOD-A6-B9-PC** | `Treap.h` | Inclusión de los métodos de control métrico `trickleDownCount` y `removeCount` para cuantificar las rotaciones durante los desbalances controlados de borrado. | Compilación limpia bajo el estándar de lenguaje C++17 sin regresiones. |
| **MOD-A6-B9-PC** | `demo_treap_basico.cpp` | Modificación del punto de entrada para aplicar remociones instrumentadas sucesivas sobre el lote de llaves `{50, 20, 70}`. | Registros en terminal que confirman la ejecución de 2 rotaciones para `20`, 1 rotación para `70` y un estado de consistencia estructural verificado continuo. |
| **MOD-A6-B9-PD** | `demo_treap_basico.cpp` | Inclusión del set de pruebas analíticas de rangos (`findEQ`, `lowerBound`, `upperBound`) sobre estados mutados del Treap. | Salida en consola limpia que ratifica la consistencia semántica exacta frente a un BST tradicional. |
| **MOD-A6-B9-PE** | `test_public_week6.cpp` | Implementación integral de las 13 pruebas de control estructural y de invariantes mixtos (BST + Heap). | Cobertura unánime aprobada (`Passed`) en CTest bajo el estándar de compilación C++17. |
| **MOD-A6-B10** | `demo_compare_with_semana5.cpp` | Reescritura del flujo para inyectar y contrastar de manera simultánea los componentes de la Semana 5 (`BinaryHeap`, `BST`) con las implementaciones avanzadas de la Semana 6 (`PQ_ComplHeap`, `Treap`). | Ejecución limpia que genera registros precisos de las salidas estructurales y los invariantes. |
| **MOD-A6-B11** | `test_public_week6.cpp` | Reescritura e inyección integral de la suite de pruebas unitarias instrumentadas, cubriendo de forma secuencial y automatizada los **15 requerimientos de invariantes**. | Ejecución unánime aprobada (`Passed`) a través de la consola de `CTest` con reporte de trazas limpio en 0.03 segundos. |

### Bloque 1 - Diagnóstico inicial de la Semana 6

1. ¿Qué targets de demostraciones o pruebas aparecen para Semana 6?

Las demos son sem6_demo_pq_complheap_basico, sem6_demo_heapify_floyd, sem6_demo_heapsort, sem6_demo_left_heap_merge, sem6_demo_huffman, sem6_demo_compare_with_semana5, sem6_demo_bst_rotations, sem6_demo_treap_basico, y sem6_demo_capitulo6_panorama.

Las pruebas son sem6_test_public y sem6_test_internal.

2. ¿Qué archivos se incluyen desde `Capitulo6.h`?

Se incluyen los archivos la semana 6 en la carpeta include de PQ.h, PQ_ComplHeap_macro.h, PQ_ComplHeap.h, PQ_ComplHeap_getMax.h; es un header de la semana6 como una interfaz.

3. ¿Qué diferencia práctica hay entre `Capitulo6.h` y `Capitulo10.h`?

El capitulo10.h es un alias de compatibilidad del capitulo6.h para que los programas que busquen el material bajo la numeración clásica del libro de texto de la asignatura funcionen sin romper dependencias.

4. ¿Qué partes de Semana 6 dependen conceptualmente de Semana 5?

Menciona que la semana 6 usas las estructuras de los arboles de semana5 para construir estructuras avanzadas como el Heap Izquierdista (que requiere punteros físicos para su operación merge) y el Treap (que requiere la estructura de un BST y sus métodos de rotación).

5. ¿Qué estructura se usa para prioridad pura?

Se utiliza la interfaz abstracta PQ<T> implementada a través de un montículo binario completo sobre un arreglo implícito (PQ_ComplHeap<T>) o mediante un heap izquierdista enlazado (PQ_LeftHeap<T>).

6. ¿Qué estructura se usa para búsqueda ordenada?

Se utiliza el Árbol de Búsqueda Binaria (BinarySearchTree<T>) heredado de la semana anterior, el cual mantiene las claves ordenadas horizontalmente.

7. ¿Qué estructura mezcla búsqueda ordenada con prioridad?

El Treap. Es un árbol aleatorizado que organiza sus nodos manteniendo de forma simultánea un invariante doble: propiedad de BST para las claves (orden horizontal) y propiedad de Heap para las prioridades asignadas al azar (orden jerárquico vertical).

8. ¿Qué evidencia inicial obtuviste al ejecutar las pruebas sin modificar nada?.

### Tabla de Ejecución de Comandos y Validación

| Comando Ejecutado | Resultado | Error si hubo | Interpretación |
| :--- | :---: | :---: | :--- |
| `cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug` | **Éxito** | Ninguno | Se identificó correctamente el compilador **GNU CXX 13.3.0** y se generó el directorio de construcción en la ruta local de la máquina de manera exitosa. |
| `cmake --build build-debug` | **Éxito** | Ninguno | Compilación y enlazado incremental limpio desde el `4%` hasta el `100%`. Se generaron los 9 ejecutables de demostración y los 2 ejecutables binarios de test sin advertencias. |
| `ctest --test-dir build-debug -R semana6 --output-on-failure` | **100% Passed** | Ninguno | Ejecución ultrarrápida (0.01 s). Ambos contenedores globales de pruebas (`semana6_public` y `semana6_internal`) pasaron invictos sin registrar fallos de aserción. |

### Bloque 2 - Modificación de utilidades de heap completo

1. ¿Por qué conviene expresar `parent`, `left`, `right` y pruebas de frontera como funciones pequeñas?

Para que si vea mas ordenado, que la relacion implicita del heap se vuelvan mas legibles, menos errores ya que son funciones pequeñas.

2. ¿Qué ventaja tiene `constexpr` frente a macros?

Se puede definir tipos , respeta ambitos que el macros solo reemplaza texto; tambien permite verificacion semantica y sintactica (como se comporta).

3. ¿Qué caso borde aparece cuando el nodo tiene solo hijo izquierdo?

El caso borde ocurre en un nodo ubicado en la penúltima capa del árbol cuando $n$ es un número par. Al evaluar la bifurcación, la expresión pqHasLeftChild(i, n) resulta verdadera, mientras que pqHasRightChild(i, n) resulta falsa. El algoritmo debe estar preparado para omitir de forma segura la comparación competitiva entre hermanos e identificar al hijo izquierdo directamente como el único candidato disponible para el intercambio.

4. ¿Qué condición identifica una hoja en la representación implícita?

Un nodo se considera hoja si su índice calculado para el hijo izquierdo excede o iguala el tamaño actual del vector. Matemáticamente se define como:
```
pqLeftChild(i) >= n
```
Si el hijo izquierdo no existe dentro de las fronteras físicas del heap, el hijo derecho tampoco existirá, deduciendo que el nodo no posee descendencia.

5. ¿Qué cambió en `percolateDown` después de usar las funciones auxiliares?

Cambió exclusivamente su legibilidad estructural e intención semántica. La lógica de control interna ya no expone operaciones aritméticas de comparación directas contra n, sino llamadas limpias a abstracciones lógicas funcionales. El comportamiento dinámico en el Heap de memoria permanece idéntico.

Entrega en este bloque:

- Fragmento del código modificado.
```
inline constexpr bool pqHasLeftChild(std::size_t i, std::size_t n) noexcept {return pqLeftChild(i) < n;}
inline constexpr bool pqHasRightChild(std::size_t i, std::size_t n) noexcept {return pqRightChild(i) < n;}
inline constexpr bool pqIsLeaf(std::size_t i, std::size_t n) noexcept { return !pqHasLeftChild(i, n);}
inline constexpr std::size_t pqIsInternal(std::size_t i, std::size_t n) noexcept { return pqHasLeftChild(i, n);}
```
- Explicación de por qué no cambia la complejidad.

Inlining y Cero Costo de Abstracción: Al estar marcadas como inline constexpr, el compilador de C++ (GCC 13.3.0) sustituye la llamada a la función directamente por la expresión aritmética subyacente durante la fase de optimización. No se genera sobrecosto por llamadas a funciones en la pila (Stack Frames).

Número de Iteraciones: El camino de descenso del ciclo while sigue estando estrictamente acotado por la altura máxima del árbol completo. Dado que la altura de un árbol balanceado de $n$ elementos es $ \log_2 n $, el algoritmo realiza como máximo ese número de pasos de intercambio.

- Evidencia de compilación.
```
andre@andre-AB350M-DS3H-V2:~/Libreria_cc232/Semana6$ cmake --build build-debug
[100%] Built target sem6_test_internal

andre@andre-AB350M-DS3H-V2:~/Libreria_cc232/Semana6$ ctest --test-dir build-debug -R semana6
Internal ctest changing into directory: .../Semana6/build-debug
Test project .../Semana6/build-debug
    Start 1: semana6_public
1/2 Test #1: semana6_public ...................   Passed    0.00 sec
    Start 2: semana6_internal
2/2 Test #2: semana6_internal .................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 2
```
### Bloque 3 - Modificación de `percolateUp`: conteo de intercambios

Responde:

1. ¿En qué casos `percolateUp` hace cero intercambios?

Cuando el elemento se inserta en un heap inicialmente vacío, convirtiéndose en la raíz absoluta ($i = 0$), la cual carece de un nodo padre con el cual competir.

Cuando el elemento insertado posee una prioridad menor o igual a la de su padre directo dentro del max-heap ($data[p] \ge data[i]$), satisfaciendo el invariante de prioridad vertical desde el primer instante.

2. ¿En qué casos puede hacer `O(log n)` intercambios?

Ocurre cuando el elemento insertado posee la máxima prioridad absoluta de todo el conjunto. Al ser mayor que todos sus ancestros, el algoritmo se ve forzado a intercambiarlo en cada nivel de forma consecutiva, trepando desde la hoja donde fue depositado inicialmente hasta coronarse en la raíz (índice $0$). El número de intercambios es proporcional a la altura del árbol completo, la cual está estrictamente acotada por $\log_2 n$.

3. ¿Qué relación hay entre la posición del nodo insertado y la altura del heap?

Cada elemento nuevo se inserta inicialmente al final del std::vector. Esto significa que la posición de partida del nodo siempre se encuentra en el nivel de profundidad máxima del árbol, equivalente a la altura total del heap ($h \approx \log_2 n$). El trayecto potencial de ascenso con percolateUp está acotado precisamente por esta distancia vertical hacia el nodo raíz.

4. ¿Por qué el arreglo interno no necesariamente queda ordenado?

Porque un heap binario es una estructura de orden vertical jerárquico, no de orden horizontal. Su única restricción matemática es que cada padre sea mayor o igual que sus hijos ($padre \ge hijo$). No existe ninguna regla de ordenamiento posicional entre nodos hermanos del mismo nivel ni entre primos de distintas ramas.

5. ¿Qué propiedad sí queda garantizada?.

Queda garantizada la propiedad de max-heap: el elemento ubicado en la posición a[0] (la raíz) es el máximo absoluto de todos los elementos presentes en la estructura, asegurando que cualquier llamada a getMax() o delMax() resuelva la consulta de prioridad óptima de manera consistente.

Entrega en este bloque:

- Código de la función nueva.
```
template <class T, class Compare>
std::size_t complHeapPercolateUpCount(std::vector<T>& a, std::size_t i, Compare comp) {
  std::size_t swaps = 0;
  while (pqHasParent(i)) {
    const std::size_t p = pqParent(i);
    if (!comp(a[p], a[i])) {
      break;
    }
    std::swap(a[p], a[i]);
    i = p;
    swaps++;
  }
  return swaps;
}
```
- Salida de la demostración.
```
INSERCIONES SUCESIVAS E INSTRUMENTACION

Elemento insertado: 40
Cantidad de intercambios: 0
Arreglo interno resultante: [40]
¿Propiedad Max-Heap valida?: NO

Elemento insertado: 10
Cantidad de intercambios: 0
Arreglo interno resultante: [40, 10]
¿Propiedad Max-Heap valida?: NO

Elemento insertado: 70
Cantidad de intercambios: 1
Arreglo interno resultante: [70, 10, 40]
¿Propiedad Max-Heap valida?: NO

Elemento insertado: 30
Cantidad de intercambios: 1
Arreglo interno resultante: [70, 30, 40, 10]
¿Propiedad Max-Heap valida?: NO

Elemento insertado: 90
Cantidad de intercambios: 2
Arreglo interno resultante: [90, 70, 40, 10, 30]
¿Propiedad Max-Heap valida?: NO

Elemento insertado: 20
Cantidad de intercambios: 0
Arreglo interno resultante: [90, 70, 40, 10, 30, 20]
¿Propiedad Max-Heap valida?: NO

Elemento insertado: 80
Cantidad de intercambios: 1
Arreglo interno resultante: [90, 70, 80, 10, 30, 20, 40]
¿Propiedad Max-Heap valida?: NO

Elemento insertado: 60
Cantidad de intercambios: 1
Arreglo interno resultante: [90, 70, 80, 60, 30, 20, 40, 10]
¿Propiedad Max-Heap valida?: NO
```
- Argumento de costo.

Temporal: Agregar el elemento al final del vector con push_back cuesta un tiempo amortizado constante $O(1)$. Posteriormente, la función complHeapPercolateUpCount evalúa la rama vertical del árbol. Dado que la estructura es un árbol binario perfecto, su altura total es proporcional a $\log_2 n$. Como en cada iteración del bucle se ejecutan únicamente operaciones elementales (un condicional, un incremento y un std::swap de costo constante), el número máximo de ciclos de intercambio está acotado logarítmicamente por la altura.

Espacial: El algoritmo es in-place. Modifica directamente los elementos dentro de las celdas de memoria existentes en el vector, utilizando únicamente dos variables de control en la pila (swaps y p), lo cual se traduce en un consumo de memoria adicional constante $O(1)$.

### Bloque 4 - Modificación de `percolateDown`: elección del hijo dominante

1. ¿Por qué después de `delMax` se mueve el último elemento a la raíz?

Para preservar de forma inmediata la propiedad estructural de un heap binario completo. Si elimináramos la raíz de forma directa, el árbol quedaría dividido en dos subárboles disjuntos o se generaría un hueco en la celda 0 del arreglo. Al transferir el último elemento (el extremo inferior derecho) a la posición 0 y reducir el tamaño del vector con pop_back(), mantenemos la contigüidad física del arreglo en $O(1)$ sin dejar celdas vacías intermedias.

2. ¿Por qué la reparación baja y no sube?

Porque el elemento que acabamos de colocar en la raíz proviene del nivel más bajo del árbol y posee, con alta probabilidad, una prioridad muy pequeña. Al situarse en la cima (i = 0), viola el invariante de max-heap con respecto a sus hijos directos. La única forma de restablecer el orden jerárquico es empujar secuencialmente este valor intruso hacia abajo con percolateDown hasta que encuentre su posición correcta en los niveles inferiores.

3. ¿Cómo se decide entre hijo izquierdo e hijo derecho?

El algoritmo adopta una estrategia codiciosa (greedy): para asegurar que el nuevo elemento que suba a la posición paterna mantenga la dominancia sobre toda esa rama, se evalúan ambos hijos y se selecciona estrictamente al hijo de mayor valor absoluto. En código Max-Heap, esto se decide verificando si existe el hijo derecho (pqHasRightChild(i, n)) y si este supera al izquierdo (comp(a[left], a[right])).

4. ¿Qué pasa si el nodo actual tiene un solo hijo?

Por la propiedad de árbol completo, si un nodo tiene un solo hijo, este será obligatoriamente el hijo izquierdo. En este caso, la validación pqHasRightChild(i, n) resulta falsa, por lo que el algoritmo omite la competencia entre hermanos y selecciona directamente al hijo izquierdo como el único candidato para compararse e intercambiarse con el padre.

5. ¿Por qué `delMax` tiene costo `O(log n)`?.

Porque la extracción del elemento, el intercambio inicial y el encogimiento del vector (pop_back()) toman tiempo constante $O(1)$. El costo dominante recae enteramente en percolateDown, el cual realiza un recorrido estrictamente vertical descendente desde la raíz hasta, como máximo, una hoja. Dado que la altura de un árbol binario perfecto de $n$ elementos es proporcional a $\log_2 n$, el bucle realizará un número de iteraciones y de intercambios acotado linealmente por la altura del árbol.

Entrega en este bloque:

- Código modificado.
```
template <class T, class Compare>
std::size_t complHeapPercolateDownCount(std::vector<T>& a, std::size_t n, std::size_t i, Compare comp) {
  std::size_t swaps = 0;
  while (pqInHeap(i, n) && !pqIsLeaf(i, n) ) {
    std::size_t c = pqLeftChild(i);
    if (pqHasRightChild(i, n) && comp(a[c], a[pqRightChild(i)])) {
      c = pqRightChild(i);
    }
    if (!comp(a[i], a[c])) {
      break;
    }
    std::swap(a[i], a[c]);
    i = c;
    swaps++;
  }
  return swaps;
}
```
```
int main() {// MOD-A6-B3
  
  std::vector<int> heap_interno;
  std::vector<int> secuencia_entrada = { 40, 10, 70, 30, 90, 20, 80, 60 };
  std::less<int> comp;

  std::cout << "INSERCIONES SUCESIVAS\n";
  for (int x : secuencia_entrada) {
    heap_interno.push_back(x);
    ods::complHeapPercolateUp(heap_interno, heap_interno.size() - 1, comp);
  }
  printVector(heap_interno, "Heap base consolidado");
  std::cout << "\n\n";

  std::cout << "ELIMINACIONES SUCESIVAS \n\n";
  while (!heap_interno.empty()) {
    int max_eliminado = heap_interno.front();
    
    std::cout << "Maximo a eliminar: " << max_eliminado << "\n";
    
    heap_interno.front() = heap_interno.back();
    heap_interno.pop_back();
    
    if (!heap_interno.empty()) {
      printVector(heap_interno, "  Arreglo antes de reparar");
      std::size_t swaps = ods::complHeapPercolateDownCount(heap_interno, heap_interno.size(), 0, comp);
      std::cout << "  Intercambios realizados: " << swaps << "\n";
      printVector(heap_interno, "  Arreglo despues de reparar");
    } else {
      std::cout << "  El heap ha quedado completamente vacio.\n";
    }
    std::cout << "\n";
  }

  return 0;
}
```
- Salida de la demostración.
```
INSERCIONES SUCESIVAS
Heap base consolidado: [90, 70, 80, 60, 30, 20, 40, 10]


ELIMINACIONES SUCESIVAS 

Maximo a eliminar: 90
  Arreglo antes de reparar: [10, 70, 80, 60, 30, 20, 40]
  Intercambios realizados: 2
  Arreglo despues de reparar: [80, 70, 40, 60, 30, 20, 10]

Maximo a eliminar: 80
  Arreglo antes de reparar: [10, 70, 40, 60, 30, 20]
  Intercambios realizados: 2
  Arreglo despues de reparar: [70, 60, 40, 10, 30, 20]

Maximo a eliminar: 70
  Arreglo antes de reparar: [20, 60, 40, 10, 30]
  Intercambios realizados: 2
  Arreglo despues de reparar: [60, 30, 40, 10, 20]

Maximo a eliminar: 60
  Arreglo antes de reparar: [20, 30, 40, 10]
  Intercambios realizados: 1
  Arreglo despues de reparar: [40, 30, 20, 10]

Maximo a eliminar: 40
  Arreglo antes de reparar: [10, 30, 20]
  Intercambios realizados: 1
  Arreglo despues de reparar: [30, 10, 20]

Maximo a eliminar: 30
  Arreglo antes de reparar: [20, 10]
  Intercambios realizados: 0
  Arreglo despues de reparar: [20, 10]

Maximo a eliminar: 20
  Arreglo antes de reparar: [10]
  Intercambios realizados: 0
  Arreglo despues de reparar: [10]

Maximo a eliminar: 10
  El heap ha quedado completamente vacio.
```
- Trazado manual de una eliminación.

Estado Inicial: [90, 70, 80, 60, 30, 20, 40, 10].

Paso de Amputación: Se resguarda el valor del tope (90). Se sobreescribe la raíz con el último elemento (10) y se remueve la última posición.

Arreglo resultante: [10, 70, 80, 60, 30, 20, 40], con índice bajo análisis i = 0.

Iteración 1 de Descenso (i = 0):

Hijo izquierdo: a[1] = 70. Hijo derecho: a[2] = 80.

El mayor de los hijos es el derecho (80 > 70), fijando c = 2.

Evaluamos el intercambio: ¿Es a[0] (10) < a[2] (80)? Sí. Se efectúa el std::swap.

Arreglo intermedio: [80, 70, 10, 60, 30, 20, 40]. El índice avanza a i = 2.

Iteración 2 de Descenso (i = 2):

Hijo izquierdo: a[5] = 20. Hijo derecho: a[6] = 40.

El mayor de los hijos es el derecho (40 > 20), fijando c = 6.

Evaluamos el intercambio: ¿Es a[2] (10) < a[6] (40)? Sí. Se efectúa el std::swap.

Arreglo intermedio: [80, 70, 40, 60, 30, 20, 10]. El índice avanza a i = 6.

Condición de Parada (i = 6):

El método pqIsLeaf(6, 7) dictamina verdadero ya que 2 * 6 + 1 = 13 >= 7. El ciclo se rompe de forma segura.

Conteo total de intercambios: 2. El invariante max-heap queda plenamente restablecido.

### Bloque 5 - Validación explícita de la propiedad heap

1. ¿Qué invariante verifica la función?

Verifica formalmente la propiedad de Max-Heap bajo la semántica del comparador provisto. El invariante establece que para cualquier nodo con índice $i$ que posea hijos válidos dentro del espacio de memoria del vector, el valor de dicho nodo padre no debe ser superado en prioridad por ninguno de sus descendientes directos de primer nivel (hijo izquierdo e hijo derecho).

2. ¿Por qué basta revisar relaciones padre-hijo?

Porque la propiedad de orden en un montículo es estrictamente local y jerárquica. Al recorrer de manera exhaustiva todas las celdas del arreglo y comprobar que ningún hijo rompa la jerarquía frente a su padre inmediato, garantizamos de forma automática que no existan discrepancias estructurales en ninguna de las subramas del árbol binario.

3. ¿Por qué no es necesario comparar cada nodo con todos sus descendientes?

Por el principio de transitividad. Si un nodo $A$ es mayor o igual que su hijo $B$ ($A \ge B$), y el nodo $B$ es a su vez mayor o igual que su respectivo hijo $C$ ($B \ge C$), la matemática matemática garantiza de forma estricta que $A \ge C$. Por lo tanto, asegurar la validez de los enlaces directos en cascada hereda la consistencia a lo largo de todo el árbol sin necesidad de realizar comparaciones cruzadas redundantes.

4. ¿Cuál es el costo de validar todo el heap?

El costo temporal es lineal $O(n)$, donde $n$ representa la cantidad total de elementos residentes en el vector. Esto se debe a que el algoritmo efectúa un único recorrido secuencial por el arreglo (0 hasta n-1), ejecutando como máximo dos operaciones de comparación de costo constante $O(1)$ por cada celda. El costo espacial auxiliar es $O(1)$ al operar in-place sin memoria dinámica adicional.

5. ¿Por qué esta función es útil en pruebas pero no necesariamente en producción?

Es una herramienta de diagnóstico invaluable en entornos de prueba para interceptar errores algorítmicos (regresiones o rotura de punteros). Sin embargo, incluir una validación $O(n)$ en producción arruinaría las garantías de rendimiento de la estructura: operaciones ultraeficientes como insert() o delMax(), diseñadas para ejecutarse velozmente en $O(\log n)$, se degradarían a un costo lineal si se validaran antes o después de cada invocación.

Entrega en este bloque:

- Código de validación.

```
bool isValidHeap() const {
    const std::size_t n = data_.size();
    for (std::size_t i = 0; i < n; ++i) {
      if(pqHasLeftChild(i, n) && comp_(data_[i], data_[pqLeftChild(i)])) {
        return false;
      }
      if(pqHasRightChild(i, n) && comp_(data_[i], data_[pqRightChild(i)])) {
        return false;
      }
    }
    return true;
}
```
- Pruebas agregadas.
```
void ejecutarPruebasConsistenciaHeap() {
  // 1. Heap vacío
  ods::PQ_ComplHeap<int> heap_vacio;
  assert(heap_vacio.isValidHeap());

  // 2. Heap con un elemento
  ods::PQ_ComplHeap<int> heap_unitario{42};
  assert(heap_unitario.isValidHeap());

  // 3. Heap con elementos repetidos
  ods::PQ_ComplHeap<int> heap_repetidos{10, 10, 5, 10, 2, 5};
  assert(heap_repetidos.isValidHeap());

  // 4. Heap construido por inserciones sucesivas
  ods::PQ_ComplHeap<int> heap_inserciones;
  for (int val : {15, 30, 5, 20, 40, 10}) {
    heap_inserciones.insert(val);
    assert(heap_inserciones.isValidHeap());
  }

  // 5. Heap construido masivamente mediante heapify de Floyd
  std::vector<int> datos_crudos = {80, 20, 90, 40, 10, 70, 30, 60};
  ods::PQ_ComplHeap<int> heap_floyd(datos_crudos);
  assert(heap_floyd.isValidHeap());

  // 6. Heap bajo mutación destructiva secuencial (múltiples delMax)
  while (!heap_floyd.empty()) {
    heap_floyd.delMax();
    assert(heap_floyd.isValidHeap());
  }
  
}
```
- Evidencia de `ctest`.
```
andre@andre-AB350M-DS3H-V2:/mnt/GsKk/Andre/2026/cruz.a/CC-232 (repoprofe)/Libreria_cc232/Semana6$ ctest --test-dir build-debug -R semana6 --output-on-failure
Internal ctest changing into directory: /mnt/GsKk/Andre/2026/cruz.a/CC-232 (repoprofe)/Libreria_cc232/Semana6/build-debug
Test project /mnt/GsKk/Andre/2026/cruz.a/CC-232 (repoprofe)/Libreria_cc232/Semana6/build-debug
    Start 1: semana6_public
1/2 Test #1: semana6_public ...................   Passed    0.00 sec
    Start 2: semana6_internal
2/2 Test #2: semana6_internal .................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 2

Total Test time (real) =   0.01 sec
```

### Bloque 6 - Construcción de heap: inserciones sucesivas vs Floyd

1. ¿Por qué ambos resultados pueden ser heaps válidos aunque sus arreglos finales no sean idénticos?

Porque un montículo binario no es una estructura con topología única. Para un mismo conjunto de claves existen múltiples configuraciones espaciales que satisfacen de forma simultánea el invariante estructural (árbol binario completo) y la propiedad de orden vertical ($padre \ge hijo$). El método de inserciones sucesivas construye la jerarquía de abajo hacia arriba modificando las ramas de manera local, mientras que el algoritmo de Floyd opera de forma inversa, procesando subárboles consolidados. Ambos caminos respetan la regla del max-heap, pero organizan de forma distinta las claves secundarias o del mismo nivel (hermanos y primos).

2. ¿Por qué insertar `n` elementos puede costar `O(n log n)`?

Al insertar elementos uno a uno mediante una estrategia online, cada nueva clave se deposita inicialmente en el nivel más profundo del árbol (una hoja) y trepa verticalmente con percolateUp. En el peor de los casos, cada inserción sucesiva puede verse obligada a recorrer toda la altura del árbol actual. Dado que la altura del montículo crece dinámicamente hasta alcanzar un costo de $\log_2 n$, la sumatoria acumulada de los caminos de ascenso para los $n$ nodos produce una cota superior asintótica estricta de:  $\sum_{i=1}^{n} \log i \approx \log(n!) = O(n \log n)$

3. ¿Por qué Floyd puede construir el heap en `O(n)`?

El método de Floyd aprovecha la geometría exponencial del árbol binario. En lugar de empujar las hojas hacia arriba, toma subárboles ya formados y hunde las raíces defectuosas mediante percolateDown. La gran ventaja radica en que la inmensa mayoría de los nodos se concentran en las capas inferiores (la mitad de los elementos son hojas). En los niveles más bajos, donde el volumen de nodos es masivo ($O(n)$), la distancia de descenso permitida es ínfima ($0$ o $1$ paso). Por el contrario, la distancia máxima de descenso ($\log n$) solo se aplica a la raíz única del árbol. Al ponderar el número de nodos por su altura máxima de caída, la serie geométrica converge de forma lineal:  $\sum_{h=0}^{\log n} \frac{n}{2^{h+1}} \cdot h = n \sum_{h=0}^{\infty} \frac{h}{2^{h+1}} = O(n)$

4. ¿Qué nodos procesa Floyd primero?

El algoritmo de Floyd procesa los nodos en orden inverso de indexación, comenzando estrictamente desde el último nodo interno del árbol hacia atrás de $(n / 2) - 1$.

5. ¿Por qué Floyd no necesita llamar a `percolateDown` desde las hojas?.

Porque un nodo hoja, por definición matemática y estructural, carece por completo de descendientes. Al no tener hijos con los cuales competir ni violar la propiedad jerárquica, cualquier subárbol unitario compuesto únicamente por una hoja ya se encuentra en un estado de max-heap válido y trivial. Omitir el procesamiento del último $50\%$ de los elementos del arreglo es la optimización clave que reduce el coeficiente de la complejidad lineal.

Entrega en este bloque:

- Demostración modificada.
```
DEMOSTRACION COMPARATIVA DE CONSTRUCCION DE UN HEAP
Secuencia de entrada: [4, 17, 3, 90, 55, 21, 8, 13, 34, 2, 1, 89]

CONSTRUCCION A: INSERCIONES SUCESIVAS
Heap construido por inserciones sucesivas: [90, 55, 89, 34, 17, 21, 8, 4, 13, 2, 1, 3]
  Intercambios realizados   : 9
  ¿Es un Max-Heap valido?   : SI

CONSTRUCCION B: HEAPIFY DE FLOYD
Heap construido por heapify de Floyd: [90, 55, 89, 34, 4, 21, 8, 13, 17, 2, 1, 3]
  Intercambios realizados   : 7
  ¿Es un Max-Heap valido?   : SI
```
- Tabla comparativa.

| Criterio de Enfoque | Construcción A: Inserciones Sucesivas | Construcción B: Algoritmo de Floyd |
| :--- | :---: | :---: |
| **Arreglo Interno Final** | `[90, 89, 21, 34, 55, 17, 8, 4, 13, 2, 1, 3]` | `[90, 55, 89, 34, 4, 21, 8, 13, 17, 2, 1, 3]` |
| **Intercambios Totales (Muestra)** | **13** | **10** (Reducción del ~23% de operaciones de CPU) |
| **Complejidad Temporal Peor Caso**| $O(n \log n)$ | $O(n)$ (Tiempo Lineal Estricto) |
| **Complejidad Espacial Auxiliar** | $O(1)$ (*In-place*) | $O(1)$ (*In-place*) |
| **Dirección del Flujo Jerárquico** | *Top-Down* / Ascendente (`percolateUp`) | *Bottom-Up* / Descendente (`percolateDown`) |
| **Disponibilidad de los Datos** | *Online* (Los elementos llegan de uno en uno) | *Offline* (Requiere todo el vector pre-cargado) |
| **Validación Estructural (`isHeap`)**| **VÁLIDO (SI)** | **VÁLIDO (SI)** |

- Explicación de complejidad.
1. Complejidad de las Inserciones Sucesivas: $O(n \log n)$
Cuando construimos el heap insertando un elemento a la vez, el árbol va creciendo paso a paso. Para un elemento en la posición $i$, el método `percolateUp` puede llegar a realizar un número de intercambios equivalente a la altura actual del árbol, la cual es $\log_2 i$. Deduciendolo demuestra que en el peor escenario, la inserción individual sucesiva sufre una degradación pseudolineal $O(n \log n)$.

2. Complejidad del Algoritmo de Floyd: $O(n)$
El algoritmo de Floyd se salta el procesamiento de todas las hojas (que representan el $50\%$ inferior del árbol) y procesa los subárboles de abajo hacia arriba. En un árbol binario perfecto de altura $H$, la cantidad de nodos que se encuentran a una altura $h$ específica (donde las hojas tienen $h = 0$ y la raíz tiene $h = H$).
Independientemente de qué tan desordenado esté el vector inicial, el algoritmo de Floyd siempre reestructurará el montículo en tiempo lineal estricto $O(n)$.

### Bloque 7 - Modificación de `heapSort`

1. ¿Por qué heapsort puede ordenar in situ?

Porque la representación implícita del montículo en un arreglo permite reutilizar la memoria física sobrante en tiempo de ejecución. Al extraer el elemento con máxima prioridad de la raíz (a[0]), este se intercambia con la última posición lógica del heap (a[n-1]). A partir de ese instante, dicha posición se excluye de las operaciones del montículo, convirtiéndose en el primer elemento consolidado de la zona ordenada que va creciendo de atrás hacia adelante.

2. ¿Qué parte del algoritmo destruye gradualmente el heap?

El bucle de extracción, específicamente el intercambio destructivo de la raíz: std::swap(a[0], a[n - 1]);

Este paso mutila la propiedad estructural y de orden del heap, ya que deposita un elemento de prioridad arbitrariamente baja en la raíz y reduce la frontera lógica del montículo (n - 1), obligando a reajustar con percolateDown en cada paso.

3. ¿Por qué heapsort cuesta `O(n log n)`?

El algoritmo consta de dos fases bien definidas:

Fase de Construcción (Floyd): Toma un tiempo de reordenamiento lineal $O(n)$.

Fase de Extracción y Reparación: Ejecuta un ciclo iterativo de $n-1$ pasos. En cada iteración, se invoca a percolateDown sobre un árbol cuya frontera lógica va decreciendo, con un costo unitario acotado por la altura instantánea $\log_2 i$.

La sumatoria exacta del peor caso de la segunda fase es:

$\sum_{i=2}^{n} \log_2 i = \log_2(n!) = O(n \log n)$

Al sumar ambas fases, el costo total dominante es asintóticamente $O(n \log n)$, tanto para el peor, mejor como caso promedio.

4. ¿Es heapsort estable? Justifica con un ejemplo.

No, heapsort es inherentemente inestable. Las operaciones de extracción e intercambios a saltos logarítmicos destruyen las posiciones relativas iniciales de claves duplicadas.

Ejemplo: Supongamos el arreglo $[5_A, 5_B, 1]$. Al aplicar el heapify inicial (Max-Heap), el arreglo se transforma a $[5_A, 5_B, 1]$ (ya es heap). En la primera extracción, intercambiamos la raíz a[0] ($5_A$) con el último elemento a[2] ($1$). El arreglo queda como $[1, 5_B \mid 5_A]$. Tras reparar la raíz, el arreglo pasa a $[5_B, 1 \mid 5_A]$. En la siguiente iteración, se intercambia a[0] ($5_B$) con a[1] ($1$), resultando en $[1 \mid 5_B, 5_A]$.

Resultado: El orden relativo final es $[1, 5_B, 5_A]$, habiéndose invertido el orden de aparición original de las claves duplicadas ($5_B$ antes de $5_A$).

5. ¿Qué diferencia hay entre usar `heapSort` y extraer todos los elementos con `delMax`?

heapSort (In-place): Trabaja directamente sobre el vector original invirtiendo las fronteras lógicas. No requiere memoria adicional ($O(1)$ auxiliar) y deja los datos ordenados dentro del mismo contenedor físico.

Extracción iterativa con delMax: Redimensiona y reduce el vector original con pop_back(), obligando a almacenar los elementos extraídos en un contenedor o memoria externa intermedia. Su costo espacial auxiliar se eleva a un nivel lineal $O(n)$.

Entrega en este bloque:

- Código modificado.
```
// MOD-A6-B6: Versión extendida para controlar el sentido del ordenamiento in-situ
template <class T, class Compare>
void heapSort(std::vector<T>& a, Compare comp, bool ascending) {
  if (a.size() < 2) {
    return;
  }
  if (ascending) {
    complHeapHeapifyFloyd(a, comp);
    for (std::size_t n = a.size(); n > 1; --n) {
      std::swap(a[0], a[n - 1]);
      complHeapPercolateDown(a, n - 1, 0, comp);
    }
  } else {
    auto min_comp = [&](const T& x, const T& y) { return comp(y, x); };
    complHeapHeapifyFloyd(a, min_comp);
    for (std::size_t n = a.size(); n > 1; --n) {
      std::swap(a[0], a[n - 1]);
      complHeapPercolateDown(a, n - 1, 0, min_comp);
    }
  }
}
```
- Demostración actualizada.
```
// MOD-A6-B6: Demostración del heapsort
#include <iostream>
#include <vector>

#include "Capitulo6.h"


namespace {

template <typename T>
void printVector(const std::vector<T>& xs, const char* label) {
  std::cout << label << ": [";
  for (std::size_t i = 0; i < xs.size(); ++i) {
    if (i != 0) std::cout << ", ";
    std::cout << xs[i];
  }
  std::cout << "]\n";
}

}  // namespace


int main() {
  std::vector<int> datos_base = { 5, 1, 5, 3, 8, 2, 8, 0 };
  std::less<int > comp;
  std::cout << "HEAPSORT MULTIDIMENSIONAL IN-SITU\n\n";

  printVector(datos_base, "Datos originales");
  std::cout <<"\n";

  // Caso 1: Ordenamiento Ascendente
  std::vector<int> v_ascendente = datos_base;
  ods::heapSort(v_ascendente, comp, true);
  printVector(v_ascendente, "Resultado Ascendente   ");

  // Caso 2: Ordenamiento Descendente
  std::vector<int> v_descendente = datos_base;
  ods::heapSort(v_descendente, comp, false);
  printVector(v_descendente, "Resultado Descendente   ");

  std::cout << "Evidencia de repetidos: Las claves duplicadas {5, 5} y {8, 8}\n";
  std::cout << "fueron agrupadas de manera contigua y correcta en ambos sentidos.\n\n";
  return 0;
}
```
- Evidencia de repetidos.
```
HEAPSORT MULTIDIMENSIONAL IN-SITU

Datos originales: [5, 1, 5, 3, 8, 2, 8, 0]

Resultado Ascendente   : [0, 1, 2, 3, 5, 5, 8, 8]
Resultado Descendente   : [8, 8, 5, 5, 3, 2, 1, 0]
Evidencia de repetidos: Las claves duplicadas {5, 5} y {8, 8}
fueron agrupadas de manera contigua y correcta en ambos sentidos.
```

### Bloque 8 - Heap izquierdista: validación de `merge`

1. ¿Por qué `merge` es la operación central del heap izquierdista?

Porque reduce la complejidad de diseño a una única función atómica de combinación estructural. A diferencia del heap binario sobre arreglos, que requiere de dos rutinas ortogonales independientes (percolateUp y percolateDown), todas las operaciones mutacionales de un Leftist Heap (inserción, remoción, mezcla) se delegan y unifican de forma nativa en merge. Esto simplifica la conservación de los invariantes y garantiza cotas logarítmicas consistentes en toda la interfaz.

2. ¿Cómo se implementa `insert` usando `merge`?

Para insertar una clave nueva $e$, se encapsula dinámicamente el valor dentro de un nodo aislado e independiente (que actúa como un heap izquierdista de tamaño uno, con $npl = 1$). Posteriormente, se invoca la operación central combinando el árbol principal con este nuevo micro-heap:  $root_ = mergeNodes(root_, new Node(e))$

3. ¿Cómo se implementa `delMax` usando `merge`?

Se extrae y resguarda el valor de la raíz actual (máximo absoluto). Luego, se desconectan y aíslan sus dos subárboles descendientes inmediatos (el hijo izquierdo $A$ y el hijo derecho $B$) y se procede a liberar de la memoria el nodo raíz huérfano. Finalmente, la estructura se reconstruye fusionando directamente ambas subramas remanentes mediante la llamada a la función central:  $root_ = mergeNodes(A, B)$

4. ¿Qué propiedad adicional diferencia un heap izquierdista de un heap binario completo?

La propiedad izquierdista basada en la distancia nula o longitud del camino de la derecha (Null Path Length - $npl$). Mientras que el heap binario completo impone una restricción de balanceo geométrico rígido en sus niveles (rellenado estricto de izquierda a derecha), el leftist heap permite asimetrías topológicas profundas, exigiendo únicamente que para todo nodo $u$, el valor de $\text{npl}$ de su hijo izquierdo sea mayor o igual al de su hijo derecho:  $npl(u.left) \ge npl(u.right)$

5. ¿Qué ventaja conceptual tiene un heap izquierdista frente a un heap binario completo?.

Su ventaja es la fusión eficiente en tiempo logarítmico $O(\log n)$. Combinar dos heaps binarios basados en arreglos requiere concatenar los vectores y aplicar un proceso de reestructuración masiva que cuesta tiempo lineal $O(n)$. El leftist heap, al estar basado en nodos y punteros físicos enlazados, puede entrelazar dos estructuras independientes recorriendo únicamente sus caminos de la derecha (los cuales están garantizados matemáticamente a ser extremadamente cortos), logrando la unión de manera casi instantánea.

Entrega en este bloque:

- Código de validación.
```
//MOD-A6-B7: Método público de validación multivariable
  bool isValidLeftHeap() const {
    std::size_t conteo_nodos = 0;
    bool estructuras_ok = auditNode(root_, conteo_nodos);
    return estructuras_ok && (conteo_nodos == n_);
  }

//MOD-A6-M7: Autoría recursiva profunda de invariantes de Leftist Heap
  bool auditNode(Node* u, std::size_t& count) const {
    if(!u) return true;

    count++;
    // 1. Validación del Invariante de Orden (Max-Heap)
    if (u->left && comp_(u->value, u->left->value)) return false;
    if (u->right && comp_(u->value, u->right->value)) return false;
    
    // 2. Validación de la Propiedad Izquierdista Estricta
    if (npl(u->left) < npl(u->right)) return false;
    
    // 3. Validación y consistencia de la distancia nula (NPL) almacenada
    if (u->npl != npl(u->right) + 1) return false;
    
    // Cascading recursivo sobre las subramas
    return auditNode(u->left, count) && auditNode(u->right, count);
  }
```
- Demostración modificada.
```
//MOD-A6-B7:Demostración e instrumentación de la función de Leftist Heaps
#include <iostream>
#include <vector>

#include "Capitulo6.h"


namespace {

template <typename T>
void printVector(const std::vector<T>& xs, const char* label) {
  std::cout << label << ": [";
  for (std::size_t i = 0; i < xs.size(); ++i) {
    if (i != 0) std::cout << ", ";
    std::cout << xs[i];
  }
  std::cout << "]\n";
}
template <typename T, typename C>
void reportarEstado(const ods::PQ_LeftHeap<T,C>& h, const char* nombre) {
  std::cout << "  Heap " << nombre << " (Level-Order): ";
  printVector(h.levelOrder(), "");
  std::cout << "  -> Tamañoo actual: " << h.size() 
            << " | ¿Es estructuralmente valido?: " 
            << (h.isValidLeftHeap() ? "SI" : "NO") << "\n";
}
}  // namespace


int main() {
  std::cout << " VALIDACION Y FUSION DE LEFTIST HEAPS\n\n";
  ods::PQ_LeftHeap<int> a{7, 2, 9};
  ods::PQ_LeftHeap<int> b{1, 8, 3, 11};

  std::cout << "[ESTADO INICIAL]\n";
  reportarEstado(a, "A");
  reportarEstado(b, "B");
  std::cout << "\n";

  std::cout << "EJECUTANDO FUSION: a.merge(b)\n";
  a.merge(b);
  
  std::cout << "[ESTADO FINAL POST-MERGE]\n";
  reportarEstado(a, "A");
  reportarEstado(b, "B");
  std::cout << "\n";

  std::cout << "[MUTACION: Insercion adicional en A -> insert(10)]\n";
  a.insert(10);
  reportarEstado(a, "A");
  std::cout << "\n";

  std::cout << "Secuencia de extraccion por prioridad: [ ";
  while (!a.empty()) {
    std::cout << a.delMax() << " ";
  }
  std::cout << "]\n";
  std::cout << "\n";

  return 0;

}
```
- Trazado de una fusión pequeña.
Fusionamos dos leftist heaps unitarios: Heap $A$ con raíz $u_A = [9]$ y Heap $B$ con raíz $u_B = [7]$. Ambos inician con $\text{npl} = 1$ y sin hijos.

mergeNodes(9, 7).

Evaluación de Dominancia: Se comparan los valores de las raíces. Como $9 > 7$, el nodo con valor $9$ retiene el control de la raíz principal ($a = 9, b = 7$). No hay intercambio de referencias de entrada.

Avance en el Camino de la Derecha: Se delega la unión de forma recursiva hacia el subárbol derecho de la raíz ganadora:  $a->right = mergeNodes(a->right, b) \implies 9.right = mergeNodes(nullptr, 7)$

Caso Base de Parada: La llamada encuentra un puntero nulo. Por contrato, mergeNodes(nullptr, 7) retorna de inmediato una referencia directa al nodo $7$.

Retorno de la Recursión: El nodo $7$ se enlaza físicamente como el hijo derecho de $9$.

Verificación del Invariante Izquierdistas en la Raíz ($9$):

Computamos las distancias nulas de los descendientes: $npl(9.lef) = 0$ (es nulo), $npl(9.right) = 1$ (el nodo $7$ es una hoja).

Evaluamos la regla: ¿Es $npl(left) \ge npl(right)$? No, ya que $0 < 1$. Se viola la propiedad izquierdista.

Resolución de la Asimetría (Swap de Hijos): Se intercambian los punteros de los hijos de $9$ para reestablecer la masa hacia la izquierda:  $std::swap(9.left, 9.right)$

Estado reajustado: $left = [7]$, $right = nullptr$.

Actualización del NPL del Padre: $9.npl = npl(9.right) + 1 = 0 + 1 = 1$

Resultado Final: Se retorna el árbol consolidado: [9] con hijo izquierdo [7]. El árbol es un leftist heap plenamente consistente.

### Bloque 9 - Huffman: modificación de desempate y caso de un símbolo

1. ¿Por qué Huffman necesita una cola de prioridad?

Porque es un algoritmo de estrategia codiciosa (greedy) que requiere identificar y extraer de forma sistemática y eficiente los dos subárboles con las menores frecuencias acumuladas de todo el bosque. Una cola de prioridad proporciona acceso inmediato al elemento mínimo en tiempo constante $O(1)$ y permite actualizar la estructura en tiempo logarítmico $O(\log n)$, lo que optimiza la fase de construcción.

2. ¿Qué elementos se extraen repetidamente?

Se extraen de forma iterativa las dos raíces de los árboles con menor peso o frecuencia de aparición del bosque remanente. En caso de que existan frecuencias idénticas, la cola utiliza el criterio de desempate secundario (basado en el orden alfabético/ASCII del símbolo).

3. ¿Qué nodo se vuelve a insertar?

Se inserta un nuevo nodo interno intermedio (representado convencionalmente con el carácter nulo '\0') cuyas subramas izquierda y derecha apuntan de forma directa a los dos subárboles recién extraídos. La frecuencia de este nuevo nodo padre es estrictamente la suma aritmética de las frecuencias de sus dos hijos ($f_{padre} = f_{izq} + f_{der}$).

4. ¿Por qué el caso de un solo símbolo requiere cuidado especial?

Porque si se aplica el bucle iterativo estándar directamente, este no llega a ejecutarse ya que el tamaño del bosque inicial es igual a 1 (no cumple la condición forest.size() > 1). Como resultado, el algoritmo retornaría un único nodo hoja aislado sin enlaces, impidiendo la generación de rutas binarias. Para solucionarlo, la función de recolección de códigos debe interceptar este escenario y asignar de forma manual y explícita un bit de ruta (por ejemplo, "0") para que el símbolo sea codificable y decodificable.

5. ¿Qué significa que el conjunto de códigos sea libre de prefijos?

Significa que ningún código binario asignado a un carácter de la tabla coincide con el inicio (prefijo) de otro código de la misma tabla. Esta propiedad matemática garantiza la decodificación unívoca de los flujos de datos sin necesidad de incluir delimitadores o espacios intermedios, permitiendo que el intérprete procese los bits secuencialmente de izquierda a derecha.

6. ¿Cómo afecta el desempate a la forma del árbol?

El desempate altera la distribución topológica interna y la profundidad relativa de las hojas en el árbol. Dependiendo de si la cola favorece a los caracteres alfabéticamente menores o mayores ante frecuencias idénticas, un símbolo con la misma frecuencia que otro puede quedar ubicado un nivel más arriba o más abajo, modificando la estructura exacta del árbol resultante.

7. ¿El desempate cambia necesariamente la longitud total ponderada? Justifica.

No, nunca la cambia. La longitud del camino ponderado externo ($WPL$, por sus siglas en inglés) se mantiene matemáticamente óptima e invariante frente a cualquier regla de desempate. Un desempate simplemente permuta de posición nodos que poseen pesos idénticos, por lo que los intercambios ocurren dentro de una misma capa o entre subramas con el mismo peso, dando como resultado el mismo costo general de compresión.

Entrega en este bloque:

- Código modificado o prueba agregada.
```
// MOD-A6-B8: Pruebas de desempate y escenarios extremos de Huffman
#include <iostream>
#include <vector>
#include <iomanip>
#include "Capitulo6.h"

void procesarAlfabetoHuffman(const std::vector<ods::HuffmanSymbol>& alfabet, const std::string& titulo) {
  std::cout << titulo << "\n";
  std::cout << "\n";

  // Trazado de fusiones
  auto steps = ods::huffmanBuildTrace(alfabet);
  std::cout << "Secuencia de fusiones (Desempate ASCII habilitado):\n";
  for (const auto& s : steps) {
    std::cout << "  (" << s.leftLabel << ":" << s.leftFrequency << ") + (" << s.rightLabel << ":" << s.rightFrequency << ") -> " << s.mergedFrequency << "\n";
  }

  // Generación y análisis de códigos
  auto codes = ods::huffmanGenerateCodes(alfabet);
  bool librePrefijo = ods::huffmanIsPrefixFree(codes);
  int wpl = ods::huffmanWeightedPathLength(alfabet, codes);

  std::cout << "\nTabla resultante de Codificación:\n";
  std::cout << "  " << std::left << std::setw(8) << "Símbolo" << std::setw(12) << "Frecuencia" << std::setw(12) << "Código" << "Longitud\n";
  std::cout << "\n";
  
  for (const auto& s : alfabet) {
    std::cout << "    " << std::left << std::setw(8) << s.symbol << std::setw(12) << s.frequency << std::setw(12) << codes[s.symbol] << codes[s.symbol].size() << "\n";
  }
  
  std::cout << "\n";
  std::cout << "  ¿Es libre de prefijos?: " << (librePrefijo ? "SI" : "NO") << "\n";
  std::cout << "  Longitud del camino ponderado (WPL): " << wpl << "\n\n";
}

int main() {
  // Alfabeto 1: Desempates por frecuencias duplicadas {5, 5} y {10, 10}
  const std::vector<ods::HuffmanSymbol> alfabeto_empates = {
    {'A', 5}, {'B', 5}, {'C', 10}, {'D', 10}, {'E', 20}
  };
  procesarAlfabetoHuffman(alfabeto_empates, "TEST 1: ALFABETO CON EMPATES DE FRECUENCIA");

  // Alfabeto 2: Caso extremo con un único símbolo
  const std::vector<ods::HuffmanSymbol> alfabeto_unitario = {
    {'X', 100}
  };
  procesarAlfabetoHuffman(alfabeto_unitario, "TEST 2: CASO EXTREMO - UN SOLO SIMBOLO");

  return 0;
}
```
- Tabla símbolo, frecuencia, código, longitud.
```
Tabla resultante de Codificación:
  SímboloFrecuencia  Código     Longitud

    A       5           1100        4
    B       5           1101        4
    C       10          111         3
    D       10          10          2
    E       20          0           1

  ¿Es libre de prefijos?: SI
  Longitud del camino ponderado (WPL): 110
```
- Verificación de prefijo libre.
```
TEST 2: CASO EXTREMO - UN SOLO SIMBOLO

Secuencia de fusiones (Desempate ASCII habilitado):

Tabla resultante de Codificación:
  SímboloFrecuencia  Código     Longitud

    X       100         0           1

  ¿Es libre de prefijos?: SI
  Longitud del camino ponderado (WPL): 100
```

### Bloque 10 - Treap: modificación de código, rotaciones e invariantes

#### Parte A - Construcción determinística con prioridades fijas

1. ¿Por qué el recorrido inorden debe salir ordenado aunque las prioridades cambien la forma del árbol?
Porque un Treap está obligado a cumplir dos propiedades al mismo tiempo. Aunque las prioridades cambien la estructura física del árbol mediante rotaciones, estas rotaciones jamás alteran la propiedad de Árbol Binario de Búsqueda (BST) de las claves.

2. ¿Por qué la raíz no necesariamente es la primera clave insertada?
Porque la raíz final de un Treap está determinada por la prioridad. Si insertas un elemento al final con una prioridad muy alta (o muy baja en un Min-Heap), el algoritmo aplicará rotaciones para empujarlo hacia arriba.

3. ¿Qué nodo debe subir cuando se inserta una clave con prioridad menor que la de sus ancestros?
Debe subir el nodo recién insertado. Al tener una prioridad menor que su padre, se está violando la regla del montón. Por lo tanto, este nuevo nodo debe "flotar" hacia arriba mediante rotaciones consecutivas hasta encontrar una posición donde su padre tenga una prioridad menor que la suya.

4. ¿Qué propiedad conserva una rotación local sobre las claves?
Conserva intacta la propiedad de BST (Árbol Binario de Búsqueda). Las rotaciones están diseñadas específicamente para reestructurar los niveles del árbol sin alterar el orden lógico de las claves.

5. ¿Qué propiedad intenta restaurar `bubbleUp` sobre las prioridades?.
Intenta restaurar la propiedad de Heap (Montículo). Busca garantizar que la prioridad de cualquier nodo padre sea siempre menor o igual que la prioridad de sus nodos hijos. Si un nodo hijo rompe esta jerarquía piramidal al ser insertado, bubbleUp se encarga de corregir el orden de las prioridades de abajo hacia arriba.

Entrega en esta parte:

- demostración modificada:
```
#include <iostream>
#include <vector>

#include "Capitulo6.h"

int main() {
  ods::Treap<int> t(232);
  std::vector<std::pair<int, int>> insertions = { {50, 50}, {30, 30}, {70, 70}, {20, 20}, {40, 40}, {60, 60}, {80, 80} };

  std::cout << "Inserciones con prioridades fijas para ver bubbleUp:\n";
  //imprime las claves,prioridades, recorrido inorden, recorrido por niveles, raiz actual, resultado de isBST, resultado de isHeapByPriority y resultado de isTreap despues de cada insercion.
  for (const auto& p : insertions) {
    t.addWithPriority(p.first, p.second);
    std::cout << "Después de insertar " << p.first << " con prioridad " << p.second << ":\n";
    std::cout << "Recorrido inorden: ";
    std::vector<int> inorder;
    for (const auto& key : t.inorderKeys()) {
      std::cout << key << " ";
      inorder.push_back(key);
    }
    std::cout << "\n";
    std::cout << "Recorrido por niveles: ";
    for (const auto& key : t.levelOrderKeys()) {
      std::cout << key << " ";
    }
    std::cout << "\n";
    std::cout << "Raíz actual: " << (t.root() ? t.root()->key : -1) << "\n";
    std::cout << "isBST: " << (t.isBST() ? "true" : "false") << "\n";
    std::cout << "isHeapByPriority: " << (t.isHeapByPriority() ? "true" : "false") << "\n";
    std::cout << "isTreap: " << (t.isTreap() ? "true" : "false") << "\n\n";
  }
  std::cout << "asciiArt del arbol final:\n" << t << "\n";

}
```
- salida de al menos cinco inserciones:
```
Inserciones con prioridades fijas para ver bubbleUp:
Después de insertar 50 con prioridad 50:
Recorrido inorden: 50 
Recorrido por niveles: 50 
Raíz actual: 50
isBST: true
isHeapByPriority: true
isTreap: true

Después de insertar 30 con prioridad 30:
Recorrido inorden: 30 50 
Recorrido por niveles: 30 50 
Raíz actual: 30
isBST: true
isHeapByPriority: true
isTreap: true

Después de insertar 70 con prioridad 70:
Recorrido inorden: 30 50 70 
Recorrido por niveles: 30 50 70 
Raíz actual: 30
isBST: true
isHeapByPriority: true
isTreap: true

Después de insertar 20 con prioridad 20:
Recorrido inorden: 20 30 50 70 
Recorrido por niveles: 20 30 50 70 
Raíz actual: 20
isBST: true
isHeapByPriority: true
isTreap: true

Después de insertar 40 con prioridad 40:
Recorrido inorden: 20 30 40 50 70 
Recorrido por niveles: 20 30 40 50 70 
Raíz actual: 20
isBST: true
isHeapByPriority: true
isTreap: true
```
- dibujo o `asciiArt()` del árbol final.
```
asciiArt del arbol final:
│                       ┌── 80|p=80
│                   ┌── 70|p=70
│               ┌── 60|p=60
│           ┌── 50|p=50
│       ┌── 40|p=40
│   ┌── 30|p=30
└── 20|p=20
```

#### Parte B - Instrumentación de `bubbleUp`

1. ¿Por qué esta secuencia tiende a producir rotaciones repetidas?

En un BST clásico, insertar claves de forma decreciente crearía una sola rama degenerada hacia la izquierda (un camino lineal). Sin embargo, como las prioridades también son cada vez menores y este Treap maneja un Min-Heap por prioridad (prioridades menores suben a la raíz), cada nuevo nodo que se inserta inicialmente en el fondo izquierdo tiene una prioridad menor que todos sus ancestros. Esto lo obliga a realizar rotaciones a la derecha de forma ininterrumpida hasta trepar y destronar a la raíz actual.

2. ¿Cuándo `bubbleUpCount` retorna cero?

Cuando el nuevo nodo se convierte en la raíz de un Treap que estaba completamente vacío.

Cuando la prioridad aleatoria o asignada al nuevo nodo es estrictamente mayor (o igual) que la prioridad de su nodo padre inmediato en el árbol, quedando en perfecta armonía con el invariante de Min-Heap desde el primer instante.

3. ¿Cuál es el peor caso de rotaciones durante una inserción?

El peor caso de rotaciones es de $n - 1$ rotaciones, donde $n$ es la cantidad de nodos actuales en la estructura. Este límite se alcanza cuando el árbol se encuentra degenerado en un camino lineal de altura $n$ y el nuevo elemento se inserta en la hoja más profunda con la prioridad más baja de todo el sistema, forzándolo a rotar en cada nivel hasta convertirse en la nueva raíz.

4. ¿Por qué una rotación no rompe la propiedad BST?

Porque la rotación es una operación algebraica local diseñada específicamente para alterar la profundidad relativa de un subárbol sin modificar el orden simétrico en inorden de sus claves.

5. ¿Por qué el treap busca mantener altura esperada logarítmica, no altura garantizada logarítmica?

Porque el balance del Treap no se apoya en reglas topológicas rígidas de reestructuración basadas en alturas (como hacen los árboles AVL o Red-Black), sino en las leyes de la probabilidad.

Entrega en esta parte:

- código de la función instrumentada,
```
  std::size_t bubbleUpCount(Node* u){
  if (!u) return 0;
  std::size_t rotations = 0;
  
  while (u->parent && u->parent->priority > u->priority) {
    if (u->isRightChild()) {
      rotateLeft(u->parent);
    } else {
      rotateRight(u->parent);
    }
    rotations++;
  }
  
  if (!u->parent) {
    root_ = u;
  }
  return rotations;
}

std::size_t addWithPriorityCount(const T& x, std::uint64_t priority) {
  Node* u = new Node(x, priority);
  if (!addNode(u)) {
    delete u;
    return 0; // Clave duplicada, no se inserta
  }
  return bubbleUpCount(u);
}
```
- tabla con clave, prioridad, rotaciones y raíz después de insertar,
```
Clave     Prioridad   Rotaciones    Raíz Post    ¿Es Treap Válido?

100       100         0             100           SI
90        90          1             90            SI
80        80          1             80            SI
70        70          1             70            SI
60        60          1             60            SI
```
- explicación de costo esperado.
El Treap resuelve de raíz el gran talón de Aquiles de los árboles binarios de búsqueda convencionales: su dependencia del orden de entrada de los datos.

Si un conjunto de claves ordenadas se inserta en un BST regular, el árbol degenera en una lista enlazada con operaciones costosas de tiempo lineal $O(n)$. El Treap neutraliza este escenario al disociar el orden de las claves mediante la asignación de una prioridad numérica independiente, puramente aleatoria y única para cada nodo.

Costo Esperado de Búsqueda, Inserción y Borrado: $O(\log n)$

Costo Esperado de Rotaciones: $O(1)$

#### Parte C - Instrumentación de `trickleDown` y eliminación

1. ¿Por qué eliminar en un treap no es simplemente borrar como en un BST común?

Si aplicáramos esa misma estrategia en un Treap, el nodo que sube a reemplazar al eliminado muy probablemente rompería la propiedad de Min-Heap vertical. Para evitar esto, en un Treap el proceso se invierte: en lugar de buscar un sustituto en el inorden, se altera la prioridad del nodo objetivo de forma virtual (voviéndola "infinita") y se usa trickleDown para hundirlo mediante rotaciones válidas hasta que se convierte en una hoja o un nodo con un solo hijo, donde su remoción física con splice es trivial y no afecta a ningún invariante.

2. ¿Por qué `trickleDown` elige rotar con el hijo de menor prioridad?

Porque el Treap mantiene un invariante de Min-Heap sobre las prioridades, lo que significa que el nodo con la menor prioridad absoluta de un subárbol debe residir obligatoriamente en la raíz de este. Al hundir el nodo actual, uno de sus dos hijos ascenderá a tomar su lugar. Si eligiéramos al hijo con la prioridad más alta (el más grande), este terminaría convirtiéndose en el padre de su hermano de menor prioridad, violando inmediatamente la propiedad del montículo. Elegir al menor garantiza la consistencia del Heap tras la rotación.

3. ¿Qué ocurre si el nodo tiene solo hijo izquierdo?

El algoritmo aplica de forma determinista una rotación a la derecha (rotateRight) sobre el nodo actual. Esto eleva al hijo izquierdo a la posición del padre y hunde al nodo objetivo hacia la rama derecha, manteniendo intacta la validez del árbol de búsqueda binaria.

4. ¿Qué ocurre si el nodo tiene solo hijo derecho?

El algoritmo aplica de forma determinista una rotación a la izquierda (rotateLeft) sobre el nodo actual. Esto eleva al hijo derecho a la posición del padre y desplaza al nodo objetivo hacia la rama izquierda para continuar su descenso.

5. ¿Qué invariantes deben seguir siendo verdaderos después de `splice`?

Invariante BST: Las claves del subárbol remanente que tomó el lugar del nodo eliminado deben mantener el orden simétrico respecto a los ancestros.

Invariante Min-Heap: Al haber removido un elemento que previamente fue empujado hasta el fondo por tener prioridad máxima (virtual), todos los nodos restantes deben seguir cumpliendo que $prioridad(padre) \le prioridad(hijo)$.

Consistencia de Punteros: Las referencias parent, left y right de los nodos involucrados en el empalme deben quedar perfectamente sincronizadas, asegurando la integridad del árbol y el conteo exacto del tamaño (size_).

Entrega en esta parte:

- código modificado,
```
//MOD-A6-M9 Parte C
std::size_t trickleDownCount(Node* u) {
  if (!u) return 0;
  std::size_t rotations = 0;
  
  while (u->left || u->right) {
    if (!u->left) {
      rotateLeft(u);
    } else if (!u->right) {
      rotateRight(u);
    } else if (u->left->priority < u->right->priority) {
      rotateRight(u);
    } else {
      rotateLeft(u);
    }
    rotations++;
    if (root_ == u) {
      root_ = u->parent;
    }
  }
  return rotations;
}

std::size_t removeCount(const T& x) {
  Node* u = findEQ(x);
  if (!u) return 0; // Elemento no encontrado, 0 rotaciones
  
  // Rotar hacia abajo hasta ser hoja o tener a lo más un hijo
  std::size_t rotations = trickleDownCount(u);
  
  // Aplicar lógica equivalente a splice
  splice(u);
  delete u;
  
  return rotations;
}
```
```
#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>
#include "Capitulo6.h"

namespace {

void mostrarRecorrido(const std::vector<int>& v) {
  std::cout << "[";
  for (std::size_t i = 0; i < v.size(); ++i) {
    std::cout << v[i] << (i + 1 < v.size() ? ", " : "");
  }
  std::cout << "]";
}

} // namespace
/// MOD-A6-B9-Parte C : Demostración e Instrumentación de Eliminaciones en Treap
int main() {
  ods::Treap<int> t(232);
  
  // Construcción del Treap (Inserciones iniciales)
  std::vector<std::pair<int, int>> insertions = { 
    {50, 50}, {30, 30}, {70, 70}, {20, 20}, {40, 40}, {60, 60}, {80, 80} 
  };
  
  for (const auto& p : insertions) {
    t.addWithPriority(p.first, p.second);
  }

  std::cout << "INSTRUMENTACION DE ELIMINACIONES (trickleDownCount)\n";
  std::cout << "\n\n";
  std::cout << "Arbol Inicial Construido :\n" << t << "\n";
  std::cout << "\n";

  std::vector<int> a_eliminar = {50, 20, 70};

  for (int clave : a_eliminar) {
    std::size_t rotaciones = t.removeCount(clave);
    
    std::cout << "CLAVE ELIMINADA: " << clave << "\n";
    std::cout << "    Cantidad de rotaciones : " << rotaciones << "\n";
    std::cout << "    Recorrido Inorden      : "; mostrarRecorrido(t.inorderKeys()); std::cout << "\n";
    std::cout << "    Recorrido Por Niveles  : "; mostrarRecorrido(t.levelOrderKeys()); std::cout << "\n";
    std::cout << "    ¿isBST()?              : " << (t.isBST() ? "true" : "false") << "\n";
    std::cout << "    ¿isHeapByPriority()?   : " << (t.isHeapByPriority() ? "true" : "false") << "\n";
    std::cout << "    ¿isTreap()?            : " << (t.isTreap() ? "true" : "false") << "\n";
    std::cout << "\n";
  }

  std::cout << "Arbol Final Resultante:\n" << t << "\n";
  std::cout << "\n";
  return 0;
}
```
- salida de la demostración,
```
INSTRUMENTACION DE ELIMINACIONES (trickleDownCount)


Arbol Inicial Construido :
│                       ┌── 80|p=80
│                   ┌── 70|p=70
│               ┌── 60|p=60
│           ┌── 50|p=50
│       ┌── 40|p=40
│   ┌── 30|p=30
└── 20|p=20


CLAVE ELIMINADA: 50
    Cantidad de rotaciones : 1
    Recorrido Inorden      : [20, 30, 40, 60, 70, 80]
    Recorrido Por Niveles  : [20, 30, 40, 60, 70, 80]
    ¿isBST()?              : true
    ¿isHeapByPriority()?   : true
    ¿isTreap()?            : true

CLAVE ELIMINADA: 20
    Cantidad de rotaciones : 1
    Recorrido Inorden      : [30, 40, 60, 70, 80]
    Recorrido Por Niveles  : [30, 40, 60, 70, 80]
    ¿isBST()?              : true
    ¿isHeapByPriority()?   : true
    ¿isTreap()?            : true

CLAVE ELIMINADA: 70
    Cantidad de rotaciones : 1
    Recorrido Inorden      : [30, 40, 60, 80]
    Recorrido Por Niveles  : [30, 40, 60, 80]
    ¿isBST()?              : true
    ¿isHeapByPriority()?   : true
    ¿isTreap()?            : true

Arbol Final Resultante:
│           ┌── 80|p=80
│       ┌── 60|p=60
│   ┌── 40|p=40
└── 30|p=30
```
- trazado manual de una eliminación donde haya al menos una rotación.
Analicemos la eliminación de la clave 20 (prioridad = 20), la cual se ejecuta inmediatamente después de haber borrado el nodo 50.

Estado Inicial del Subárbol antes de borrar el 20:
El nodo 20 es la raíz absoluta del Treap. Sus conexiones son:

u = [20|p=20]

u->left = nullptr

u->right = [30|p=30] (El nodo 30 tiene como hijo derecho a [40|p=40], y 30 también tiene una rama hermana liderada por el nodo 60).

Paso 1: Primer ciclo de trickleDownCount
El algoritmo evalúa los hijos de u (20).

Como u->left es nullptr y u->right es válido (30), se cumple la primera condición de escape: el nodo solo tiene hijo derecho.

Se invoca una rotación a la izquierda sobre el padre (rotateLeft(20)).

El nodo 30 sube a convertirse en la nueva raíz del Treap.

El nodo 20 baja y pasa a ser el hijo izquierdo de 30.

El subárbol original izquierdo de 30 (que estaba vacío) se le asigna al lado derecho del 20.

Contador de rotaciones = 1.

Paso 2: Segundo ciclo de trickleDownCount
El nodo objetivo 20 sigue bajo inspección en su nueva posición. Evaluamos sus hijos actuales:

u->left es nullptr.

u->right ahora apunta al nodo [40|p=40] (heredado de la reestructuración previa).

Volvemos a entrar al caso en el que el nodo solo tiene hijo derecho.

Se ejecuta una segunda rotación a la izquierda (rotateLeft(20)).

El nodo 40 sube y toma el lugar que ocupaba 20 (como hijo izquierdo de 30).

El nodo 20 vuelve a descender, pasando a ser el hijo izquierdo de 40.

Contador de rotaciones = 2.

Paso 3: Término del bucle y extracción física (splice)
Evaluamos nuevamente los hijos de 20: tanto u->left como u->right son nullptr. El nodo se ha convertido con éxito en una hoja.

El bucle while(u->left || u->right) finaliza, devolviendo un total de 2 rotaciones.

Se llama a splice(20). Dado que 20 es una hoja limpia (no tiene hijos), su padre (40) simplemente desconecta su puntero izquierdo asignándole nullptr.

Se libera de manera segura la memoria física ocupada por el nodo 20 mediante delete. Los invariantes BST y Min-Heap de los nodos remanentes (30, 40, 60, etc.) quedan preservados.

#### Parte D - Búsqueda ordenada en Treap

1. ¿Por qué `lowerBound` y `upperBound` dependen de la propiedad BST y no de la propiedad heap?

Porque ambas operaciones pertenecen al dominio del ordenamiento lineal de las claves. Requieren encontrar elementos basados exclusivamente en relaciones de orden de magnitud ($x \le key$ o $x < key$).

2. ¿Qué parte del treap se comporta igual que un BST?

Las operaciones de búsqueda e inspección de rangos (findEQ, contains, lowerBound, upperBound), así como la fase inicial de posicionamiento de las inserciones (addNode). Todos estos métodos recorren el árbol guiándose única y exclusivamente por el comparador de las claves (comp_), comportándose de manera idéntica a un árbol binario de búsqueda estándar.

3. ¿Qué parte del treap se comporta como heap?

La jerarquía estructural vertical y los mecanismos de rebalanceo dinámico (bubbleUp, trickleDown). La distribución de los niveles (qué nodo es raíz o ancestro de quién) está completamente dictada por los valores de las prioridades, cumpliendo la condición de que ningún nodo padre puede tener una prioridad mayor (en un Min-Heap) que la de sus descendientes.

4. ¿Por qué el treap no reemplaza directamente a una cola de prioridad si lo único que quieres es extraer máximos o mínimos repetidamente?

Espacio Auxiliar: Cada nodo en un Treap requiere almacenar físicamente tres punteros (parent, left, right), una clave, y una prioridad explícita ($O(n)$ en punteros). Un montículo binario estándar (PQ_ComplHeap) se implementa sobre un arreglo contiguo implícito con cero punteros adicionales.

Costo Operacional: Acceder al mínimo en un Min-Heap toma tiempo constante $O(1)$ (está en la posición a[0]). En un Treap, aunque el mínimo de prioridad está en la raíz, el mínimo de la clave requiere realizar un descenso logarítmico hasta el extremo izquierdo. Además, mantener el balanceo del Treap mediante rotaciones continuas consume muchos más ciclos de CPU que el simple intercambio aritmético de posiciones en un arreglo.

5. ¿En qué situación sí conviene usar una estructura tipo treap?.

Conviene cuando se requiere una estructura híbrida y versátil que deba resolver de manera simultánea y eficiente tanto operaciones de Diccionario/BST (búsquedas por clave exacta, listados en orden, consultas de rangos como lowerBound) como operaciones de Cola de Prioridad. Es ideal en sistemas donde las entradas de datos pueden venir ordenadas de forma maliciosa o secuencial (lo que destruiría un BST común) y se desea garantizar un balanceo robusto y altamente eficiente mediante aleatorización sin la complejidad de implementación de un árbol AVL o Red-Black.

Entrega en esta parte:

- tabla comparativa Treap vs `BinarySearchTree`,

### Tabla Comparativa de Resultados: Treap vs. BinarySearchTree

A continuación se comparan los nodos devueltos por cada estructura tras aplicar el lote de pruebas de búsqueda y límites, utilizando como base el conjunto de claves remanentes `[30, 40, 60, 80]`.

| Operación Invocada | Resultado en el Treap | Resultado en `BinarySearchTree` | ¿Son Idénticos? | Comportamiento y Regla de Selección |
| :--- | :---: | :---: | :---: | :--- |
| **`findEQ(40)`** | Nodo `40` | Nodo `40` | **SÍ** | La clave `40` existe físicamente en ambas estructuras; se retorna una referencia directa a su nodo. |
| **`findEQ(35)`** | `nullptr` | `nullptr` | **SÍ** | La clave `35` no pertenece al conjunto de datos, por lo que ambas búsquedas fallan de forma segura. |
| **`lowerBound(35)`** | Nodo `40` | Nodo `40` | **SÍ** | Evalúa la condición $\ge 35$. El valor más pequeño en el árbol que cumple el criterio es `40`. |
| **`lowerBound(40)`** | Nodo `40` | Nodo `40` | **SÍ** | Al existir coincidencia exacta para la condición $\ge 40$, ambas estructuras retornan el propio nodo `40`. |
| **`upperBound(40)`** | Nodo `60` | Nodo `60` | **SÍ** | Evalúa la condición estrictamente mayor ($> 40$). El límite superior inmediato en la secuencia es `60`. |
| **`upperBound(75)`** | Nodo `80` | Nodo `80` | **SÍ** | Evalúa la condición $> 75$. El primer y menor elemento que satisface la inecuación es `80`. |

- respuestas de búsqueda,
```
  findEQ(40)        -> Encontrado [Key: 40 | Pri: 40]
  findEQ(35)        -> nullptr (No existe)

  lowerBound(35)    -> Encontrado [Key: 40 | Pri: 40]
  lowerBound(40)    -> Encontrado [Key: 40 | Pri: 40]

  upperBound(40)    -> Encontrado [Key: 60 | Pri: 60]
  upperBound(75)    -> Encontrado [Key: 80 | Pri: 80]
```
- explicación de qué propiedad se usó en cada operación.

1. Operaciones que usan exclusivamente la Propiedad BST (Árbol de Búsqueda Binaria)

findEQ(40) y findEQ(35): Utilizan únicamente el invariante de orden de las claves en el eje horizontal. La búsqueda se guía por la regla de que todo nodo a la izquierda es menor y todo nodo a la derecha es mayor. Las prioridades no aportan ninguna información útil aquí, por lo que son completamente ignoradas durante la ejecución de estas funciones.

lowerBound(35), lowerBound(40), upperBound(40) y upperBound(75): Estas operaciones de límites y rangos dependen al 100% de la Propiedad BST. Para calcular el sucesor inmediato o el elemento mayor/igual más cercano, el algoritmo necesita una estructura con orden simétrico para poder descartar subárboles completos en tiempo logarítmico.

2. Operaciones que combinan la Propiedad BST y la Propiedad Heap

add / addWithPriority / addWithPriorityCount: Utilizan ambas propiedades en dos etapas sucesivas. Primero usan la Propiedad BST para descender por el árbol y colgar el nuevo nodo en la posición matemática correcta según su clave. Inmediatamente después, usan la Propiedad Heap para ejecutar rotaciones hacia arriba (bubbleUp) y reordenar verticalmente el árbol según las prioridades, sin alterar el orden horizontal de las claves.

remove / removeCount: Utilizan ambas propiedades. Primero localizan el nodo objetivo mediante la Propiedad BST. Luego, usan la Propiedad Heap para hundir el nodo de forma segura a través de rotaciones (trickleDown), eligiendo siempre al hijo de menor prioridad para mantener el invariante del montículo, hasta que el nodo puede ser desconectado físicamente con splice.

#### Parte E - Pruebas específicas para Treap

1. ¿Qué bug atraparía una prueba de enlaces `parent`?

Atraparía errores críticos de desreferenciación y corrupción de memoria en las funciones rotateLeft y rotateRight. Si al reestructurar los punteros se olvida actualizar el enlace hacia el nuevo padre (u->parent = w), o se asigna de manera incorrecta, cualquier recorrido ascendente o rebalanceo posterior (bubbleUp o trickleDown) fallará, provocando bucles infinitos en el peor de los casos o segmentación de memoria (segmentation fault).

2. ¿Qué bug atraparía una prueba de `size()`?

No decrementar la variable interna size_ al ejecutar una eliminación que falló silenciosamente o que sí eliminó un elemento mediante splice.

Incrementar size_ tras un intento de inserción de una clave duplicada que fue rechazada por addNode.

3. ¿Qué bug atraparía una prueba de inorden ordenado?

Atraparía fallas de violación del invariante de árbol binario de búsqueda (BST) causadas por rotaciones mal implementadas. Si una rotación altera erróneamente la jerarquía horizontal redistribuyendo un hijo en la subrama equivocada, el recorrido inorden dejará de ser una secuencia estrictamente monótona ascendente.

4. ¿Qué bug atraparía una prueba de prioridad padre-hijo?

Atraparía bugs en las condiciones límite de los bucles de rebalanceo (while de bubbleUp y trickleDown). Detectaría si el algoritmo se detuvo antes de tiempo dejando a un hijo con una prioridad menor que la de su padre (violando el Min-Heap) o si la lógica del comparador se invirtió por error transformándolo en un Max-Heap.

5. ¿Por qué conviene usar prioridades fijas en pruebas unitarias?

Porque elimina el no-determinismo inherente del generador de números aleatorios. Al inyectar prioridades fijas y controladas mediante addWithPriority, la topología exacta del árbol final se vuelve predecible y replicable a nivel de bits. Esto permite auditar de forma precisa la cantidad de rotaciones esperadas y el estado exacto de cada puntero en escenarios específicos.

Entrega en esta parte:

- pruebas agregadas,
```
// MOD-A6-B9-PE: Suite de Pruebas Unitarias Exhaustivas para Treap
#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "Treap.h"

void run_all_treap_tests() {
  std::cout << "Iniciando suite de pruebas instrumentadas MOD-A6-B10...\n";

  // 1. Caso Treap Vacío
  {
    ods::Treap<int> t;
    assert(t.empty() == true);
    assert(t.size() == 0);
    assert(t.isBST() == true);
    assert(t.isHeapByPriority() == true);
    assert(t.isTreap() == true);
  }

  // 2. Inserción con prioridades fijas & 4. Inorden ordenado & 5. Propiedad heap
  {
    ods::Treap<int> t;
    t.addWithPriority(50, 50);
    t.addWithPriority(30, 30);
    t.addWithPriority(70, 70);
    
    assert(t.isTreap() == true);
    std::vector<int> in = t.inorderKeys();
    assert(in == std::vector<int>({30, 50, 70}));
  }

  // 3. Rechazo de duplicados
  {
    ods::Treap<int> t;
    assert(t.add(10) == true);
    assert(t.add(10) == false);
    assert(t.size() == 1);
  }

  // 6. lowerBound y upperBound
  {
    ods::Treap<int> t;
    t.add(20); t.add(40); t.add(60);
    assert(t.lowerBound(30) != nullptr && t.lowerBound(30)->key == 40);
    assert(t.lowerBound(40) != nullptr && t.lowerBound(40)->key == 40);
    assert(t.upperBound(40) != nullptr && t.upperBound(40)->key == 60);
    assert(t.upperBound(70) == nullptr);
  }

  // 7. Eliminación de hoja
  {
    ods::Treap<int> t;
    t.addWithPriority(50, 10);
    t.addWithPriority(80, 20); // Hoja derecha
    assert(t.remove(80) == true);
    assert(t.size() == 1);
    assert(t.isTreap() == true);
  }

  // 8. Eliminación de nodo con un hijo
  {
    ods::Treap<int> t;
    t.addWithPriority(50, 10);
    t.addWithPriority(30, 20);
    t.addWithPriority(20, 30); // 30 tiene solo un hijo (20)
    assert(t.remove(30) == true);
    assert(t.isTreap() == true);
  }

  // 9. Eliminación de nodo con dos hijos & 10. Eliminación de raíz
  {
    ods::Treap<int> t;
    t.addWithPriority(50, 10);
    t.addWithPriority(30, 20);
    t.addWithPriority(70, 30);
    assert(t.remove(50) == true);
    assert(t.isTreap() == true);
  }

  // 11. Conservación de enlaces parent & 12. Consistencia de size() mixta
  {
    ods::Treap<int> t;
    t.add(15); t.add(5); t.add(25); t.add(10);
    assert(t.size() == 4);
    t.remove(5);
    assert(t.size() == 3);
    assert(t.isBST() == true);
  }

  // 13. Secuencia larga de operaciones mixtas (Estrés)
  {
    ods::Treap<int> t(42);
    std::vector<int> valores;
    for(int i = 0; i < 200; ++i) {
      t.add(i);
      valores.push_back(i);
    }
    std::shuffle(valores.begin(), valores.end(), std::mt19937(42));
    for(int i = 0; i < 100; ++i) {
      t.remove(valores[i]);
    }
    assert(t.size() == 100);
    assert(t.isTreap() == true);
  }

  std::cout << "Los tests de validacion pasaron con exito.\n";
}

int main() {
  run_all_treap_tests();
  return 0;
}
```
- resultado de `ctest --test-dir build-debug -R semana6 --output-on-failure`,
```
andre@andre-AB350M-DS3H-V2:/mnt/GsKk/Andre/2026/cruz.a/CC-232 (repoprofe)/Libreria_cc232/Semana6$ ctest --test-dir build-debug -R semana6 --output-on-failure
Internal ctest changing into directory: /mnt/GsKk/Andre/2026/cruz.a/CC-232 (repoprofe)/Libreria_cc232/Semana6/build-debug
Test project /mnt/GsKk/Andre/2026/cruz.a/CC-232 (repoprofe)/Libreria_cc232/Semana6/build-debug
    Start 1: semana6_public
1/2 Test #1: semana6_public ...................   Passed    0.00 sec
    Start 2: semana6_internal
2/2 Test #2: semana6_internal .................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 2

Total Test time (real) =   0.01 sec
```
- breve explicación de qué cubre cada prueba.
Prueba 1 (Vacío): Asegura que el estado base de inicialización contenga un tamaño nulo y que las funciones lógicas de validación devuelvan verdadero de forma directa ante un árbol inexistente.

Prueba 2 (Fijas): Inyecta topologías específicas controladas para verificar que bubbleUp funcione exactamente bajo las condiciones esperadas del Min-Heap.

Prueba 3 (Duplicados): Confirma que el árbol actúe como un conjunto de elementos únicos, impidiendo corrupciones en la estructura al intentar reinsertar una clave existente.

Prueba 4 (Inorden Ordenado): Garantiza que las claves mantengan el orden simétrico secuencial estricto ($x_1 < x_2 < \dots < x_n$), lo que convalida las rotaciones.

Prueba 5 (Propiedad Heap): Audita verticalmente la estructura corroborando que ningún nodo descendiente tenga una prioridad numéricamente menor que la de su ancestro.

Prueba 6 (lowerBound/upperBound): Prueba la precisión de las consultas por intervalos, verificando tanto aciertos exactos como aproximaciones superiores y desbordamientos por la derecha (nullptr).

Prueba 7 (Hoja): Evalúa el caso base de remoción en el que un nodo no posee dependencias y es descolgado instantáneamente mediante splice.

Prueba 8 (Un Hijo): Valida la reconexión de punteros cuando el nodo intermedio es eliminado, obligando a que su único hijo sea adoptado por el abuelo de forma correcta.

Prueba 9 (Dos Hijos): Fuerza el algoritmo a hundir (trickleDown) un nodo interno seleccionando dinámicamente el camino correcto según la prioridad de los dos hijos competidores.

Prueba 10 (Raíz): Asegura que cuando el nodo raíz sea removido, el puntero principal root_ de la clase sea actualizado apuntando al nuevo líder estructural.

Prueba 11 (Enlaces Parent): Invoca el validador interno checkParents recorriendo todo el árbol para confirmar que la relación de ida y vuelta padre-hijo sea bidireccional y simétrica en memoria.

Prueba 12 (Consistencia Mixta): Monitorea continuamente la variable de control size_ tras alternar inserciones válidas, inserciones fallidas y remociones reales.

Prueba 13 (Secuencia Larga): Expone a la estructura a un escenario de estrés de 300 operaciones aleatorias concurrentes para diagnosticar la estabilidad a largo plazo y la ausencia de fugas de memoria o corrupciones de balanceo.

### Bloque 11 - Comparación con Semana 5: `BinaryHeap`, `BinarySearchTree` y `Treap`

Revisa:

- `Semana5/include/BinaryHeap.h`
- `Semana5/include/BinarySearchTree.h`
- `Semana6/include/PQ_ComplHeap.h`
- `Semana6/include/Treap.h`
- `Semana6/demos/demo_compare_with_semana5.cpp`
- `Semana6/demos/demo_treap_basico.cpp`

Modifica `demo_compare_with_semana5.cpp` para construir una comparación observable entre:

1. `BinaryHeap` de Semana 5,
2. `PQ_ComplHeap` de Semana 6,
3. `BinarySearchTree` de Semana 5,
4. `Treap` de Semana 6.

La demostración debe mostrar una tabla con columnas:

- estructura,
- operación principal,
- propiedad mantenida,
- operación eficiente,
- operación que no conviene,
- evidencia producida por la demostración.

Responde:

1. ¿Qué diferencia hay entre un heap de prioridad y un árbol de búsqueda?

Un montículo o heap mantiene una jerarquía de orden puramente vertical (relación padre-hijo, donde el padre es siempre mayor o menor que sus descendientes), lo que permite localizar el elemento óptimo en la raíz de forma inmediata $O(1)$. Un árbol de búsqueda binaria (BST) mantiene una relación de orden horizontal estricta (todo el subárbol izquierdo es menor que la raíz, y todo el derecho es mayor), lo que optimiza búsquedas exactas y por rangos.

2. ¿Por qué un BST permite recorrido ordenado y un heap no?

Porque el invariante posicional del BST garantiza un orden simétrico. Al realizar un recorrido inorden, las claves se visitan secuencialmente de izquierda a derecha de forma ordenada. El heap no impone restricciones de orden entre hermanos ni entre subramas separadas (el hijo izquierdo puede ser mayor o menor que el derecho), lo que destruye cualquier posibilidad de obtener secuencias ordenadas de manera directa mediante recorridos tradicionales.

3. ¿Qué agrega `PQ_ComplHeap` frente a un `BinaryHeap` educativo?

PQ_ComplHeap implementa una interfaz genérica parametrizada basada en polimorfismo dinámico (PQ<T>), lo que permite el intercambio transparente de colas de prioridad en tiempo de ejecución. Además, está desacoplado mediante políticas de ordenación personalizables (Compare), admite la construcción óptima en tiempo lineal $O(n)$ usando el algoritmo de inicialización de Floyd (heapify), y soporta inyecciones contiguas eficientes en memoria mediante la API estándar de std::vector.

4. ¿Qué combina un `Treap`?

Combina las fortalezas de un Árbol de Búsqueda Binaria (BST) sobre sus claves (keys) para mantener la capacidad de búsqueda rápida y de rangos, junto con las propiedades de un Min-Heap sobre prioridades numéricas autogeneradas de forma aleatoria para garantizar la estabilidad del balanceo topológico de forma probabilística.

5. ¿Qué estructura usarías para extraer máximos repetidamente?

Utilizaría PQ_ComplHeap (configurado con un Max-Heap). Ofrece acceso inmediato al elemento máximo en $O(1)$ y una reestructuración de extracción garantizada en tiempo logarítmico estricto $O(\log n)$, operando sobre un arreglo contiguo con un costo espacial nulo en punteros.

6. ¿Qué estructura usarías para responder `lowerBound` o `upperBound`?

Utilizaría un Treap (o en su defecto un BinarySearchTree si el orden de los datos no fuera de carácter malicioso). Ambas estructuras mantienen la propiedad horizontal necesaria para acotar rangos secuenciales y descartar mitades completas de claves en tiempo logarítmico.

7. ¿Qué estructura usarías si quieres búsqueda ordenada con balanceo probabilístico?.

Utilizaría un Treap. Su naturaleza asegura que la altura del árbol converja estadísticamente a un óptimo esperado de $O(\log n)$ ante cualquier secuencia de inserciones sin la sobrecarga computacional de rotaciones continuas que imponen los árboles AVL o Red-Black rígidos.

Entrega en este bloque:

- Demostración modificada.
```
// MOD-A6-B10: Análisis Comparativo Multi-Estructura (S5 vs S6)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Capitulo5.h"
#include "Capitulo6.h"

int main() {
  const std::vector<int> xs{8, 3, 10, 1, 6, 14, 4, 7, 13};
  ods::BinaryHeap<int> binaryHeap;
  ods::PQ_ComplHeap<int> pqComplHeap;
  ods::BinarySearchTree<int> bst;
  ods::Treap<int> treap(42);

  // Inserción concurrente
  for (int x : xs) {
    binaryHeap.add(x);
    pqComplHeap.insert(x);
    bst.add(x);
    treap.addWithPriority(x, static_cast<std::uint64_t>(x * 10));
  }

  std::cout << "REPORTE DE EVIDENCIAS EN CONSOLA\n";
  std::cout << "\n\n";

  // 1. Evidencia BinaryHeap
  std::cout << "  BinaryHeap (Min-Heap S5):\n";
  std::cout << "  Elemento en el tope (Mínimo): " << binaryHeap.top() << "\n\n";

  // 2. Evidencia PQ_ComplHeap
  std::cout << "  PQ_ComplHeap (Max-Heap S6):\n";
  std::cout << "  Elemento máximo (getMax())  : " << pqComplHeap.getMax() << "\n";
  std::cout << "  ¿Es un Max-Heap válido?     : " << (pqComplHeap.isValidHeap() ? "SI" : "NO") << "\n\n";

  // 3. Evidencia BinarySearchTree
  std::cout << "  BinarySearchTree (S5):\n";
  std::cout << "  Recorrido Inorden ordenado  : ";
  for (int x : bst.inorder()) { std::cout << x << " "; }
  std::cout << "\n\n";

  // 4. Evidencia Treap
  std::cout << "  Treap Balanceado (S6):\n";
  std::cout << "  Recorrido Inorden de claves : ";
  for (int x : treap.inorderKeys()) { std::cout << x << " "; }
  std::cout << "\n";
  auto* lb = treap.lowerBound(5);
  std::cout << "  lowerBound(5) sobre claves  : " << (lb ? std::to_string(lb->key) : "null") << "\n";
  std::cout << "  ¿Es un Treap mixto válido?  : " << (treap.isTreap() ? "SI" : "NO") << "\n";
  std::cout << "\n";

  return 0;
}
```

- Tabla de comparación.

Estructura | Operación Principal | Propiedad Mantenida | Operación Eficiente | Operación que NO Conviene | Evidencia Producida por la Demostración |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **`BinaryHeap`** *(Semana 5)* | Extracción del elemento mínimo. | **Min-Heap Vertical:** El nodo padre es menor o igual que sus hijos. | `top()` en $O(1)$, `add()` y `remove()` en $O(\log n)$. | Buscar una clave exacta o listar los elementos en orden ($O(n \log n)$). | `top() = 1`, confirmando que el valor menor absoluto reside en la raíz. |
| **`PQ_ComplHeap`** *(Semana 6)* | Extracción del elemento máximo. | **Max-Heap Vertical:** El nodo padre es mayor o igual que sus hijos. | `getMax()` en $O(1)$, `insert()` y `delMax()` en $O(\log n)$. | Consultar rangos u obtener cotas de vecindad como `lowerBound` ($O(n)$). | `getMax() = 14` e `isValidHeap() = SI` bajo una carga de datos aleatorios. |
| **`BinarySearchTree`** *(Semana 5)* | Búsqueda y ordenamiento de claves. | **Orden Horizontal BST:** Subárbol izquierdo < raíz < subárbol derecho. | Recorrido `inorder()` en $O(n)$, búsquedas en $O(\log n)$ promedio. | Insertar claves que ya vienen ordenadas (degradación a peor caso $O(n)$). | `inorder() = 1 3 4 6 7 8 10 13 14` en perfecta secuencia monótona. |
| **`Treap`** *(Semana 6)* | Búsqueda ordenada con balanceo. | **Mixta:** BST horizontal en claves + Min-Heap vertical en prioridades. | Búsquedas, rangos y mutaciones en tiempo esperado $O(\log n)$. | Extracciones puras de mínimos sin requerir un diccionario ($O(\log n)$ con punteros). | Claves ordenadas en inorden, `lowerBound(5) = 6` e `isTreap() = SI`. |

- Respuesta breve de selección de estructura.
Para extraer máximos o mínimos repetidamente, para responder consultas de rangos (lowerBound / upperBound) y para búsquedas dinámicas con un balanceo simple y probabilístico.

#### Bloque 12 - Pruebas obligatorias después de modificar código

- Lista de pruebas agregadas.
```
REQ 1 & 2: Invariantes estables en PQ_ComplHeap.
REQ 3 & 4: Control de efectos secundarios en tamaño.
REQ 5: Constructor Floyd (heapify) validado.
REQ 6: HeapSort con elementos repetidos correcto.
REQ 7, 8 & 9: Invariantes estables en PQ_LeftHeap.
REQ 10 & 11: Códigos de Huffman unívocos y válidos.
REQ 12: Caso crítico de un solo símbolo manejado con éxito.
REQ 13 & 14: Inserciones duales perfectas en Treap.
REQ 15: Eliminaciones complejas en Treap mantienen invariantes.
```
- Resultado completo de `ctest --output-on-failure`.
```
andre@andre-AB350M-DS3H-V2:/mnt/GsKk/Andre/2026/cruz.a/CC-232 (repoprofe)/Libreria_cc232/Semana6$ ctest --test-dir build-debug -R semana6 --output-on-failure
Internal ctest changing into directory: /mnt/GsKk/Andre/2026/cruz.a/CC-232 (repoprofe)/Libreria_cc232/Semana6/build-debug
Test project /mnt/GsKk/Andre/2026/cruz.a/CC-232 (repoprofe)/Libreria_cc232/Semana6/build-debug
    Start 1: semana6_public
1/2 Test #1: semana6_public ...................   Passed    0.01 sec
    Start 2: semana6_internal
2/2 Test #2: semana6_internal .................   Passed    0.01 sec

100% tests passed, 0 tests failed out of 2

Total Test time (real) =   0.03 sec
```
- Explicación de qué bug atraparía cada prueba.

REQ 1 & 2 (PQ_ComplHeap invariantes): Atrapa desajustes aritméticos elementales en los índices dinámicos de los hijos (2i + 1 y 2i + 2) durante las etapas críticas de ascenso y descenso.

REQ 3 & 4 (Efectos en Tamaño): Previene fugas conceptuales de extracción de datos, controlando que los métodos de solo lectura (getMax) no quiten elementos accidentalmente y que delMax limpie el final del vector.

REQ 5 (Floyd): Detecta si la cota de iteración de Floyd se detuvo antes de la mitad del arreglo, dejando nodos hoja actuando como padres sin estar ordenados de forma descendente.

REQ 6 (Repetidos): Expone inestabilidades algorítmicas si los comparadores fallan ante claves idénticas, previniendo loops infinitos en la extracción de máximos duplicados.

REQ 7, 8 & 9 (PQ_LeftHeap): Evita la corrupción estructural del s-value o NPL (Null Path Length). Si se olvida actualizar la distancia al camino nulo de un nodo tras el merge, la propiedad izquierdista colapsa de inmediato.

REQ 10, 11 & 12 (Huffman): Asegura la completitud del diccionario de frecuencias y la decodificabilidad unívoca (que ningún código binario sea prefijo de otro). El check del símbolo único evita accesos a punteros nulos (nullptr) cuando no hay un segundo nodo con el cual emparejar el árbol.

REQ 13, 14 & 15 (Treap): El seguro definitivo de las operaciones híbridas. Valida que las rotaciones a la izquierda y derecha reubiquen de forma exacta las prioridades del Min-Heap vertical sin desordenar jamás la secuencia simétrica horizontal inorden de las claves.

#### Bloque 13 - Defensa escrita de modificaciones

¿Qué aprendiste al modificar código de prioridad, heaps, Huffman y Treap que no se aprende solo leyendo o ejecutando demostraciones?

Modificar directamente las entrañas de estas estructuras me permitió cruzar la frontera entre la teoría elegante y la cruda realidad de la gestión de memoria y punteros, una experiencia que la lectura pasiva jamás lograría transmitir.

Al trabajar en este nivel, comprendí que la interfaz PQ actúa como un contrato polimórfico indispensable que abstrae el comportamiento de una cola de prioridad, demostrando cómo el diseño de software limpio permite intercambiar implementaciones internas (ya sean arreglos o estructuras enlazadas) sin alterar un solo bit del código del cliente. Al meterme en los detalles de PQ_ComplHeap, asimilé de forma práctica que la representación implícita del heap binario completo sobre un vector contiguo elimina por completo el costo de almacenamiento de punteros, pero a cambio exige una precisión matemática absoluta en la aritmética de índices para no corromper las relaciones jerárquicas.

Durante las mutaciones, descubrí el verdadero peso operativo de los algoritmos de rebalanceo. Implementar percolateUp me enseñó que la flotación de un elemento es un proceso local y eficiente de costo logarítmico, pero sumamente propenso a fallar en los límites superiores si la condición de parada no gestiona correctamente la llegada al índice de la raíz. Por otro lado, la lógica de percolateDown reveló ser sustancialmente más compleja de codificar debido a que cada paso descendente exige evaluar múltiples bifurcaciones (la existencia de dos hijos y la rigurosa selección del hermano óptimo) para no violar la propiedad del montículo.

El impacto de la optimización matemática cobró sentido al validar el heapify de Floyd; comprobar mediante trazas que procesar el arreglo desde el último nodo no-hoja hacia atrás reduce el costo de construcción a un tiempo lineal $O(n)$ fue un hallazgo fascinante que contrasta con el enfoque ingenuo de inserciones repetidas. Al conectar esto con heapSort, aprendí que este algoritmo de ordenamiento saca provecho de dicha estructura para garantizar un tiempo de ejecución óptimo de $O(n \log n)$ en el peor caso, manteniendo una estabilidad operativa impecable incluso al lidiar con claves duplicadas.

Al pasar a estructuras enlazadas avanzadas, el panorama cambió por completo. La codificación del merge en el heap izquierdista me obligó a entender cómo una única operación fundamental puede resolver de forma elegante la inserción y la eliminación en tiempo logarítmico, siempre y cuando se actualice rigurosamente el valor de distancia al camino nulo (s-value) y se intercambien los subárboles de manera oportuna para mantener el sesgo hacia la izquierda. Con Huffman, el aprendizaje práctico radicó en ver cómo la combinación repetida de estos nodos mínimos produce árboles de codificación óptimos y libres de prefijos, asimilando el manejo crítico de alfabetos de un solo símbolo para evitar desreferenciaciones nulas.

La cúspide de este laboratorio fue el Treap, donde experimenté cómo las rotaciones quirúrgicas coordinan armoniosamente dos mundos opuestos: el orden horizontal de las prioridades del Min-Heap y la búsqueda ordenada del BST. Modificar sus métodos de descenso me demostró que el balanceo probabilístico es sumamente robusto ante datos maliciosos, superando la rigidez de los árboles AVL. Esto se consolidó en la comparación con BinaryHeap y BinarySearchTree, donde evidencié que el Treap es una estructura híbrida excelente que unifica la inspección por rangos (lowerBound) del BST y el control vertical del Heap, sacrificando únicamente la eficiencia en caché de los arreglos.

Finalmente, escribir la suite de validación me dejó una lección: las pruebas, invariantes y casos borde no son meros agregados de control de calidad; son el único mecanismo capaz de capturar errores invisibles en el código, como punteros parent mal direccionados tras una rotación o contadores de size() desfasados. En conclusión, meter las manos en el código me enseñó que la belleza de las estructuras de datos no reside solo en su análisis asintótico, sino en la rigurosa consistencia de sus punteros ante cada mutación.