//Problem Statement -- https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/

#include <iostream>

#define key data

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

node* findLCA(node* root, const int n1, const int n2) {
    if(root == nullptr)
        return nullptr;
    
    if(root->data == n1 || root->data == n2)
        return root;
    
    node* l = findLCA(root->left, n1, n2);
    node* r = findLCA(root->right, n1, n2);

    if(l && r)
        return root;
    
    return (l != nullptr ? l : r);
}

int main() {
    node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->key;
    cout << "\nnLCA(4, 6) = " << findLCA(root, 4, 6)->key;
    cout << "\nnLCA(3, 4) = " << findLCA(root, 3, 4)->key;
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4)->key<<endl;

    return 0;
}
