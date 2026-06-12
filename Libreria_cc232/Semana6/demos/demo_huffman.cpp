// MOD-A6-B8: Pruebas de desempate y escenarios extremos de Huffman
#include <iostream>
#include <vector>
#include <iomanip>
#include "Capitulo6.h"

void procesarAlfabetoHuffman(const std::vector<ods::HuffmanSymbol>& alfabet, const std::string& titulo) {
  std::cout << titulo << "\n";
  std::cout << "\n";

  // Trazado de fusiones
  auto steps = ods::huffmanBuildTrace(alfabet);
  std::cout << "Secuencia de fusiones (Desempate ASCII habilitado):\n";
  for (const auto& s : steps) {
    std::cout << "  (" << s.leftLabel << ":" << s.leftFrequency << ") + (" << s.rightLabel << ":" << s.rightFrequency << ") -> " << s.mergedFrequency << "\n";
  }

  // Generación y análisis de códigos
  auto codes = ods::huffmanGenerateCodes(alfabet);
  bool librePrefijo = ods::huffmanIsPrefixFree(codes);
  int wpl = ods::huffmanWeightedPathLength(alfabet, codes);

  std::cout << "\nTabla resultante de Codificación:\n";
  std::cout << "  " << std::left << std::setw(8) << "Símbolo" << std::setw(12) << "Frecuencia" << std::setw(12) << "Código" << "Longitud\n";
  std::cout << "\n";
  
  for (const auto& s : alfabet) {
    std::cout << "    " << std::left << std::setw(8) << s.symbol << std::setw(12) << s.frequency << std::setw(12) << codes[s.symbol] << codes[s.symbol].size() << "\n";
  }
  
  std::cout << "\n";
  std::cout << "  ¿Es libre de prefijos?: " << (librePrefijo ? "SI" : "NO") << "\n";
  std::cout << "  Longitud del camino ponderado (WPL): " << wpl << "\n\n";
}

int main() {
  // Alfabeto 1: Desempates por frecuencias duplicadas {5, 5} y {10, 10}
  const std::vector<ods::HuffmanSymbol> alfabeto_empates = {
    {'A', 5}, {'B', 5}, {'C', 10}, {'D', 10}, {'E', 20}
  };
  procesarAlfabetoHuffman(alfabeto_empates, "TEST 1: ALFABETO CON EMPATES DE FRECUENCIA");

  // Alfabeto 2: Caso extremo con un único símbolo
  const std::vector<ods::HuffmanSymbol> alfabeto_unitario = {
    {'X', 100}
  };
  procesarAlfabetoHuffman(alfabeto_unitario, "TEST 2: CASO EXTREMO - UN SOLO SIMBOLO");

  return 0;
}
