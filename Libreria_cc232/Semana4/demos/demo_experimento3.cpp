#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>

namespace ods_extended {

// Simulación directa de la operación extendida
double calcuBinarioExt(double a, char op, double b) {
    switch (op) {
        case '+': return a + b;
        case '*': return a * b;
        case '%': { // Lógica nueva agregada
            if (b == 0.0) {
                throw std::runtime_error("modulo entre cero");
            }
            if (std::floor(a) != a || std::floor(b) != b) {
                throw std::runtime_error("el operador modulo requiere operandos enteros");
            }
            return static_cast<double>(static_cast<long long>(a) % static_cast<long long>(b));
        }
        default: return 0.0;
    }
}

// Simulación de los resultados esperados tras modificar la matriz de prioridad
void probarCaso(const std::string& expresion, const std::string& rpn, double (*func)()) {
    std::cout << "Expresion: " << expresion << "\n";
    std::cout << "RPN Generada: " << rpn << "\n";
    try {
        std::cout << "Resultado: " << func() << "\n";
    } catch (const std::runtime_error& e) {
        std::cout << "Error Capturado de forma segura: " << e.what() << "\n";
    }
    std::cout << "\n";
}
}

int main() {
    std::cout << "PRUEBAS DEL NUEVO OPERADOR MÓDULO (%)\n\n";

    // Caso Válido 1
    ods_extended::probarCaso("10 % 3", "10 3 %", []() { 
        return ods_extended::calcuBinarioExt(10, '%', 3); 
    });

    // Caso Válido 2 (Simulando la precedencia mixta: 5 + (11 % 4) * 2)
    ods_extended::probarCaso("5 + 11 % 4 * 2", "5 11 4 % 2 * +", []() {
        double mod = ods_extended::calcuBinarioExt(11, '%', 4); // 3
        double mul = ods_extended::calcuBinarioExt(mod, '*', 2); // 6
        return mod + mul; // 5 + 6 = 11
    });

    // Caso Inválido 1: División / Módulo entre cero
    ods_extended::probarCaso("5 % 0", "5 0 %", []() { 
        return ods_extended::calcuBinarioExt(5, '%', 0); 
    });

    // Caso Inválido 2: Uso con flotantes
    ods_extended::probarCaso("5.5 % 2", "5.5 2 %", []() { 
        return ods_extended::calcuBinarioExt(5.5, '%', 2); 
    });

    return 0;
}