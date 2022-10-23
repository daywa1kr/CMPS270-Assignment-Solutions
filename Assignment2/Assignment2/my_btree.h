#pragma once
#include<iostream>

template<typename T>
class BST {
private:
    struct treeNode {
        T data;
        struct treeNode* left;
        struct treeNode* right;
    };

    struct treeNode* root;
    int size;

public:
    BST() {
       root = NULL;
       size = 0;
    }

    ~BST() {
        deleteTree(root);
    }

    void addNode(T val){
        addNode(val, &root);
    }

    void inOrderPrint() {
        inOrderPrint(root);
        std::cout << '\n';
    }

    void preOrderPrint() {
        preOrderPrint(root);
        std::cout << '\n';
    }

    void postOrderPrint() {
        postOrderPrint(root);
        std::cout << '\n';
    }

    int treeSize() const {
        return size;
    }

private:
    void addNode(T val, struct treeNode** node) {
        if (*node == NULL) {
            struct treeNode* tmp = new struct treeNode;
            tmp->data = val;
            tmp->left = NULL;
            tmp->right = NULL;
            *node = tmp;

            size++;
        }
        else {
            if (val > (*node)->data) {
                addNode(val, &(*node)->right);
            }
            else {
                addNode(val, &(*node)->left);
            }
        }
    }
    void inOrderPrint(struct treeNode* node) {
        if (node != NULL) {
            inOrderPrint(node->left);
            std::cout << node->data << ", ";
            inOrderPrint(node->right);
        }
    }
    void postOrderPrint(struct treeNode* node) {
        if (node != NULL) {
            postOrderPrint(node->left);
            postOrderPrint(node->right);
            std::cout << node->data << ", ";
        }
    }
    void preOrderPrint(struct treeNode* node) {
        if (node != NULL) {
            std::cout << node->data << ", ";
            preOrderPrint(node->left);
            preOrderPrint(node->right);
        }
    }
    void deleteTree(struct treeNode* node) {
        if (node != NULL) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }
};