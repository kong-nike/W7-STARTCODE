#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <string>
#include "Node.h"

class BinaryTree {
private:
    Node* root;
public:
    BinaryTree(int value) {
        root = new Node(value);
    }
    void insertLeft(int value) {
        root->left = new Node(value);
    }
    void insertRight(int value) {
        root->right = new Node(value);
    }

    std::string inOrderTraverse() {
        std::string result = "";
        inOrder(root, result);
        return result;
    }
    std::string preOrderTraverse() {
        std::string result = "";
        preOrder(root, result);
        return result;
    }
    std::string postOrderTraverse() {
        std::string result = "";
        postOrder(root, result);
        return result;
    }

    Node* getroot() {
        return root;
    }


private:
   void inOrder(Node* node, std::string& result) {
        if (node == nullptr) return;
        inOrder(node->left, result); 
        result += std::to_string(node->data) + " ";  
        inOrder(node->right, result); 
    }

    void preOrder(Node* node, std::string& result) {
        if (node == nullptr) return;
        result += std::to_string(node->data) + " "; 
        preOrder(node->left, result); 
        preOrder(node->right, result);
    }

    void postOrder(Node* node, std::string& result) {
        if (node == nullptr) return;
        postOrder(node->left, result);  
        postOrder(node->right, result); 
        result += std::to_string(node->data) + " ";  
    }
};

#endif // BINARYTREE_H
