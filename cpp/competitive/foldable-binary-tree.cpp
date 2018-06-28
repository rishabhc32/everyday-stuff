//Problem Statement -- https://www.geeksforgeeks.org/foldable-binary-trees/

#include <iostream>

using namespace std;

struct node {
    int data;
    node *right = nullptr, *left = nullptr;
};

inline node* new_node(int data) {
    node* temp = new node;
    temp->data = data;
    return temp;
}

bool if_foldable(node *root) {
    if(root==nullptr)
        return true;
    else if(root->left != nullptr && root->right != nullptr)
        return 
            !(if_foldable(root->left->left) ^ if_foldable(root->right->right)) && 
            !(if_foldable(root->left->right) ^ if_foldable(root->right->left));
    else 
        return false;   
}

int main() {
    node *root = new_node(10);
    root->left = new_node(7);
    root->right = new_node(15);
    root->right->left = new_node(9);
    root->right->left->left = new_node(11);
     root->left->right = new_node(0);



    cout<<if_foldable(root)<<endl;

    return 0;
}