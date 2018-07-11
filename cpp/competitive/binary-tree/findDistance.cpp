//Problem Statement -- https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/

#include <iostream>

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

int findDistance(node* root, int n1, int n2, int level = 0) {
    if(root == nullptr)
        return -1;
    
    if(root->data == n1 || root->data == n2) 
        return level;
    
    int l = findDistance(root->left, n1, n2, level+1);
    int r = findDistance(root->right, n1, n2, level+1);

    if(l != -1 && r != -1)
        return l+r;

    return (l != -1 ? l : r);
}

int main() {
    node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);

    cout<<findDistance(findLCA(root, 8, 5), 8, 5)<<endl;
    cout<<findDistance(findLCA(root, 4, 6), 4, 6)<<endl;
    
    return 0;
}
