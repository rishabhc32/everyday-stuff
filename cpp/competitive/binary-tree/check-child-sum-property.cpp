//Problem Statement -- https://www.geeksforgeeks.org/check-for-children-sum-property-in-a-binary-tree/

#include <iostream>

using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

struct node* newNode(int data) {
    node* t = new node;
    t->data = data;
    t->left = nullptr;
    t->right = nullptr;
    return t;
}

bool isSumProperty(struct node* node) {
    if(node == nullptr || (node->left == nullptr && node->right == nullptr))
        return true;  

    int temp = 0;
    
    if(node->right != nullptr)
        temp += node->right->data;
    if(node->left != nullptr)
        temp += node->left->data;
 
    if(temp == node->data)
        return isSumProperty(node->left) && isSumProperty(node->right);
    else 
        return false;
}

int main() {
    node *root         = newNode(10);
    root->left         = newNode(8);
    root->right        = newNode(2);
    root->left->left   = newNode(3);
    root->left->right  = newNode(6);
    root->right->right = newNode(2);

    if(isSumProperty(root))
        cout<<"The given tree satisfies the children sum property ";
    else
        cout<<"The given tree does not satisfy the children sum property ";

    cout<<endl;

    return 0;
}