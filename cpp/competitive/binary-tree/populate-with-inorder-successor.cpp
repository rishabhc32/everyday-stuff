// Problem Statement -- https://www.geeksforgeeks.org/populate-inorder-successor-for-all-nodes/

#include <iostream>
#include <vector>

using namespace std;

struct node {
    int data;
    node *right = nullptr, *left = nullptr;
    node *next = nullptr;
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
        else {
            cout<<root->data<<" ";
            if(root->next != nullptr)
                cout<<root->next->data;
            cout<<endl;
        }

        get_inorder(root->right, v);
    }
}

void point_next(vector<node *>& v) {
    for(int i = 0 ; i < v.size()-1 ; ++i) {
        v.at(i)->next = v.at(i+1);
    }
}

int main() {
    node* root = new_node(1); 
    root->left = new_node(2);       
    root->right = new_node(3);      
    root->left->left = new_node(4); 
    root->left->right = new_node(5); 
    root->right->left = new_node(6);
    root->right->right = new_node(7);

    vector<node *> v;

    get_inorder(root, &v);
    point_next(v);
    get_inorder(root);

    return 0;
}