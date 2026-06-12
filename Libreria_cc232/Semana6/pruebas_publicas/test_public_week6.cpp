// MOD-A6-B11: Suite de Verificación Exhaustiva de Invariantes (15 Checks)
#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include "Capitulo5.h" 
#include "Capitulo6.h"

void ejecutar_suite_semana6() {
  std::cout << "EJECUTANDO SUITE DE PRUEBAS COMPLETA\n\n";

  // REQ 1 & 2: PQ_ComplHeap conserva propiedad heap tras inserción y eliminación
  {
    ods::PQ_ComplHeap<int> pq;
    std::vector<int> datos = {14, 8, 3, 10, 1, 6, 4, 7, 13};
    
    for (int x : datos) {
      pq.insert(x);
      assert(pq.isValidHeap() && "REQ 1 FAILED: Invariante roto en inserción");
    }
    
    while (!pq.empty()) {
      pq.delMax();
      assert(pq.isValidHeap() && "REQ 2 FAILED: Invariante roto en eliminación");
    }
    std::cout << "REQ 1 & 2: Invariantes estables en PQ_ComplHeap.\n";
  }

  // REQ 3 & 4: getMax no cambia el tamaño, delMax sí lo cambia
  {
    ods::PQ_ComplHeap<int> pq;
    pq.insert(42);
    pq.insert(17);
    
    std::size_t size_inicial = pq.size();
    int max1 = pq.getMax();
    int max2 = pq.getMax();
    assert(max1 == max2);
    assert(pq.size() == size_inicial && "REQ 3 FAILED: getMax alteró el tamaño");
    
    pq.delMax();
    assert(pq.size() == size_inicial - 1 && "REQ 4 FAILED: delMax no decrementó el tamaño");
    std::cout << "REQ 3 & 4: Control de efectos secundarios en tamaño.\n";
  }

  // REQ 5: heapifyFloyd produce un heap válido
  {
    std::vector<int> desordenado = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    ods::PQ_ComplHeap<int> pq(desordenado);
    assert(pq.isValidHeap() && "REQ 5 FAILED: Floyd produjo un heap inválido");
    std::cout << "REQ 5: Constructor Floyd (heapify) validado.\n";
  }

  // REQ 6: heapSort ordena con repetidos
  {
    std::vector<int> con_repetidos = {5, 1, 5, 3, 1, 5, 9, 3};
    ods::PQ_ComplHeap<int> pq(con_repetidos);
    
    std::vector<int> ordenado;
    while(!pq.empty()) {
      ordenado.push_back(pq.delMax());
    }
    assert(std::is_sorted(ordenado.rbegin(), ordenado.rend()) && "REQ 6 FAILED: Falló ordenamiento");
    std::cout << "REQ 6: HeapSort con elementos repetidos correcto.\n";
  }

  // REQ 7, 8 & 9: PQ_LeftHeap conserva su propiedad en merge, insert y delMax
  {
    ods::PQ_LeftHeap<int> lh1 = {20, 7, 18, 3};
    ods::PQ_LeftHeap<int> lh2 = {19, 8, 4, 1, 17};
    
    assert(lh1.isLeftistHeap() && "REQ 8 FAILED: Falló en inicialización/insert lh1");
    assert(lh2.isLeftistHeap() && "REQ 8 FAILED: Falló en inicialización/insert lh2");
    
    lh1.merge(lh2);
    assert(lh1.isLeftistHeap() && "REQ 7 FAILED: Propiedad rota tras merge");
    
    lh1.delMax();
    assert(lh1.isLeftistHeap() && "REQ 9 FAILED: Propiedad rota tras delMax");
    std::cout << "REQ 7, 8 & 9: Invariantes estables en PQ_LeftHeap.\n";
  }

  // REQ 10 & 11: Huffman produce códigos completos y libres de prefijos
  {
    std::vector<ods::HuffmanSymbol> simbolos = {
      {'a', 45}, {'b', 13}, {'c', 12}, {'d', 16}, {'e', 9}, {'f', 5}
    };
    
    auto codigos = ods::huffmanGenerateCodes(simbolos);
    
    // REQ 10: Frecuencia positiva tiene código
    assert(codigos.size() == simbolos.size() && "REQ 10 FAILED: Símbolos omitidos");
    
    // REQ 11: Libres de prefijos
    assert(ods::huffmanIsPrefixFree(codigos) && "REQ 11 FAILED: Códigos colisionan en prefijo");
    std::cout << "REQ 10 & 11: Códigos de Huffman unívocos y válidos.\n";
  }

  // REQ 12: Huffman maneja el caso de un solo símbolo
  {
    std::vector<ods::HuffmanSymbol> un_simbolo = {{'z', 100}};
    auto codigos = ods::huffmanGenerateCodes(un_simbolo);
    
    assert(codigos.size() == 1 && "REQ 12 FAILED: Caso base fallido");
    assert(!codigos['z'].empty() && "REQ 12 FAILED: Código vacío para símbolo único");
    std::cout << "[PASSED] REQ 12: Caso crítico de un solo símbolo manejado con éxito.\n";
  }

  // REQ 13 & 14: Treap conserva BST y Heap por prioridad tras insertar
  {
    ods::Treap<int> t;
    std::vector<std::pair<int, std::uint64_t>> nodos = {
      {8, 80}, {3, 40}, {10, 90}, {1, 20}, {6, 70}
    };
    
    for (const auto& item : nodos) {
      t.addWithPriority(item.first, item.second);
      assert(t.isBST() && "REQ 13 FAILED: Orden BST roto en inserción");
      assert(t.isHeapByPriority() && "REQ 14 FAILED: Orden Heap roto en inserción");
    }
    std::cout << "REQ 13 & 14: Inserciones duales perfectas en Treap.\n";
  }

  // REQ 15: Treap conserva ambas propiedades después de eliminar
  {
    ods::Treap<int> t;
    t.addWithPriority(8, 80);
    t.addWithPriority(3, 40);
    t.addWithPriority(10, 90);
    t.addWithPriority(1, 20);
    
    t.remove(3);
    assert(t.isTreap() && "REQ 15 FAILED: Propiedad de Treap rota en remoción");
    
    t.remove(8);
    assert(t.isTreap() && "REQ 15 FAILED: Propiedad de Treap rota al remover raíz");
    std::cout << "REQ 15: Eliminaciones complejas en Treap mantienen invariantes.\n";
  }

  std::cout << "TODOS LOS CHECKS DE VALIDACIÓN FUERON EXITOSOS.\n\n";
}

int main() {
  ejecutar_suite_semana6();
  return 0;
}


/*
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
*/