## Actividad 4-CC232

### Estudiante
- Chumbimuni Ricci Andre Dylan


### Bloque 1 - Núcleo conceptual de la semana

1. Explica con tus palabras la diferencia entre acceso `LIFO` y acceso `FIFO`.

LIFO como indica el nombre es el ultimo en entrar es el primero en salir y FIFO es el primero en entrar y primero en salir.

2. Explica por qué `Stack` resuelve naturalmente problemas donde importa "lo último pendiente".

Una Pila Stack es LIFO. Al hacerlo, la información más reciente que guardas se convierte inmediatamente en la primera que vas a procesar

3. Explica por qué `Queue` modela naturalmente procesos de espera y atención.

Una Cola Queue funciona bajo el modelo FIFO, que es la representación exacta de la "justicia cronológica": el que llega primero, es atendido primero.

4. Explica qué significa reemplazar recursión implícita por una estructura explícita.

Una función recursiva es una función que se llama a sí misma, el programa utiliza la Pila de Llamadas (Call Stack) del sistema para recordar en qué línea se quedó cada función y qué valores tenía.la recursion implicita es cuando tu no lo gestionas si no el SO.

5. Explica qué información mínima debe guardarse para que una pila permita reconstruir una solución parcial.

El estado actual y las alternativas de caminos pendientes, si un camino falla prueba la siguiente alternativa.

6. Compara la conversión de base recursiva e iterativa: ¿qué comparten y qué cambia en el control del proceso?

Comparten que ambos dividen al numero entre la base y guardan los residuos y los leen en orden inverso.
En la recursiva, el SO controla el LIFO usando la pila de llamadas. En la iterativa,tú controlas el proceso creando explícitamente una estructura de datos Stack.

7. Explica por qué la verificación iterativa de paréntesis necesita almacenar aperturas pendientes.

Porque cuando almacena un parentisis de entrada no se sabe cuando aparecera el parentesis de salida, por lo que necesitas recordar el parentisis de entrada.

8. Explica por qué el evaluador de expresiones necesita dos pilas y no una sola.

Porque una expresión  es para los números (operandos) y el otro para los símbolos (operadores). Necesitas separarlos para poder aplicar reglas como multiplicar antes de sumar. Una pila guarda los valores acumulados y la otra guarda los operadores en espera de que les llegue su turno de ejecutarse.

9. Explica por qué N-Reinas y laberinto son ejemplos naturales de backtracking.

Porque son problemas de ensayo y error. No existe una fórmula directa para saber dónde poner la reina o qué camino tomar.

10. Explica por qué la simulación bancaria no se modela bien con pila, pero sí con colas.

Porque un banco real funciona bajo el principio de "justicia". Si usaras una Pila (LIFO), la última persona en entrar es la primera en ser atendida, y la persona que llegó temprano seria la ultima, cosa que en una cola seria al revez.

11. Explica qué relación hay entre estructura auxiliar, estado parcial y correctitud.

Estructura auxiliar: Es la memoria (Pila, Cola), el estado parcial es "dónde estoy ahora" en medio del cálculo y la correctitud es que el algoritmo dé la respuesta correcta.
La relación es si eliges la estructura auxiliar adecuada, esta guardará los estados parciales en el orden correcto (LIFO o FIFO). Al procesarlos en el orden dictado por la naturaleza del problema, garantizas la correctitud del resultado final.

12. Explica qué diferencia conceptual hay entre "resolver un problema" y "simular un proceso".

Resolver un problema se enfoca en encontrar un resultado final único u óptimo. No importa cómo llegues ahí, lo importante es la respuesta final.
Simular un proceso se enfoca en imitar el comportamiento de un sistema paso a paso. Aquí no hay una "respuesta final" ganadora; el objetivo es estudiar cómo cambian los estados intermedios a través del tiempo.

### Bloque 2 - Demostración y trazado guiado

| Archivo | Salida u observable importante | Estructura o técnica central | Qué concepto permite defender |
| :--- | :--- | :--- | :--- |
| **`demo_stack_queue.cpp`** | `Tope = 9` / `Pop = 9`<br>`Frente = 10` / `Dequeue = 10` | Pila (`ods::Stack`) y Cola (`ods::Queue`) lineales. | La diferencia fundamental entre la filosofía **LIFO** (último en entrar, primero en salir) y **FIFO** (primero en entrar, primero en salir). |
| **`demo_base_conversion.cpp`** | Ambas funciones devuelven la misma cadena `12345 en base 8 = 30071`. | Recursión implícita vs. `Stack` explícito. | La **equivalencia de control**: cualquier proceso recursivo puede simularse iterativamente usando una pila propia para evitar el *Stack Overflow*. |
| **`demo_paren_rpn.cpp`** | `Parentesis balanceados = true`, la cadena en RPN y el `Valor de la expresion = 2012`. | Pilas duales (operadores/operandos) y algoritmo Shunting-yard. | Cómo las pilas eliminan la ambigüedad y los paréntesis de una operación, convirtiéndola en una estructura lineal fácil de evaluar por una máquina. |
| **`demo_nqueens.cpp`** | `N=4,  soluciones = 2, verificaciones = 84` y las matrices con las posiciones({1 3 0 2},{2 0 3 1}). | **Backtracking** (Ensayo y error sistemático). | La capacidad de explorar un árbol de decisiones completo, **guardando estados parciales** y retrocediendo cuando se viola una regla de aislamiento. |
| **`demo_maze.cpp`** | `Medida del camino = 5` y la lista secuencial de coordenadas `(1,1) (1,2) (1,3) (2,3) (3,3)`. | Búsqueda de caminos mediante Pilas/Colas sobre matrices. | El uso de estructuras auxiliares para reconstruir una **solución geométrica paso a paso** sin perder el rastro del camino correcto. |
| **`demo_bank.cpp`** | `Llegadas=7 `, `atendidos=0` y las listas `[t=0: [87][][], t=1: [86][12][] ...` . | Simulación por tiempo discreto usando múltiples colas FIFO. | La **justicia cronológica** en el modelado de procesos reales. Demuestra cómo las colas gestionan la congestión en sistemas de espera. |
| **`demo_capitulo4_panorama.cpp`** | Mensaje de éxito inicial `Semana 4 cargada correctamente` y la impresión de todas las salidas integradas en un solo bloque. | Integración modular de TDA (Pilas y Colas) y algoritmos avanzados. | La **versatilidad** de las estructuras lineales: herramientas simples (pilas/colas) sirven como base para resolver problemas complejos y diversos. |



1. En `demo_stack_queue.cpp`, ¿qué parte de la salida deja más clara la diferencia entre tope y frente?

Como stack es un pila(LIFO) donde el tope es el elemento 9(cima) sera el primero en salir; y en la cola queue, el primer elemento(frente) es 10 que va a ser el primero en salir (FIFO) .

2. En `demo_base_conversion.cpp`, ¿qué observable permite afirmar que las versiones recursiva e iterativa producen la misma representación?

El observable es el resultado textual idéntico en la consola. Ambas funciones reciben el mismo número (12345) y la misma base (8), y devuelven exactamente el mismo string.

3. En `demo_paren_rpn.cpp`, ¿qué relación observas entre paréntesis balanceados, RPN y valor final?

La relación es un flujo de validación y transformación:

Primero se verifica que los paréntesis estén balanceados (true) para garantizar que la expresión sea válida.
Luego, las pilas separan los operadores de los operandos, reordenándolos en RPN, lo que destruye la necesidad de usar paréntesis.
Finalmente, esa cadena lineal limpia en RPN es la que permite procesar y calcular de manera directa y sin ambigüedades el valor final.

4. En `demo_nqueens.cpp`, ¿qué significan `solutions` y `checks`, y por qué no miden lo mismo?

solutions: Es la cantidad de tableros finales válidos encontrados donde las 4 reinas están a salvo.

checks: Es el número total de veces que el algoritmo tuvo que validar si una reina atacaba a otra en cualquier celda.
No miden lo mismo porque checks mide el esfuerzo total del algoritmo, incluyendo todos los caminos falsos e intentos fallidos que el Backtracking tuvo que explorar y desechar (poda) antes de encontrar las soluciones reales.

5. En `demo_maze.cpp`, ¿qué muestra la secuencia de coordenadas sobre el camino encontrado?

Muestra una ruta continua y adyacente paso a paso, desde el punto de inicio (1,1) hasta el punto de destino (3,3). Al ver que las coordenadas cambian de uno en uno (por ejemplo, de 1,1 a 1,2), se demuestra que la estructura guardó el rastro físico del laberinto sin dar saltos mágicos o atravesar paredes (#).

6. En `demo_bank.cpp`, ¿qué representa cada lista impresa en cada instante `t`?

Representa la fotografía exacta de las filas del banco en ese segundo o minuto específico. Cada [] es una ventanilla de atención, y los números dentro de los corchetes muestran cuántos clientes están haciendo cola en ese preciso instante de tiempo t. Permite ver visualmente cómo la cola crece cuando llegan clientes o se vacía cuando son atendidos.

7. En `demo_capitulo4_panorama.cpp`, ¿qué salida resume mejor la idea de que una misma semana reúne estructuras y aplicaciones?

Lo resume el bloque final de impresiones en consola, donde se ejecutan consecutivamente algoritmos de áreas totalmente distintas: evaluación matemática (RPN), juegos/inteligencia artificial (N-Reinas), robótica/navegación (Laberinto) y operaciones de negocios (Banco). Ver todas esas salidas juntas demuestra que las estructuras fundamentales de Pilas y Colas son el motor de aplicaciones muy diversas.

### Bloque 3 - Pruebas públicas, pruebas internas y correctitud

1. ¿Qué operaciones mínimas valida la prueba pública para `Stack`?

Valida el ciclo de vida básico de la estructura en orden LIFO:

empty(): Verifica que inicie vacía y termine vacía tras los procesos.

push(): Inserta elementos consecutivamente (5 y luego 9).

top(): Comprueba cuál es la cima actual sin removerla (debe ser 9).

pop(): Extrae y devuelve los elementos en orden inverso al que entraron (primero el 9, luego el 5).

2. ¿Qué operaciones mínimas valida la prueba pública para `Queue`?

Valida el comportamiento de una fila en orden FIFO:

empty(): Monitorea el estado de vacío inicial y final.

enqueue(): Inserta elementos en fila (1, 2 y luego 3).

front(): Inspecciona el primer elemento en espera sin sacarlo (debe ser 1).

dequeue(): Extrae los elementos respetando estrictamente el orden de llegada (1, luego 2 y al final 3).

3. ¿Qué valida la prueba pública sobre conversión de base?

Comprueba que un número entero genérico (12345) sea transformado correctamente a base octal ("30071"), y asegura que tanto la estrategia recursiva como la iterativa produzcan exactamente el mismo resultado string.

4. ¿Qué valida la prueba pública sobre paréntesis balanceados?

Valida tres escenarios de agrupación comunes:

Un caso simple con paréntesis uniformes perfectamente emparejados (true).

Un caso complejo que mezcla múltiples símbolos ((), [], {}) ordenados correctamente (true).

Un error de cruce de cierres incorrecto (([)]), que debe ser detectado como inválido (false).

5. ¿Qué valida la prueba pública sobre evaluación de expresiones y RPN?

Valida una expresión aritmética masiva que combina múltiples reglas: operaciones aritméticas básicas, prioridades con paréntesis, factoriales (!) y potencias (^). Asegura que el algoritmo reordene correctamente los tokens en la cadena RPN y que la evaluación final con números flotantes sea exacta (2012.0).

6. ¿Qué valida la prueba pública sobre `NQueens`?

Valida el funcionamiento del Backtracking sobre el tablero estándar de N = 4. Verifica que el algoritmo sea capaz de encontrar exactamente las 2 soluciones únicas que existen matemáticamente para este tamaño de cuadrícula sin omitir ninguna.

7. ¿Qué valida la prueba pública sobre `Maze`?

Valida la resolución de un laberinto con una ruta accesible. Comprueba que el algoritmo devuelva una lista de coordenadas que no esté vacía, y asegura las condiciones de frontera básicas: que el punto de partida sea obligatoriamente (1,1) y la meta alcanzada sea (3,3).

8. ¿Qué valida la prueba pública sobre `bestWindow` en la simulación bancaria?

Valida la lógica de decisión inteligente para la asignación de clientes. El test simula un banco con tres ventanillas: una con dos personas, otra con una persona, y una tercera completamente vacía. Verifica que el código retorne el índice 2, demostrando que el sistema elige correctamente la ventanilla con la menor carga de espera.

9. ¿Qué casos adicionales cubre la prueba interna y no aparecen de forma explícita en la pública?

Valores nulos y límites en bases: Evalúa la conversión del número 0 (que suele romper bucles mal diseñados) y el uso de bases con caracteres alfanuméricos como la Hexadecimal (255 -> "FF").

Gestión de Excepciones: Intenta forzar una conversión con una base inválida (base 1) para certificar que el código lance correctamente un error std::invalid_argument.

Strings atípicos en paréntesis: Valida cadenas que no tienen ningún paréntesis ("sin parentesis" que debe dar true) y cadenas que inician con un cierre huérfano (")()(" que debe dar false).

Operadores unarios: Evalúa cómo se comporta el calculador ante un signo de menos negativo al inicio de la expresión ("-3+5").

El laberinto imposible: Prueba un mapa donde la meta está completamente bloqueada por paredes (#), validando que el algoritmo lo detecte devolviendo un camino vacío (empty()) de forma segura en lugar de caer en un bucle infinito.

El tablero mínimo: Prueba NQueens con N = 1, que es el caso base absoluto del problema.

10. ¿Por qué pasar pruebas no reemplaza una explicación de invariantes, estado y complejidad?

Porque las pruebas unitarias solo demuestran que el programa funciona para un conjunto limitado y cerrado de ejemplos.

Un algoritmo pésimo con complejidad de tiempo horrible (como un Laberinto que explore de forma ineficiente tardando horas) pasará el test público si el mapa es minúsculo.

La sustentación teórica demuestra que el código es robusto ante cualquier situación y que su consumo de recursos es óptimo.

11. Da un ejemplo de un error conceptual que podría sobrevivir si solo se ejecutaran los casos mínimos.

Si se asume que el símbolo de resta - siempre separa a dos números (un operador binario como A - B), la prueba pública pasará perfectamente porque dice -(5!-67...) donde el menos actúa de forma similar tras resolver el paréntesis. Sin embargo, si le ingresas el caso de la prueba interna ("-3+5"), un código con ese error conceptual fallará rotundamente o crasheará, porque el menos ahí es un operador unario (modifica solo al 3) y no tiene un operando izquierdo con el cual trabajar.

### Bloque 4 - Comparación recursivo vs iterativo

1. En conversión de base, ¿qué papel juegan el cociente, el residuo y la pila?

El Residuo (n % base): Representa el valor del dígito actual en la nueva base. Las divisiones sucesivas van extrayendo estos dígitos desde las unidades hacia arriba.

El Cociente (n / base): Es la parte reducida del número que queda por procesar. Se utiliza como el nuevo valor de n para la siguiente iteración o llamada recursiva hasta llegar a 0.

La Pila (Stack<char>): Recibe los residuos en el orden en que se calculan (al revés). Como la pila opera bajo el principio LIFO, al retirar todos los elementos al final con popAll, los dígitos salen invertidos, devolviendo el número en el orden correcto de lectura.

2. ¿Por qué los residuos se apilan antes de formar la cadena final?

Porque el algoritmo matemático de división sucesiva extrae los dígitos "de atrás hacia adelante" (empezando por las unidades). Si concatenáramos los residuos directamente en un string conforme van saliendo, el número final quedaría completamente al revés. La pila se usa como una herramienta de inversión lógica: lo primero que entra es lo último que sale, ordenando la cadena de manera correcta de izquierda a derecha.

3. ¿Qué cambia entre dejar que el call stack haga el trabajo y manejar una pila explícita?

En la versión iterativa, el estado de las variables y el bucle while ocurren dentro de un único marco de ejecución. Es altamente eficiente en memoria.

En la versión recursiva, cada paso genera una nueva llamada a convertRecursive. El Sistema Operativo tiene que usar el Call Stack (pila de llamadas) del sistema para recordar en qué línea se quedó cada función y qué valores tenían n y base. Si el número fuera colosalmente grande, delegar el control al Call Stack podría arriesgar un desbordamiento de pila (Stack Overflow).

4. En `parenRecursive`, ¿qué idea intenta capturar `divideParentheses`?

Intenta capturar el concepto de aislamiento de un bloque jerárquico. Dado un paréntesis de apertura en la posición lo, esta función busca su pareja exacta de cierre mi. Para lograrlo, utiliza un contador (crc) que aumenta con cada ( y disminuye con cada ). Esto permite "saltarse" limpiamente cualquier sub-bloque que esté anidado adentro. Una vez encontrado el límite, el problema se divide en dos: validar lo que está adentro del bloque y validar lo que continúa después de él.

5. ¿Qué limitación conceptual tiene la versión recursiva mostrada frente a la iterativa cuando aparecen `[]` y `{}`?

La versión recursiva compartida está completamente acoplada a un solo tipo de símbolo (). Su función trimParentheses ignora físicamente las llaves y los corchetes, tratándolos como si fueran texto ordinario. Modificar esta lógica para que valide de forma recursiva estructuras mixtas o cruzadas como {[(])} requeriría un árbol de decisiones extremadamente complejo y costoso de programar. La versión iterativa, en cambio, maneja múltiples tipos de forma nativa simplemente comparando el tope de la pila en un switch-case.

6. En `parenIterative`, ¿por qué un cierre incorrecto puede detectarse apenas aparece?

Debido a la naturaleza LIFO. Si el programa lee un ] y al inspeccionar la pila nota que está vacía (un cierre huérfano) o que el elemento en la cima es un (, la regla de oro se rompe inmediatamente. El algoritmo no necesita perder tiempo leyendo el resto de la cadena; detecta el error al instante y retorna false.

7. Compara ambas parejas de funciones: ¿en cuál caso la versión iterativa te parece más natural y en cuál la recursiva resulta más expresiva?

Conversión de base: La versión iterativa es la más natural. El proceso matemático se reduce a un bucle directo y plano que divide un número consecutivamente. Añadir recursión aquí no aporta claridad y consume más recursos.

Verificación de paréntesis: La versión iterativa es, por mucho, la más limpia y expresiva para escenarios del mundo real. Aunque la recursividad es una manera muy elegante de esquematizar la teoría de lenguajes y bloques jerárquicos, en la práctica del código se vuelve rígida, ineficiente y difícil de adaptar a múltiples tipos de llaves.

#### Experimento 1

Creado en la carpeta demos llamado demo_experimento1.cpp:
Imprimiendo las 5 primeras filas:
```
| Número    | Base | Salida Recursiva  | Salida Iterativa      | ¿Coinciden? | Comentario |
|          0 |     2 |                    0 |                    0 |        Sí | Caso base límite: El cero es invariante en cualquier base. |
|          0 |     8 |                    0 |                    0 |        Sí | Caso base límite: El cero es invariante en cualquier base. |
|          0 |    10 |                    0 |                    0 |        Sí | Caso base límite: El cero es invariante en cualquier base. |
|          0 |    16 |                    0 |                    0 |        Sí | Caso base límite: El cero es invariante en cualquier base. |
|         45 |     2 |               101101 |               101101 |        Sí | Base binaria: Evalúa la máxima longitud de bits en la pila. |
```
#### Experimento 2

Creado en la carpeta demos llamado demo_experimento2.cpp:
Imprimiendo las 3 primeras filas:
```
| Categoría       | Expresión | Resultado Recursivo | Resultado Iterativo | ¿Coinciden? | Explicación del Caso |
| Vacía   |         | TRUE (Válido)        | TRUE (Válido)        | Sí                  | Caso base absoluto. Ambos algoritmos lo procesan como exitoso inmediatamente. |
| Sin paréntesis   | Expresion plana con texto 123        | TRUE (Válido)        | TRUE (Válido)        | Sí                  | No contiene delimitadores. La iterativa termina con pila vacía y la recursiva reduce sus índices a cero. |
| Correctamente anidada   | ((a + b) * (c - d))        | TRUE (Válido)        | TRUE (Válido)        | Sí                  | Estructura pura de paréntesis circulares con anidamiento válido. Ambos métodos funcionan perfecto. |
```
### Bloque 5 - Evaluación de expresiones y prioridad de operadores

1. Explica qué información guarda `EvaluationResult`.

Es una estructura de datos (struct) diseñada para empaquetar y devolver de manera compacta los dos productos finales del procesamiento de la expresión:

double value: El valor numérico final calculado tras resolver todas las operaciones aritméticas.

std::string rpn: La representación de la expresión en Notación Polaca Inversa, donde los operandos anteceden a sus operadores y se eliminan por completo los paréntesis.

2. Explica por qué primero se eliminan espacios.

Para simplificar la fase de tokenización y análisis sintáctico. Al limpiar caracteres invisibles como  , \t o \n mediante removeSpaces, el algoritmo garantiza que el puntero de lectura (i) avance de manera continua y predecible de un carácter significativo al siguiente. Además, evita tener que implementar comprobaciones redundantes de espacios en funciones clave como la lectura de números o la detección del operador unario.

3. Explica cómo se detecta el signo menos unario.

La función isUnaryMinus implementa una máquina de estados contextual. Para que un caracter - sea interpretado como el signo negativo de un número y no como una operación de resta, debe cumplir tres condiciones concurrentes:

Tener un dígito o un punto inmediatamente a su derecha (i + 1).

Estar al principio absoluto de la expresión (i == 0).O, si está en el medio, estar precedido inmediatamente por otro operador o paréntesis de apertura (por ejemplo, el - en 5 * (-3) o + - 4). 

Si lo antecediera un número o un factorial, se trataría de una resta ordinaria.

4. Explica por qué el factorial se trata como operador unario y qué restricción impone el código.

Es un operador unario porque semánticamente se aplica sobre un único operando situado inmediatamente a su izquierda ($n!$).El código impone dos restricciones estrictas sobre él:

Numérica: El operando debe ser matemáticamente un número entero (std::fabs(b - rounded) < 1e-9). Si es un flotante puro (como 5.5!), el código lanza un runtime_error.

De Dominio: El entero no puede ser negativo (n < 0), arrojando una excepción en factorialInt ya que el factorial estándar no está definido en ese espectro.

5. Explica cómo la RPN se va construyendo durante la evaluación y no al final.

Se construye mediante un enfoque on-the-fly aprovechando la misma lógica de decisión del algoritmo:

Cuando el lector identifica un número, este se concatena inmediatamente a la cadena rpn.

Cuando el analizador determina que un operador del tope tiene mayor precedencia que el símbolo actual (caso '>'), el operador es retirado de la pila e incorporado a la cadena rpn justo antes de ser ejecutado.

Esto evita tener que hacer un doble recorrido; ambos procesos van de la mano.

6. Explica qué significa la relación entre operador del tope y símbolo actual.

Representa la acción sintáctica dictada por la matriz de precedencia pri en OperatorPriority.h:

'<' (Precedencia Menor): El operador del tope tiene menos jerarquía que el entrante. El símbolo actual se apila en operators para esperar su momento.

'>' (Precedencia Mayor): El operador en el tope es más prioritario que el entrante. Se desapila, se manda a la RPN y se evalúa sobre los operandos acumulados.

'=' (Prioridad Equivalente): Ocurre únicamente entre un paréntesis izquierdo  y uno derecho , o entre el inicio y el fin de la expresión (\0). Significa que el bloque se ha cerrado con éxito y el operador se descarta.

7. Explica por qué una expresión mal formada debe terminar en error y no en un valor arbitrario.

Porque un software de cálculo debe garantizar la integridad de los datos. Si una expresión como 5 + * 3 o (4 + 2 devolviera un valor por defecto (como 0.0), el sistema ocultaría fallos de lógica del usuario o errores de transmisión de datos. Lanzar un runtime_error detiene la ejecución inmediatamente y notifica de manera transparente que la entrada es inválida, impidiendo que cálculos erróneos se propaguen.

8. ¿Qué ventaja conceptual tiene obtener a la vez el valor y la RPN?

Proporciona un mecanismo nativo de auditoría y verificación. 
La RPN actúa como la "caja negra" o el mapa de ejecución que muestra exactamente cómo interpretó la máquina las prioridades asociadas por el usuario. Al depurar o evaluar, si el value no coincide con lo esperado, inspeccionar la rpn te permite discernir de inmediato si el error fue un fallo de cálculo numérico o una mala interpretación de la jerarquía de los operadores.

#### Experimento 3
Creado en la carpeta demos llamado demo_experimento3.cpp:

Imprimiendo las filas:
```
Categoría: Válida sin paréntesis (1)
Expresión: 3+4*2^3
RPN Obtenida:  3 4 2 3 ^ * +
Valor Obtenido: 35

Categoría: Válida sin paréntesis (2)
Expresión: 5!/4-2
RPN Obtenida:  5 ! 4 / 2 -
Valor Obtenido: 28

Categoría: Válida con anidamiento (1)
Expresión: (2+3)^(4-2)
RPN Obtenida:  2 3 + 4 2 - ^
Valor Obtenido: 25

Categoría: Válida con anidamiento (2)
Expresión: 2*(3!+(4-1)!)
RPN Obtenida:  2 3 ! 4 1 - ! + *
Valor Obtenido: 24

Categoría: Con menos unario
Expresión: -5+3!*-2
RPN Obtenida:  -5 3 ! -2 * +
Valor Obtenido: -17

Categoría: Expresión Inválida
Expresión: 5+*3
Error Observado: std::runtime_error (faltan operandos para el operador binario)
```
#### Extensión opcional

Símbolo agregado: % (Operador Módulo).

Aridad: Binario (requiere dos operandos, ej. $A \% B$).

Prioridad: Tiene la misma jerarquía que la multiplicación y la división. Esto significa que es superior a la suma y la resta, pero inferior a la potencia y al factorial. De izquierda a derecha, se evalúa conforme aparece (asociatividad a la izquierda).

Casos válidos probados:10 % 3 $\rightarrow$ 
Debe dar 1.0 (RPN: 10 3 %).5 + 11 % 4 * 2 $\rightarrow$ 
Primero el módulo ($11 \% 4 = 3$), luego multiplicación ($3 \times 2 = 6$) y suma ($5 + 6 = 11$). 
Debe dar 11.0.

Caso inválido probado:5 % 0 $\rightarrow$ Debe lanzar un error en tiempo de ejecución (runtime_error) por intentar calcular un residuo con un divisor igual a cero.5.5 % 2 $\rightarrow$ 
Debe lanzar un error dado que el módulo conceptualmente requiere operandos enteros.

2. Modificaciones Obligatorias en el Código

Modificación A: En OperatorPriority.h

Expandir el Enum: Añadir el identificador MOD antes de los paréntesis.

Crecer la Matriz: Modificar N_OPTR de 9 a 10 e insertar una nueva fila y columna en la tabla pri que copie exactamente el comportamiento de las filas/columnas de MUL (*) y DIV (/).

Mapear el Carácter: En optr2rank, añadir el case '%': return MOD;.

Modificación B: En ExpressionEvaluator.h

Registrar como Operador: En isOperatorChar, añadir case '%': para que el tokenizador lo reconozca y no intente leerlo como parte de un número.

Implementar la Operación: En la función sobrecargada calcu para operaciones binarias, añadir el cálculo matemático:

### Bloque 6 - Backtracking explícito: N-Reinas y laberinto

1. En `Queen`, ¿qué significa que dos reinas entren en conflicto?

Significa que ambas reinas se encuentran en una posición del tablero donde se pueden amenazar mutuamente según las reglas del ajedrez. El operador sobrecargado == lo verifica de forma puramente matemática mediante cuatro condiciones:

x == other.x: Comparten la misma fila.

y == other.y: Comparten la misma columna.

x + y == other.x + other.y: Comparten la diagonal secundaria (pendiente positiva).

x - y == other.x - other.y: Comparten la diagonal principal (pendiente negativa).

2. En `NQueens`, ¿qué representa exactamente la pila `solution`?

La pila representa el estado parcial de un tablero válido en un momento determinado de la búsqueda. Cada elemento de la pila es un objeto Queen cuyas coordenadas $(x, y)$ indican la fila y columna donde ha sido colocada de forma segura. El tamaño de la pila (solution.size()) indica de manera directa cuántas filas consecutivas (desde la $0$ hasta la $x-1$) han sido resueltas con éxito hasta el momento.

3. ¿Qué significa avanzar en columna dentro de una fila y cuándo toca retroceder?

Avanzar en columna (++q.y): Significa desplazar lateralmente a la reina actual para probar si la siguiente celda de la misma fila está libre de amenazas. Esto ocurre de forma secuencial dentro del bucle while mientras se sigan detectando conflictos con las reinas ya fijadas.

Cuándo toca retroceder (Backtrack): Toca retroceder cuando el puntero de columna llega al borde del tablero (q.y >= n) sin haber encontrado ninguna casilla segura en esa fila. El algoritmo reconoce que el camino actual es un callejón sin salida, retira la última reina colocada de la pila (solution.pop()) para regresar a la fila anterior y desplaza a esa reina previa a la siguiente columna (++q.y) para explorar alternativas.

4. ¿Por qué `checks` es una métrica útil para analizar la búsqueda?

Porque permite auditar y cuantificar la complejidad temporal práctica del algoritmo. En lugar de basarse únicamente en el tiempo de reloj del procesador (que cambia según el hardware), la variable checks cuenta el número exacto de comparaciones individuales realizadas entre pares de reinas. Es una métrica excelente para observar el comportamiento exponencial del algoritmo frente a distintos valores de $N$ y comprobar cómo el Backtracking poda ramas enteras del árbol de decisiones.

5. ¿Qué cambia cuando `collectPlacements` vale `false`?

Cambia radicalmente la eficiencia en el uso de la memoria dinámica. Cuando es false, el algoritmo simplemente cuenta cuántas configuraciones válidas existen (++result.solutions) pero no almacena las coordenadas de los tableros en el contenedor result.placements. Esto evita la asignación repetida de vectores e impide que la memoria RAM se sature cuando se buscan soluciones para valores de $N$ muy grandes ($N \ge 12$), donde el número de soluciones crece de forma masiva.

6. En `Maze`, ¿qué representa el estado `AVAILABLE`, `ROUTE`, `BACKTRACKED` y `WALL`?

Representan el ciclo de vida y la clasificación topológica de cada celda del laberinto:

WALL: Una pared infranqueable; el algoritmo nunca la puede pisar.

AVAILABLE: Una celda de pasadizo libre que aún no ha sido explorada ni evaluada por la ruta.

ROUTE: Una celda que forma parte activa del camino actual guardado en la pila hacia la meta.

BACKTRACKED: Una celda que ya fue visitada pero que demostró ser un callejón sin salida. Se marca así para que el algoritmo no vuelva a perder tiempo entrando en ella.

7. ¿Qué información codifican `incoming` y `outgoing`?

Codifican la historia direccional y el flujo del movimiento en los puntos cardinales (Este, Sur, Oeste, Norte):

outgoing: Almacena hacia qué punto cardinal se está intentando avanzar desde la celda actual. Funciona como una memoria local para recordar qué direcciones ya se probaron y cuál toca evaluar a continuación.

incoming: Registra desde qué dirección se ingresó a la celda actual. Es de vital importancia para establecer el vínculo físico de procedencia con el nodo padre al avanzar con la función advance.

8. ¿Por qué el algoritmo del laberinto marca y desmarca estado en lugar de solo "moverse"?

Porque opera bajo el principio de búsqueda con memoria. Al marcar una celda como ROUTE, el camino se autoprotege de morderse la cola. Al marcarla como BACKTRACKED, el algoritmo deja un rastro o "migaja de pan" permanente que clausura esa sección del mapa, asegurando que el proceso siempre progrese hacia áreas inexploradas o termine de forma segura si no hay solución.

9. Compara N-Reinas y laberinto: ¿qué comparten como problemas de búsqueda y qué cambia en la representación del estado?

Lo que comparten: Ambos problemas son modelados como árboles de decisión explorados de manera iterativa mediante Búsqueda en Profundidad (DFS) asistida por una pila explicita (Stack). Los dos aplican la filosofía del Backtracking: avanzan de forma optimista explorando un camino y, en el instante en que violan una restricción matemática o física desatan un retorno controlado para reconfigurar la última decisión tomada.

Lo que cambia en la representación del estado:

En N-Reinas, el estado es abstracto y global. No existe un mapa físico precargado. Cada paso genera dinámicamente restricciones espaciales en todo el tablero futuro. El estado se recupera íntegramente leyendo el contenido de la pila.

En el Laberinto, el estado es concreto, local y topológico. Existe una cuadrícula física preexistente (Maze). Las restricciones están dadas de forma estática por las paredes (WALL) y de forma dinámica por la celda adyacente inmediata. Aquí la pila solo almacena los punteros del camino de celdas activas, pero el estado de visitado o clausurado queda guardado directamente dentro de cada celda de la matriz (cells_).

#### Experimento 4

Cambiando demo_nqueens.cpp para que imprima N, soluciones, verificaciones, la distribucion de coordenadas de columnas por fila.

| `n` | Número de Soluciones | Número de `checks` | ¿Crece rápido o lento? | Comentario |
| :---: | :---: | :---: | :--- | :--- |
| **4** | 2 | 84 | Lento | Caso mínimo con solución. El árbol de búsqueda es sumamente pequeño y se resuelve de inmediato. |
| **5** | 10 | 405 | Moderado | El número de verificaciones se quintuplica, reflejando cómo cada nueva fila añade ramificaciones al árbol. |
| **6** | 4 | 2,016 | Rápido | Curiosamente hay menos soluciones que en $N=5$, pero el costo de exploración interna se dispara considerablemente. |
| **8** | 92 | 46,752 | **Exponencial** | El clásico tablero de ajedrez estándar. La cantidad de `checks` explota masivamente, evidenciando el costo del problema. |


1. ¿Qué patrón observas en el crecimiento de `checks`?

El crecimiento de la métrica checks sigue un patrón combinatorio/exponencial ($O(N!)$ en el peor de los casos). Al incrementar $N$ linealmente, el espacio de estados no crece sumando casillas, sino multiplicando las posibilidades de cada fila nueva por todas las anteriores. Por ejemplo, al pasar de $N=6$ a $N=8$ (un incremento de solo dos unidades), el número de verificaciones saltó de menos de $2,016$ a casi $46,752$.

2. ¿Por qué contar verificaciones no es lo mismo que contar soluciones?

Contar soluciones es simplemente llevar el registro de los "éxitos absolutos", es decir, cuántas veces la pila se llenó por completo (solution.size() == n) con reinas que no se atacan.

Contar verificaciones (checks) mide el esfuerzo de exploración total, incluyendo todos los intentos fallidos, callejones sin salida y retrocesos.

3. ¿Dónde aparece la "poda" en este código, aunque no haya una estructura formal con ese nombre?

La poda ocurre de manera implícita en la condición del bucle while que busca una columna válida:

```
while (q.y < n && conflictsWithAny(solution, q, result.checks)) {
    ++q.y;
}
```
Si la reina candidata q en la fila actual genera conflicto con cualquiera de las reinas ya colocadas en la pila (solution), el algoritmo descarta esa casilla inmediatamente incrementando q.y. Al hacer esto, el algoritmo evita pasar a la siguiente fila (++q.x). Conceptualmente, lo que está haciendo es amputar (podar).

#### Experimento 5

Cambiando demo_maze.cpp para los tres casos:
```
Inicio: (1, 1) -> Destino: (3, 1)
Medida del camino = 11 celdas
Mapa de Evidencia ('*'=camino, 'B'=Retroceso):
#######
#*****#
#####*#
#*****#
#######

LABERINTO 2: SIN SALIDA 
Inicio: (1,1) -> Destino: (1,5)
Longitud del camino: 0 (Ausencia de camino)
Mapa de Evidencia ('*'=Camino, 'B'=Retroceso):
#######
#BBB#.#
###B#.#
#BBB#.#
#######

LABERINTO 3: MÚLTIPLES RETROCESOS
Inicio: (1,1) -> Destino: (5,4)
Longitud del camino: 8 celdas
Mapa de Evidencia ('*'=Camino, 'B'=Retroceso):
########
#*BBBBB#
#*####B#
#*#..#B#
#*##.#B#
#****#B#
########
```
### Bloque 7 - Simulación bancaria y experimentación con colas

1. ¿Qué representa cada `Queue<Customer>` dentro del vector `windows`?

Representa la fila física de clientes esperando ser atendidos delante de una ventanilla específica. Cada ventanilla tiene asignada su propia cola independiente de tipo FIFO (First-In, First-Out). El primer cliente en la cola es el que está siendo atendido activamente en ese instante por el cajero, mientras que los que están detrás esperan su turno conforme el tiempo restante de atención (time) del cliente al frente se reduce a cero.

2. ¿Qué criterio usa `bestWindow` y qué decisión toma cuando hay empate?

Criterio: Evalúa de manera codiciosa (greedy) la longitud actual de todas las filas y elige aquella que tenga la menor cantidad de clientes en espera (windows[i].size()).

En caso de empate: El algoritmo favorece a la ventanilla con el índice numérico más bajo. Esto se debe al operador de comparación estricta < (if (windows[i].size() < minSize)). Si encuentra otra ventana con exactamente el mismo tamaño mínimo que el ya registrado, la condición resulta falsa y no actualiza la variable opt.

3. ¿Qué significa que la simulación use una semilla (`seed`)?

Significa que el experimento es estocástico pero $100\%$ determinista y replicable. Al inicializar el motor de números pseudoaleatorios con un valor fijo (std::mt19937 rng(seed)), la secuencia de eventos (cuándo llega un cliente y cuánto tiempo de atención requiere) será exactamente la misma cada vez que ejecutes el programa. Esto es crucial en ingeniería de software para depurar código, comparar cambios en el algoritmo bajo idénticas condiciones de estrés y realizar auditorías científicas de rendimiento.

4. ¿Qué relación debe cumplirse entre `totalArrivals` y `totalServed`, y por qué?

Debe cumplirse de manera estricta que:$$\text{totalArrivals} \ge \text{totalServed}$$

Porque el banco no puede atender a más clientes de los que físicamente han ingresado al sistema. La diferencia entre ambos valores ($\text{totalArrivals} - \text{totalServed}$) representa con precisión el número de clientes remanentes que se quedaron atrapados haciendo fila en las ventanillas en el instante en que la simulación se detuvo (now == servTime).

5. ¿Qué representa la línea de tiempo (`timeline`) en el resultado?

Representa una bitácora de auditoría histórica paso a paso. Es un vector que almacena una captura fotográfica (BankSimulationStep) del estado completo del banco en cada segundo o unidad de tiempo transcurrida. Almacena cronológicamente el instante actual y una matriz con el tiempo restante de atención de todos y cada uno de los clientes distribuidos en sus respectivas filas, permitiendo reconstruir o graficar el comportamiento del sistema a posteriori.

6. ¿Por qué esta aplicación necesita colas y no pilas?

Porque el modelo de negocio bancario exige una política de justicia distributiva básica (Equidad). Una cola garantiza la semántica FIFO, asegurando que el cliente que llegó primero sea el primero en ser atendido.

7. ¿Qué simplificación del mundo real introduce este simulador?

Tiempos discretos: Todo ocurre en ticks fijos de tiempo; no hay retrasos de transición ni demoras entre que un cliente se retira y el siguiente avanza.

Fidelidad absoluta: Los clientes eligen una fila al entrar y se quedan estáticos en ella. En el mundo real, las personas cambian de fila si ven que otra avanza más rápido (jockeying) o abandonan el banco si la fila es demasiado larga (balking).

Frecuencia homogénea: La probabilidad de llegada es constante a lo largo del tiempo, ignorando la existencia de "horas pico".

8. ¿Qué cambiaría si la política ya no fuera "cola más corta" sino otra?

Cambiaría drásticamente la distribución de la carga y la eficiencia del banco:

Si fuera una Cola Única para múltiples ventanillas (Modelo Serpiente): El banco sería mucho más eficiente. Ninguna ventanilla se quedaría vacía si hay gente esperando, eliminando el problema de quedarse atrapado detrás de un cliente con un trámite larguísimo.

Si fuera Aleatoria o Round-Robin: Las filas se desbalancearían masivamente. Podrías tener una ventanilla colapsada con 10 personas mientras la de al lado está completamente vacía.

#### Experimento 6

Cambiando demo_bank.cpp para las variaciones pedidas:
| `nWin` | `servTime` | `seed` | `totalArrivals` | `totalServed` | `tamaño final` | `Observación` |
| :---: | :---: | :---: | :--- | :--- | :---: | :--- |
| 1 | 30 | 12345 | 16 | 0 | [16]` | Pocas ventanas (1). Colapso inminente por acumulación. |
| 3 | 30 | 12345 | 24 | 1 | [8, 8, 7]` | Mismo tiempo/semilla, pero más ventanas. Fluidez notable. |
| 3 | 100 | 12345 | 80 | 3 | [26, 26, 25]` | Mayor duración. Permite ver el comportamiento a largo plazo. |
| 3 | 30 | 99999 | 24 | 1 | [8, 8, 7]` | Mismas ventanas/tiempo que el Caso 2, pero diferente semilla. |
| 3 | 30 | 12345 | 24 | 1 | [8, 8, 7]` | Réplica exacta del Caso 2 para demostrar determinismo. |
| 5 | 30 | 55555 | 24 | 1 | [5, 5, 5, 4, 4]` | Muchas ventanas. Alta probabilidad de colas vacías. |


1. ¿Qué parámetro parece influir más en la congestión observable?

El número de ventanillas (nWin). Cuando nWin = 1, la tasa de salida de clientes está severamente limitada. Al incrementar las ventanillas, el procesamiento pasa a ser en paralelo, lo que reduce la longitud de las filas, aun cuando la cantidad de personas que ingresan al banco (totalArrivals) se mantenga similar.

2. ¿Qué cambia cuando repites exactamente la misma semilla?

No cambia absolutamente nada. Esto demuestra que el generador std::mt19937 es puramente matemático y predecible dada una base inicial.

3. ¿Qué cambia cuando mantienes `nWin` y `servTime`, pero alteras la semilla?

Cambia el escenario estocástico específico. Al alterar la semilla (comparando la fila 2 con la fila 4), se modifica el orden y los valores de los números que el generador arroja. Esto se traduce en que los clientes llegan en momentos distintos del tiempo y con requisitos de atención (time) completamente diferentes, alterando las métricas de rendimiento finales del banco.

4. ¿Qué evidencia usarías para defender que la cola más corta es una política razonable, aunque no necesariamente óptima?

La evidencia se encuentra en la homogeneidad de los tamaños finales de las colas en los escenarios con múltiples ventanillas (ej. [6, 6, 5] o [18, 17, 17]).

Esta política es razonable porque el algoritmo distribuye la carga equitativamente, logrando que ninguna ventanilla quede ociosa mientras otra esté saturada. Sin embargo, no es óptima porque solo mira el número de personas y no el tiempo que tardarán. Si una cola tiene un solo cliente al que le faltan 90 unidades de tiempo, y otra cola tiene dos clientes a los que les falta 1 unidad a cada uno, el algoritmo enviará al nuevo usuario a la fila del cliente de 90 unidades, haciéndolo esperar más tiempo.

### Bloque 8 - Cierre comparativo y preparación de sustentación

**¿Qué cambia cuando pasamos de "usar pilas y colas como ADTs básicos" a "usarlas como mecanismos de control para resolver problemas"?**

El paso de concebir las pilas y colas como simples estructuras de datos contenedoras (ADTs básicos que guardan y extraen elementos) a utilizarlas como motores de control de flujo altera por completo la arquitectura del software, transformando las políticas de ordenamiento en estrategias lógicas para gobernar el tiempo, el espacio y la toma de decisiones en un algoritmo.

Sobre LIFO y FIFO: LIFO se transforma en el núcleo del rastreo jerárquico y de profundidad, mientras que FIFO se erige como el árbitro de la equidad operativa y la simulación cronológica paralela.

Sobre recursión implícita frente a estructura explícita: El uso de una pila explícita en lugar de la recursión delegada al sistema operativo traslada el control del estado del programa desde la pila de llamadas (Call Stack) del hardware hacia el espacio de usuario, eliminando el riesgo de un desbordamiento de pila y permitiendo pausar, auditar o inspeccionar las variables de control en cualquier instante del ciclo de ejecución.

Sobre evaluación de expresiones: En el análisis y resolución de expresiones algebraicas, la pila deja de ser un mero depósito de datos para actuar como un operador sintáctico en tiempo real, donde la política de precedencias de una matriz decide dinámicamente si un operador es retenido en memoria o si es despachado de inmediato hacia la Notación Polaca Inversa (RPN).

Sobre backtracking: En las estrategias de backtracking, la pila se convierte en un mapa de decisiones reversibles y dinámicas, actuando como el diario de viaje del algoritmo.

Sobre simulación: Al implementar simulaciones de sistemas, la cola se transforma en la representación del tiempo de espera y la congestión de un entorno estocástico, modelando cómo interactúan flujos independientes de entidades discretas frente a recursos limitados y permitiendo analizar cuantitativamente la eficiencia de políticas operativas sin necesidad de alterar el mundo real.

Sobre correctitud experimental: El uso de estas estructuras como mecanismos de control permite que la correctitud de un algoritmo no se asuma de forma teórica, sino que se demuestre a través de la auditoría de su rastro en memoria.


### Autoevaluación breve

- Qué puedo defender con seguridad: La diferencia radical entre LIFO (pila) y FIFO (cola) como motores de control. Puedo demostrar cómo la pila gobierna el retroceso controlado (backtracking) en búsquedas y la jerarquía sintáctica en expresiones, mientras que la cola gestiona el paralelismo, el tiempo y la equidad distributiva en sistemas de servicios.

- Qué todavía confundo: La optimización del estado global frente al local. Específicamente, cómo mapear las restricciones dinámicas en el espacio de estados (como el cálculo de diagonales en N-Reinas) en comparación con las restricciones físicas e inmóviles de una matriz estática (las paredes en el Laberinto).

- Qué experimento me dio mejor evidencia: El de Validación de Paréntesis (Cruce Incorrecto). Demostró experimentalmente un falso positivo (un bug de diseño) en el algoritmo recursivo al evaluar expresiones como ([)]. Evidenció que mientras la recursión fallaba por ignorar caracteres, la estructura explícita de la pila iterativa defendía con éxito la integridad sintáctica.

- Qué evidencia usaría en una sustentación: Las métricas de checks en N-Reinas y el mapa de celdas BACKTRACKED en el Laberinto. Con los checks demuestras matemáticamente cómo el algoritmo realiza la "poda" de ramas muertas sin explorarlas por completo, y con las celdas B del laberinto pruebas visualmente el rastro físico del backtracking en memoria.