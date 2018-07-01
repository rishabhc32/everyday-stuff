// Problem Statement -- https://www.geeksforgeeks.org/threaded-binary-tree/

#include <iostream>
#include <vector>

using namespace std;

struct node {
    int data;
    node *right = nullptr, *left = nullptr;
    bool rightThreaded = false;
};

inline node* new_node(int data) {
    node* temp = new node;
    temp->data = data;
    return temp;
}

void get_inorder(node *root, vector<node *>* v = nullptr) {
    if (root != nullptr) {
        get_inorder(root->left, v);

        if(v != nullptr)
            v->push_back(root);
        else
            cout<<root->data<<" ";

        get_inorder(root->right, v);
    }
}

void make_threads(vector<node *>& v) {
    for(auto it = v.begin() ; it != v.end()-1 ; ++it) {
        if((*it)->right == nullptr) {
            (*it)->right = *(it+1);
            (*it)->rightThreaded = true;
        }
    }
}

node* get_leftmost(node *root) {
    if(root == nullptr)
        return nullptr;

    while(root->left != nullptr)
        root = root->left;
    
    return root;
}

void threaded_inorder_traversal(node* root) {
    node *curr = get_leftmost(root);

    while(curr != nullptr) {
        cout<<curr->data<<" ";

        if(curr->rightThreaded)
            curr = curr->right;
        else
            curr = get_leftmost(curr->right);
    }

    cout<<endl;
}

int main() {
    node* root = new_node(6); 
    root->left = new_node(3);       
    root->right = new_node(8);      
    root->left->left = new_node(1); 
    root->left->right = new_node(5); 
    root->right->left = new_node(7);
    root->right->right = new_node(11);
    root->right->right->left = new_node(9);
    root->right->right->right = new_node(13);

    vector<node *> inorder_traversal;

    get_inorder(root, &inorder_traversal);
    make_threads(inorder_traversal);
    threaded_inorder_traversal(root);

    return 0;
}