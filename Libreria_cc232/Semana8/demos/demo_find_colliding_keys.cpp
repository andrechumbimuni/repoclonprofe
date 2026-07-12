#include <iostream>
#include <vector>
#include <iomanip>
#include "HashCode.h"
#include "ChainedHashTable.h"

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

int main() {
    std::size_t capacity = 8;
    std::size_t targetBucket = 3;
    std::size_t needed = 4;

    std::vector<int> bad_keys = findCollidingKeys(capacity, targetBucket, needed);

    std::cout << "\n CLAVES ENCONTRADAS PARA BUCKET: " << targetBucket << "\n\n";
    std::cout << std::setw(10) << "Clave (x)" << std::setw(25) << "hashCode(x)" << std::setw(15) << "hashCode(x)%m" << "\n";
    std::cout << "\n";
    
    for (int x : bad_keys) {
        std::cout << std::setw(10) << x << std::setw(25) << ods::hashCode(x) << std::setw(15) << (ods::hashCode(x) % capacity) << "\n";
    }

    std::cout << "\nValidando colision en ChainedHashTable (capacidad fija sin rehash)...\n";
    ods::RehashPolicy rigid_policy;
    rigid_policy.maxLoad = 0.99;
    rigid_policy.maxOccupiedLoad = 0.995;
    rigid_policy.minLoad = 0.01;
    ods::ChainedHashTable<int> table(capacity, rigid_policy);

    for (int x : bad_keys) {
        table.add(x);
    }

    std::cout << "Resultado -> Longitud del bucket " << targetBucket << ": " << table.longestBucket() << "\n";
    std::cout << "Estadisticas de colisiones: " << table.stats().collisions << "\n";
    return 0;
}