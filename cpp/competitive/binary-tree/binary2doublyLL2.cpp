//Problem Statement -- https://www.geeksforgeeks.org/convert-given-binary-tree-doubly-linked-list-set-3/

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

void tree2doublyLL(node* root, node*& head) {
    if(root == nullptr)
        return;
    
    static node* pre = nullptr;

    tree2doublyLL(root->left, head);

    if(head == nullptr)
        head = root;
    else {
        root->left = pre;
        pre->right = root;
    }
    pre = root;

    tree2doublyLL(root->right, head);
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

    node* head = nullptr;

    tree2doublyLL(root, head);
    listTraverse(head);
    cout<<endl;

    return 0;
}
