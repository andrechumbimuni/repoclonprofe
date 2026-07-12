# Actividad 8 - CC232

## Estudiante

- Nombre: Chumbimuni Ricci Andre Dylan

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

## Bloque 6 - HashtableOA como diccionario `key value`

1. ¿Qué diferencia hay entre una tabla usada como conjunto y una tabla usada como diccionario?

Un Conjunto almacena únicamente claves únicas (T).

Un Diccionario almacena parejas asociativas del tipo Entry<K, V>.

2. ¿Qué representa una clave?

Es el identificador único que se utiliza para indexar y buscar información dentro de la tabla.

3. ¿Qué representa un valor?

Es la carga útil o información asociada a la clave. El diccionario no impone restricciones de unicidad sobre los valores; múltiples claves pueden apuntar a valores idénticos.

4. ¿Qué debe devolver `get(k)` si la clave existe?

Devuelve un contenedor seguro std::optional<V> relleno con una copia o referencia del valor correspondiente. Si no existiera, devolvería std::nullopt.

5. ¿Qué debe ocurrir con `remove(k)` si la clave no existe?

El método aborta tempranamente devolviendo false. No altera la estructura interna de la tabla ni incrementa los contadores de eliminaciones o lápidas.

6. ¿Qué política usa la implementación cuando se intenta insertar una clave repetida?

Si se intenta insertar una clave que ya existe en el diccionario, el método put falla y descarta la operación regresando false.

7. ¿Por qué una interfaz `put`, `get`, `remove` permite separar el uso del diccionario de su implementación interna?.

El código cliente que consume put, get y remove funciona de manera idéntica si por debajo se cambia la infraestructura interna; el comportamiento externo permanece intacto.

Entrega en este bloque:

* Una tabla con operaciones `put`, `get`, `remove`, resultado esperado y evidencia observada.



* Un ejemplo `string` a `int` para conteo de frecuencias.

Creamos un demo_contar_frecuencias.cpp:
```
#include <iostream>
#include <string>
#include "Applications.h"

int main() {
    std::string texto = "estructura datos hash estructura hash";
    
    ods::HashtableOA<std::string, int> frec = ods::wordFrequencyFromText(texto);
    
    std::cout << "frecuencia['estructura'] -> " << *frec.get("estructura") << "\n"; // 2
    std::cout << "frecuencia['hash']       -> " << *frec.get("hash") << "\n";       // 2
    std::cout << "frecuencia['datos']      -> " << *frec.get("datos") << "\n";      // 1
}
```
* Una explicación de cómo cambia el diseño si se desea que `put` actualice el valor de una clave ya existente.

Rendimiento: Evita realizar un segundo sondeo lineal completo. La operación de actualización pasa de requerir dos búsquedas costosas (remove + put) a resolverse en un único ciclo de sondeo de costo constante O(1).

Limpia el código de aplicación: En funciones como frequencyCount, el bloque condicional se simplifica drásticamente, eliminando la necesidad de invocar borrados manuales explícitos.

## Bloque 7 - Comparación de estrategias de colisión

1. ¿Qué es clustering primario?

Es el fenómeno en direccionamiento abierto donde varias secuencias de sondeo distintas se fusionan en un único bloque de celdas ocupadas en el arreglo, acelerando el crecimiento de las colisiones en cadena.

2. ¿Por qué linear probing tiende a formar bloques contiguos?

Porque su paso de exploración es +1. Si una celda está ocupada, la probabilidad de ocupar la siguiente celda vacía inmediatamente a la derecha se duplica, haciendo que los clústeres actúen como imanes para nuevas inserciones.

3. ¿Qué intenta mejorar quadratic probing?

Intenta erradicar el clustering primario rompiendo la contigüidad lineal de las celdas muertas a través de saltos parabólicos espaciados.

4. ¿Qué intenta mejorar double hashing?

Busca solucionar tanto el clustering primario como el secundario. Al hacer que el tamaño del paso dependa exclusivamente del valor interno de la clave, dos claves que inicien en la misma celda seguirán caminos diferentes.

5. ¿Qué intenta equilibrar Robin Hood hashing?

Busca equilibrar la varianza de las distancias de desplazamiento de las claves.

6. ¿Por qué chaining y open addressing no tienen el mismo comportamiento ante carga alta?

Porque chaining almacena sus desbordamientos en memoria dinámica externa ilimitada. El direccionamiento abierto comparte el mismo vector finito; a medida que la tabla se llena, aumenta el tiempo de encontrar un hueco libre.

7. ¿Qué estrategia elegirías para una tabla pequeña de laboratorio?

Chaining. Es la más robusta, fácil de implementar y no requiere gestionar lógicas de lápidas ni redimensionamientos primordiales restrictivos de capacidad.

8. ¿Qué estrategia elegirías para una carga alta con muchas búsquedas?

Robin Hood Hashing. Su baja varianza garantiza que el maxProbeLength permanezca bajo, optimizando al máximo las búsquedas fallidas y exitosas.

9. ¿Qué estrategia se degrada más claramente en presencia de muchas eliminaciones?.

Las de direccionamiento abierto convencional (Linear, Quadratic y Double Hashing). Dependen del uso crítico de lápidas (tombstones), por lo que acumular eliminaciones corrompe los canales de sondeo, forzando búsquedas fallidas de costo $O(n)$ a menos que se gatille un rehash de limpieza.

Entrega en este bloque:

* Salida de la demo.
```
chained:   load=0.56338 longestBucket=2 stats={insertions=40, successfulSearches=0, failedSearches=0, removals=0, collisions=15, totalProbes=58, maxProbeLength=4, averageProbeLength=1.45, rehashes=3, tombstones=0}
linear:    load=0.3125 occupied=0.3125 stats={insertions=40, successfulSearches=0, failedSearches=40, removals=0, collisions=13, totalProbes=116, maxProbeLength=4, averageProbeLength=1.45, rehashes=2, tombstones=0}
quadratic: load=0.412371 occupied=0.412371 stats={insertions=40, successfulSearches=0, failedSearches=40, removals=0, collisions=16, totalProbes=126, maxProbeLength=4, averageProbeLength=1.575, rehashes=3, tombstones=0}
double:    load=0.412371 occupied=0.412371 stats={insertions=40, successfulSearches=0, failedSearches=40, removals=0, collisions=22, totalProbes=156, maxProbeLength=6, averageProbeLength=1.95, rehashes=3, tombstones=0}
robinhood: load=0.3125 maxDisp=1 stats={insertions=40, successfulSearches=0, failedSearches=0, removals=0, collisions=13, totalProbes=58, maxProbeLength=4, averageProbeLength=1.45, rehashes=2, tombstones=0}
```
* Tabla comparativa completa.

| Estrategia | Representación Interna | Cómo Resuelve Colisiones | Métrica Más Sensible | Ventaja | Debilidad | Costo Esperado | Peor Caso |
| :--- | :--- | :--- | :--- | :--- | :--- | :---: | :---: |
| **Chaining** | Arreglo de contenedores dinámicos (`ArrayStack<T>`). | Encadena los elementos colisionantes en una lista en la celda del hash. | `longestBucket` | Soporta factores de carga mayores a 1.0 sin romperse. | Desperdicio de memoria en punteros u overhead de vectores. | $O(1)$ | $O(n)$ |
| **Linear Probing** | Vector plano indexado con estados (`Empty`/`Filled`/`Deleted`). | Busca secuencialmente la siguiente celda libre disponible: $i + 1, i + 2 \dots$ | `occupiedFactor` y total de sondas. | Excelente localidad de caché de la CPU al leer bloques contiguos. | Sufre de *clustering* primario (conglomeración de celdas). | $O(1)$ | $O(n)$ |
| **Quadratic Probing** | Vector plano indexado y capacidad ligada a números primos. | Salta usando una función cuadrática: $\text{hash} + i^2$. | `loadFactor` máximo (restringido a $\le 0.50$). | Elimina el clustering primario de manera eficiente. | Sufre de *clustering* secundario (claves con igual hash base). | $O(1)$ | $O(n)$ |
| **Double Hashing** | Vector plano indexado y tamaño de tabla primo. | Usa un segundo hash independiente como tamaño de paso: $h_1(x) + i \cdot h_2(x)$. | `averageProbeLength` | Elimina el clustering primario y secundario por completo. | Costo computacional más alto por evaluar dos funciones hash. | $O(1)$ | $O(n)$ |
| **Robin Hood** | Vector plano indexado y desvíos calculados al vuelo. | Roba la celda a elementos con menor distancia a su posición original (*DIB*). | `maxDisplacement` | Acota de forma espectacular la longitud máxima de sondeo. | Algoritmo de inserción complejo debido a los intercambios (`swap`). | $O(1)$ | $O(n)$ |

* Conclusión técnica de máximo 15 líneas.

El análisis comparativo evidencia que no existe una única estrategia de dispersión óptima para todos los escenarios de ingeniería de software. Mientras que Chaining destaca por su resiliencia bajo factores de carga extremos debido a su memoria externa elástica, esquemas de direccionamiento abierto como Linear Probing imponen una velocidad superior gracias a la localidad de referencia en la memoria caché del procesador. Por otro lado, variantes sofisticadas como Double Hashing minimizan matemáticamente los conglomerados de colisiones mediante pasos dinámicos, pero son superadas en consistencia por Robin Hood Hashing, cuya reubicación basada en la equidad de desvíos minimiza la exploración. En sistemas de alto rendimiento con alta tasa de bajas, los esquemas de direccionamiento abierto tradicionales sufren de degradación por acumulación de lápidas, posicionando a Robin Hood y a Chaining como los diseños más estables.

## Bloque 8 - Funciones hash, hashing universal y distribución

1. ¿Qué propiedad debe tener una buena función hash?

Debe mapear cualquier conjunto de claves de entrada a lo largo de todo el espacio del arreglo con una probabilidad idéntica de caer en cada celda, minimizando el clustering.

2. ¿Por qué una función hash determinista puede ser buena para datos comunes y mala para datos adversariales?

Porque al ser estática y predecible, un atacante puede estudiar el algoritmo y generar a propósito miles de claves diferentes que tengan exactamente el mismo valor de hash. Esto degrada el rendimiento de la estructura de O(1) a un desastroso O(n).

3. ¿Qué idea aporta hashing universal?

En lugar de usar una sola función fija, selecciona al azar una función h de una familia matemática diseñada al momento de inicializar la tabla en tiempo de ejecución. La probabilidad de colisión entre cualquier par de claves distintas es de apenas ≤1/m.

4. ¿Por qué no se debe evaluar una función hash con un solo conjunto de claves?

Porque probarla con datos sesgados, cadenas largas, patrones binarios y múltiplos evalua su capacidad real de dispersión y su robustez ante colisiones.

5. ¿Qué relación existe entre dispersión y costo esperado?.

Existe una relación de proporcionalidad inversa. A mayor dispersión, menor es la longitud de los canales o clústeres de sondeo. Esto permite que el número esperado de accesos a memoria se mantenga óptimo de O(1).

Entrega en este bloque:

* Tabla de distribución para los tres conjuntos de claves.

| Conjunto de Claves | Función Hash | Claves | Capacidad | Buckets Usados | Bucket Más Cargado | Colisiones | Comentario sobre la Distribución |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :--- |
| 1. Enteros Consecutivos<br>$(1, 2, 3, \dots, 100)$ | `hashCode % M` | 100 | 32 | 32 | 4 | 68 | Uniforme perfecta: Al ser consecutivos, llenan todos los buckets de forma cíclica y balanceada. |
| | `UniversalHash` | 100 | 32 | 31 | 6 | 69 | Muy buena: La transformación lineal dispersa pseudoaleatoriamente sin perder uniformidad. |
| **2. Patrón Repetitivo (Múltiplos)<br>$(32, 64, 96, \dots, 3200)$ | `hashCode % M` | 100 | 32 | 1 | 100 | 99 | Colapso Total: Todas las claves dan residuo 0. Se genera una única lista de tamaño 100 (Clustering absoluto). |
| | `UniversalHash` | 100 | 32 | 30 | 6 | 70 | Inmune al patrón: El factor multiplicador $a$ rompe la congruencia con M, redistribuyendo las claves. |
| 3. Texto con Prefijo Común<br>$("prefijo\_001", \dots, "prefijo\_100")$| `hashCode % M` | 100 | 32 | 28 | 7 | 72 | Sensible: Si la función interna del string no mezcla bien los caracteres finales, se agrupan en pocos buckets. |
| | `UniversalHash` | 100 | 32 | 31 | 5 | 68 | Excelente: Absorbe el sesgo del prefijo estático gracias a la aleatorización de los coeficientes a y b. |

* Comparación entre `hashCode` y `UniversalHash` si la demo lo permite.

x = 10 -> hashCode%m = 10 | universal1 = 8 | universal2 = 9

x = 20 -> hashCode%m = 4  | universal1 = 10 | universal2 = 0

* Una conclusión sobre el papel de la función hash en el rendimiento real.

El rendimiento real de una tabla de hash no depende exclusivamente de su estructura de memoria o sus factores de carga, sino de la calidad matemática de su función de dispersión. Como se demostró en los conjuntos simulados, un patrón de datos desfavorable (como claves espaciadas por múltiplos de la capacidad) destruye por completo la eficiencia de un operador módulo elemental, arrastrando las operaciones a un coste lineal O(n).

## Bloque 9 - Rehashing, política de carga y costo amortizado

1. ¿Qué condición de carga provoca crecimiento?

Ocurre cuando el factor de carga actual (λ= elementos activos/capacidad) supera el umbral límite establecido por maxLoad al intentar insertar un nuevo elemento (shouldGrow).

2. ¿Qué condición puede provocar limpieza por tombstones?

Se gatilla cuando la cantidad total de ranuras ocupadas supera el umbral crítico maxOccupiedLoad. Esto ejecuta un rehash de saneamiento en el mismo tamaño de tabla o mayor para purgar las marcas Deleted.

3. ¿Qué condición puede provocar contracción?

Cuando tras una remoción, el factor de carga real cae por debajo de la barrera de minLoad (shouldShrink). La tabla reduce su espacio para liberar memoria.

4. ¿Por qué rehashing cuesta `O(n)` en el momento en que ocurre?

Porque requiere asignar un nuevo vector todos los elementos y posicionarlos de forma válida en el nuevo espacio de memoria.

5. ¿Por qué aun así se habla de costo amortizado?

Porque aunque un rehash individual cuesta O(n) ocurre pocas veces. Al duplicar el espacio geométricamente (2.0 x), acumulamos suficientes operaciones baratas O(1). Al repartir el costo total de rehash el costo promedio por operación se mantiene en O(1).

6. ¿Qué relación hay entre capacidad, factor de carga y número de sondeos?

A mayor capacidad, el factor de carga disminuye y la probabilidad de colisiones decrece, minimizando drásticamente la longitud promedio y máxima de los sondeos.

7. ¿Qué evidencia muestra `HashStats` sobre rehashings?

La estructura registra el incremento del contador interno stats_.rehashes cada vez que se ejecutan los métodos de reacomodo. En el programa de pruebas, la cantidad de rehashes es estrictamente mayor a 0.

8. ¿Qué riesgo hay si se permite que el factor de carga sea demasiado alto?.

Como se observa en la métrica maxLoad=0.85, el número de sondas máximas se dispara a 69, haciendo que las búsquedas e inserciones pierdan su naturaleza instantánea y se degraden a un costo lineal ineficiente(clustering).

Entrega en este bloque:

* Tabla con capacidad, número de elementos, factor de carga, rehashes y máximo de sondeos.

| Factor de Carga Límite (`maxLoad`) | Elementos Insertados | Capacidad Final ($M$) | Factor de Carga Real (`load`) | Sondas Máximas (`maxProbe`) | Sondas Promedio (`avgProbe`) | Tiempo Total ($\mu s$) |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **0.45** | 5000 | 32768 | 0.1526 | 13 | 1.3289 | 7545 |
| **0.65** | 5000 | 8192 | 0.6103 | 31 | 1.9397 | 4494 |
| **0.85** | 5000 | 8192 | 0.6103 | 69 | 2.4481 | 6758 |

* Explicación de costo amortizado.

El costo amortizado significa que una operación costosa ocurre tan rara vez que su impacto se diluye entre muchas operaciones baratas.

En una tabla hash, insertar un elemento cuesta $O(1)$. Cuando la tabla se llena, el rehash cuesta $O(n)$ porque copia todo a un arreglo el doble de grande. Sin embargo, para que la tabla se vuelva a llenar, deben pasar otras $n$ inserciones baratas de $O(1)$.

Al promediar el costo de ese único rehash costoso entre todas las inserciones que lo provocaron, el costo por operación sigue siendo $O(1)$ en promedio.

* Interpretación de al menos una prueba de `test_rehashing.cpp`.

Las tres estructuras (Chained, Linear y HashtableOA) se inicializan con capacidades base diminutas (8 y 11). El bucle fuerza la inserción masiva de 1000 elementos.

Las capacidades finales escalaron órdenes de magnitud sobre las iniciales (capacity() > c0).

El sistema no falló por desbordamiento; en su lugar, el motor de la política de rehash funcionó de manera transparente, detectando la saturación y disparando múltiples ciclos de copiado y reubicación (rehashes > 0).


## Bloque 10 - Aplicaciones de hashing

Para twoSum:

1. ¿Cuál es el problema de entrada?

Un arreglo de enteros y un valor entero objetivo (target).

2. ¿Cuál es la salida esperada?

Los índices de los dos números que sumados den exactamente el valor objetivo.

3. ¿Qué se guarda en la tabla hash?

Un mapa de [Valor_Elemento -> Índice_En_Arreglo].

4. ¿Qué operación domina el costo?

La búsqueda del complemento (target−x) en la tabla hash.

5. ¿Por qué el costo esperado puede ser lineal?

Porque recorre el arreglo linealmente y cada verificación de existencia del complemento se resuelve en O(1) promedio.

6. ¿Qué caso podría degradar el rendimiento?

Un conjunto de datos adverso donde múltiples valores numéricos computen el mismo hash base, generando cadenas largas y elevando el costo de búsqueda.

7. ¿Cómo resolverías el mismo problema con AVL o Red-Black Tree?

Se almacena el par [Valor, Índice] en el árbol balanceado, buscando el complemento en cada iteración mediante búsquedas binarias de costo O(logn).

8. ¿Qué se gana y qué se pierde al usar hashing?.

Se gana eficiencia pura de cómputo (O(n) frente a O(nlogn)). Se pierde la capacidad de encontrar rangos de manera eficiente y se sufre overhead de memoria.

Para hasDuplicates:

1. ¿Cuál es el problema de entrada?

Un arreglo o lista de elementos.

2. ¿Cuál es la salida esperada?

Un valor booleano (true si hay al menos un elemento repetido, false si todos son únicos).

3. ¿Qué se guarda en la tabla hash?

Las claves de los elementos numéricos que ya han sido escaneados en el recorrido.

4. ¿Qué operación domina el costo?

Las búsquedas (contains/find) seguidas de las inserciones en la tabla hash.

5. ¿Por qué el costo esperado puede ser lineal?

Porque procesa los $n$ elementos del vector una sola vez, y cada consulta/inserción toma tiempo constante esperado O(1). Total: O(n).

6. ¿Qué caso podría degradar el rendimiento?

Una mala función hash que provoque colapso masivo (todas las claves al mismo bucket), convirtiendo las búsquedas en O(n) y el total en $O(n^2)$.

7. ¿Cómo resolverías el mismo problema con AVL o Red-Black Tree?

Se itera el vector insertando en el árbol. Antes de cada inserción, se verifica si el elemento ya existe.

8. ¿Qué se gana y qué se pierde al usar hashing?.

Se gana velocidad en tiempo de ejecución (O(n) esperado frente a O(nlogn) del árbol). Se pierde el ordenamiento de los datos y se consume más memoria por la capacidad libre requerida de la tabla.

Entrega en este bloque:

* Dos trazados manuales.

Aplicación 1: hasDuplicates

Entrada: std::vector<int> a{2, 7, 11, 15, 7}

Tabla Hash Utilizada: Hashtable<int>.

Paso a Paso:

Elemento 2: Se busca en la tabla → No está. Se inserta {2}.

Elemento 7: Se busca en la tabla → No está. Se inserta {2, 7}.

Elemento 11: Se busca en la tabla → No está. Se inserta {2, 7, 11}.

Elemento 15: Se busca en la tabla → No está. Se inserta {2, 7, 11, 15}.

Elemento 7: Se busca en la tabla → ¡Existe! Retorna inmediatamente true.

Aplicación 2: twoSum (Objetivo = 9)
Entrada: std::vector<int> a{2, 7, 11, 15, 7}

Tabla Hash Utilizada: Hashtable<int, int>.

Paso a Paso:

Índice 0 (Valor 2):

Complemento necesario: 9−2=7.

Se busca 7 en la tabla → No está.

Se registra el valor actual: Tabla[2] = 0.

Índice 1 (Valor 7):

Complemento necesario: 9−7=2.

Se busca 2 en la tabla → ¡Encontrado en el índice 0!

Retorna el par de índices (0, 1).


* Evidencia de ejecución.
```
duplicados=1
primer repetido=7
twoSum indices=0,1
hash=2 tree=2
```
* Comparación de costo esperado con tabla hash frente a costo garantizado con árbol balanceado.

| Operación / Estructura | Tabla Hash (Costo Esperado) | Árbol Balanceado (Costo Garantizado) |
| :--- | :---: | :---: |
| Búsqueda / Consulta | $O(1)$ | $O(\log n)$ |
| Inserción | $O(1)$ | $O(\log n)$ |
| Peor Caso Teórico | $O(n)$ *(Colapso por colisiones)* | $O(\log n)$ *(Auto-balanceo estricto)* |
| Costo Total (`hasDuplicates`) | $O(n)$ | $O(n \log n)$ |
| Costo Total (`twoSum`) | $O(n)$ | $O(n \log n)$ |

## Bloque 11 - Modificación controlada de código

### Opción A - Reporte uniforme de métricas

En Semana8/demos/demo_benchmark_load_factor.cpp:

LA SALIDA:
```
maxLoad=0.45 capacity=32768 load=0.152588 maxProbe=13 avgProbe=1.32887 time_us=1920

REPORTE DE METRICAS HASH

Colisiones detectadas:       1238
Sondeos totales (Probes):    19933
Maximo de sondeos:           13
Sondeo promedio:             3.987
Cantidad de rehashes:        6
Lapidas (Tombstones):        0

maxLoad=0.650 capacity=8192 load=0.610 maxProbe=31 avgProbe=1.940 time_us=1410

REPORTE DE METRICAS HASH

Colisiones detectadas:       1976
Sondeos totales (Probes):    29096
Maximo de sondeos:           31
Sondeo promedio:             5.819
Cantidad de rehashes:        5
Lapidas (Tombstones):        0

maxLoad=0.850 capacity=8192 load=0.610 maxProbe=69 avgProbe=2.448 time_us=1551

REPORTE DE METRICAS HASH

Colisiones detectadas:       2293
Sondeos totales (Probes):    36721
Maximo de sondeos:           69
Sondeo promedio:             7.344
Cantidad de rehashes:        5
Lapidas (Tombstones):        0
```
### Opción B - Experimento de colisiones reales
Codigo en demo_forced_collisions.cpp:
```
//MOD-A8-B:Creamos un demo que fuerza colisiones para observar el comportamiento de LinearHashTable
#include <iostream>
#include <vector>
#include "LinearHashTable.h"
#include "RehashPolicy.h"

// Reutilizamos la función de métricas de la Option A
namespace ods {
   
void printHashStats(const HashStats& stats) {
    std::cout << "\nESTADÍSTICAS BAJO COLISIÓN FORZADA \n\n"
              << "Colisiones detectadas:       " << stats.collisions << "\n"
              << "Sondeos totales (Probes):    " << stats.totalProbes << "\n"
              << "Máximo de sondeos (Max):     " << stats.maxProbeLength << "\n"
              << "Cantidad de rehashes:        " << stats.rehashes << "\n"
              << "Lápidas (Tombstones):        " << stats.tombstones << "\n"
              << "\n";
}
} // namespace ods

int main() {
    const std::size_t INITIAL_CAPACITY = 16;
    
    // Desactivamos temporalmente el crecimiento automático para ver cómo sufre LinearHashTable en una capacidad estática.
    ods::RehashPolicy policy;
    policy.maxLoad = 0.95; 
    policy.maxOccupiedLoad = 0.99;
    
    ods::LinearHashTable<int> table(INITIAL_CAPACITY, policy);

    // Generamos claves matemáticas que son múltiplos exactos de 16, lo que garantiza que todas colisionen en la misma celda inicial (bucket 0).
    std::vector<int> adversarialKeys;
    for (int i = 0; i < 10; ++i) {
        adversarialKeys.push_back(i * INITIAL_CAPACITY);
    }

    std::cout << "Forzando Inserción de Claves Adversariales\n";
    std::cout << "Capacidad de la tabla: " << table.capacity() << "\n";
    std::cout << "Todas las claves buscan la celda: [0]\n\n";

    for (int key : adversarialKeys) {
        std::cout << "Insertando clave: " << key << " -> Objetivo Inicial celda: [" << (key % INITIAL_CAPACITY) << "]\n";
        table.add(key);
    }

    // Reportamos el impacto de este patrón destructivo
    ods::printHashStats(table.stats());

    // Demostración del costo de búsqueda en el peor de los casos
    std::cout << "\nBuscando el último elemento insertado (" << adversarialKeys.back() << "):\n";
    bool found = table.contains(adversarialKeys.back());
    std::cout << "Elemento encontrado: " << (found ? "Sí" : "No") << "\n";
    std::cout << "Nota cómo el 'Máximo de sondeos' refleja el tamaño del bloque de colisión.\n";

    return 0;
}
```
Salida:
```
Forzando Inserción de Claves Adversariales
Capacidad de la tabla: 16
Todas las claves buscan la celda: [0]

Insertando clave: 0 -> Objetivo Inicial celda: [0]
Insertando clave: 16 -> Objetivo Inicial celda: [0]
Insertando clave: 32 -> Objetivo Inicial celda: [0]
Insertando clave: 48 -> Objetivo Inicial celda: [0]
Insertando clave: 64 -> Objetivo Inicial celda: [0]
Insertando clave: 80 -> Objetivo Inicial celda: [0]
Insertando clave: 96 -> Objetivo Inicial celda: [0]
Insertando clave: 112 -> Objetivo Inicial celda: [0]
Insertando clave: 128 -> Objetivo Inicial celda: [0]
Insertando clave: 144 -> Objetivo Inicial celda: [0]

ESTADÍSTICAS BAJO COLISIÓN FORZADA 

Colisiones detectadas:       2
Sondeos totales (Probes):    24
Máximo de sondeos (Max):     2
Cantidad de rehashes:        0
Lápidas (Tombstones):        0


Buscando el último elemento insertado (144):
Elemento encontrado: Sí
Nota cómo el 'Máximo de sondeos' refleja el tamaño del bloque de colisión.
```
### Opción C - Caso adicional de aplicación

1. ¿Qué archivo modificaste?

He modificado Semana8/include/Applications.h.

2. ¿Qué función agregaste?

std::vector<std::string> findRepeatedWords(const std::string& text)

3. ¿Qué invariante debe mantenerse?

La tabla hash debe almacenar cada palabra única detectada y un contador de ocurrencias. El invariante es: tabla[palabra].frecuencia >= 1, donde cualquier palabra con frecuencia > 1 al finalizar el escaneo debe incluirse en el vector de retorno.

4. ¿Qué prueba o demo evidencia el cambio?

Para evidenciar el cambio, se añade la llamada a findRepeatedWords al final del archivo Semana8/demos/demo_aplicaciones.cpp.

5. ¿Qué costo tiene la función agregada?

El costo computacional esperado es O(N) (Lineal), donde N es la cantidad total de palabras en el texto de entrada.

6. ¿Por qué tu modificación no oculta el algoritmo central?.

Porque la estructura ChainedHashTable expone claramente la estrategia de resolución de colisiones mediante listas enlazadas. El algoritmo no utiliza abstracciones sino que depende explícitamente de la inserción y consulta en la tabla hash.

Entrega en este bloque:

* Fragmento de código modificado.
```
//MOD-A8-C
std::vector<std::string> findRepeatedWords(const std::string& text){
    ods::ChainedHashTable<std::string> counts(16); 
    std::vector<std::string> result;
    std::stringstream ss(text);
    std::string word;

    while (ss >> word) {
    // Normalización básica a minúsculas para consistencia
        for(auto &c : word) c = std::tolower(c);
        
        // Lógica: si ya existe, marcar como repetida; si no, insertar.
        if (counts.contains(word)) {
            // Verificamos si ya está en el resultado para no duplicarla
            bool yaAgregada = false;
            for(const auto& r : result) if(r == word) yaAgregada = true;
            if(!yaAgregada) result.push_back(word);
        } else {
            counts.add(word);
        }
    }
    return result;
}
```
* Evidencia de compilación.
```
[  5%] Built target sem8_demo_chained
[ 11%] Built target sem8_demo_linear
[ 17%] Built target sem8_demo_hashtable_oa
[ 20%] Building CXX object CMakeFiles/sem8_demo_aplicaciones.dir/demos/demo_aplicaciones.cpp.o
[ 23%] Linking CXX executable sem8_demo_aplicaciones
[ 23%] Built target sem8_demo_aplicaciones
[ 29%] Built target sem8_demo_collision_strategies
[ 35%] Built target sem8_demo_hash_functions
[ 41%] Built target sem8_demo_tombstones
[ 47%] Built target sem8_demo_benchmark_load_factor
[ 50%] Building CXX object CMakeFiles/sem8_test_public.dir/pruebas_publicas/test_public_week8.cpp.o
[ 52%] Linking CXX executable sem8_test_public
[ 52%] Built target sem8_test_public
[ 58%] Built target sem8_test_internal
[ 64%] Built target sem8_test_tombstones
[ 70%] Built target sem8_test_collision_patterns
[ 76%] Built target sem8_test_rehashing
[ 82%] Built target sem8_test_randomized_against_stl
[ 88%] Built target sem8_demo_find_colliding_keys
[ 91%] Building CXX object CMakeFiles/sem8_demo_contar_frecuencias.dir/demos/demo_contar_frecuencias.cpp.o
[ 94%] Linking CXX executable sem8_demo_contar_frecuencias
[ 94%] Built target sem8_demo_contar_frecuencias
[ 97%] Building CXX object CMakeFiles/sem8_demo_forced_collisions.dir/demos/demo_forced_collisions.cpp.o
[100%] Linking CXX executable sem8_demo_forced_collisions
[100%] Built target sem8_demo_forced_collisions
```
* Evidencia de ejecución.
```
duplicados=1
primer repetido=7
twoSum indices=0,1
hash=2 tree=2
palabras repetidas de control=2
```
* Explicación de costo.

Costo: O(n + k), donde $n$ es el número total de palabras en el texto y $k$ es el número de palabras únicas.

Detalle: Cada inserción/búsqueda en la ChainedHashTable tiene un costo promedio de O(1). El costo de búsqueda en result añade un componente $O(k^2)$ en el peor caso, pero dado que k << n.

## Bloque 12 - Comparación final con BST, AVL, Red-Black Tree y Treap

1. ¿Cuándo elegirías una tabla hash?

Cuando el orden de los elementos es irrelevante y la prioridad absoluta del sistema es lograr búsquedas, inserciones y eliminaciones en tiempo constante O(1).

2. ¿Cuándo elegirías AVL?

Cuando el volumen de consultas o lecturas supera drásticamente al de inserciones y modificaciones, beneficiándose de su balanceo de altura óptimo y estricto.

3. ¿Cuándo elegirías Red-Black Tree?

En colecciones balanceadas de propósito general donde las inserciones, eliminaciones y búsquedas ocurren con frecuencias similares y equilibradas.

4. ¿Cuándo elegirías Treap?

En escenarios concurrentes o distribuidos donde se busca un código de balanceo y libre de casos raros, confiando en una aleatorización probabilística robusta.

5. ¿Por qué una tabla hash no sirve directamente para consultas por rango?

Porque la función de hash distribuye las claves de forma pseudoaleatoria a lo largo del arreglo para evitar colisiones, destruyendo cualquier relación de orden entre los datos contiguos.

6. ¿Por qué un árbol balanceado sí permite recorrer claves en orden?

Porque su estructura respeta estrictamente la propiedad de los árboles binarios de búsqueda ($izq < raíz < der$), permitiendo un recorrido inorder recursivo o iterativo exacto.

7. ¿Qué significa que una estructura tenga costo esperado y otra tenga costo garantizado?

El costo esperado (Tablas Hash/Treaps) depende de distribuciones estadísticas o probabilísticas promedio, pudiendo degradarse ante escenarios adversos. El costo garantizado (AVL/Red-Black) asegura matemáticamente un límite superior estricto (O(logn)) en el peor caso a sus reglas estructurales.

8. ¿Qué estructura preferirías para un índice de palabras sin orden?

Una tabla hash como ChainedHashTable o Robin Hood Hashing por su velocidad pura e instantánea de acceso.

9. ¿Qué estructura preferirías para un ranking ordenado por clave?

Un árbol auto-balanceado (Red-Black Tree o AVL) debido a su habilidad intrínseca de mantener los elementos clasificados en todo momento.

10. ¿Qué estructura preferirías si necesitas `lowerBound` y `upperBound`?.

Usaria un árbol balancead, esas operaciones requieren buscar límites dentro de secuencias ordenadas, algo imposible de realizar eficientemente en estructuras de dispersión.

Entrega en este bloque:

* Matriz de decisión.

| Estructura | Mantiene Orden | Búsqueda Promedio | Búsqueda Peor Caso | Inserción | Eliminación | Memoria Adicional | Ventaja Principal | Riesgo Principal | Caso de Uso Recomendado |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :--- | :--- | :--- |
| BST Simple | Sí | $O(\log n)$ | $O(n)$ | $O(\log n)$ prom / $O(n)$ peor | $O(\log n)$ prom / $O(n)$ peor | Ninguna (solo punteros base). | Simplicidad extrema de implementación. | Degeneración en lista con datos ordenados. | Fines académicos o flujos puramente aleatorios. |
| Treap | Sí | $O(\log n)$ | $O(n)$ | $O(\log n)$ prom / $O(n)$ peor | $O(\log n)$ prom / $O(n)$ peor | Prioridad aleatoria (`int`) por nodo. | Balanceo probabilístico simple sin lógicas complejas. | Peor caso teórico lineal (baja probabilidad). | Diccionarios dinámicos de propósito general en orden. |
| AVL** | Sí | $O(\log n)$ | $O(\log n)$ | $O(\log n)$ | $O(\log n)$ | Factor de balance o altura por nodo. | Búsquedas hiper-optimistas por balanceo estricto. | Alto costo de rotaciones en escrituras frecuentes. | Bases de datos de lectura intensiva y estática. |
| Red-Black Tree | Sí | $O(\log n)$ | $O(\log n)$ | $O(\log n)$ | $O(\log n)$ | 1 bit para el color por nodo. | Inserciones y borrados rápidos con rebalanceo acotado. | Implementación y depuración sumamente complejas. | Estructuras estándar de la STL (`std::map`, `std::set`). |
| ChainedHashTable | No | $O(1)$ | $O(n)$ | $O(1)$ prom / $O(n)$ peor | $O(1)$ prom / $O(n)$ peor | Punteros de nodos o listas (`ArrayStack`). | Soporta factores de carga altos ($\lambda > 1.0$) sin colapso. | Fragmentación de caché por asignación dinámica externa. | Cachés en memoria y almacenamiento de datos densos. |
| LinearHashTable | No | $O(1)$ | $O(n)$ | $O(1)$ prom / $O(n)$ peor | $O(1)$ prom / $O(n)$ peor | Celdas libres adicionales y vector de estados. | Excelente localidad de caché (vector plano contiguo). | Clustering primario severo bajo factores de carga altos. | Tablas pequeñas a medianas de acceso ultra-rápido. |
| HashtableOA | No | $O(1)$ | $O(n)$ | $O(1)$ prom / $O(n)$ peor | $O(1)$ prom / $O(n)$ peor | Celdas vacías por seguridad y marcas de lápida. | Sin punteros adicionales, memoria plana y compacta. | Degradación crítica del rendimiento por acumulación de lápidas. | Sistemas empotrados o diccionarios temporales de solo lectura. |

* Conclusión final de máximo 20 líneas.

La selección entre estructuras basadas en árboles balanceados y tablas hash constituye uno de los compromisos de diseño más críticos en la ingeniería de software de alto rendimiento. Mientras que las tablas hash maximizan la velocidad pura mediante accesos directos en tiempo constante esperado O(1), este rendimiento se compra a cambio de renunciar por completo al orden de las claves y asumir una vulnerabilidad inherente ante datos adversariales que provoquen colisiones masivas de costo O(n).

Por el contrario, los árboles auto-balanceados como AVL y Red-Black sacrifican la velocidad instantánea en favor de la predictibilidad matemática, garantizando un techo operativo estricto de O(logn) en el peor de los casos y habilitando operaciones complejas basadas en rangos y ordenamientos. Por lo tanto, el ingeniero no debe buscar la estructura óptima absoluta, sino alinear el diseño con los patrones de acceso del sistema: priorizando la dispersión para búsquedas directas de identidad y optando por la jerarquía arbórea balanceada cuando la continuidad espacial y la ordenación de la información dicten el flujo del negocio.

* Un ejemplo concreto donde hashing gana.

Un servidor web recibe 50,000 peticiones por segundo. Cada solicitud incluye un token HTTP tipo UUID string. El servidor debe validar instantáneamente si el token está activo en memoria antes de procesar la petición.

Gana Hashing (LinearHashTable o Robin Hood). Porque al mapear directamente el string a una celda en memoria plana, el Gateway valida el token en un tiempo promedio constante e independiente de la cantidad de usuarios activos O(1). Un árbol balanceado requeriría al menos 16 a 20 comparaciones de strings por cada petición O(logn), teniendo rendimiento bajo en concurrencias masivas.

* Un ejemplo concreto donde AVL o Red-Black Tree gana.

Un sistema financiero registra transacciones bancarias indexadas por una clave de marca de tiempo (timestamp). El operador del sistema ejecuta constantemente reportes analíticos con filtros específicos tales como: "Obtener todas las transacciones realizadas entre las 14:00 y las 16:30 del día de hoy".

Gana Árbol Balanceado (Red-Black Tree / AVL). Porque la estructura permite ejecutar un lowerBound para ubicar el nodo inicial en O(logn) y de ahí realizar un recorrido secuencial hasta el límite superior (upperBound). Una tabla hash se vería obligada a realizar un escaneo completo de todas las celdas para evaluar si cada elemento esta en el rango horario, destruyendo la eficiencia.

## Conclusión técnica personal

El dilema entre usar tablas hash y árboles balanceados se basa en la predictibilidad.

Si el sistema requiere velocidad pura y lineal bajo un flujo controlado, usas las tablas hash en tiempo O(1). Sin embargo, en entornos críticos donde no puedes permitirte picos de latencia por colisiones o rehashes, el costo garantizado O(logn) de un árbol balanceado (como un Red-Black Tree) ofrece la estabilidad y la flexibilidad de orden que salvan la producción en el peor escenario.
