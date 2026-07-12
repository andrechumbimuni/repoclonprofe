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