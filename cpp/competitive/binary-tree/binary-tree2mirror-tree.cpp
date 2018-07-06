//Problem Statement -- https://www.geeksforgeeks.org/write-an-efficient-c-function-to-convert-a-tree-into-its-mirror-tree/

#include <iostream>

using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

node* newNode(int data) {
    node* t = new node;
    t->data = data;
    t->left = nullptr;
    t->right = nullptr;
    return t;
}

void make_mirror_tree(node* root) {
    if(root == nullptr)
        return;
    
    make_mirror_tree(root->left);
    make_mirror_tree(root->right);

    node* t = root->left;
    root->left = root->right;
    root->right = t;
}

void inorder(node* root) {
    if(root == nullptr)
        return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main() {
    node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5); 

    inorder(root);
    cout<<endl;

    make_mirror_tree(root);

    inorder(root);
    cout<<endl;

    return 0;
}
