//Problem Statement -- https://www.geeksforgeeks.org/convert-a-binary-tree-to-a-circular-doubly-link-list/

#include <iostream>
#include <vector>

using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

node* newNode(int data) {
    node* t = new node;
    t->data = data;
    t->left = nullptr;
    t->right = nullptr;
    return t;
}

void tree2doublyLLWrapper(node* root, node*& head) {
    if(root == nullptr)
        return;
    
    static node* pre = nullptr;

    tree2doublyLLWrapper(root->left, head);

    if(head == nullptr)
        head = root;
    else {
        root->left = pre;
        pre->right = root;
    }
    pre = root;

    head->left = pre;

    tree2doublyLLWrapper(root->right, head);
}

void tree2doublyLL(node* root, node*& head) {
    tree2doublyLLWrapper(root, head);

    head->left->right = head;
}

void listTraverse(node* root) {
    node* temp = root;
    do {
        cout<<temp->data<<" ";
        temp = temp->right;
    } while(temp != root);
}

int main() {
    node *root        = newNode(10);
    root->left        = newNode(12);
    root->right       = newNode(15);
    root->left->left  = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);

    node* head = nullptr;

    tree2doublyLL(root, head);
    listTraverse(head);
    cout<<endl;

    return 0;
}
