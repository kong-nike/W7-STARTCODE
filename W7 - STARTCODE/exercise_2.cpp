#include <iostream>
#include "BinaryTree.h"
#include "Node.h"

void insert(Node* root, int value){
    if (value < root->data){
        if (root->left == NULL){
            root->left = new Node(value);
        } else {
            insert(root->left, value);
        }
    } else {
        if (root->right == NULL) {
            root->right = new Node(value);
        } else {
            insert(root->right, value);
        }
    }
}

int Height(Node* node){
    if(node == NULL){
        return 0;
    }
    int leftHeight = Height(node->left);
    int rightHeight = Height(node->right);
    return std::max(leftHeight, rightHeight) + 1;
}

int main() {
    srand(time(0));
    BinaryTree tree(50);
    std::cout << "Numbers Generated: ";
    for (int i = 1; i <= 50; i++) {
        int num = rand()%100;
        std::cout << num << " ";
        insert(tree.getroot(), num);
    }

    std::cout << "\n";
    std::cout << "\nIn-Order Traversal: " << tree.inOrderTraverse() << "\n";
    std::cout << "Pre-Order Traversal: " << tree.preOrderTraverse() << "\n";
    std::cout << "Post-Order Traversal: " << tree.postOrderTraverse() << "\n";
    int height = Height(tree.getroot());
    std::cout << "Height of the Tree: " << height << "\n";
    return 0;
}
