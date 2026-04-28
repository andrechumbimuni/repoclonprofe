### Actividad 3 - Semana 3

- Duración: 3 horas de clase.
- Modalidad: Trabajo en parejas.
- Tiempo de instalación: 15 minutos al inicio.
- Entrega: Un archivo llamado `actividad3-CC232.md`.

#### Objetivo

Consolidar lo trabajado en la Semana 3 a partir de código, demos, pruebas y una defensa escrita breve.

La meta es distinguir con claridad qué cambia cuando pasamos de representaciones contiguas a representaciones enlazadas, por qué en una lista enlazada el acceso importante deja de ser por rango y pasa a ser por posición o enlace, cómo una `SLList` implementa muy bien operaciones de `Stack` y `Queue`, cómo una `DLList` con nodo centinela simplifica inserciones y eliminaciones, y por qué una `SEList` ofrece un trade-off entre acceso, actualización local y uso de espacio.

Además, se busca conectar las implementaciones enlazadas de Morin con la interfaz y operaciones de lista reforzadas por Deng, incluyendo el uso de `DengList` y `MorinDengBridge` para reutilizar operaciones como ordenamiento, eliminación de duplicados y reversa sin reescribir toda la lógica estructural.

#### Material de trabajo

##### Código de la semana
- `Semana3/README.md`
- `Semana3/include/SLList.h`
- `Semana3/include/DLList.h`
- `Semana3/include/SEList.h`
- `Semana3/include/ArrayDeque.h`
- `Semana3/include/array.h`
- `Semana3/include/LinkedStack.h`
- `Semana3/include/LinkedQueue.h`
- `Semana3/include/LinkedDeque.h`
- `Semana3/include/MinStack.h`
- `Semana3/include/MinQueue.h`
- `Semana3/include/MinDeque.h`
- `Semana3/include/XorList.h`
- `Semana3/include/CleanList.h`
- `Semana3/include/DengList.h`
- `Semana3/include/MorinDengBridge.h`
- `Semana3/include/Capitulo3.h`
- `Semana3/demos/demo_sllist.cpp`
- `Semana3/demos/demo_dllist.cpp`
- `Semana3/demos/demo_selist.cpp`
- `Semana3/demos/demo_deng_list.cpp`
- `Semana3/demos/demo_morin_deng_bridge.cpp`
- `Semana3/demos/demo_capitulo3_panorama.cpp`
- `Semana3/demos/demo_min_structures.cpp`
- `Semana3/demos/demo_xor_list.cpp`
- `Semana3/demos/demo_linked_adapters.cpp`
- `Semana3/demos/demo_contiguous_vs_linked.cpp`
- `Semana3/pruebas_publicas/README.md`
- `Semana3/pruebas_publicas/test_public_week3.cpp`
- `Semana3/pruebas_publicas/test_public_deng_bridge.cpp`
- `Semana3/pruebas_publicas/test_public_extras.cpp`
- `Semana3/pruebas_publicas/test_public_linked_adapters.cpp`
- `Semana3/pruebas_publicas/test_public_contiguous_vs_linked.cpp`
- `Semana3/pruebas_internas/test_internal_week3.cpp`
- `Semana3/pruebas_internas/test_internal_deng_algorithms.cpp`
- `Semana3/pruebas_internas/test_internal_extras.cpp`
- `Semana3/pruebas_internas/stress_selist_week3.cpp`
- `Semana3/sustentacion/preguntas_semana3.md`
- `Semana3/sustentacion/rubrica_semana3.md`
- `Semana3/benchmarks/benchmark_semana3.cpp`

#### Lecturas obligatorias

- `Parte3-Deng.pdf`
- `Parte3-Morin.pdf`

#### Bloque 0 - Instalación y preparación

1. Dejen lista su carpeta de trabajo.
2. Verifiquen que pueden abrir `Semana3`, las lecturas y el archivo de entrega.
3. Creen el archivo `Actividad3-CC232.md`.
4. Anoten los nombres de los integrantes.
5. Compilen y ejecuten al menos una demo y una prueba pública de Semana 3.

#### Bloque 1 - Núcleo conceptual de la semana

Revisen:

- `Semana3/README.md`
- `Parte3-Deng.pdf`
- `Parte3-Morin.pdf`
- `Semana3/include/SLList.h`
- `Semana3/include/DLList.h`
- `Semana3/include/SEList.h`
- `Semana3/include/DengList.h`
- `Semana3/include/MorinDengBridge.h`

Respondan:

1. Expliquen con sus palabras qué cambia cuando una estructura pasa de almacenamiento contiguo a almacenamiento dinámico.

Se pierde el acceso directo , ya no puedes "saltar" a una posición(el contiguo); debes "navegar" la estructura siguiendo el rastro de enlaces desde el inicio y ganas la libertad de que la estructura crezca o se encoja orgánicamente(el dinamico).

2. Expliquen la diferencia entre acceso por rango y acceso por posición o enlace.

Acceso por posición (ligado a memoria contigua): Es un mecanismo de acceso directo. Al conocer el índice, el sistema calcula su dirección exacta en memoria en tiempo constante O(1).

Acceso por enlace (ligado a memoria dinámica): Es un mecanismo de recorrido secuencial. Estás obligado a empezar desde el primer nodo (la cabeza) y seguir la cadena de referencias de uno en uno. El tiempo de acceso depende directamente de qué tan lejos esté en la secuencia.

3. Expliquen por qué una lista enlazada mejora inserciones y eliminaciones locales, pero empeora el acceso por índice.

Empeora el acceso por índice porque los nodos están dispersos y conectados por referencias, la computadora es ciega a la estructura global. Para leer el índice i, forzosamente debe recorrer secuencialmente todos los nodos anteriores, lo que eleva el costo de acceso a una complejidad de tiempo O(n).

Insertar o eliminar solo requiere "romper" y "reconectar" un par de referencias (punteros) entre los nodos vecinos. En contraste, en una estructura contigua (como un vector), insertar un dato en el medio obliga a desplazar físicamente todos los elementos posteriores hacia la derecha lo cual es costoso.

4. Expliquen por qué `SLList` implementa bien operaciones de `Stack` y `Queue`.

Una lista enlazada simple (SLList) incluye no solo un puntero head (cabeza), sino también un puntero tail (cola).

Para un Stack (LIFO): Las operaciones ocurren en un solo extremo. En SLList, push(x) inserta un nuevo nodo al inicio (apuntando al antiguo head) y pop() elimina el head actual, actualizándolo al siguiente nodo.

Para una Queue (FIFO): La operación de encolar (add(x)) se hace en tiempo O(1) simplemente conectando el nuevo nodo a tail->next y actualizando el tail. 

5. Expliquen por qué `SLList` no implementa naturalmente todas las operaciones de un `Deque` con el mismo costo.

Un Deque (Double-Ended Queue) exige que las operaciones de inserción y eliminación en ambos extremos tengan una complejidad de O(1).

Mientras que SLList puede insertar al final en O(1) (gracias al tail), eliminar en el final (pop_back) le resulta costoso. Dado que los enlaces son unidireccionales (solo apuntan a next), para eliminar el último nodo necesitarias conocer cuál es el penúltimo nodo. La única forma es recorrerla secuencialmente desde el head hasta el final, lo que degrada el costo de eliminación al final a O(n).

6. Expliquen qué aporta el nodo centinela `dummy` en `DLList`.

El nodo centinela (dummy) en la implementación de ods::DLList aporta simetría estructural y eliminación de casos borde (edge cases).

En lugar de usar punteros nulos para representar el inicio o el fin, dummy es un nodo circular donde dummy.next actúa como el head y dummy.prev como el tail lógico. Cuando la lista está vacía, dummy se apunta a sí mismo.
Esto simplifica ya que no es necesario escribir condicionales como if (head == nullptr) o if (u->next != nullptr).

7. Expliquen por qué `DLList` permite justificar `get(i)`, `set(i,x)`, `add(i,x)` y `remove(i)` con costo `O(1 + min(i, n-i))`.

En el método getNode(i), la lista no empieza a recorrer desde el principio siempre sino que evalúa la condición if (i < n / 2).

Si el índice buscado está en la primera mitad de la lista, recorre hacia adelante desde el inicio (dummy.next). En este caso, dará i pasos.

Si el índice está en la segunda mitad, recorre hacia atrás desde el final (dummy.prev). En este caso, dará n - i pasos.

El algoritmo siempre elige el camino más corto. Por tanto, el número máximo de pasos que dará es el min(i, n - i). El +1 constante representa las operaciones locales de desenlace o actualización de valores una vez que se llega al nodo.

8. Expliquen cuál es la idea espacial central de `SEList`.

La idea central de la SEList es reducir el desperdicio de memoria y mejorar la localidad espacial (cache locality).
En una lista doble tradicional (DLList), por cada elemento almacenado se gastan dos punteros extra (next y prev). La SEList soluciona esto agrupando múltiples elementos dentro de un solo nodo (una lista desenrollada o unrolled linked list). Cada nodo contiene un pequeño bloque contiguo. De este modo, los punteros next y prev van a cada bloque de elementos, amortizando drásticamente el consumo de memoria dinámica.

9. Expliquen por qué `SEList` reutiliza una `BDeque` basada en `ArrayDeque`.

Dentro de cada nodo de la SEList, los elementos se almacenan en una BDeque (Block Deque), la cual hereda de ArrayDeque.

Un ArrayDeque funciona como un arreglo circular. Esto es crucial porque, cuando la SEList inserta o elimina elementos, a menudo necesita reacomodar los datos hacia otros nodos (operaciones internas spread y gather). Al ser un ArrayDeque, el bloque permite añadir o retirar elementos por cualquiera de sus dos extremos en tiempo O(1) sin tener que desplazar físicamente todos los elementos internos.

10. Expliquen qué papel cumple `DengList` dentro de esta semana y por qué no reemplaza a las estructuras de Morin.

Las estructuras de Pat Morin (ods::DLList, ods::SEList) están diseñadas con un enfoque minimalista: se limitan exclusivamente a retener datos y proveer operaciones de acceso y mutación elementales (CRUD) con alta eficiencia.

Por el contrario, DengList representa un enfoque académico más algorítmico. Expone métodos complejos como sort(), dedup(), uniquify(), y reverse().

#### Bloque 2 - Demostración y trazado guiado

Revisen:

- `Semana3/demos/demo_sllist.cpp`
- `Semana3/demos/demo_dllist.cpp`
- `Semana3/demos/demo_selist.cpp`
- `Semana3/demos/demo_deng_list.cpp`
- `Semana3/demos/demo_morin_deng_bridge.cpp`
- `Semana3/demos/demo_capitulo3_panorama.cpp`
- `Semana3/demos/demo_min_structures.cpp`
- `Semana3/demos/demo_xor_list.cpp`
- `Semana3/demos/demo_linked_adapters.cpp`
- `Semana3/demos/demo_contiguous_vs_linked.cpp`

Construyan una tabla con cuatro columnas:

- Archivo
- Salida u observable importante
- Idea estructural
- Argumento de costo, espacio o diseño


| Archivo | Salida u observable importante | Idea estructural | Argumento de costo, espacio o diseño |
| :--- | :--- | :--- | :--- |
| `demo_sllist.cpp` | `size = 3`, `peek = 5`, `pop = 5`, `remove = 10` | Lista simplemente enlazada con punteros `head` y `tail`. | Operaciones en extremos (Pila/Cola) con costo $O(1)$. No apta para borrado al final $O(N)$. |
| `demo_dllist.cpp` | `DLList: 10 20 30` | Lista doblemente enlazada con nodo centinela (`dummy`). | Navegación bidireccional en $O(1 + \min(i, n-i))$. El centinela elimina *edge cases*. |
| `demo_selist.cpp` | `SEList: 0 10 20 ... 90` | Nodos enlazados que contienen bloques contiguos (`BDeque`). | Reduce el *overhead* de punteros (ahorro espacial) y mejora la localidad de caché. |
| `demo_deng_list.cpp` | `ordenada: 5 10 20 30` | *Wrapper* o fachada que encapsula una lista para algoritmos complejos. | Abstracción de alto nivel enfocada en utilidad (ADT completo) más que en estructura base. |
| `demo_morin_deng_bridge.cpp` | `DLList reforzada... 1 2 3 4` | Patrón adaptador temporal (Puente) entre librerías. | Reutilización de código (DRY). Permite ordenar una `DLList` minimalista sin modificar su fuente. |
| `demo_min_structures.cpp` | `MinStack min=3 top=7` | Aumento de estructura con metadatos (pila/cola monótona). | Intercambia memoria adicional para lograr consulta de mínimo en tiempo constante $O(1)$. |
| `demo_linked_adapters.cpp` | Operaciones estrictas de Stack/Queue. | Adaptador de interfaz que restringe una estructura base. | Diseño seguro. Previene violaciones de política (LIFO/FIFO) ocultando métodos de acceso aleatorio. |
| `demo_contiguous_vs_linked.cpp` | Comparación de `get(4)` entre `ArrayDeque` y `DLList`. | Contraste entre memoria contigua (índices) y dinámica (enlaces). | *Trade-off*: Contiguo gana en acceso $O(1)$ y caché; Enlazado en mutación local sin desplazar memoria. |

Luego respondan:

1. En `demo_sllist.cpp`, ¿qué secuencia deja más clara la coexistencia de comportamiento tipo pila y tipo cola dentro de `SLList`?

La secuencia donde primero se inserta al final usando q.add(10) y q.add(20) (FIFO) y luego se inserta al inicio usando q.push(5) (LIFO). La estructura soporta ambas gracias a sus punteros head y tail.

2. En `demo_dllist.cpp`, ¿qué operación muestra mejor la inserción en una posición intermedia?

La ejecución de d.add(1, 20). Previamente se insertó el 10 en el índice 0 y el 30 en el índice 1. Al insertar el 20 en el índice 1, la estructura esta en el punto medio y reconecta los punteros adyacentes, desplazando el 30 sin tener que mover toda la memoria.

3. En `demo_selist.cpp`, ¿qué observable permite defender que la lista mantiene orden lógico aunque internamente trabaje por bloques?

El bucle de impresión final imprime la secuencia: 0 10 20 ... 90. Para el usuario, la estructura se comporta exactamente como una secuencia lineal. El usuario no se entera de que internamente los valores están saltando entre distintos BDeque de tamaño 3.

4. En `demo_deng_list.cpp`, ¿qué evidencia muestra que la lista reforzada por Deng ofrece operaciones más cercanas a un ADT de lista completo?

El uso directo del método lista.sort(), las estructuras minimalistas de Open Data Structures (ods) solo guardan y sacan datos. DengList asume la responsabilidad de proveer algoritmos de transformación (ordenamiento, desduplicación), comportándose como un ADT.

5. En `demo_morin_deng_bridge.cpp`, ¿qué parte de la salida permite justificar que se reutilizan algoritmos sin reescribir la estructura base?

El hecho de que logramos imprimir una DLList (estructura de Morin) totalmente ordenada y sin duplicados (1 2 3 4). Esto fue mediante funciones como stable_sort_with_deng(lista), las cuales transforman temporalmente la DLList en una DengList, la ordenan con la lógica de Deng, y la devuelven.

6. En `demo_min_structures.cpp`, ¿qué diferencia conceptual observan entre almacenar valores y almacenar información adicional para responder `min()`?

Almacenar valores representa guardar la secuencia de datos real del problema. Almacenar información adicional para responder min() representa guardar metadatos de estado operativo. Requiere mantener una estructura secundaria paralela que rastree el mínimo histórico en cada momento, pagando costo espacial para ganar velocidad de consulta.

7. En `demo_linked_adapters.cpp`, ¿qué adaptador representa mejor la idea de reutilizar una estructura existente para ofrecer una interfaz nueva?

Los tres lo hacen LinkedStack, LinkedQueue, LinkedDeque. Un adaptador toma una clase flexible y restringe sus capacidades para ofrecer una interfaz estricta ej: LinkedStack solo te deja usar push, pop y top.

8. En `demo_contiguous_vs_linked.cpp`, ¿qué contraste se observa entre acceso por índice, inserción local y localidad de memoria?

El ArrayDeque gana en el acceso por índice (get(4)) porque calcula la posición matemáticamente en O(1) y aprovecha la caché del procesador (localidad de memoria). Sin embargo, sufre al insertar en medio porque debe desplazar datos.

La DLList (enlazada) no tiene localidad de memoria (los nodos están dispersos) y debe recorrerse secuencialmente para el get(4). Pero es mejor en inserción local: una vez hallado el lugar, reconectar punteros es rapido sin desplazar bloques de memoria.

#### Bloque 3 - Pruebas públicas, stress y correctitud

Revisen:

- `Semana3/pruebas_publicas/README.md`
- `Semana3/pruebas_publicas/test_public_week3.cpp`
- `Semana3/pruebas_publicas/test_public_deng_bridge.cpp`
- `Semana3/pruebas_publicas/test_public_extras.cpp`
- `Semana3/pruebas_publicas/test_public_linked_adapters.cpp`
- `Semana3/pruebas_publicas/test_public_contiguous_vs_linked.cpp`
- `Semana3/pruebas_internas/test_internal_week3.cpp`
- `Semana3/pruebas_internas/test_internal_deng_algorithms.cpp`
- `Semana3/pruebas_internas/test_internal_extras.cpp`
- `Semana3/pruebas_internas/stress_selist_week3.cpp`

Respondan:

1. ¿Qué operaciones mínimas valida la prueba pública para `SLList`?
2. ¿Qué operaciones mínimas valida la prueba pública para `DLList`?
3. ¿Qué operaciones mínimas valida la prueba pública para `SEList`?
4. ¿Qué operaciones nuevas quedan cubiertas por `test_public_extras.cpp`?
5. ¿Qué valida específicamente `test_public_linked_adapters.cpp` sobre `LinkedStack`, `LinkedQueue` y `LinkedDeque`?
6. ¿Qué demuestra `test_public_deng_bridge.cpp` sobre integración y reutilización?
7. En `stress_selist_week3.cpp`, ¿qué comportamiento intenta estresar sobre crecimiento, borrado y mantenimiento del tamaño lógico?
8. ¿Qué sí demuestra una prueba pública sobre una estructura enlazada?
9. ¿Qué no demuestra una prueba pública por sí sola?
10. ¿Por qué pasar pruebas no reemplaza una explicación de invariantes, punteros y complejidad?

#### Bloque 4 - SLList, DLList y SEList: lectura cercana del código

Revisen:

- `Semana3/include/SLList.h`
- `Semana3/include/DLList.h`
- `Semana3/include/SEList.h`
- `Parte3-Morin.pdf`
- `Parte3-Deng.pdf`

Respondan:

1. En `SLList`, ¿qué papel cumplen `head`, `tail` y `n`?
2. En `SLList::push`, `pop`, `add` y `remove`, ¿qué punteros cambian exactamente?
3. Expliquen cómo funciona `secondLast()` y por qué no puede resolverse directamente con solo mirar `tail`.
4. Expliquen paso a paso cómo funciona `reverse()` y por qué no necesita estructura auxiliar.
5. Expliquen qué verifica `checkSize()` y por qué esta función ayuda a defender correctitud.
6. En `DLList`, expliquen por qué `getNode(i)` puede empezar desde el inicio o desde el final.
7. En `DLList::addBefore`, ¿qué enlaces se actualizan y por qué el nodo centinela elimina casos borde?
8. Expliquen cómo funciona `rotate(r)` sin mover los datos elemento por elemento.
9. Expliquen cómo `isPalindrome()` aprovecha la naturaleza doblemente enlazada de la estructura.
10. En `SEList`, expliquen qué representa `Location`.
11. Expliquen qué hacen `spread()` y `gather()` y en qué situaciones aparecen.
12. Expliquen cómo el tamaño de bloque `b` afecta el trade-off entre acceso, actualización y uso de espacio.

#### Bloque 5 - Adaptadores y estructuras derivadas

Revisen:

- `Semana3/include/LinkedStack.h`
- `Semana3/include/LinkedQueue.h`
- `Semana3/include/LinkedDeque.h`
- `Semana3/include/MinStack.h`
- `Semana3/include/MinQueue.h`
- `Semana3/include/MinDeque.h`
- `Semana3/demos/demo_linked_adapters.cpp`
- `Semana3/demos/demo_min_structures.cpp`

Respondan:

1. ¿Cómo reutiliza `LinkedStack` a `SLList`?
2. ¿Cómo reutiliza `LinkedQueue` a `SLList`?
3. ¿Por qué `LinkedDeque` se construye naturalmente sobre `DLList` y no sobre `SLList`?
4. En `MinStack`, ¿por qué cada entrada guarda el valor y el mínimo acumulado?
5. En `MinQueue`, ¿por qué usar dos pilas permite mantener semántica FIFO y consulta de mínimo?
6. En `MinDeque`, ¿qué problema resuelve el rebalanceo entre `front_` y `back_`?
7. Comparen "implementar una estructura" y "adaptar una estructura existente" usando ejemplos de este bloque.
8. ¿Qué operaciones pueden defender como constantes y cuáles deben defender como amortizadas?

#### Bloque 6 - Deng como refuerzo algorítmico y puente de integración

Revisen:

- `Semana3/include/CleanList.h`
- `Semana3/include/DengList.h`
- `Semana3/include/MorinDengBridge.h`
- `Semana3/demos/demo_deng_list.cpp`
- `Semana3/demos/demo_morin_deng_bridge.cpp`
- `Semana3/pruebas_publicas/test_public_deng_bridge.cpp`
- `Semana3/pruebas_internas/test_internal_deng_algorithms.cpp`
- `Parte3-Deng.pdf`

Respondan:

1. ¿Qué operaciones del ADT de lista aparecen reforzadas en `DengList`?
2. ¿Qué ventaja tiene encapsular una lista más rica sin cambiar el resto de estructuras de Semana 3?
3. Expliquen qué hacen `to_deng` y `assign_from_deng`.
4. Expliquen por qué `stable_sort_with_deng` no obliga a reimplementar ordenamiento dentro de `DLList` o `SEList`.
5. Expliquen qué hace `dedup_with_deng` y qué relación guarda con `deduplicate()` o `uniquify()` de la teoría.
6. Expliquen por qué `reverse_with_deng` es un ejemplo de reutilización de algoritmos sobre una interfaz común.
7. ¿Qué costo adicional introduce la conversión entre estructuras y cuándo vale la pena aceptarlo?

#### Bloque 7 - Comparación enlazado vs contiguo, variantes y evidencia experimental

Revisen:

- `Semana3/include/ArrayDeque.h`
- `Semana3/include/XorList.h`
- `Semana3/demos/demo_contiguous_vs_linked.cpp`
- `Semana3/demos/demo_xor_list.cpp`
- `Semana3/benchmarks/benchmark_semana3.cpp`
- `Parte3-Morin.pdf`

Respondan:

1. Comparen `ArrayDeque` y `LinkedDeque`: ¿qué cambia en representación y qué cambia en costo observable?
2. ¿Qué significa que una representación contigua tenga mejor localidad de memoria?
3. ¿Qué tipo de operaciones favorecen más a la representación enlazada?
4. En el benchmark, ¿qué comparación sirve mejor para discutir acceso aleatorio y cuál sirve mejor para discutir operaciones en extremos?
5. ¿Por qué el benchmark no debe leerse como prueba absoluta de superioridad de una estructura sobre otra?
6. ¿Qué idea intenta mostrar `XorList` respecto al ahorro de punteros?
7. ¿Qué desventaja práctica introduce una estructura como `XorList` aunque sea interesante desde el punto de vista del espacio?.

#### Bloque 8 - Cierre comparativo y preparación de sustentación

Respondan esta pregunta final:

¿Qué cambia cuando pasamos de "usar arreglos dinámicos" a "diseñar estructuras enlazadas y adaptadores sobre nodos"?

La respuesta debe incluir obligatoriamente:

- Una afirmación sobre representación
- Una afirmación sobre acceso por rango frente a acceso por posición
- Una afirmación sobre inserciones y eliminaciones locales
- Una afirmación sobre complejidad de `SLList`, `DLList` y `SEList`
- Una afirmación sobre reutilización mediante adaptadores o puentes
- Una comparación entre representación contigua y enlazada.

#### Formato sugerido de entrega

    ## Actividad 3-CC232

    ### Integrantes
    - Nombre 1
    - Nombre 2

    #### Bloque 1
    (respuestas)

    #### Bloque 2
    (tabla y respuestas)

    #### Bloque 3
    (respuestas)

    #### Bloque 4
    (respuestas)

    #### Bloque 5
    (respuestas)

    #### Bloque 6
    (respuestas)

    #### Bloque 7
    (respuestas)

    #### Bloque 8
    (respuesta final)

    #### Autoevaluación breve
    - Qué podemos defender con seguridad:
    - Qué todavía confundimos:
    - Qué evidencia usaríamos en una sustentación:

#### Criterio general de trabajo

Se espera lectura real de los archivos, respuestas breves pero justificadas, y conexión explícita entre código, correctitud, costo, representación, punteros, invariantes y reutilización.

No basta con ejecutar el programa: deben poder explicar por qué funciona, qué punteros se actualizan, qué invariante mantiene cada estructura y qué costo justifica su diseño.
