//Problem Statement -- https://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/

#include <iostream>
#include <queue>

using namespace std;

struct node {
    int data;
    struct node *left, *right;
};
 
node* newNode(int data) {
    node* temp = new node;
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}
void printLeftBoundary(node* root) {
    if(root->left != nullptr) {
        cout<<root->data<<" ";
        printLeftBoundary(root->left);
    }
}

void printRightBoundary(node* root) {
    if(root->right != nullptr) {
        printRightBoundary(root->right);
        cout<<root->data<<" ";
    }
}

void printLeaf(node* root) {
    if(root != nullptr) {
        printLeaf(root->left);

        if(root->left == nullptr && root->right == nullptr)
            cout<<root->data<<" ";
        
        printLeaf(root->right);
    }
}

void printBoundary(node* root) {
    printLeftBoundary(root);
    printLeaf(root);
    printRightBoundary(root->right);
}

int main() {
    node *root                = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);

    printBoundary(root);
    cout<<endl;

    return 0;
}
