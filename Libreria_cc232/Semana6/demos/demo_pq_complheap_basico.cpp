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

//MOD-A6-B2
bool verificarPropiedadMaxHeap(const std::vector<int>& a) {
  for (std::size_t i = 0; i < a.size(); ++i) {
    std::size_t p = (i - 1) / 2;
    if (a[p] < a[i]) {
      return false;
    }
  }
  return true;
}
}  // namespace

int main() {// MOD-A6-B3
  
  std::vector<int> heap_interno;
  std::vector<int> secuencia_entrada = { 40, 10, 70, 30, 90, 20, 80, 60 };
  std::less<int> comp;

  std::cout << "INSERCIONES SUCESIVAS\n";
  for (int x : secuencia_entrada) {
    heap_interno.push_back(x);
    ods::complHeapPercolateUp(heap_interno, heap_interno.size() - 1, comp);
  }
  printVector(heap_interno, "Heap base consolidado");
  std::cout << "\n\n";

  std::cout << "ELIMINACIONES SUCESIVAS \n\n";
  while (!heap_interno.empty()) {
    int max_eliminado = heap_interno.front();
    
    std::cout << "Maximo a eliminar: " << max_eliminado << "\n";
    
    heap_interno.front() = heap_interno.back();
    heap_interno.pop_back();
    
    if (!heap_interno.empty()) {
      printVector(heap_interno, "  Arreglo antes de reparar");
      std::size_t swaps = ods::complHeapPercolateDownCount(heap_interno, heap_interno.size(), 0, comp);
      std::cout << "  Intercambios realizados: " << swaps << "\n";
      printVector(heap_interno, "  Arreglo despues de reparar");
    } else {
      std::cout << "  El heap ha quedado completamente vacio.\n";
    }
    std::cout << "\n";
  }

  return 0;
}

/*
int main() {
  std::vector<int> heap_interno;
  std::vector<int> secuencia_entrada = { 40, 10, 70, 30, 90, 20, 80, 60 };
  std::less<int> comp;

  std::cout << "INSERCIONES SUCESIVAS E INSTRUMENTACION\n\n";

  for (int x : secuencia_entrada) {
    heap_interno.push_back(x);
    std::size_t swaps = ods::complHeapPercolateUpCount(heap_interno, heap_interno.size() - 1, comp);
    
    std::cout << "Elemento insertado: " << x << "\n";
    std::cout << "Cantidad de intercambios: " << swaps << "\n";
    printVector(heap_interno, "Arreglo interno resultante");
    std::cout << "¿Propiedad Max-Heap valida?: " << (verificarPropiedadMaxHeap(heap_interno) ? "SI" : "NO") << "\n";
    std::cout << "\n";
  }

  return 0;
}


int main() {
  std::vector<int> base{4, 10, 7, 1, 3, 9};
  ods::PQ_ComplHeap<int> pq(base);

  std::cout << "PQ_ComplHeap construido con heapify de Floyd\n";
  printVector(base, "entrada");
  printVector(pq.data(), "heap interno");
  std::cout << "getMax() = " << pq.getMax() << "\n\n";

  for (int x : {12, 5, 14}) {
    pq.insert(x);
    std::cout << "insert(" << x << ")\n";
    printVector(pq.data(), "heap interno");
    std::cout << "max actual = " << pq.getMax() << "\n\n";
  }

  while (!pq.empty()) {
    int y = pq.delMax();
    std::cout << "delMax() -> " << y << "\n";
    printVector(pq.data(), "heap interno");
  }
}
*/