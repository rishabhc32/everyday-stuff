//Problem Statement -- https://www.geeksforgeeks.org/construct-tree-from-ancestor-matrix/

#include <iostream>
#include <utility>
#include <unordered_map>

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

 int mat[6][6] = {
    { 0, 0, 0, 0, 0, 0 },
    { 1, 0, 0, 0, 1, 0 },
    { 0, 0, 0, 1, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 0 }
};

void inorder_traversaal(node* root) {
    if(root) {
        inorder_traversaal(root->left);
        cout<<root->data<<" ";
        inorder_traversaal(root->right);
    }
}

void make_tree(int n) {
    unordered_map<int, pair<node *, bool> >m;
    
    for(int i = 0 ; i < n ; ++i) {
        for(int j = 0 ; j < n ; ++j) {
            if(m[i][j] == 1) {
                
            } 
        }
    }
}