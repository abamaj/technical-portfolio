#include "BinaryTree.hpp"
#include <iomanip>
using namespace std;
#define COUNT 10


binaryTree::binaryTree(){
    root = 0;
}


void displayHelp(Node *input, int space){

    if(input == 0){

        return;
    }

    space += COUNT;

    displayHelp(input->right, space);

    printf("/n");

    for(int i = COUNT; i < space; i++){
        printf(" ");
    }
    printf("%d\n", input->key);


    displayHelp(input->left, space);

}

void insertHelp(Node * &input, int val){
    if(input == 0){
        Node *node = new Node(val);

        input = node;
    }

    else{
        if(input->key > val){
            insertHelp(input->left, val);
        }

        else if(input->key < val){
            insertHelp(input->right, val);
        }
    }

    return;
}

Node *searchHelp(Node *input, int searchval){

    if(input == 0){

        return 0;
    }

    else{
        if(input->key == searchval){

            return input;
        }

        else if(searchval < input->key){

            return search(input->left, searchval);
        }

        else{

            return search(input->right, searchval);
        }
    }
}

void binaryTree::displayBST(){

    displayHelp(root, space);
}

void binaryTree::insertChild(int val){

    insertHelp(root, val);
}

Node* binaryTree::search(int searchVal){

    return searchHelp(root, searchVal);
}
