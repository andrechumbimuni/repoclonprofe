#include <iostream>

#include "NQueens.h"

int main() {
    std::vector<int> ns = {4, 5, 6, 8};
    std::cout << "Bateria de experimentos para el problema de las N-Reinas\n";
    for (int n : ns) {
        const auto result = ods::placeQueens(n);
        std::cout << "N = " << result.n << "\n";
        std::cout << "soluciones : " << result.solutions <<"\n";
        std::cout<< "verificaciones : " << result.checks << "\n";
        std::cout << "Distribución (coordenadas de columnas por fila):\n";
        for (size_t i = 0; i < result.placements.size(); ++i) {
            std::cout << "solución: "<<i+1<<": [";
            for (int col : result.placements[i]) {
                std::cout << col << " ";
            }
            std::cout << "]\n";
        }
        std::cout << "\n";
    }
    return 0;
}