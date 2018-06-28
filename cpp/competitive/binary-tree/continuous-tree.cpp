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

bool if_continuous(node* temp) {
    if(temp == nullptr) 
        return true;

    if(temp->left == nullptr && temp->right == nullptr)
        return true;
}

int main() {
    node *root = new_node(3);
    root->left = new_node(2);
    root->right = new_node(4);
    root->left->left = new_node(1);
    root->left->right = new_node(3);
    root->right->right = new_node(5);

    cout<<if_continuous(root)<<endl;
    
    return 0;
}

