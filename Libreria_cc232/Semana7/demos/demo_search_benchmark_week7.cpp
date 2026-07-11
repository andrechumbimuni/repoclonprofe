// Semana7/demos/demo_search_benchmark_week7.cpp
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include <type_traits>
#include "Capitulo7.h"

struct BenchmarkResult {
    double bstTime;
    double avlTime;
    double rbtTime;
};

template <typename TreeType>
void insertKeys(TreeType& tree, const std::vector<int>& keys) {
    for (int x : keys) {
        if constexpr (std::is_same_v<TreeType, ods::AVL<int>>) {
            tree.insert(x);
        } else {
            tree.add(x); 
        }
    }
}

template <typename TreeType>
double profileSearches(TreeType& tree, const std::vector<int>& successKeys, const std::vector<int>& failKeys) {
    auto start = std::chrono::high_resolution_clock::now();

    // 1. Búsquedas Exitosas
    for (int x : successKeys) {
        if constexpr (std::is_same_v<TreeType, ods::AVL<int>>) {
            // En tu clase AVL, si no tiene find, se busca indirectamente intentando insertar 
            // un duplicado (retorna falso si ya existe) o usando su método homólogo nativo
            volatile bool res = !tree.insert(x); 
            (void)res;
        } else {
            // El BST común y el RedBlackTree de ODS usan findEQ para búsquedas exactas
            volatile auto res = tree.findEQ(x);
            (void)res;
        }
    }

    // 2. Búsquedas Fallidas
    for (int x : failKeys) {
        if constexpr (std::is_same_v<TreeType, ods::AVL<int>>) {
            // Si la inserción es exitosa en el árbol de fallidas, significa que no estaba. 
            // Para mantener el árbol intacto en el benchmark, limpiamos el nodo insertado erróneamente.
            if (tree.insert(x)) {
                tree.remove(x);
            }
        } else {
            volatile auto res = tree.findEQ(x);
            (void)res;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    return elapsed.count();
}

BenchmarkResult runBenchmark(int n, bool ordered) {
    std::vector<int> insertKeysVec(n);
    std::vector<int> failKeysVec(n);

    for (int i = 0; i < n; ++i) {
        insertKeysVec[i] = i * 2;       
        failKeysVec[i] = (i * 2) + 1;   
    }

    if (!ordered) {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(insertKeysVec.begin(), insertKeysVec.end(), g);
        std::shuffle(failKeysVec.begin(), failKeysVec.end(), g);
    }

    ods::BinarySearchTree<ods::BSTNode1<int>, int> bst;
    ods::AVL<int> avl;
    ods::RedBlackTree1<int> rbt;

    insertKeys(bst, insertKeysVec);
    insertKeys(avl, insertKeysVec);
    insertKeys(rbt, insertKeysVec);

    BenchmarkResult res;
    res.bstTime = profileSearches(bst, insertKeysVec, failKeysVec);
    res.avlTime = profileSearches(avl, insertKeysVec, failKeysVec);
    res.rbtTime = profileSearches(rbt, insertKeysVec, failKeysVec);

    return res;
}

void printResults(int n, const std::string& caseName, const BenchmarkResult& res) {
    std::cout << "n = " << n << "\n";
    std::cout << "Caso " << caseName << "\n";
    std::cout << "BST search time: " << res.bstTime << " ms\n";
    std::cout << "AVL search time: " << res.avlTime << " ms\n";
    std::cout << "RedBlack search time: " << res.rbtTime << " ms\n\n";
}

int main() {
    std::cout << "\nBENCHMARK\n\n";
    
    for (int n : {1000, 5000, 10000}) {
        BenchmarkResult orderedRes = runBenchmark(n, true);
        printResults(n, "ordenado", orderedRes);

        BenchmarkResult randomRes = runBenchmark(n, false);
        printResults(n, "aleatorio", randomRes);
        std::cout << "\n";
    }

    return 0;
}