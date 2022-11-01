#pragma once
#include <iostream>
#include <queue>
#include <stack>

/*
    generic complete binary tree class
*/
template<typename T>
class BT {
private:
    /*
        struct for a tree node containing a value and pointers to its left and right children
    */
    struct treeNode {
        T data;
        struct treeNode* left;
        struct treeNode* right;
    };

    struct treeNode* root;
    int size;
    std::queue<struct treeNode*> q;

public:
    /*
        effects: creates an instance of BT class with root set to null and size initialized to 0
    */
    BT() {
       root = NULL;
       size = 0;
    }
    /*
        effects: destroys the BT instance
    */
    ~BT() {
        deleteTree(root);
    }
    /*
        requires: a value T of the node to be added
        effects: adds a new node with the given value val to the highest rightmost node

        test:
            adding negative, positive, zero values -> valid
    */
    void addNode(T val){
       root = addNode(val, root);
    }
    /*
        requires: a value T of the node to be deleted
        effects: deletes the node with value val if it is a leaf else prints "CANNOT DELETE NODE"

        tests:
            deleting leaves ->valid
            deleting interior nodes ->invalid, prompts the user
            deleting values not contained in the tree -> invalid, does nothing
    */
    void deleteNode(T val) {
        root = deleteNode(val, root);
    }
    /*
        effects: performs inorder traversal on the tree and prints the values of nodes
        tests:
            on char and int trees that conatin 1 node, many nodes and are balances, unbalanced
    */
    void inOrderPrint() {
        inOrderPrint(root);
        std::cout << '\n';
    }
    /*
        effects: performs preorder traversal on the tree and prints the values of nodes
        tests:
            on char and int trees that conatin 1 node, many nodes and are balances, unbalanced
    */
    void preOrderPrint() {
        preOrderPrint(root);
        std::cout << '\n';
    }
    /*
        effects: performs postorder traversal on the tree and prints the values of nodes
        tests:
            on char and int trees that conatin 1 node, many nodes and are balances, unbalanced
    */
    void postOrderPrint() {
        postOrderPrint(root);
        std::cout << '\n';
    }
    /*
        effects: returns the number of nodes in the tree
    */
    int treeSize() const {
        return size;
    }
    /*
        main function for testing - called in main.cpp -
    */
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
        t1.inOrderPrint();
        t1.deleteNode(24);
        std::cout << "after deleting a val thats not in the tree: ";
        t1.inOrderPrint();

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
    /*
        helper function for addNode(T val)

        requires: a T val for the data of the node to be added and a node that will be a pointer to the root
        effects: creates a new node with the given val and if the node is null assigns it the new node.
                 else checks for the last added node (stroed in the queue) with an empty child and adds the new node to it.
                 after adding if both children are taken the node is popped. the function returns the node passed as an argument
    */
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
    /*
        helper function for deleteNode(T val)

        requires: a T val for the data of the node to be deleted and a node that will be a pointer to the root
        effects: the function recursively traverses the whole tree until it reaches the leaves. if any of the leaves is a node with 
                 the specified val, it gets deleted, else if the node is found to be internal the function prints "CANNOT DELETE NODE"
                 if the entered value is not in the tree no changes are made
    */
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
    /*
        helper function for inOrderPrint()

        requires: a pointer to the root 
        effects: prints the in order traversal of the tree
    */
    void inOrderPrint(struct treeNode* node) {
        if (node != NULL) {
            inOrderPrint(node->left);
            std::cout << node->data << " ";
            inOrderPrint(node->right);
        }
    }
    /*
        helper function for postOrderPrint()

        requires: a pointer to the root
        effects: prints the post order traversal of the tree
    */
    void postOrderPrint(struct treeNode* node) {
        if (node != NULL) {
            postOrderPrint(node->left);
            postOrderPrint(node->right);
            std::cout << node->data << " ";
        }
    }
    /*
        helper function for preOrderPrint()

        requires: a pointer to the root
        effects: prints the pre order traversal of the tree
    */
    void preOrderPrint(struct treeNode* node) {
        if (node != NULL) {
            std::cout << node->data << " ";
            preOrderPrint(node->left);
            preOrderPrint(node->right);
        }
    }
    /*
        helper function for the destructor

        requires: a pointer to the root
        effects: deallocates the memory of all the nodes
    */
    void deleteTree(struct treeNode* node) {
        if (node != NULL) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }
};