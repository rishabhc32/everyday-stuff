//Problem Statement -- https://www.geeksforgeeks.org/diagonal-traversal-of-binary-tree/

#include <iostream>
#include <queue>

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

void diagnol_traversal(node* root) {
    queue<node *> q;
    
    while(root != nullptr) {
        q.push(root);
        root = root->right;
    }

    while(q.empty() == false) {
        root = q.front();
        q.pop();

        cout<<root->data<<" ";

        root = root->left;
        while(root != nullptr) {
            q.push(root);
            root = root->right;
        }
    }

    cout<<endl;
}

int main() {
    node* root = newNode(8);
    root->left = newNode(3);
    root->left->left = newNode(1);
    root->right = newNode(10);
    root->right->left = newNode(6);
    root->right->left->left = newNode(4);
    root->right->left->right = newNode(7);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);

    diagnol_traversal(root);

    return 0;
}
