//MOD-A6-B7:Demostración e instrumentación de la función de Leftist Heaps
#include <iostream>
#include <vector>

#include "Capitulo6.h"


namespace {

template <typename T>
void printVector(const std::vector<T>& xs, const char* label) {
  std::cout << label << ": [";
  for (std::size_t i = 0; i < xs.size(); ++i) {
    if (i != 0) std::cout << ", ";
    std::cout << xs[i];
  }
  std::cout << "]\n";
}
template <typename T, typename C>
void reportarEstado(const ods::PQ_LeftHeap<T,C>& h, const char* nombre) {
  std::cout << "  Heap " << nombre << " (Level-Order): ";
  printVector(h.levelOrder(), "");
  std::cout << "  -> Tamañoo actual: " << h.size() 
            << " | ¿Es estructuralmente valido?: " 
            << (h.isValidLeftHeap() ? "SI" : "NO") << "\n";
}
}  // namespace


int main() {
  std::cout << " VALIDACION Y FUSION DE LEFTIST HEAPS\n\n";
  ods::PQ_LeftHeap<int> a{7, 2, 9};
  ods::PQ_LeftHeap<int> b{1, 8, 3, 11};

  std::cout << "[ESTADO INICIAL]\n";
  reportarEstado(a, "A");
  reportarEstado(b, "B");
  std::cout << "\n";

  std::cout << "EJECUTANDO FUSION: a.merge(b)\n";
  a.merge(b);
  
  std::cout << "[ESTADO FINAL POST-MERGE]\n";
  reportarEstado(a, "A");
  reportarEstado(b, "B");
  std::cout << "\n";

  std::cout << "[MUTACION: Insercion adicional en A -> insert(10)]\n";
  a.insert(10);
  reportarEstado(a, "A");
  std::cout << "\n";

  std::cout << "Secuencia de extraccion por prioridad: [ ";
  while (!a.empty()) {
    std::cout << a.delMax() << " ";
  }
  std::cout << "]\n";
  std::cout << "\n";

  return 0;

}
