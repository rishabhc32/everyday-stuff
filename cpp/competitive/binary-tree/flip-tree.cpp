//Problem Statement -- https://www.geeksforgeeks.org/flip-binary-tree/

#include<iostream>
#include<stack>

using namespace std;

struct node{
  int data;
  node *left, *right;
};

struct node* newNode(int data){
  struct node *Node = new node;
  Node->data = data;
  Node->left= nullptr;
  Node->right = nullptr;

  return Node;
}

node* flip_tree(node* root) {
    if(root == nullptr)
        return root;
    if(root->left == nullptr && root->right == nullptr)
        return root;
    
    node* t = flip_tree(root->left);

    root->left->left = root->right;
    root->left->right = root;
    root->left = root->right = nullptr;

    return t;
}

void inorder(node* root) {
    if(root == nullptr)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main() {
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);

    root = flip_tree(root);
    inorder(root);
    cout<<endl;
    
    return 0;
}
