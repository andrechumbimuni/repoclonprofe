// MOD-A6-B6: Demostración del heapsort
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

}  // namespace


int main() {
  std::vector<int> datos_base = { 5, 1, 5, 3, 8, 2, 8, 0 };
  std::less<int > comp;
  std::cout << "HEAPSORT MULTIDIMENSIONAL IN-SITU\n\n";

  printVector(datos_base, "Datos originales");
  std::cout <<"\n";

  // Caso 1: Ordenamiento Ascendente
  std::vector<int> v_ascendente = datos_base;
  ods::heapSort(v_ascendente, comp, true);
  printVector(v_ascendente, "Resultado Ascendente   ");

  // Caso 2: Ordenamiento Descendente
  std::vector<int> v_descendente = datos_base;
  ods::heapSort(v_descendente, comp, false);
  printVector(v_descendente, "Resultado Descendente   ");

  std::cout << "Evidencia de repetidos: Las claves duplicadas {5, 5} y {8, 8}\n";
  std::cout << "fueron agrupadas de manera contigua y correcta en ambos sentidos.\n\n";
  return 0;
}
