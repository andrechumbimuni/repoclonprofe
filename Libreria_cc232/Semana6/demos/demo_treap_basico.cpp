#include <iostream>
#include <vector>

#include "Capitulo6.h"

int main() {
  ods::Treap<int> t(232);
  std::vector<std::pair<int, int>> insertions = { {50, 50}, {30, 30}, {70, 70}, {20, 20}, {40, 40}, {60, 60}, {80, 80} };

  std::cout << "Inserciones con prioridades fijas para ver bubbleUp:\n";
  //imprime las claves,prioridades, recorrido inorden, recorrido por niveles, raiz actual, resultado de isBST, resultado de isHeapByPriority y resultado de isTreap despues de cada insercion.
  for (const auto& p : insertions) {
    t.addWithPriority(p.first, p.second);
    std::cout << "Después de insertar " << p.first << " con prioridad " << p.second << ":\n";
    std::cout << "Recorrido inorden: ";
    std::vector<int> inorder;
    for (const auto& key : t.inorderKeys()) {
      std::cout << key << " ";
      inorder.push_back(key);
    }
    std::cout << "\n";
    std::cout << "Recorrido por niveles: ";
    for (const auto& key : t.levelOrderKeys()) {
      std::cout << key << " ";
    }
    std::cout << "\n";
    std::cout << "Raíz actual: " << (t.root() ? t.root()->key : -1) << "\n";
    std::cout << "isBST: " << (t.isBST() ? "true" : "false") << "\n";
    std::cout << "isHeapByPriority: " << (t.isHeapByPriority() ? "true" : "false") << "\n";
    std::cout << "isTreap: " << (t.isTreap() ? "true" : "false") << "\n\n";
  }
  std::cout << "asciiArt del arbol final:\n" << t << "\n";

}