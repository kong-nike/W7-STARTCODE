#include <iostream>
#include "BinaryTree.h"
#include "Node.h"

int main() {
    // Create the binary tree with root value 7
    BinaryTree tree(7);

    Node* root = tree.getroot();

    // Build the left subtree
    root->left = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(6);

    // Build the right subtree
    root->right = new Node(9);
    root->right->left = new Node(8);
    root->right->right = new Node(11);

    // Print traversal outputs
    std::cout << "In-Order Traversal: " << tree.inOrderTraverse() << std::endl;
    std::cout << "Pre-Order Traversal: " << tree.preOrderTraverse() << std::endl;
    std::cout << "Post-Order Traversal: " << tree.postOrderTraverse() << std::endl;
    /* Output: 
    In-Order Traversal: 1 5 6 7 8 9 11 
    Pre-Order Traversal: 7 5 1 6 9 8 11 
    Post-Order Traversal: 1 6 5 8 11 9 7 
    */
    return 0;
}
