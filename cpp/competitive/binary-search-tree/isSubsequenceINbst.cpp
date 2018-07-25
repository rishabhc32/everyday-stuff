// Problem Statement -- https://www.geeksforgeeks.org/check-if-given-sorted-sub-sequence-exists-in-binary-search-tree/

#include <iostream>
#include <deque>

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

node* insert(node* root, int key) {
    if (root == NULL)
        return newNode(key);
    if (root->data > key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

void isThere(node* root, deque<int>& q) {
    if(root == nullptr)
        return;

    isThere(root->left, q);
    if(root->data == q.front())
        q.pop_front();
    isThere(root->right, q);
}

int main() {
    node* root = nullptr;
    root = insert(root, 8);
    root = insert(root, 10);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 14);
    root = insert(root, 13);

    deque<int> q{4,6,8,14};

    isThere(root, q);

    if(q.empty())
        cout<<"YES\n";
    else    
        cout<<"NO\n";

    return 0;
}

