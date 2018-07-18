//Problem Statemet -- https://www.geeksforgeeks.org/binary-tree-to-binary-search-tree-conversion/

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

void inorder_vector(node* root, vector<int>& v) {
    if(root == nullptr)
        return;
    
    inorder_vector(root->left, v);
    v.push_back(root->data);
    inorder_vector(root->right, v);
}

void inorder_store(node* root, const vector<int>& v) {
    static int index = 0;

    if(root == nullptr)
        return;

    inorder_store(root->left, v);

    root->data = v.at(index);
    ++index;

    inorder_store(root->right, v);
}

void bt2bst(node* root) {
    vector<int> v;

    inorder_vector(root, v);
    sort(v.begin(), v.end());
    inorder_store(root, v);
}

void inorder_print(node* root) {
    if(root == nullptr)
        return;

    inorder_print(root->left);
    cout<<root->data<<" ";
    inorder_print(root->right);
}

int main() {
    node *root = nullptr;
    root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);

    bt2bst(root);
    inorder_print(root);
    cout<<endl;

    return 0;
}
