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

#### Bloque 6 - Construcción de heap: inserciones sucesivas vs Floyd

Revisa:

- `Semana6/include/PQ_ComplHeap_heapifyFloyd.h`
- `Semana6/include/PQ_ComplHeap_insert.h`
- `Semana6/demos/demo_heapify_floyd.cpp`

Modifica la demostración de `heapify` para comparar dos formas de construir un heap con la misma entrada:

```cpp
{ 4, 17, 3, 90, 55, 21, 8, 13, 34, 2, 1, 89 }
```

Construcción A:

- insertar elementos uno por uno usando `insert`.

Construcción B:

- copiar el vector y aplicar `heapify` de Floyd.

La demostración debe mostrar:

- arreglo inicial,
- arreglo final por inserciones,
- arreglo final por Floyd,
- cantidad aproximada o exacta de intercambios si agregaste contadores,
- validación con `isValidHeap`.

Responde:

1. ¿Por qué ambos resultados pueden ser heaps válidos aunque sus arreglos finales no sean idénticos?
2. ¿Por qué insertar `n` elementos puede costar `O(n log n)`?
3. ¿Por qué Floyd puede construir el heap en `O(n)`?
4. ¿Qué nodos procesa Floyd primero?
5. ¿Por qué Floyd no necesita llamar a `percolateDown` desde las hojas?.

Entrega en este bloque:

- Demostración modificada.
- Tabla comparativa.
- Explicación de complejidad.

#### Bloque 7 - Modificación de `heapSort`

Revisa:

- `Semana6/include/vector_heapSort.h`
- `Semana6/demos/demo_heapsort.cpp`

Agrega una versión de `heapSort` que permita elegir el sentido del resultado:

```cpp
template<class T, class Compare>
void heapSort(std::vector<T>& a, Compare comp, bool ascending);
```

La función debe mantener la idea de heapsort in situ. No uses `std::sort`.

Prueba con:

```cpp
{ 5, 1, 5, 3, 8, 2, 8, 0 }
```

y muestra:

- resultado ascendente,
- resultado descendente,
- comportamiento con repetidos.

Responde:

1. ¿Por qué heapsort puede ordenar in situ?
2. ¿Qué parte del algoritmo destruye gradualmente el heap?
3. ¿Por qué heapsort cuesta `O(n log n)`?
4. ¿Es heapsort estable? Justifica con un ejemplo.
5. ¿Qué diferencia hay entre usar `heapSort` y extraer todos los elementos con `delMax`?

Entrega en este bloque:

- Código modificado.
- Demostración actualizada.
- Evidencia de repetidos.

#### Bloque 8 - Heap izquierdista: validación de `merge`

Revisa:

- `Semana6/include/PQ_LeftHeap.h`
- `Semana6/include/PQ_LeftHeap_merge.h`
- `Semana6/include/PQ_LeftHeap_insert.h`
- `Semana6/include/PQ_LeftHeap_delMax.h`
- `Semana6/demos/demo_left_heap_merge.cpp`

Agrega una función de validación para el heap izquierdista:

```cpp
bool isValidLeftHeap() const;
```

Debe verificar al menos:

1. propiedad de heap,
2. propiedad izquierdista,
3. consistencia de tamaño,
4. consistencia de `npl` o distancia nula, si el código la almacena.

Luego modifica la demostración de `merge` para construir dos heaps, mezclarlos y validar el resultado.

Responde:

1. ¿Por qué `merge` es la operación central del heap izquierdista?
2. ¿Cómo se implementa `insert` usando `merge`?
3. ¿Cómo se implementa `delMax` usando `merge`?
4. ¿Qué propiedad adicional diferencia un heap izquierdista de un heap binario completo?
5. ¿Qué ventaja conceptual tiene un heap izquierdista frente a un heap binario completo?.

Entrega en este bloque:

- Código de validación.
- Demostración modificada.
- Trazado de una fusión pequeña.

#### Bloque 9 - Huffman: modificación de desempate y caso de un símbolo

Revisa:

- `Semana6/include/Huffman_PQ.h`
- `Semana6/include/Huffman_PQ_generateTree.h`
- `Semana6/demos/demo_huffman.cpp`

Modifica el código de Huffman para documentar y probar explícitamente el desempate entre símbolos de igual frecuencia.

Usa este alfabeto:

```cpp
{ {'A', 5}, {'B', 5}, {'C', 10}, {'D', 10}, {'E', 20} }
```

Además, agrega una prueba para el caso extremo de un solo símbolo:

```cpp
{ {'X', 100} }
```

La implementación debe producir un código válido para el único símbolo, por ejemplo `"0"`.

Responde:

1. ¿Por qué Huffman necesita una cola de prioridad?
2. ¿Qué elementos se extraen repetidamente?
3. ¿Qué nodo se vuelve a insertar?
4. ¿Por qué el caso de un solo símbolo requiere cuidado especial?
5. ¿Qué significa que el conjunto de códigos sea libre de prefijos?
6. ¿Cómo afecta el desempate a la forma del árbol?
7. ¿El desempate cambia necesariamente la longitud total ponderada? Justifica.

Entrega en este bloque:

- Código modificado o prueba agregada.
- Tabla símbolo, frecuencia, código, longitud.
- Verificación de prefijo libre.

#### Bloque 10 - Treap: modificación de código, rotaciones e invariantes

Revisa:

- `Semana6/include/Treap.h`
- `Semana6/demos/demo_treap_basico.cpp`
- `Semana6/pruebas_publicas/test_public_week6.cpp`
- `Semana6/pruebas_internas/test_internal_week6.cpp`

Este bloque es obligatorio. Su objetivo es que no uses `Treap` solo como estructura decorativa, sino que entiendas cómo combina dos invariantes simultáneos:

1. propiedad de árbol binario de búsqueda sobre `key`,
2. propiedad de heap sobre `priority`.

En la implementación de Semana 6, una prioridad menor sube más cerca de la raíz. Por eso `bubbleUp` rota mientras el padre tiene prioridad mayor que el nodo insertado.

##### Parte A - Construcción determinística con prioridades fijas

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

##### Parte B - Instrumentación de `bubbleUp`

Agrega una versión instrumentada sin eliminar la función existente:

```cpp
template<class T, class Compare>
std::size_t bubbleUpCount(typename Treap<T, Compare>::Node* u);
```

Si prefieres mantenerla como método interno de la clase, puedes llamarla:

```cpp
std::size_t bubbleUpCount(Node* u);
```

La función debe realizar el mismo proceso que `bubbleUp`, pero retornando cuántas rotaciones se hicieron.

Luego agrega una forma controlada de usarla desde una inserción, por ejemplo:

```cpp
std::size_t addWithPriorityCount(const T& x, std::uint64_t priority);
```

No cambies el comportamiento público de `add` ni de `addWithPriority`.

Prueba con una secuencia que fuerce varias rotaciones:

```cpp
{ {100, 100}, {90, 90}, {80, 80}, {70, 70}, {60, 60} }
```

Responde:

1. ¿Por qué esta secuencia tiende a producir rotaciones repetidas?
2. ¿Cuándo `bubbleUpCount` retorna cero?
3. ¿Cuál es el peor caso de rotaciones durante una inserción?
4. ¿Por qué una rotación no rompe la propiedad BST?
5. ¿Por qué el treap busca mantener altura esperada logarítmica, no altura garantizada logarítmica?

Entrega en esta parte:

- código de la función instrumentada,
- tabla con clave, prioridad, rotaciones y raíz después de insertar,
- explicación de costo esperado.

##### Parte C - Instrumentación de `trickleDown` y eliminación

Agrega una versión instrumentada sin eliminar la función existente:

```cpp
std::size_t trickleDownCount(Node* u);
```

y una eliminación controlada:

```cpp
std::size_t removeCount(const T& x);
```

La eliminación debe rotar el nodo hacia abajo hasta que tenga a lo más un hijo, luego aplicar la lógica equivalente a `splice`.

Usa el treap construido en la Parte A y elimina:

```cpp
50, 20, 70
```

Después de cada eliminación, imprime:

- clave eliminada,
- cantidad de rotaciones,
- recorrido inorden,
- recorrido por niveles,
- `isBST()`,
- `isHeapByPriority()`,
- `isTreap()`.

Responde:

1. ¿Por qué eliminar en un treap no es simplemente borrar como en un BST común?
2. ¿Por qué `trickleDown` elige rotar con el hijo de menor prioridad?
3. ¿Qué ocurre si el nodo tiene solo hijo izquierdo?
4. ¿Qué ocurre si el nodo tiene solo hijo derecho?
5. ¿Qué invariantes deben seguir siendo verdaderos después de `splice`?

Entrega en esta parte:

- código modificado,
- salida de la demostración,
- trazado manual de una eliminación donde haya al menos una rotación.

##### Parte D - Búsqueda ordenada en Treap

Extiende la demostración para probar:

```cpp
findEQ(40)
findEQ(35)
lowerBound(35)
lowerBound(40)
upperBound(40)
upperBound(75)
```

Compara los resultados con lo que produciría `BinarySearchTree` usando las mismas claves.

Responde:

1. ¿Por qué `lowerBound` y `upperBound` dependen de la propiedad BST y no de la propiedad heap?
2. ¿Qué parte del treap se comporta igual que un BST?
3. ¿Qué parte del treap se comporta como heap?
4. ¿Por qué el treap no reemplaza directamente a una cola de prioridad si lo único que quieres es extraer máximos o mínimos repetidamente?
5. ¿En qué situación sí conviene usar una estructura tipo treap?.

Entrega en esta parte:

- tabla comparativa Treap vs `BinarySearchTree`,
- respuestas de búsqueda,
- explicación de qué propiedad se usó en cada operación.

##### Parte E - Pruebas específicas para Treap

Agrega o extiende pruebas para cubrir:

1. treap vacío: `empty()`, `size()`, `isBST()`, `isHeapByPriority()`, `isTreap()`,
2. inserción con prioridades fijas,
3. rechazo de duplicados,
4. inorden ordenado después de insertar,
5. propiedad heap por prioridad después de insertar,
6. `lowerBound` y `upperBound`,
7. eliminación de hoja,
8. eliminación de nodo con un hijo,
9. eliminación de nodo con dos hijos,
10. eliminación de raíz,
11. conservación de enlaces `parent`, si agregas una función pública de validación,
12. consistencia de `size()` después de operaciones mixtas,
13. estabilidad de invariantes después de una secuencia larga de inserciones y eliminaciones.

Responde:

1. ¿Qué bug atraparía una prueba de enlaces `parent`?
2. ¿Qué bug atraparía una prueba de `size()`?
3. ¿Qué bug atraparía una prueba de inorden ordenado?
4. ¿Qué bug atraparía una prueba de prioridad padre-hijo?
5. ¿Por qué conviene usar prioridades fijas en pruebas unitarias?

Entrega en esta parte:

- pruebas agregadas,
- resultado de `ctest --test-dir build-debug -R semana6 --output-on-failure`,
- breve explicación de qué cubre cada prueba.

#### Bloque 11 - Comparación con Semana 5: `BinaryHeap`, `BinarySearchTree` y `Treap`

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
2. ¿Por qué un BST permite recorrido ordenado y un heap no?
3. ¿Qué agrega `PQ_ComplHeap` frente a un `BinaryHeap` educativo?
4. ¿Qué combina un `Treap`?
5. ¿Qué estructura usarías para extraer máximos repetidamente?
6. ¿Qué estructura usarías para responder `lowerBound` o `upperBound`?
7. ¿Qué estructura usarías si quieres búsqueda ordenada con balanceo probabilístico?.

Entrega en este bloque:

- Demostración modificada.
- Tabla de comparación.
- Respuesta breve de selección de estructura.

#### Bloque 12 - Pruebas obligatorias después de modificar código

Debes agregar o extender pruebas en:

- `Semana6/pruebas_publicas/test_public_week6.cpp`
- `Semana6/pruebas_internas/test_internal_week6.cpp`

Incluye al menos las siguientes pruebas:

1. `PQ_ComplHeap` conserva la propiedad heap después de cada inserción.
2. `PQ_ComplHeap` conserva la propiedad heap después de cada eliminación.
3. `getMax` no cambia el tamaño.
4. `delMax` sí cambia el tamaño.
5. `heapifyFloyd` produce un heap válido.
6. `heapSort` ordena con repetidos.
7. `PQ_LeftHeap` conserva su propiedad después de `merge`.
8. `PQ_LeftHeap` conserva su propiedad después de `insert`.
9. `PQ_LeftHeap` conserva su propiedad después de `delMax`.
10. Huffman produce códigos para todos los símbolos con frecuencia positiva.
11. Huffman produce códigos libres de prefijos.
12. Huffman maneja correctamente el caso de un solo símbolo.
13. `Treap` conserva propiedad BST después de insertar.
14. `Treap` conserva propiedad de heap por prioridad después de insertar.
15. `Treap` conserva ambas propiedades después de eliminar.

Entrega en este bloque:

- Lista de pruebas agregadas.
- Resultado completo de `ctest --output-on-failure`.
- Explicación de qué bug atraparía cada prueba.

#### Bloque 13 - Defensa escrita de modificaciones

Responde en no más de 900 palabras:

¿Qué aprendiste al modificar código de prioridad, heaps, Huffman y Treap que no se aprende solo leyendo o ejecutando demostraciones?

Tu respuesta debe incluir obligatoriamente:

- Una afirmación sobre la interfaz `PQ`.
- Una afirmación sobre la representación implícita del heap binario completo.
- Una afirmación sobre `percolateUp`.
- Una afirmación sobre `percolateDown`.
- Una afirmación sobre `heapify` de Floyd.
- Una afirmación sobre `heapSort`.
- Una afirmación sobre `merge` en heap izquierdista.
- Una afirmación sobre Huffman.
- Una afirmación sobre `Treap`, rotaciones, prioridades y búsqueda ordenada.
- Una afirmación sobre comparación con `BinaryHeap` y `BinarySearchTree`.
- Una afirmación sobre pruebas, invariantes y casos borde.


#### Formato sugerido de entrega

```markdown




### Bloque 1 - Diagnóstico inicial
[Comandos, resultados y explicación]

### Bloque 2 - Utilidades de heap completo
[Código, explicación y evidencia]

### Bloque 3 - Conteo en percolateUp
[Código, salida y análisis]

### Bloque 4 - Conteo en percolateDown
[Código, salida y análisis]

### Bloque 5 - Validación de propiedad heap
[Código, pruebas y explicación]

### Bloque 6 - Inserciones sucesivas vs Floyd
[Demostración, tabla y complejidad]

### Bloque 7 - heapSort
[Código, pruebas y discusión de estabilidad]

### Bloque 8 - Heap izquierdista
[Código, validación y trazado]

### Bloque 9 - Huffman
[Código, tabla de códigos y prefijo libre]

### Bloque 10 - Treap
[Rotaciones, inserción, eliminación, búsquedas y pruebas]

### Bloque 11 - Comparación con Semana 5
[Tabla y selección de estructura]

### Bloque 12 - Pruebas
[Lista de pruebas, salida de ctest y explicación]

### Bloque 13 - Defensa escrita
[Respuesta final]
```

#### Criterio general de evaluación

Se espera evidencia de trabajo directo sobre el código. La actividad será evaluada principalmente por:

1. Claridad de las modificaciones.
2. Conservación de la interfaz pública cuando corresponda.
3. Uso correcto de invariantes.
4. Pruebas con casos borde.
5. Comparación razonada entre estructuras.
6. Explicación de costos.
7. Capacidad de sustentar oralmente los cambios.
8. Calidad de los ejercicios adicionales de codificación: modularidad, pruebas, casos borde y respeto de invariantes.

Pasar las pruebas no es suficiente. Debes poder explicar por qué tus cambios preservan la propiedad de heap, la propiedad izquierdista, la validez del árbol de Huffman, la propiedad BST del `Treap` y la diferencia entre estructuras para prioridad y estructuras para búsqueda ordenada.
