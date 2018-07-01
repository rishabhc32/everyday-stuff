#include <iostream>

using namespace std;

struct node {
    int data;
    struct node *left, *right;
};
 
node* newNode(int data) {
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}

void morrisTraversalPreorder(node* root) {
    while(root != nullptr) {
        if(root->left == nullptr) {
            cout<<root->data<<" ";
            root = root->right;
        }
        else {
            node* current = root->left;

            while(current->right != nullptr && current->right != root)
                current = current->right;
            
            if(current->right == root) {
                current->right = nullptr;
                root = root->right;
            }
            else {
                cout<<root->data<<" ";
                current->right = root;
                root = root->left;
            }
        }
    }

    cout<<endl;
}

int main() {
    node* root = nullptr;
 
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(11);

    morrisTraversalPreorder(root);

    return 0;
}