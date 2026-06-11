//MOD-A6-B5: Demostración comparativa de la construcción de un heap
#include <iostream>
#include <vector>
#include <algorithm>
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
//Funcion auxiliar para simular la construcción A y contar intercambios
template <typename T, typename Compare>
std::size_t construirPorInserciones(std::vector<T>& dest, const std::vector<T>& origen, Compare comp) {
  std::size_t total_swaps = 0;
  for (const auto& elemento : origen) {
    dest.push_back(elemento);
    total_swaps += ods::complHeapPercolateUpCount(dest, dest.size() - 1, comp);
  }
  return total_swaps;
}
//Funcion auxiliar para simular la construcción B y contar intercambios
template <typename T, typename Compare>
std::size_t construirPorFloyd(std::vector<T>& a, Compare comp) {
  if(a.size() < 2) {
    return 0;
  }
  std::size_t total_swaps = 0;
  for (std::size_t i = a.size() / 2; i-- > 0;) {
    total_swaps += ods::complHeapPercolateDownCount(a, a.size(), i, comp);
  }
  return total_swaps;
}

//verificación local usando la funcion del bloque anterior
template <typename T, typename Compare>
bool verificarHeap(const std::vector<T>& a, Compare comp) {
  const std::size_t n = a.size();
  for (std::size_t i = 0; i < n; ++i) {
    std::size_t l = 2 * i + 1;
    std::size_t r = 2 * i + 2;
    if (l < n && comp(a[i], a[l])) {
      return false;
    }
    if (r < n && comp(a[i], a[r])) {
      return false;
    }
  }
  return true;
}
}  // namespace


int main() {
  std::vector<int> entrada = { 4, 17, 3, 90, 55, 21, 8, 13, 34, 2, 1, 89 };
  std::less<int> comp;
  std::cout << "DEMOSTRACION COMPARATIVA DE CONSTRUCCION DE UN HEAP\n";

  printVector(entrada, "Secuencia de entrada");
  std::cout << "\n";

  //construcción A: inserciones sucesivas
  std::vector<int> heap_inserciones;
  std::size_t swaps_inserciones = construirPorInserciones(heap_inserciones, entrada, comp);

  std::cout << "CONSTRUCCION A: INSERCIONES SUCESIVAS\n";
  printVector(heap_inserciones, "Heap construido por inserciones sucesivas");
  std::cout << "  Intercambios realizados   : " << swaps_inserciones << "\n";
  std::cout << "  ¿Es un Max-Heap valido?   : " << (verificarHeap(heap_inserciones, comp) ? "SI" : "NO") << "\n";
  std::cout << "\n";

  //construcción B: heapify de Floyd
  std::vector<int> heap_floyd = entrada;
  std::size_t swaps_floyd = construirPorFloyd(heap_floyd, comp);

  std::cout << "CONSTRUCCION B: HEAPIFY DE FLOYD\n";
  printVector(heap_floyd, "Heap construido por heapify de Floyd");
  std::cout << "  Intercambios realizados   : " << swaps_floyd << "\n";
  std::cout << "  ¿Es un Max-Heap valido?   : " << (verificarHeap(heap_floyd, comp) ? "SI" : "NO") << "\n";
  return 0;
}
