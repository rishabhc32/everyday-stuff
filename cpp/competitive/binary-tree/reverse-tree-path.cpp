//Problem Statement -- https://www.geeksforgeeks.org/reverse-tree-path/

#include <iostream>
#include <vector>

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

void reverse_path(node* root, vector<node*>& v, int key) {
    static bool flag = false;

    if(root == nullptr)
        return;
    
    if(flag == false) {
        if(root->key == key)
            flag = true;

        if(flag == false)
            reverse_path(root->left, v, key);
        if(flag == false)
            reverse_path(root->right, v, key);
    }

    if(flag == true) {
        v.push_back(root);
        return;
    }
}

void vector_reverse(node* root, int key) {
    vector<node*> v;

    reverse_path(root, v, key);

    auto it1 = v.begin(), it2 = v.end()-1;

    while(it1 < it2){
        int t = (*it1)->key;
        (*it1)->key = (*it2)->key;
        (*it2)->key = t; 

        ++it1;
        --it2;
    }
}

void inorder(node* root) {
    if(root == nullptr)
        return;
    
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}

int main() {
    node* root = newNode(7);
    root->left = newNode(6);
    root->right = newNode(5);
    root->left->left = newNode(4);
    root->left->right = newNode(3);
    root->right->left = newNode(2);
    root->right->right = newNode(1);

    inorder(root);
    cout<<endl;

    vector_reverse(root, 4);

    inorder(root);
    cout<<endl;

    return 0;
}