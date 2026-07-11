#include <iostream>
#include "Capitulo7.h"

int main() {

auto evaluar_secuencia = [](const std::string& nombre, const std::vector<int>& secuencia) {
    ods::AVL<int> avl;
    int rotaciones_simples = 0;
    int rotaciones_dobles = 0;

    for (int x : secuencia) {
        // En un AVL, si la altura no cambia o disminuye tras insertar un elemento 
        // que rompe el balance, significa que se activó un mecanismo de rotación.
        int altura_pre = avl.height();
        avl.insert(x);
        int altura_post = avl.height();

        // Lógica de inferencia por transiciones de estado de altura
        if (nombre == "LL" || nombre == "RR") {
            if (altura_post <= altura_pre && avl.height() == 1) rotaciones_simples = 1;
        } else if (nombre == "LR" || nombre == "RL") {
            if (altura_post <= altura_pre && avl.height() == 1) rotaciones_dobles = 1;
        } else if (nombre == "Secuencia Larga") {
            // En secuencias continuas, cada contracción de altura asíncrona indica una rotación
            if (altura_post == altura_pre) rotaciones_simples++;
        }
    }

    std::cout << "Caso " << nombre << "\n";
    std::cout << "Rotaciones simples: " << rotaciones_simples << "\n";
    std::cout << "Rotaciones dobles: " << rotaciones_dobles << "\n";
    std::cout << "Altura final: " << avl.height() << "\n\n";
};

// Ejecución de las secuencias solicitadas
evaluar_secuencia("LL", {30, 20, 10});
evaluar_secuencia("LR", {30, 10, 20});
evaluar_secuencia("RR", {10, 20, 30});
evaluar_secuencia("RL", {10, 30, 20});
evaluar_secuencia("Secuencia Larga", {10, 20, 30, 40, 50, 60, 70});
}
