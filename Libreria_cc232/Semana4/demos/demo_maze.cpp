#include <iostream>
#include <string>
#include <vector>

#include "Maze.h"

void imprimirEvidencia(const ods::Maze& maze, const std::vector<std::pair<int, int>>& path) {
    std::vector<std::vector<char>> evidencia(maze.rows(), std::vector<char>(maze.cols(), ' '));
    for (int i = 0; i < maze.rows(); ++i) {
        for (int j = 0; j < maze.cols(); ++j) {
            const auto* cell = maze.at(i, j);
            if (cell->status == ods::WALL) {
                evidencia[i][j] = '#';
            } else if (cell->status == ods::BACKTRACKED) {
                evidencia[i][j] = 'B';
            } else {
                evidencia[i][j] = '.';
            }
        }
    }
    for (const auto& [x, y] : path) {
        evidencia[x][y] = '*';
    }
    for (const auto& row : evidencia) {
        for (char c : row) {
            std::cout << c;
        }
        std::cout << '\n';
    }
}
int main() {
    std::cout << "Bateria de experimentos: LABERINTOS\n\n";
    std::vector<std::string> l1 = {
        "#######",
        "#.....#",
        "#####.#",
        "#.....#",
        "#######"
    };
    ods::Maze m1(l1);
    const auto p1 = ods::findPath(m1, 1, 1, 3, 1);
    std::cout << "Inicio: (1, 1) -> Destino: (3, 1)\n";
    std::cout << "Medida del camino = " << p1.size() << " celdas\n";
    std::cout << "Mapa de Evidencia ('*'=camino, 'B'=Retroceso):\n";
    imprimirEvidencia(m1,p1);
    std::cout << '\n';

    std::cout << "LABERINTO 2: SIN SALIDA \n";
    std::vector<std::string> l2 = {
        "#######",
        "#...#.#",
        "###.#.#",
        "#...#.#",
        "#######"
    };
    ods::Maze m2(l2);
    auto p2 = ods::findPath(m2, 1, 1, 1, 5); // El destino (1,5) está aislado por paredes
    
    std::cout << "Inicio: (1,1) -> Destino: (1,5)\n";
    std::cout << "Longitud del camino: " << p2.size() << " (Ausencia de camino)\n";
    std::cout << "Mapa de Evidencia ('*'=Camino, 'B'=Retroceso):\n";
    imprimirEvidencia(m2, p2);
    std::cout << "\n";

    std::cout << "LABERINTO 3: MÚLTIPLES RETROCESOS\n";
    std::vector<std::string> l3 = {
        "########",
        "#......#",
        "#.####.#",
        "#.#..#.#",
        "#.##.#.#",
        "#....#.#",
        "########"
    };
    ods::Maze m3(l3);
    auto p3 = ods::findPath(m3, 1, 1, 5, 4); // Obliga a la prioridad ESTE a fallar en callejones largos
    
    std::cout << "Inicio: (1,1) -> Destino: (5,4)\n";
    std::cout << "Longitud del camino: " << p3.size() << " celdas\n";
    std::cout << "Mapa de Evidencia ('*'=Camino, 'B'=Retroceso):\n";
    imprimirEvidencia(m3, p3);
    std::cout << "\n";
    
    return 0;
}