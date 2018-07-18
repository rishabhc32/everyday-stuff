//Problem Statemet -- https://www.geeksforgeeks.org/transform-bst-sum-tree/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

node* newNode(int item) {
    node* temp =  new node;
    temp->data = item;
    temp->left = temp->right = nullptr;

    return temp;
}

void bst2gst(node* root) {
    static int sum = 0;

    if(root == nullptr)
        return;
    
    bst2gst(root->right);

    int temp = root->data;
    root->data = sum;
    sum += temp;

    bst2gst(root->left);
}

void inorder_print(node* root) {
    if(root == nullptr)
        return;

    inorder_print(root->left);
    cout<<root->data<<" ";
    inorder_print(root->right);
}

int main() {
    node *root = newNode(11);
    root->left = newNode(2);
    root->right = newNode(29);
    root->left->left = newNode(1);
    root->left->right = newNode(7);
    root->right->left = newNode(15);
    root->right->right = newNode(40);
    root->right->right->left = newNode(35);
 
    cout << "Inorder Traversal of given tree\n";
    inorder_print(root);
 
    bst2gst(root);
 
    cout << "\n\nInorder Traversal of transformed tree\n";
    inorder_print(root);
    cout<<endl;

    return 0;
}
