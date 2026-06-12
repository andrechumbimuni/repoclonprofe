#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>
#include "Capitulo6.h"

// MOD-A6-B9-Parte D: Pruebas de Búsqueda y Límites sobre Treaps

namespace {

void evaluarBusqueda(const ods::Treap<int>& t, int clave) {
  auto* nodo = t.findEQ(clave);
  std::cout << "  findEQ(" << clave << ")        -> ";
  if (nodo) std::cout << "Encontrado [Key: " << nodo->key << " | Pri: " << nodo->priority << "]\n";
  else std::cout << "nullptr (No existe)\n";
}

void evaluarLowerBound(const ods::Treap<int>& t, int clave) {
  auto* nodo = t.lowerBound(clave);
  std::cout << "  lowerBound(" << clave << ")    -> ";
  if (nodo) std::cout << "Encontrado [Key: " << nodo->key << " | Pri: " << nodo->priority << "]\n";
  else std::cout << "nullptr\n";
}

void evaluarUpperBound(const ods::Treap<int>& t, int clave) {
  auto* node = t.upperBound(clave);
  std::cout << "  upperBound(" << clave << ")    -> ";
  if (node) std::cout << "Encontrado [Key: " << node->key << " | Pri: " << node->priority << "]\n";
  else std::cout << "nullptr\n";
}

} // namespace

int main() {
  ods::Treap<int> t(232);

  t.addWithPriority(30, 30);
  t.addWithPriority(40, 40);
  t.addWithPriority(60, 60);
  t.addWithPriority(80, 80);

  std::cout << "EVALUACION DE BUSQUEDAS Y LIMITES\n\n";
  std::cout << "Estructura del Treap de prueba bajo inorden: [30, 40, 60, 80]\n\n";

  // Ejecución del lote de pruebas solicitado
  evaluarBusqueda(t, 40);
  evaluarBusqueda(t, 35);
  std::cout << "\n";
  evaluarLowerBound(t, 35);
  evaluarLowerBound(t, 40);
  std::cout << "\n";
  evaluarUpperBound(t, 40);
  evaluarUpperBound(t, 75);
  std::cout << "\n";

  return 0;
}


/*
/// MOD-A6-B9-Parte C : Demostración e Instrumentación de Eliminaciones en Treap
int main() {
  ods::Treap<int> t(232);
  
  // Construcción del Treap (Inserciones iniciales)
  std::vector<std::pair<int, int>> insertions = { 
    {50, 50}, {30, 30}, {70, 70}, {20, 20}, {40, 40}, {60, 60}, {80, 80} 
  };
  
  for (const auto& p : insertions) {
    t.addWithPriority(p.first, p.second);
  }

  std::cout << "INSTRUMENTACION DE ELIMINACIONES (trickleDownCount)\n";
  std::cout << "\n\n";
  std::cout << "Arbol Inicial Construido :\n" << t << "\n";
  std::cout << "\n";

  std::vector<int> a_eliminar = {50, 20, 70};

  for (int clave : a_eliminar) {
    std::size_t rotaciones = t.removeCount(clave);
    
    std::cout << "CLAVE ELIMINADA: " << clave << "\n";
    std::cout << "    Cantidad de rotaciones : " << rotaciones << "\n";
    std::cout << "    Recorrido Inorden      : "; mostrarRecorrido(t.inorderKeys()); std::cout << "\n";
    std::cout << "    Recorrido Por Niveles  : "; mostrarRecorrido(t.levelOrderKeys()); std::cout << "\n";
    std::cout << "    ¿isBST()?              : " << (t.isBST() ? "true" : "false") << "\n";
    std::cout << "    ¿isHeapByPriority()?   : " << (t.isHeapByPriority() ? "true" : "false") << "\n";
    std::cout << "    ¿isTreap()?            : " << (t.isTreap() ? "true" : "false") << "\n";
    std::cout << "\n";
  }

  std::cout << "Arbol Final Resultante:\n" << t << "\n";
  std::cout << "\n";
  return 0;
}
 
//Parte B
int main() {
  ods::Treap<int> t(232);
  
  // Secuencia crítica que fuerza rotaciones sucesivas al tope
  const std::vector<std::pair<int, std::uint64_t>> secuencia_critica = {
    {100, 100}, {90, 90}, {80, 80}, {70, 70}, {60, 60}
  };

  std::cout << "INSTRUMENTACION DE BUBBLE-UP EN TREAPS\n";
  std::cout << "\n\n";

  std::cout << std::left << std::setw(10) << "Clave" << std::setw(12) << "Prioridad" << std::setw(14) << "Rotaciones" << std::setw(14) << "Raíz Post" << "¿Es Treap Válido?\n";
  std::cout << "\n";

  for (const auto& par : secuencia_critica) {
    int clave = par.first;
    std::uint64_t prioridad = par.second;
    
    // Inserción y conteo de rotaciones físicas
    std::size_t rotaciones = t.addWithPriorityCount(clave, prioridad);
    
    std::string validacion = t.isTreap() ? "SI" : "NO";
    int raiz_actual = t.root() ? t.root()->key : -1;

    std::cout << std::left << std::setw(10) << clave << std::setw(12) << prioridad << std::setw(14) << rotaciones << std::setw(14) << raiz_actual << validacion << "\n";
  }

  std::cout << "\n\n";
  std::cout << "Estructura final del Treap (Vista ASCII):\n";
  std::cout << t << "\n";
  std::cout << "\n";

  return 0;
}
*/