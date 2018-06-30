//Problem Statement -- https://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/

#include <iostream>
#include <stack>

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

void spiral_level_order(node *root) {
    stack<node *> s1, s2;
    s1.push(root);

    while(!s1.empty() || !s2.empty()) {
        while(!s1.empty()) {
            node* temp = s1.top();
            cout<<temp->data<<" ";

            if(temp->right != nullptr)
                s2.push(temp->right);
            if(temp->left != nullptr)
                s2.push(temp->left);

            s1.pop();
        }

        while(!s2.empty()) {
            node* temp = s2.top();
            cout<<temp->data<<" ";

            if(temp->left != nullptr)
                s1.push(temp->left);
            if(temp->right != nullptr)
                s1.push(temp->right);

            s2.pop();
        }
    }
    
    cout<<endl;
}

int main() {
    node *root         = new_node(1);
    root->left         = new_node(2);
    root->right        = new_node(3);
    root->left->left   = new_node(7);
    root->left->right  = new_node(6);
    root->right->left  = new_node(5);
    root->right->right = new_node(4);

    spiral_level_order(root);

    return 0;
}