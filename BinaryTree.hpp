#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP
#include <string>
#include <math.h>
#include <iostream>
#include <iomanip>

using namespace std;

struct Node{

    int key;
    Node *left;
    Node *right;
};

class binaryTree{

    private:
        Node *root;

    public:
        binaryTree();
        void displayBST();
        void insertChild(int val);
        void search(int searchVal);



};

#endif;

