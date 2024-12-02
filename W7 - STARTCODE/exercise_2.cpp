#include <iostream>
#include <random>  
#include "BinaryTree.h"
#include "Node.h"

int generateRandomNumber(int lower, int upper) {
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> dist(lower, upper);  
    return dist(gen);  
}

int getTreeHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    int leftHeight = getTreeHeight(node->left);
    int rightHeight = getTreeHeight(node->right);
    return std::max(leftHeight, rightHeight) + 1;
}

int main() {

    int rootValue = generateRandomNumber(1, 100); 
    BinaryTree tree(rootValue);

    for (int i = 0; i < 50; ++i) {
        int newValue = generateRandomNumber(1, 100); 
        if (rand() % 2 == 0) {  
            tree.insertLeft(newValue);
        } else {
            tree.insertRight(newValue);
        }
    }

    std::cout << "In-order Traversal: " << tree.inOrderTraverse() << std::endl;
    std::cout << "Pre-order Traversal: " << tree.preOrderTraverse() << std::endl;
    std::cout << "Post-order Traversal: " << tree.postOrderTraverse() << std::endl;

    int height = getTreeHeight(tree.getroot());
    std::cout << "Height of the tree: " << height << std::endl;

    return 0;
}
