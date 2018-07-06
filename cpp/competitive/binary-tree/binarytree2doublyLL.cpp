//Problem Statement -- https://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/

#include <iostream>
#include <vector>

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

void inorder(node* root, vector<node *>& v) {
    if(root == nullptr)
        return;
    
    inorder(root->left, v);
    v.push_back(root);
    inorder(root->right, v);
}

void tree2LL(node*& root) {
    vector<node *> v;
    inorder(root, v);

    auto it = v.begin();
    (*it)->right = *(it+1);
    (*it)->left = nullptr;

    root = *it;

    for(it ; it != v.end()-1 ; ++it) {
        (*it)->right = *(it+1);
        (*it)->left = *(it-1);
    }

    (*it)->left = *(it-1);
    (*it)->right = nullptr;
}

void listTraverse(node* root) {
    if(root == nullptr)
        return;
    cout<<root->data<<" ";
    listTraverse(root->right);
}

int main() {
    node *root        = newNode(10);
    root->left        = newNode(12);
    root->right       = newNode(15);
    root->left->left  = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);

    tree2LL(root);
    listTraverse(root);
    cout<<endl;

    return 0;
}
