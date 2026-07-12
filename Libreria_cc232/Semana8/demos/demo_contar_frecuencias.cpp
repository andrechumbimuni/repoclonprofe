#include <iostream>
#include <string>
#include "Applications.h"

int main() {
    std::string texto = "estructura datos hash estructura hash";
    
    ods::HashtableOA<std::string, int> frec = ods::wordFrequencyFromText(texto);
    
    std::cout << "frecuencia['estructura'] -> " << *frec.get("estructura") << "\n"; // 2
    std::cout << "frecuencia['hash']       -> " << *frec.get("hash") << "\n";       // 2
    std::cout << "frecuencia['datos']      -> " << *frec.get("datos") << "\n";      // 1
}