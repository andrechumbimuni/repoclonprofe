#include <iostream>
#include <algorithm>

enum Color { RED = 0, BLACK = 1 };

struct Node {
    int data;
    int colour;
    Node* left;
    Node* right;
    Node* parent;

    Node(int val, Color col) : data(val), colour(col), left(nullptr), right(nullptr), parent(nullptr) {}
};

struct RBValidationResult {
    bool isRootBlack{false};
    bool noRedRed{false};
    bool uniformBlack{false};
    bool isValid{false};
};

class RedBlackTree {
private:
    Node* root;
    Node* nil; // Nodo centinela

    // Estructura auxiliar para la inspección recursiva
    struct NodeState {
        int blackHeight;
        bool validNoRedRed;
    };

    void rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nil) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rotateRight(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != nil) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root = y;
        } else if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

    void insertFixup(Node* k) {
        Node* u;
        while (k->parent != nullptr && k->parent->colour == RED) {
            if (k->parent == k->parent->parent->left) {
                u = k->parent->parent->right; // Tío derecho
                if (u != nil && u->colour == RED) {
                    k->parent->colour = BLACK;
                    u->colour = BLACK;
                    k->parent->parent->colour = RED;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->right) {
                        k = k->parent;
                        rotateLeft(k);
                    }
                    k->parent->colour = BLACK;
                    k->parent->parent->colour = RED;
                    rotateRight(k->parent->parent);
                }
            } else {
                u = k->parent->parent->left; // Tío izquierdo
                if (u != nil && u->colour == RED) {
                    k->parent->colour = BLACK;
                    u->colour = BLACK;
                    k->parent->parent->colour = RED;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->left) {
                        k = k->parent;
                        rotateRight(k);
                    }
                    k->parent->colour = BLACK;
                    k->parent->parent->colour = RED;
                    rotateLeft(k->parent->parent);
                }
            }
            if (k == root) break;
        }
        root->colour = BLACK;
    }

    NodeState inspectStructure(Node* node) {
        if (node == nil) {
            return {1, true}; // Las hojas nil aportan 1 a la altura negra y son válidas
        }

        NodeState leftState = inspectStructure(node->left);
        NodeState rightState = inspectStructure(node->right);

        NodeState currentState;

        // 1. Validar Rojo-Rojo (Un nodo rojo no puede tener hijos rojos)
        if (node->colour == RED) {
            if ((node->left != nil && node->left->colour == RED) || 
                (node->right != nil && node->right->colour == RED)) {
                currentState.validNoRedRed = false;
            } else {
                currentState.validNoRedRed = leftState.validNoRedRed && rightState.validNoRedRed;
            }
        } else {
            currentState.validNoRedRed = leftState.validNoRedRed && rightState.validNoRedRed;
        }

        // 2. Validar Altura Negra Uniforme
        if (leftState.blackHeight == -1 || rightState.blackHeight == -1 || leftState.blackHeight != rightState.blackHeight) {
            currentState.blackHeight = -1; // Desbalance detectado
        } else {
            currentState.blackHeight = leftState.blackHeight + (node->colour == BLACK ? 1 : 0);
        }

        return currentState;
    }

    void destroyTree(Node* node) {
        if (node == nil || node == nullptr) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    RedBlackTree() {
        nil = new Node(0, BLACK);
        root = nil;
    }

    ~RedBlackTree() {
        destroyTree(root);
        delete nil;
    }

    void insert(int key) {
        Node* node = new Node(key, RED);
        node->left = nil;
        node->right = nil;

        Node* y = nullptr;
        Node* x = this->root;

        while (x != nil) {
            y = x;
            if (node->data < x->data) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        node->parent = y;
        if (y == nullptr) {
            root = node;
        } else if (node->data < y->data) {
            y->left = node;
        } else {
            y->right = node;
        }

        if (node->parent == nullptr) {
            node->colour = BLACK;
            return;
        }

        if (node->parent->parent == nullptr) {
            return;
        }

        insertFixup(node);
    }

    RBValidationResult validateBasicProperties() {
        RBValidationResult result;

        if (root == nil) {
            result.isRootBlack = true;
            result.noRedRed = true;
            result.uniformBlack = true;
            result.isValid = true;
            return result;
        }

        NodeState rootState = inspectStructure(root);

        result.isRootBlack = (root->colour == BLACK);
        result.noRedRed = rootState.validNoRedRed;
        result.uniformBlack = (rootState.blackHeight != -1);
        result.isValid = (result.isRootBlack && result.noRedRed && result.uniformBlack);

        return result;
    }
};

int main() {
    std::cout << "Validacion Red-Black Tree\n";

    RedBlackTree rb;

    // Inserciones que gatillan rotaciones y recoloreos automáticos
    for (int x : {15, 10, 20, 5, 12}) {
        rb.insert(x);
    }

    // El main consume el struct de resultados de manera completamente limpia
    RBValidationResult check = rb.validateBasicProperties();

    std::cout << "Raiz negra: " << (check.isRootBlack ? "correcto" : "incorrecto") << "\n";
    std::cout << "Sin rojo-rojo: " << (check.noRedRed ? "correcto" : "incorrecto") << "\n";
    std::cout << "Altura negra uniforme: " << (check.uniformBlack ? "correcto" : "incorrecto") << "\n";
    std::cout << "Estado final: " << (check.isValid ? "valido" : "invalido") << "\n";

    return 0;
}