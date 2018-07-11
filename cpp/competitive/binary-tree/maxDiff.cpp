//Problem Statement -- https://www.geeksforgeeks.org/maximum-difference-between-node-and-its-ancestor-in-binary-tree/

#include <iostream>
#include <algorithm>
#include <climits>

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

int maxDiff =  INT_MIN;

int maxDiffFunction(node* root) {
     if (root == nullptr)
        return INT_MAX;

    if(root->left == nullptr && root->right == nullptr)
        return root->data;
    
    int l = maxDiffFunction(root->left);
    int r = maxDiffFunction(root->right);

    if( (root->data - min(l, r)) > maxDiff )
        maxDiff = root->data - min(l ,r);

    return min(root->data, min(l, r));
} 

int main() {
    node* root;
    root = newNode(8);
    root->left = newNode(3);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
    root->right = newNode(10);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);

    maxDiffFunction(root);
    cout<<maxDiff<<endl;

    return 0;
}
