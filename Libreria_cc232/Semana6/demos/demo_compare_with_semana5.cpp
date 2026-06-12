// MOD-A6-B10: Análisis Comparativo Multi-Estructura (S5 vs S6)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Capitulo5.h"
#include "Capitulo6.h"

int main() {
  const std::vector<int> xs{8, 3, 10, 1, 6, 14, 4, 7, 13};
  ods::BinaryHeap<int> binaryHeap;
  ods::PQ_ComplHeap<int> pqComplHeap;
  ods::BinarySearchTree<int> bst;
  ods::Treap<int> treap(42);

  // Inserción concurrente
  for (int x : xs) {
    binaryHeap.add(x);
    pqComplHeap.insert(x);
    bst.add(x);
    treap.addWithPriority(x, static_cast<std::uint64_t>(x * 10));
  }

  std::cout << "REPORTE DE EVIDENCIAS EN CONSOLA\n";
  std::cout << "\n\n";

  // 1. Evidencia BinaryHeap
  std::cout << "  BinaryHeap (Min-Heap S5):\n";
  std::cout << "  Elemento en el tope (Mínimo): " << binaryHeap.top() << "\n\n";

  // 2. Evidencia PQ_ComplHeap
  std::cout << "  PQ_ComplHeap (Max-Heap S6):\n";
  std::cout << "  Elemento máximo (getMax())  : " << pqComplHeap.getMax() << "\n";
  std::cout << "  ¿Es un Max-Heap válido?     : " << (pqComplHeap.isValidHeap() ? "SI" : "NO") << "\n\n";

  // 3. Evidencia BinarySearchTree
  std::cout << "  BinarySearchTree (S5):\n";
  std::cout << "  Recorrido Inorden ordenado  : ";
  for (int x : bst.inorder()) { std::cout << x << " "; }
  std::cout << "\n\n";

  // 4. Evidencia Treap
  std::cout << "  Treap Balanceado (S6):\n";
  std::cout << "  Recorrido Inorden de claves : ";
  for (int x : treap.inorderKeys()) { std::cout << x << " "; }
  std::cout << "\n";
  auto* lb = treap.lowerBound(5);
  std::cout << "  lowerBound(5) sobre claves  : " << (lb ? std::to_string(lb->key) : "null") << "\n";
  std::cout << "  ¿Es un Treap mixto válido?  : " << (treap.isTreap() ? "SI" : "NO") << "\n";
  std::cout << "\n";

  return 0;
}
