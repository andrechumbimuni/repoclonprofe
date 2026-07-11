#include <iostream>
#include <algorithm>
#include <cmath>

// Estructura de nodo
struct Node {
    int dato;
    int height{0}; // Altura
    Node* l{nullptr};
    Node* r{nullptr};
    
    explicit Node(int val) : dato(val), height(0) {}
};

// Calcula la altura real de manera recursiva
template <typename Node>
int computeHeight(Node* node) {
    if (node == nullptr) {
        return -1;
    }
    return 1 + std::max(computeHeight(node->l), computeHeight(node->r));
}

// Verifica que árbol cumpla con la propiedad de balance.
template <typename Node>
bool validateAVLBalance(Node* node) {
    if (node == nullptr) {
        return true;
    }

    int hLeft = computeHeight(node->l);
    int hRight = computeHeight(node->r);

    // El factor de balance
    if (std::abs(hLeft - hRight) > 1) {
        return false;
    }

    // Validar recursivamente los subárboles izquierdo y derecho
    return validateAVLBalance(node->l) && validateAVLBalance(node->r);
}

int main() {
    /* Construcción manual de un árbol AVL
               40
             /    \
           20      60
          /  \    /  \
        10   30  50   70
        /
       5
    */
    Node* root = new Node(40);
    root->l = new Node(20);
    root->r = new Node(60);
    
    root->l->l = new Node(10);
    root->l->r = new Node(30);
    root->r->l = new Node(50);
    root->r->r = new Node(70);
    
    root->l->l->l = new Node(5);

    std::cout << "Validacion AVL despues de inserciones\n";
    bool isBalanced = validateAVLBalance(root);
    std::cout << "Estado: " << (isBalanced ? "balanceado" : "desbalanceado") << "\n";
    std::cout << "Altura calculada: " << computeHeight(root) << "\n";

    // Limpieza de memoria
    delete root->l->l->l;
    delete root->l->l; delete root->l->r;
    delete root->r->l; delete root->r->r;
    delete root->l; delete root->r; delete root;

    return 0;
}