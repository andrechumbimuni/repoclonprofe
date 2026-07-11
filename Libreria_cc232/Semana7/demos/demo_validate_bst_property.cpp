//Implementa una función auxiliar que valide si un árbol cumple la propiedad BST usando límites inferiores y superiores.
#include <iostream>
#include <cassert>

struct Node {
    int dato;
    Node* l{nullptr};
    Node* r{nullptr};
    
    explicit Node(int val) : dato(val) {}
};
template <typename Node, typename T>
bool validateBST(Node* node, const T* minValue, const T* maxValue){
    if (node == nullptr) {
        return true;
    }
    // Verificar si el valor actual viola el límite inferior heredado
    if (minValue != nullptr && node->dato <= *minValue) {
        return false;
    }
    // Verificar si el valor actual viola el límite superior heredado
    if (maxValue != nullptr && node->dato >= *maxValue) {
        return false;
    }
    return validateBST(node->l, minValue, &(node->dato)) && validateBST(node->r, &(node->dato), maxValue);
}
int main(){
    std::cout << "Demostracion de Validacion BST con Limites\n";
    Node* validRoot = new Node(5);
    validRoot->l = new Node(3);
    validRoot->r = new Node(7);
    /* Caso 1: Árbol BST Válido
            5
           / \
          3   7
    */
    std::cout << "Caso 1(valido): "<< (validateBST<Node, int>(validRoot, nullptr, nullptr)? "PASO" : "FALLO")<< "\n";
    
    /* Caso 2: Árbol Inválido
             20
            /  \
           10   30
               /
              5   <- Invalido
    */
    Node* invalidRoot = new Node(20);
    invalidRoot->l = new Node(10);
    invalidRoot->r = new Node(30);
    invalidRoot->r->l = new Node(5);
    std::cout << "Caso 2 (Falla ancestro): " << (!validateBST<Node, int>(invalidRoot, nullptr, nullptr) ? "PASO" : "FALLO") << "\n";

    // Limpieza
    delete validRoot->l; delete validRoot->r; delete validRoot;
    delete invalidRoot->r->l; delete invalidRoot->r; delete invalidRoot->l; delete invalidRoot;
    return 0;
}