# Actividad 8 - CC232

## Bloque 1 - Diagnóstico inicial de la Semana 8

1. ¿Qué targets de demostración aparecen para Semana 8?

Aparecen 8 targets: sem8_demo_chained, sem8_demo_linear, sem8_demo_hashtable_oa, sem8_demo_aplicaciones, sem8_demo_collision_strategies, sem8_demo_hash_functions, sem8_demo_tombstones y sem8_demo_benchmark_load_factor.

2. ¿Qué pruebas públicas e internas aparecen?

Públicas: semana8_public.

Internas: semana8_internal, semana8_tombstones, semana8_collision_patterns, semana8_rehashing y semana8_randomized_against_stl.

3. ¿Qué archivos incluye `Capitulo9.h`?

Incluye cabeceras Applications.h, ArrayStack.h, Bitmap.h, ChainedHashTable.h, Dictionary.h, DoubleHashTable.h, Entry.h, HashCode.h, HashStats.h, HashtableOA.h, LinearHashTable.h, PrimeUtils.h, QuadraticHashTable.h, RehashPolicy.h, RobinHoodHashTable.h, UniversalHash.h y array.h.

4. ¿Qué relación conceptual hay entre Semana 5, Semana 6, Semana 7 y Semana 8?

Las Semanas 5, 6 y 7 usan enfoques basados en árboles donde los elementos se ordenan jerárquicamente mediante comparaciones. La Semana 8 rompe el esquema de comparaciones e introduce el Hasheo, logrando acceso directo mediante funciones matemáticas(problemas de diccionario).

5. ¿Por qué no es correcto decir que una tabla hash siempre tiene costo `O(1)` garantizado?

Porque el costo $O(1)$ es un escenario promedio y no una garantía estricta de peor caso. Si ocurren demasiadas colisiones (debido a una mala función de hash) o si el factor de carga es muy alto, la complejidad se degrada a un costo lineal $O(n)$.

6. ¿Qué evidencia inicial obtuviste al ejecutar las pruebas sin modificar nada?

La evidencia es un éxito rotundo del 100%. Los 6 tests asignados a la suite de la semana pasaron limpiamente (Passed) en un tiempo real de ejecución extremadamente bajo de 0.03 segundos, indicando que la base inicial del repositorio es estable.

7. ¿Qué diferencia práctica hay entre compilar todo el proyecto y compilar solo los targets de Semana 8?.

Compilar todo el proyecto compila múltiples sub-módulos ajenos (Semanas previas), lo que consume más tiempo y ciclos de CPU. Compilar los targets de la Semana 8 reduce drásticamente el alcance del flujo de construcción a los ejecutables definidos en el sub-directorio actual.

Entrega en este bloque:

* Una tabla con comando ejecutado, resultado, error si hubo e interpretación.

| Comando Ejecutado | Resultado | Error detectado | Interpretación |
| :--- | :--- | :--- | :--- |
| `cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug` | Configuración exitosa, archivos de construcción generados en `build-debug`. | Ninguno | El entorno detectó correctamente el compilador GCC 13.3.0 y preparó las dependencias de CMake para la compilación. |
| `cmake --build build-debug` | Compilación exitosa de 8 demos y 6 ejecutables de pruebas unitarias. Targets al 100%. | Ninguno | Todos los archivos de código fuente y cabeceras de tablas hash compilaron sin errores de sintaxis ni enlazado. |
| `ctest --test-dir build-debug -R semana8 --output-on-failure` | **100% tests passed** (6 de 6 pruebas superadas en 0.03 segundos). | Ninguno | El sistema de pruebas corroboró que las operaciones públicas e internas de hasheo funcionan perfectamente bajo las aserciones actuales. |

* Una lista breve de los archivos que revisaste primero.

Semana8/CMakeLists.txt (Para mapear la estructura de ejecutables, demos y definiciones de tests).

Semana8/include/Capitulo9.h (Para conocer las dependencias, componentes de dispersión y colisión integrados).

Semana8/README.md (Para entender la guía de actividades y el contexto teórico de la semana).

* Una conclusión inicial de máximo 8 líneas sobre el estado de la semana.

El entorno de la Semana 8 se encuentra en un estado inicial completamente limpio para el desarrollo. Toda la infraestructura de compilación está en CMake, y los archivos cabecera se acoplan limpiamente sin reportar fallos. El paso exitoso del 100% de los tests iniciales confirma la robustez funcional del esqueleto del código.

## Bloque 2 - Núcleo conceptual de hashing y diccionarios

1. Define con precisión qué es un diccionario abstracto.

Es un Tipo Abstracto de Datos que representa una colección mutable de asociaciones clave-valor, donde cada clave es única. Provee un mapeo unidireccional y eficiente para la inserción, búsqueda y eliminación.

2. Explica la diferencia entre diccionario, mapa, conjunto y tabla hash.

Diccionario: Es la interfaz abstracta pura.

Mapa: Es un sinónimo práctico de diccionario en muchas librerías.

Conjunto: Es una variante del diccionario que solo almacena claves únicas sin valores asociados.

Tabla Hash: Es una estructura de datos física e implementación concreta que usa funciones matemáticas e indexación sobre arreglos para resolver el TAD Diccionario.

3. Explica qué representa un `Entry<K,V>`.

Representa un par ordenado que empaqueta físicamente una clave y su valor asociado dentro de una sola celda en la estructura.

4. Explica qué hace una función hash.

Toma un elemento de un universo y lo transforma en un número entero de tamaño fijo. Este valor se reduce para transformarlo en un índice válido de un arreglo.

5. Explica por qué pueden existir colisiones aunque la función hash sea razonable.

El universo de claves posibles es mayor que el tamaño de almacenamiento (m). Por pura restricción matemática, múltiples claves distintas inevitablemente generarán el mismo índice de destino.

6. Explica qué significa factor de carga.

Es la relación aritmética entre la cantidad de elementos en la tabla y su capacidad total.

7. Explica qué significa rehashing.

Es el proceso estructural de crear un nuevo arreglo, recalcular el hash de cada clave activa presente y reinsertarla. Se gatilla para reducir las colisiones y restablecer la eficiencia cuando la tabla se llena o acumula demasiadas bajas.

8. Explica qué mide `HashStats`.

Registra el total de inserciones, búsquedas exitosas y fallidas, remociones, conteo de colisiones, cantidad de saltos de sondeo, rehashings totales ejecutados y la acumulación de marcas de borrado.

9. Explica qué decide `RehashPolicy`.

Establece los umbrales de tolerancia (máximos y mínimos) para decidir cuándo la tabla hash debe expandir su memoria (shouldGrow), encogerse (shouldShrink) o limpiar los registros eliminados perezosamente (shouldCleanOrGrow).

10. Compara el costo esperado de una tabla hash con el costo garantizado de AVL y Red-Black Tree.

La tabla hash ofrece un costo esperado (promedio) de O(1) para buscar, insertar y borrar, pero en el peor caso colapsa a un costo lineal de O(n). Los árboles balanceados garantizan que en el peor caso sea O(logn).

Entrega en este bloque:

* Una tabla conceptual con las columnas: concepto, definición, archivo relacionado y ejemplo.

| Concepto | Definición | Archivo Relacionado | Ejemplo |
| :--- | :--- | :--- | :--- |
| Diccionario | Interfaz abstracta para gestionar pares clave-valor únicos. | `Dictionary.h` | Un padrón electoral donde buscas los datos de un ciudadano mediante su DNI. |
| Entrada | Estructura que empaqueta físicamente una clave y su valor asociado. | `Entry.h` | El registro `{ "codigo_23", "Juan Pérez" }` guardado en memoria. |
| Dispersión | Transformación matemática de un objeto en un índice numérico de arreglo. | `HashCode.h` | Pasar el string `"hola"` por `mix64` para obtener el entero `14695981039...`. |
| Estadísticas | Contador dinámico de rendimiento de operaciones y colisiones. | `HashStats.h` | Registrar que se hicieron 4 evaluaciones de celdas antes de hallar una clave. |
| Política de Rehash| Estrategia de control de límites de carga para redimensionamiento. | `RehashPolicy.h` | Decidir duplicar el arreglo cuando el 70% de las celdas estén ocupadas. |

* Una explicación de máximo 12 líneas sobre por qué hashing no reemplaza completamente a los árboles balanceados.

El hashing destruye por completo el orden de los datos. Al distribuir los elementos de manera seudoaleatoria mediante funciones matemáticas, se pierde la relación de vecindad entre claves. Operaciones críticas como encontrar el elemento mínimo o máximo, imprimir los datos en orden alfabético o numérico (inorder), o realizar búsquedas por rangos se vuelven extremadamente costosas en una tabla hash, requiriendo un escaneo lineal completo $O(n)$ de todo el arreglo.

## Bloque 3 - Chaining: buckets, colisiones y longitud máxima

1. ¿Qué diferencia hay entre el arreglo principal y los buckets?

El arreglo principal (table_) es un contenedor contiguo y estático indexable en tiempo constante $O(1)$ y los buckets son subestructuras dinámicas e independientes para almacenar los datos colisionantes.

2. ¿Por qué chaining puede almacenar más elementos que la cantidad de posiciones del arreglo principal?

Porque los elementos no compiten por el espacio físico de las celdas del arreglo principal. Al estar encadenados externamente, el arreglo solo guarda referencias a las listas, permitiendo un factor de carga $\alpha > 1.0$.

3. ¿Qué significa que un bucket crezca demasiado?

Significa que la función hash asignó un número desproporcionado de claves al mismo índice.

4. ¿Por qué `longestBucket()` es una métrica importante?

Mide la severidad del peor caso local. Revela si la dispersión de datos es uniforme o si existe un cuello de botella que ralentizará dramáticamente las búsquedas puntuales dentro de esa cubeta específica.

5. ¿En qué caso la búsqueda en chaining deja de parecerse a `O(1)` 
esperado?

Cuando todas o la gran mayoría de las claves mapean a un número muy reducido de cubetas.

6. ¿Qué costo tiene recorrer un bucket de longitud `k`?

Un costo lineal estricto de $O(k)$ comparaciones, se inspeccionara secuencialmente cada uno de los elementos contenidos en el ArrayStack.

7. ¿Qué parte del costo depende de la función hash y qué parte depende de la distribución de claves?.

La función hash define la aleatoriedad matemática pura del mapeo inicial.

La distribución de claves define la naturaleza de los datos de entrada. 

Entrega en este bloque:

* Salida relevante de `demo_chained.cpp`.
```
ChainedHashTable
size=6 capacity=17 load=0.352941 longestBucket=2
contains(26)=1 contains(99)=0
insertions=6, successfulSearches=1, failedSearches=1, removals=0, collisions=4, totalProbes=14, maxProbeLength=3, averageProbeLength=1.75, rehashes=1, tombstones=0
```
* Tabla de operaciones.

| Operación | Clave | Bucket Inicial ($h(x) \bmod 8$) | Bucket Post-Rehash ($h(x) \bmod 17$) | Tam. Antes | Tam. Después | Colisión | `loadFactor()` | `longestBucket()` |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| `add` | $c_1$ | $idx_1$ | - | 0 | 1 | No | 0.125 | 1 |
| `add` | $c_2$ | $idx_2$ | - | 0 | 1 | No | 0.250 | 1 |
| `add` | $c_3$ | $idx_3$ | - | 0 | 1 | No | 0.375 | 1 |
| `add` | $c_4$ | $idx_4$ | - | 0 | 1 | No | 0.500 | 1 |
| `add` | $c_5$ | $idx_5$ | - | 1 | 2 | **Sí** | 0.625 | 2 |
| `add` | $c_6$ | *Dispara Rehash* | $idx_{new}$ | 0 | 1 | **Sí** (acum.)| 0.353 | 2 |
| `contains`| 26 | - | $idx_{26}$ | 2 | 2 | No | 0.353 | 2 |
| `contains`| 99 | - | $idx_{99}$ | 1 | 1 | No | 0.353 | 2 |

* Dibujo de una tabla hash con al menos 8 buckets y 10 claves.

Arreglo Principal (table)
[ Índice ] -> [ Bucket Externo]
  [ 0 ]    -> [ Vacío ]
  [ 1 ]    -> [ Clave A ] -> [ Clave B ]
  [ 2 ]    -> [ Clave C ]
  [ 3 ]    -> [ Vacío]
  [ 4 ]    -> [ Clave D ] -> [ Clave E ] -> [ Clave F ]  <- Bucket (k=3)
  [ 5 ]    -> [ Clave G ]
  [ 6 ]    -> [ Clave H ] -> [ Clave I ]
  [ 7 ]    -> [ Clave J ]

* Explicación breve de costo esperado y peor caso.

Costo Esperado ($O(1)$): Bajo la suposición de hashing uniforme simple, las claves se distribuyen equitativamente entre las $m$ cubetas. El tamaño promedio de cada lista es el factor de carga $\alpha = n/m$. Manteniendo un $\alpha \le 0.70$ mediante políticas de redimensionamiento, inspeccionar una cubeta toma un número constante y pequeño de pasos.

Peor Caso ($O(n)$): Ocurre si la función hash es defectuosa o si un atacante introduce claves diseñadas maliciosamente para generar exactamente el mismo índice. Las $n$ claves terminan amontonadas en una única lista, transformando el acceso directo en una búsqueda lineal exhaustiva.

## Bloque 4 - Colisiones controladas sin asumir hash de identidad

Revisa:

* `Semana8/include/HashCode.h`
* `Semana8/demos/demo_hash_functions.cpp`
* `Semana8/demos/demo_collision_strategies.cpp`

Modifica o crea una demostración auxiliar que busque claves enteras que caigan en el mimso bucket para una capacidad fija `m`. No asumas que `x % m` es el bucket final si antes se aplica una mezcla hash.

Puedes usar una función auxiliar con esta idea:

```cpp
std::vector<int> findCollidingKeys(std::size_t capacity,
                                   std::size_t targetBucket,
                                   std::size_t needed);
```

La función debe probar claves enteras desde `0` hacia adelante y quedarse con las que cumplan:

```cpp
hashCode(x) % capacity == targetBucket
```

Responde:

1. ¿Por qué `0, 8, 16, 24` solo garantiza colisión si la función hash efectiva es `h(x) = x mod m`?

Porque esa secuencia asume que el entero ingresa directamente a la operación aritmética de módulo. Bajo ese esquema lineal e ingenuo, cualquier múltiplo de la capacidad $m$ mapeará idénticamente al índice $0$.

2. ¿Qué ocurre si antes se aplica una mezcla como `hashCode(x)`?

La mezcla rompe la correlación lineal. Aplica corrimientos binarios y multiplicaciones por constantes primas gigantes que dispersan los bits. Provoca que enteros consecutivos o múltiplos regulares terminen en ubicaciones del arreglo completamente impredecibles y distantes.

3. ¿Qué claves encontraste para un mismo bucket con capacidad `8` o `16`?

Para capacidad 8 y cubeta destino 3, las primeras cuatro claves numéricas en colisionar consecutivamente fueron: 0, 6, 12, 17. Nótese que ya no siguen un patrón aritmético simple de +8.

4. ¿Cómo cambia el experimento si usas cadenas en lugar de enteros?

El principio de búsqueda por fuerza bruta es idéntico, pero en lugar de incrementar un contador numérico current++, se deben generar strings de forma combinatoria pasándolos por el hash polinomial de HashCode.h hasta encontrar colisiones de índices compartidos.

5. ¿Por qué este bloque es importante para defender evidencia experimental honesta?.

Porque demuestra rigurosidad matemática en tu sustentación. En lugar de asumir ciegamente la teoría, compruebas que entiendes la arquitectura de tu software interceptando los efectos de la mezcla de bits intermedia antes de evaluar los límites de las cubetas.

Entrega en este bloque:

* Código de la función auxiliar.
```
std::vector<int> findCollidingKeys(std::size_t capacity, std::size_t targetBucket, std::size_t needed) {
    std::vector<int> found;
    int current = 0;
    while (found.size() < needed) {
        if (ods::hashCode(current) % capacity == targetBucket) {
            found.push_back(current);
        }
        current++;
    }
    return found;
}
```
* Lista de claves encontradas.
Para una capacidad fija de m = 17 y buscando colisiones puras en el bucket 3, las primeras cuatro claves enteras consecutivas que saltan la mezcla de bits de mix64 y colisionan son:12, 17, 35, 36.

* Tabla con clave, valor hash normalizado y bucket.

| Clave ($x$) | Valor Hash Producido (`hashCode(x)`) | Bucket Final ($\text{hash} \bmod 17$) |
| :---: | :--- | :---: |
| 12 | $10682531704454680323$ | 3 |
| 17 | $9260656408219841379$ | 3 |
| 35 | $5574532911583637595$ | 3 |
| 36 | $16839827797137734171$ | 3 |

* Evidencia de que esas claves sí producen colisiones en tu ejecución.
```
CLAVES ENCONTRADAS PARA BUCKET: 3

 Clave (x)              hashCode(x)  hashCode(x)%m

        12     10682531704454680323              3
        17      9260656408219841379              3
        35      5574532911583637595              3
        36     16839827797137734171              3

Validando colision en ChainedHashTable (capacidad fija sin rehash)...
Resultado -> Longitud del bucket 3: 4
Estadisticas de colisiones: 3
```

## Bloque 5 - Linear probing: estados, sondeo y tombstones

1. ¿Qué representan los estados `Empty`, `Filled` y `Deleted`?

Empty: La celda está completamente virgen. Detiene inmediatamente cualquier búsqueda.

Filled: La celda contiene un elemento activo válido.

Deleted: La celda tuvo un elemento que fue borrado. Permite almacenar nuevos datos en un add, pero obliga a que un contains continúe el sondeo.

2. ¿Por qué `Deleted` no puede tratarse igual que `Empty`?

Si se tratara como Empty, rompería las secuencias de sondeo previas. Si insertamos A y luego B, al borrar A, una búsqueda posterior de B vería la celda vacía y reportaría erróneamente que B no existe en la tabla.

3. ¿Qué diferencia hay entre `size` y `occupied`?

size cuenta únicamente los elementos activos y recuperables actuales. occupied incluye los activos más todos los registros que quedaron marcados de forma perezosa como Deleted.

4. ¿Por qué `loadFactor()` y `occupiedFactor()` pueden divergir después de muchas eliminaciones?

Porque al remover elementos, size disminuye inmediatamente, mientras que occupied se mantiene intacto porque las celdas retenidas pasan a ser tombstones.

5. ¿Qué problema aparece si se acumulan demasiados tombstones?

Degrada el rendimiento de las búsquedas fallidas y exitosas hacia un costo lineal de O(n), ya que los algoritmos se ven obligados a atravesar interminables cadenas de celdas muertas antes de dar con un hueco verdaderamente Empty.

6. ¿Cuándo debe hacerse rehashing por carga ocupada aunque haya pocos elementos activos?

Cuando occupiedFactor supera el umbral crítico configurado. En este punto, aunque haya pocos elementos activos, la tabla está saturada de lápidas y requiere una purga.

7. ¿Qué costo tiene una búsqueda fallida cuando hay clustering?.

Es proporcional a la longitud total del bloque o conglomerado contiguo de celdas ocupadas/eliminadas.

Entrega en este bloque:

* Salida relevante de `demo_linear.cpp` y `demo_tombstones.cpp`.
```
1. demo_linear:

LinearHashTable
size=5 capacity=8 activeLoad=0.625 occupiedLoad=0.625 tombstones=0
insertions=6, successfulSearches=1, failedSearches=6, removals=1, collisions=1, totalProbes=17, maxProbeLength=4, averageProbeLength=1.21429, rehashes=0, tombstones=0

2.tombstones:

Linear tombstones=4 activeLoad=0.125 occupiedLoad=0.1875
HashtableOA tombstones=4 activeLoad=0.216216 occupiedLoad=0.324324
```
* Trazado manual de al menos una búsqueda exitosa y una búsqueda fallida.

Tomando el estado final de la tabla anterior donde la celda 1 es Deleted:

Búsqueda Exitosa de la clave 31:

Calcula el índice inicial: $\text{idx}(31) = 7$.

Celda 7 es Filled pero no es el elemento $\rightarrow$ salta a next(7) = 0 (Sondeos = 2).

Celda 0 es Filled pero no es el elemento $\rightarrow$ salta a next(0) = 1 (Sondeos = 3).

Celda 1 es Deleted $\rightarrow$ no se detiene, continúa a next(1) = 2 (Sondeos = 4).

Celda 2 es Filled y contiene 31 $\rightarrow$ Éxito. Retorna índice 2.

Búsqueda Fallida de la clave 23 (Eliminada previamente):

Calcula el índice inicial: $\text{idx}(23) = 7$.

Celda 7 es Filled $\rightarrow$ continúa a la celda 0.

Celda 0 es Filled $\rightarrow$ continúa a la celda 1.


Celda 1 es Deleted $\rightarrow$ continúa (si se detuviera aquí fallaría por corte erróneo, ocultando a las claves 31 y 39 que están más adelante).

Celdas 2, 3, 4 son Filled $\rightarrow$ continúa escaneando.

Celda 5 es Empty $\rightarrow$ Fin del bucle. Retorna falso (Búsqueda fallida).

* Explicación de por qué open addressing necesita una política cuidadosa de eliminación.

A diferencia del encadenamiento separado, donde borrar un nodo es una remoción física instantánea de una lista, el direccionamiento abierto comparte el mismo espacio vectorial indexado para todo el ecosistema. Si una tabla no limpia de forma perezosa y cíclica sus lápidas mediante disparadores en su RehashPolicy (shouldCleanOrGrow), la estructura se vuelve víctima de su propio historial operativo.

* Tabla de simulaciones:

| Operación | Clave | Posición hash inicial | Secuencia de sondeo | Estado final de la celda | `size` | `occupied` | `loadFactor()` | `occupiedFactor()` | `tombstoneCount()` |
| :---: | :---: | :---: | :---: | :--- | :---: | :---: | :---: | :---: | :---: |
| **Inicio** | - | - | - | - | 0 | 0 | 0.000 | 0.000 | 0 |
| `add(7)` | 7 | 7 | `[7]` | `Filled` en pos 7 | 1 | 1 | 0.125 | 0.125 | 0 |
| `add(15)` | 15 | 7 | `[7->0]` | `Filled` en pos 0 | 2 | 2 | 0.250 | 0.250 | 0 |
| `add(23)` | 23 | 7 | `[7->0->1]` | `Filled` en pos 1 | 3 | 3 | 0.375 | 0.375 | 0 |
| `add(31)` | 31 | 7 | `[7->0->1->2]` | `Filled` en pos 2 | 4 | 4 | 0.500 | 0.500 | 0 |
| `add(39)` | 39 | 7 | `[7->0->1->2->3]` | `Filled` en pos 3 | 5 | 5 | 0.625 | 0.625 | 0 |
| `remove(23)`| 23 | 7 | `[7->0->1]` | `Deleted` en pos 1 | 4 | 5 | 0.500 | 0.625 | 1 |
| `add(47)` | 47 | 7 | `[7->0->1->2->3->4]`| `Filled` en pos 4 | 5 | 6 | 0.625 | 0.750 | 1 |


#### Bloque 6 - HashtableOA como diccionario `key value`

Revisa:

* `Semana8/include/Dictionary.h`
* `Semana8/include/Entry.h`
* `Semana8/include/HashtableOA.h`
* `Semana8/demos/demo_hashtable_oa.cpp`
* `Semana8/include/Applications.h`

Ejecuta:

```bash
./build-debug/Semana8/sem8_demo_hashtable_oa
```

Responde:

1. ¿Qué diferencia hay entre una tabla usada como conjunto y una tabla usada como diccionario?
2. ¿Qué representa una clave?
3. ¿Qué representa un valor?
4. ¿Qué debe devolver `get(k)` si la clave existe?
5. ¿Qué debe ocurrir con `remove(k)` si la clave no existe?
6. ¿Qué política usa la implementación cuando se intenta insertar una clave repetida?
7. ¿Por qué una interfaz `put`, `get`, `remove` permite separar el uso del diccionario de su implementación interna?.

Entrega en este bloque:

* Una tabla con operaciones `put`, `get`, `remove`, resultado esperado y evidencia observada.
* Un ejemplo `string` a `int` para conteo de frecuencias.
* Una explicación de cómo cambia el diseño si se desea que `put` actualice el valor de una clave ya existente.

#### Bloque 7 - Comparación de estrategias de colisión

Revisa:

* `Semana8/include/ChainedHashTable.h`
* `Semana8/include/LinearHashTable.h`
* `Semana8/include/QuadraticHashTable.h`
* `Semana8/include/DoubleHashTable.h`
* `Semana8/include/RobinHoodHashTable.h`
* `Semana8/demos/demo_collision_strategies.cpp`

Ejecuta:

```bash
./build-debug/Semana8/sem8_demo_collision_strategies
```

Compara al menos cinco estrategias:

1. Chaining.
2. Linear probing.
3. Quadratic probing.
4. Double hashing.
5. Robin Hood hashing.

Construye una tabla con estas columnas:

* Estrategia
* Representación interna
* Cómo resuelve colisiones
* Métrica más sensible
* Ventaja
* Debilidad
* Costo esperado
* Peor caso

Responde:

1. ¿Qué es clustering primario?
2. ¿Por qué linear probing tiende a formar bloques contiguos?
3. ¿Qué intenta mejorar quadratic probing?
4. ¿Qué intenta mejorar double hashing?
5. ¿Qué intenta equilibrar Robin Hood hashing?
6. ¿Por qué chaining y open addressing no tienen el mismo comportamiento ante carga alta?
7. ¿Qué estrategia elegirías para una tabla pequeña de laboratorio?
8. ¿Qué estrategia elegirías para una carga alta con muchas búsquedas?
9. ¿Qué estrategia se degrada más claramente en presencia de muchas eliminaciones?.

Entrega en este bloque:

* Salida de la demo.
* Tabla comparativa completa.
* Conclusión técnica de máximo 15 líneas.

#### Bloque 8 - Funciones hash, hashing universal y distribución

Revisa:

* `Semana8/include/HashCode.h`
* `Semana8/include/UniversalHash.h`
* `Semana8/demos/demo_hash_functions.cpp`

Ejecuta:

```bash
./build-debug/Semana8/sem8_demo_hash_functions
```

Diseña tres conjuntos de claves:

1. Claves enteras consecutivas.
2. Claves enteras con patrón repetitivo.
3. Claves de texto con prefijos comunes.

Para cada conjunto, mide o reporta:

* cantidad de claves,
* capacidad de tabla,
* número de buckets usados,
* bucket más cargado,
* colisiones observadas,
* comentario sobre la distribución.

Responde:

1. ¿Qué propiedad debe tener una buena función hash?
2. ¿Por qué una función hash determinista puede ser buena para datos comunes y mala para datos adversariales?
3. ¿Qué idea aporta hashing universal?
4. ¿Por qué no se debe evaluar una función hash con un solo conjunto de claves?
5. ¿Qué relación existe entre dispersión y costo esperado?.

Entrega en este bloque:

* Tabla de distribución para los tres conjuntos de claves.
* Comparación entre `hashCode` y `UniversalHash` si la demo lo permite.
* Una conclusión sobre el papel de la función hash en el rendimiento real.

#### Bloque 9 - Rehashing, política de carga y costo amortizado

Revisa:

* `Semana8/include/RehashPolicy.h`
* `Semana8/include/HashStats.h`
* `Semana8/demos/demo_benchmark_load_factor.cpp`
* `Semana8/pruebas_internas/test_rehashing.cpp`

Ejecuta:

```bash
./build-debug/Semana8/sem8_demo_benchmark_load_factor
```

Responde:

1. ¿Qué condición de carga provoca crecimiento?
2. ¿Qué condición puede provocar limpieza por tombstones?
3. ¿Qué condición puede provocar contracción?
4. ¿Por qué rehashing cuesta `O(n)` en el momento en que ocurre?
5. ¿Por qué aun así se habla de costo amortizado?
6. ¿Qué relación hay entre capacidad, factor de carga y número de sondeos?
7. ¿Qué evidencia muestra `HashStats` sobre rehashings?
8. ¿Qué riesgo hay si se permite que el factor de carga sea demasiado alto?.

Entrega en este bloque:

* Tabla con capacidad, número de elementos, factor de carga, rehashes y máximo de sondeos.
* Explicación de costo amortizado.
* Interpretación de al menos una prueba de `test_rehashing.cpp`.

#### Bloque 10 - Aplicaciones de hashing

Revisa:

* `Semana8/include/Applications.h`
* `Semana8/demos/demo_aplicaciones.cpp`

Ejecuta:

```bash
./build-debug/Semana8/sem8_demo_aplicaciones
```

Elige dos aplicaciones y explícalas con trazado manual:

1. `hasDuplicates`.
2. `uniquePreservingOrder`.
3. `firstRepeated`.
4. `frequencyCount`.
5. `wordFrequencyFromText`.
6. `twoSum`.
7. `deduplicateLogs`.
8. `invertedIndex`.

Para cada aplicación elegida, responde:

1. ¿Cuál es el problema de entrada?
2. ¿Cuál es la salida esperada?
3. ¿Qué se guarda en la tabla hash?
4. ¿Qué operación domina el costo?
5. ¿Por qué el costo esperado puede ser lineal?
6. ¿Qué caso podría degradar el rendimiento?
7. ¿Cómo resolverías el mismo problema con AVL o Red-Black Tree?
8. ¿Qué se gana y qué se pierde al usar hashing?.

Entrega en este bloque:

* Dos trazados manuales.
* Evidencia de ejecución.
* Comparación de costo esperado con tabla hash frente a costo garantizado con árbol balanceado.

#### Bloque 11 - Modificación controlada de código

Elige una de las siguientes modificaciones. Debes marcar tu cambio con comentario `MOD-A8` y mantener compilación limpia.

#### Opción A - Reporte uniforme de métricas

Crea una función auxiliar para imprimir métricas relevantes de una tabla hash.

```cpp
void printHashStats(const HashStats& stats);
```

La salida debe incluir como mínimo:

* colisiones,
* sondeos totales,
* máximo de sondeos,
* rehashings,
* tombstones si aplica.

#### Opción B - Experimento de colisiones reales

Crea una demo que busque claves que realmente colisionen bajo `hashCode(x) % capacity` y luego las inserte en `ChainedHashTable` o `LinearHashTable`.

#### Opción C - Caso adicional de aplicación

Agrega una aplicación pequeña basada en hashing, por ejemplo:

```cpp
std::vector<std::string> findRepeatedWords(const std::string& text);
```

Debe devolver palabras que aparecen más de una vez, sin usar `std::unordered_map` como estructura principal.

Responde:

1. ¿Qué archivo modificaste?
2. ¿Qué función agregaste?
3. ¿Qué invariante debe mantenerse?
4. ¿Qué prueba o demo evidencia el cambio?
5. ¿Qué costo tiene la función agregada?
6. ¿Por qué tu modificación no oculta el algoritmo central?.

Entrega en este bloque:

* Fragmento de código modificado.
* Evidencia de compilación.
* Evidencia de ejecución.
* Explicación de costo.

#### Bloque 12 - Comparación final con BST, AVL, Red-Black Tree y Treap

Revisa:

* `Semana5/include/BinarySearchTree.h`
* `Semana6/include/Treap.h`
* `Semana7/include/AVL.h`
* `Semana7/include/RedBlackTree.h`
* `Semana8/include/ChainedHashTable.h`
* `Semana8/include/LinearHashTable.h`
* `Semana8/include/HashtableOA.h`

Construye una matriz de decisión con estas columnas:

* Estructura
* Mantiene orden
* Búsqueda promedio
* Búsqueda peor caso
* Inserción
* Eliminación
* Memoria adicional
* Ventaja principal
* Riesgo principal
* Caso de uso recomendado

Incluye:

1. BST simple.
2. Treap.
3. AVL.
4. Red-Black Tree.
5. ChainedHashTable.
6. LinearHashTable.
7. HashtableOA.

Responde:

1. ¿Cuándo elegirías una tabla hash?
2. ¿Cuándo elegirías AVL?
3. ¿Cuándo elegirías Red-Black Tree?
4. ¿Cuándo elegirías Treap?
5. ¿Por qué una tabla hash no sirve directamente para consultas por rango?
6. ¿Por qué un árbol balanceado sí permite recorrer claves en orden?
7. ¿Qué significa que una estructura tenga costo esperado y otra tenga costo garantizado?
8. ¿Qué estructura preferirías para un índice de palabras sin orden?
9. ¿Qué estructura preferirías para un ranking ordenado por clave?
10. ¿Qué estructura preferirías si necesitas `lowerBound` y `upperBound`?.

Entrega en este bloque:

* Matriz de decisión.
* Conclusión final de máximo 20 líneas.
* Un ejemplo concreto donde hashing gana.
* Un ejemplo concreto donde AVL o Red-Black Tree gana.

#### Producto final esperado

El archivo `Actividad8-CC232.md` debe contener:

1. Respuestas completas por bloque.
2. Tablas solicitadas.
3. Evidencia de comandos ejecutados.
4. Fragmentos de código modificados si corresponde.
5. Salidas relevantes de demostraciones y pruebas.
6. Trazados manuales de colisiones, sondeos y tombstones.
7. Comparación final contra BST, Treap, AVL y Red-Black Tree.
8. Conclusión técnica personal.

Además, si modificaste código, entrega los archivos cambiados y menciona exactamente qué cambiaste.
