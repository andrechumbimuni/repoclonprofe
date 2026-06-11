#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

#include "BaseConversion.h" 

std::string generarComentario(unsigned long long n, int base) {
    if (n == 0) return "Caso base límite: El cero es invariante en cualquier base.";
    if (base == 2) return "Base binaria: Evalúa la máxima longitud de bits en la pila.";
    if (base == 16 && n >= 10) return "Base hexadecimal: Valida la conversión correcta a caracteres A-F.";
    if (base == 10) return "Base decimal: Identidad matemática, la cadena debe ser igual al número.";
    return "Base octal: Conversión posicional estándar de rango medio.";
}

int main() {
    // 1. Definimos al menos 5 números significativos para probar, incluyendo casos borde y números grandes
    std::vector<unsigned long long> numeros = {
        0,              // Caso borde mínimo
        45,             // Número pequeño
        255,            // Límite de un byte (FF en hexadecimal)
        4095,           // Límite de 12 bits (FFF en hexadecimal)
        123456789012ULL // Número grande de 64 bits
    };

    // 2. Definimos las 4 bases distintas requeridas
    std::vector<int> bases = {2, 8, 10, 16};

    // 3. Imprimir la cabecera de la tabla con el formato exacto que te pidieron
    std::cout << "| Número " << std::setw(10) << "| Base " << std::setw(5) << "| Salida Recursiva " << std::setw(20) << "| Salida Iterativa " << std::setw(20) << "| ¿Coinciden? " << std::setw(10) << "| Comentario |\n";

    // 4. Ejecutar la matriz de pruebas (5 números x 4 bases = 20 pruebas automáticas)
    for (unsigned long long n : numeros) {
        for (int b : bases) {
            // Ejecutamos ambos algoritmos de tu librería ods
            std::string rec = ods::toBaseRecursive(n, b);
            std::string it = ods::toBaseIterative(n, b);
            
            // Verificamos si coinciden
            std::string coinciden = (rec == it) ? "Sí" : "No";
            
            // Generamos el comentario
            std::string comentario = generarComentario(n, b);

            // Imprimimos la fila de la tabla
            std::cout << "| " << std::setw(10) << n << " | " << std::setw(5) << b << " | " << std::setw(20) << rec << " | " << std::setw(20) << it << " | " << std::setw(10) << coinciden << " | " << comentario << " |\n";
        }
    }

    return 0;
}