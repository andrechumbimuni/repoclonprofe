// MOD-A6-B9-PE: Suite de Pruebas Unitarias Exhaustivas para Treap
#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "Treap.h"

void run_all_treap_tests() {
  std::cout << "Iniciando suite de pruebas instrumentadas MOD-A6-B10...\n";

  // 1. Caso Treap Vacío
  {
    ods::Treap<int> t;
    assert(t.empty() == true);
    assert(t.size() == 0);
    assert(t.isBST() == true);
    assert(t.isHeapByPriority() == true);
    assert(t.isTreap() == true);
  }

  // 2. Inserción con prioridades fijas & 4. Inorden ordenado & 5. Propiedad heap
  {
    ods::Treap<int> t;
    t.addWithPriority(50, 50);
    t.addWithPriority(30, 30);
    t.addWithPriority(70, 70);
    
    assert(t.isTreap() == true);
    std::vector<int> in = t.inorderKeys();
    assert(in == std::vector<int>({30, 50, 70}));
  }

  // 3. Rechazo de duplicados
  {
    ods::Treap<int> t;
    assert(t.add(10) == true);
    assert(t.add(10) == false);
    assert(t.size() == 1);
  }

  // 6. lowerBound y upperBound
  {
    ods::Treap<int> t;
    t.add(20); t.add(40); t.add(60);
    assert(t.lowerBound(30) != nullptr && t.lowerBound(30)->key == 40);
    assert(t.lowerBound(40) != nullptr && t.lowerBound(40)->key == 40);
    assert(t.upperBound(40) != nullptr && t.upperBound(40)->key == 60);
    assert(t.upperBound(70) == nullptr);
  }

  // 7. Eliminación de hoja
  {
    ods::Treap<int> t;
    t.addWithPriority(50, 10);
    t.addWithPriority(80, 20); // Hoja derecha
    assert(t.remove(80) == true);
    assert(t.size() == 1);
    assert(t.isTreap() == true);
  }

  // 8. Eliminación de nodo con un hijo
  {
    ods::Treap<int> t;
    t.addWithPriority(50, 10);
    t.addWithPriority(30, 20);
    t.addWithPriority(20, 30); // 30 tiene solo un hijo (20)
    assert(t.remove(30) == true);
    assert(t.isTreap() == true);
  }

  // 9. Eliminación de nodo con dos hijos & 10. Eliminación de raíz
  {
    ods::Treap<int> t;
    t.addWithPriority(50, 10);
    t.addWithPriority(30, 20);
    t.addWithPriority(70, 30);
    assert(t.remove(50) == true);
    assert(t.isTreap() == true);
  }

  // 11. Conservación de enlaces parent & 12. Consistencia de size() mixta
  {
    ods::Treap<int> t;
    t.add(15); t.add(5); t.add(25); t.add(10);
    assert(t.size() == 4);
    t.remove(5);
    assert(t.size() == 3);
    assert(t.isBST() == true);
  }

  // 13. Secuencia larga de operaciones mixtas (Estrés)
  {
    ods::Treap<int> t(42);
    std::vector<int> valores;
    for(int i = 0; i < 200; ++i) {
      t.add(i);
      valores.push_back(i);
    }
    std::shuffle(valores.begin(), valores.end(), std::mt19937(42));
    for(int i = 0; i < 100; ++i) {
      t.remove(valores[i]);
    }
    assert(t.size() == 100);
    assert(t.isTreap() == true);
  }

  std::cout << "Los tests de validacion pasaron con exito.\n";
}

int main() {
  run_all_treap_tests();
  return 0;
}