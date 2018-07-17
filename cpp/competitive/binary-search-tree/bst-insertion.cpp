//Problem Statement -- https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/

#include <iostream>

using namespace std;

struct node {
    int key;
    node* left;
    node* right;
};

node* newNode(int item) {
    node* temp =  new node;
    temp->key = item;
    temp->left = temp->right = nullptr;

    return temp;
}

node* insert(node* root, int key) {
    if(root == nullptr)
        return newNode(key);
    
    if(key < root->key) 
        root->left = insert(root->left, key);
    else if(key > root->key)
        root->right = insert(root->right, key);
    
    return root;
}

node* search(node* root, int key) {
    if(root == nullptr || root->key == key) 
        return root;
    
    if(key < root->key)
        return search(root->left, key);
    
    else if(key > root->key)
        return search(root->right, key);
}

void inorder(node* root) {
    if(root) {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

int main() {
    node *root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    inorder(root);
    cout<<endl;

    if(search(root, 90))
        cout<<"Found\n";
    else  
        cout<<"Not found\n";
    
    if(search(root, 80))
        cout<<"Found\n";
    else  
        cout<<"Not found\n";

    return 0;
}
