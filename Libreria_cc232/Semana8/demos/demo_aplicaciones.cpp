#include <iostream>
#include <vector>
#include "Applications.h"

int main() {
    std::vector<int> a{2, 7, 11, 15, 7};
    std::cout << "duplicados=" << ods::hasDuplicates(a) << "\n";

    auto rep = ods::firstRepeated(a);
    if (rep) std::cout << "primer repetido=" << *rep << "\n";

    auto ans = ods::twoSum(a, 9);
    if (ans) std::cout << "twoSum indices=" << ans->first << "," << ans->second << "\n";

    auto freq = ods::wordFrequencyFromText("Hash hash TREE, tree hashing.");
    std::cout << "hash=" << *freq.get("hash") << " tree=" << *freq.get("tree") << "\n";

    // MOD-A8-C
    auto rep_words = ods::findRepeatedWords("Hash hash TREE tree hashing.");
    std::cout << "palabras repetidas de control=" << rep_words.size() << "\n";

}
