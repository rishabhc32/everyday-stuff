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

void inorder_using_stack(node* root) {
    stack<node*> s;
    node *temp = root;
    
    while(true) {
        while(temp != nullptr) {
            s.push(temp);
            temp = temp->left;
        }

        if(temp == nullptr && s.empty() == false) {
            temp = s.top();
            s.pop();
            cout<<temp->data<<" ";
            temp = temp->right; 
        }

        if(temp == nullptr && s.empty() == true)
            break;
    }

    cout<<endl;
}

int main() {
    node *root = new_node(3);
    root->left = new_node(2);
    root->right = new_node(4);
    root->left->left = new_node(1);
    root->left->right = new_node(3);
    root->right->right = new_node(5);

    inorder_using_stack(root); 

    return 0;
}
