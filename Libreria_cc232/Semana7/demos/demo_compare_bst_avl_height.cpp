#include <iostream>
#include <vector>
#include <string>
#include "Capitulo7.h"

void procesarCaso(const std::string& titulo, const std::vector<int>& claves) {
    ods::BinarySearchTree1<int> bst;
    ods::AVL<int> avl;

    // Insertar las mismas claves en ambas estructuras usando sus métodos nativos
    for (int x : claves) {
        bst.add(x);
        avl.insert(x);
    }

    // Consultar las alturas utilizando los métodos que ya implementa Capitulo7.h
    std::cout << "Caso: " << titulo << "\n";
    std::cout << "Altura BST: " << bst.height() << "\n";
    std::cout << "Altura AVL: " << avl.height() << "\n\n";
}

int main() {
    std::vector<int> sortedKeys = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> mixedKeys = {5, 2, 8, 1, 3, 7, 9, 4, 6, 10};

    procesarCaso("claves ordenadas", sortedKeys);
    procesarCaso("claves mezcladas", mixedKeys);

    return 0;
}