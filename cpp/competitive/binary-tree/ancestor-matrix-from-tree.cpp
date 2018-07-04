//Problem Statement -- https://www.geeksforgeeks.org/construct-ancestor-matrix-from-a-given-binary-tree/

#include <iostream>
#include <vector>

using namespace std;

struct node {
    int data;
    struct node *left, *right;
};
 
node* newnode(int data) {
    node* temp = new node;
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}

void inorder_traversaal(node* root) {
    if(root) {
        inorder_traversaal(root->left);
        cout<<root->data<<" ";
        inorder_traversaal(root->right);
    }
}

vector< vector<bool> > v(6, vector<bool>(6, false));

void make_matrix(node* root, int n) {
    if(root == nullptr)
        return;
    
    make_matrix(root->left, n);
    make_matrix(root->right, n);

    if(root->left) {
        v[root->data][root->left->data] = true;
        
        for(int i = 0 ; i < n ; ++i) 
            if(v[root->left->data][i] == true)
                v[root->data][i] = true;
    }
    if(root->right) {
        v[root->data][root->right->data] = true;

        for(int i = 0 ; i < n ; ++i) 
            if(v[root->right->data][i] == true)
                v[root->data][i] = true;
    }
}

void print_matrix() {
    for(const auto& i : v) {
        for(const auto& j : i) 
            cout<<j<<" ";
        
        cout<<endl;
    }
}

int main() {
    node *root        = newnode(5);
    root->left        = newnode(1);
    root->right       = newnode(2);
    root->left->left  = newnode(0);
    root->left->right = newnode(4);
    root->right->left = newnode(3);

    make_matrix(root, v[0].size());
    print_matrix();

    return 0;
}