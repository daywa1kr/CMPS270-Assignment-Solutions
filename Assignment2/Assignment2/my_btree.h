#pragma once
#include <iostream>
#include <queue>
#include <stack>

template<typename T>
class BT {
private:
    struct treeNode {
        T data;
        struct treeNode* left;
        struct treeNode* right;
    };

    struct treeNode* root;
    int size;
    std::queue<struct treeNode*> q;

public:
    BT() {
       root = NULL;
       size = 0;
    }

    ~BT() {
        deleteTree(root);
    }

    void addNode(T val){
       root = addNode(val, root);
    }

    void deleteNode(T val) {
        root = deleteNode(val, root);
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

    static void main() {
        BT<int> t1;

        t1.addNode(3);
        t1.addNode(5);
        t1.addNode(1);
        t1.addNode(0);
        t1.addNode(2);
        t1.addNode(-19);
        std::cout << "before adding 23 and removing -19 : ";
        t1.inOrderPrint();
        t1.addNode(23);
        t1.deleteNode(-19);
        std::cout << "after adding 23 and removing -19 : ";
        t1.postOrderPrint();

        std::cout << "size: " << t1.treeSize() << '\n';

        BT<char> t2;

        t2.addNode('p');
        t2.addNode('d');
        t2.addNode('3');
        t2.addNode('a');
        t2.addNode('i');
        t2.addNode('X');
        t2.addNode('q');
        t2.addNode('-');

        t2.postOrderPrint();
        t2.inOrderPrint();
        t2.preOrderPrint();

        std::cout << "size: " << t2.treeSize() << '\n';
    }

private:
    struct treeNode* addNode(T val, struct treeNode* node) {
        struct treeNode* tmp = new struct treeNode;
        tmp->data = val;
        tmp->left = NULL;
        tmp->right = NULL;

        if (node == NULL) {
            node = tmp;
        }
        else if (!q.empty() && q.front()->left == NULL) {
            q.front()->left = tmp;
        }
        else {
            if (!q.empty()) {
                q.front()->right = tmp;
                q.pop();
            }
        }
        q.push(tmp);
        size++;
        return node;
    }

    struct treeNode* deleteNode(T val, struct treeNode* node) {
        if (node == NULL) {
            return NULL;
        }
        node->right = deleteNode(val, node->right);
        node->left = deleteNode(val, node->left);

        if (!node->left && !node->right && node->data==val) {
            size--;
            return NULL;
        }
        else if (node->data == val) {
            std::cout << "CANNOT DELETE NODE\n";
            return node;
        }
        return node;
    }

    void inOrderPrint(struct treeNode* node) {
        if (node != NULL) {
            inOrderPrint(node->left);
            std::cout << node->data << " ";
            inOrderPrint(node->right);
        }
    }
    void postOrderPrint(struct treeNode* node) {
        if (node != NULL) {
            postOrderPrint(node->left);
            postOrderPrint(node->right);
            std::cout << node->data << " ";
        }
    }
    void preOrderPrint(struct treeNode* node) {
        if (node != NULL) {
            std::cout << node->data << " ";
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