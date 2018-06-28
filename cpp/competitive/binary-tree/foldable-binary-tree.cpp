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

bool if_foldable(node*, node*);

bool check_foldable(node *root) {
    if(root == nullptr) 
        return true;

    return if_foldable(root->left, root->right);
}

bool if_foldable(node *left, node *right) {
    if(left == nullptr && right == nullptr)
        return true;
    else if(left == nullptr || right == nullptr)
        return false;
    else    
        return  
            if_foldable(left->left, right->right) &&
            if_foldable(left->right, right->left);  
}

int main() {
    node *root = new_node(10);
    root->left = new_node(7);
    root->right = new_node(15);
    root->right->left = new_node(9);
    root->right->left->left = new_node(11);
    root->left->right = new_node(0);
    root->left->right->right = new_node(17);

    cout<<check_foldable(root)<<endl;

    return 0;
}