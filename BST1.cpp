#include <iostream>
using namespace std;

// This node class consists of parent....i.e its specificatlly constructed for bst.
class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node* parent;

    Node(int val)  {
        left=nullptr;
        right=nullptr;
        parent=nullptr;
        value=val;
    }
};

// BST class
class BST {
public:
    Node* root;

    BST(){
        root=nullptr;
    }

    // Insert operation
    void insert(int x) {
        Node* y = new Node(x);
        if (root == nullptr) {
            root = y;
            
        }
        else{
        Node* parent = nullptr;
        Node* curr = root;
        while (curr != nullptr) {
            parent = curr;
            if (x < curr->value){
                curr = curr->left;}
            else{
                curr = curr->right;}
        }
        if (x < parent->value)
            parent->left = y;
        else
            parent->right = y;
        y->parent = parent;
    }
}

    // Search operation
    bool search(Node* node, int x) {
        if (node == nullptr)
            return false;
        if (node->value == x)
            return true;
        if (x < node->value)
            return search(node->left, x);
        return search(node->right, x);
    }

    // Get minimum value node
    Node* getMin(Node* node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    // Transplant function where we transplant u with v (i.e u goes in the place of v)...................
    void transplant(Node* u, Node* v) {
        if (u->parent == nullptr)
            root = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;
        if (v != nullptr)
            v->parent = u->parent;
    }

    // Delete operation
    void remove(int x) {
        Node* z = root;
        while (z != nullptr && z->value != x) {
            if (x < z->value)
                z = z->left;
            else
                z = z->right;
        }
        if (z == nullptr)
            return;
        if (z->left == nullptr)
            transplant(z, z->right);
        else if (z->right == nullptr)
            transplant(z, z->left);
        else {
            Node* y = getMin(z->right);
            if (y->parent != z) {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
        }
    }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Search 40: " << tree.search(tree.root, 40) << endl;
    cout << "Search 25: " << tree.search(tree.root, 25) << endl;

    tree.remove(30);
    cout << "Search 30 after deletion: " << tree.search(tree.root, 30) << endl;

    return 0;
}
