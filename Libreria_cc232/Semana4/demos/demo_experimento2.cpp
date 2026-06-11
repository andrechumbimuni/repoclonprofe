#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Parentheses.h"

struct CasoPrueba {
    std::string categoria;
    std::string expresion;
    std::string explicacion;
};

int main() {
    // Definición de las 8 expresiones solicitadas con sus objetivos de análisis
    std::vector<CasoPrueba> casos = {
        {
            "Vacía", 
            "", 
            "Caso base absoluto. Ambos algoritmos lo procesan como exitoso inmediatamente."
        },
        {
            "Sin paréntesis", 
            "Expresion plana con texto 123", 
            "No contiene delimitadores. La iterativa termina con pila vacía y la recursiva reduce sus índices a cero."
        },
        {
            "Correctamente anidada", 
            "((a + b) * (c - d))", 
            "Estructura pura de paréntesis circulares con anidamiento válido. Ambos métodos funcionan perfecto."
        },
        {
            "Con desbalance", 
            "((a + b)", 
            "Falta un paréntesis de cierre. Ambos algoritmos detectan que la estructura quedó incompleta."
        },
        {
            "Con cruce incorrecto", 
            "([)]", 
            "¡Falla crítica de la recursiva! Da TRUE porque ignora los '[]' y solo ve los '()' balanceados externamente. La iterativa sí detecta el error (FALSE)."
        },
        {
            "Varios delimitadores", 
            "{[()]}", 
            "Estructura mixta simétrica. Coinciden en TRUE porque la recursiva solo evalúa el '()' interno y la iterativa procesa todo en orden."
        },
        {
            "Expresión larga", 
            "(a+b)*{c-[d/(e+f)]-g}*[(h-i)/(j+k)]", 
            "Caso complejo del mundo real. Todos los componentes internos '()' están balanceados, por lo que ambos dan TRUE."
        },
        {
            "Inventada (Falso Positivo)", 
            "{[ ( ] ) }", 
            "Diseñada para engañar: el cruce incorrecto ocurre dentro de los corchetes/llaves. La recursiva se confunde y da TRUE; la iterativa se defiende con FALSE."
        }
    };

    // Imprimir cabecera de la tabla con formato Markdown
    std::cout << "| Categoría" << std::setw(20) << " | Expresión " << std::setw(20) << "| Resultado Recursivo " << std::setw(20) << "| Resultado Iterativo " << std::setw(10) << "| ¿Coinciden? " << std::setw(20) << "| Explicación del Caso |\n";

    // Ejecución de la batería de pruebas
    for (const auto& caso : casos) {
        // Ejecución de tus funciones de la librería ods
        bool resRec = ods::parenRecursive(caso.expresion);
        bool resIt = ods::parenIterative(caso.expresion);

        std::string strRec = resRec ? "TRUE (Válido)" : "FALSE (Inválido)";
        std::string strIt = resIt ? "TRUE (Válido)" : "FALSE (Inválido)";
        std::string coinciden = (resRec == resIt) ? "Sí" : "**NO**";

        // Imprimir
        std::cout << "| " << caso.categoria << std::setw(5) << " | " << caso.expresion << std::setw(10) << " | " << strRec << std::setw(10) << " | " << strIt << std::setw(10) << " | " << coinciden << std::setw(20) << " | " << caso.explicacion << " |\n";
    }

    return 0;
}