#include <iostream>
#include <vector>

using namespace std;

struct node {
    int data;
    node* left = nullptr;
    node* right = nullptr;
};

node* newNode(int data) {
    node* temp = new node;
    temp->data = data;
    return temp;
}

void inorder(node* root, vector<int>& v) {
    if(root == nullptr)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

void preorder(node* root, const vector<int>& v) {
    if(root == nullptr)
        return;

    static int i = 0;

    root->data = v.at(i);
    ++i;

    cout<<root->data<<" ";

    preorder(root->left, v);
    preorder(root->right, v);
}

void doStuff(node* root) {
    vector<int> v;
    inorder(root, v);
    preorder(root, v);
}

int main() {
    node *root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(5);
    root->right->right = newNode(7);

    doStuff(root);
    cout<<endl;

    return 0;
}
