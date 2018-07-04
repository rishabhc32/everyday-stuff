//Problem Statement -- https://www.geeksforgeeks.org/create-doubly-linked-list-ternary-ree/

#include <iostream>
#include <list>

using namespace std;

struct node {
    int data;
    struct node *left, *right, *middle;
};
 
node* newNode(int data) {
    node* temp = new node;
    temp->data = data;
    temp->left = temp->middle = temp->right = nullptr;
    return temp;
}

void TreetoDoubly(node* root, list<int>& l) {
    if(root == nullptr)
        return;

    l.push_back(root->data);

    TreetoDoubly(root->left, l);
    TreetoDoubly(root->middle, l);
    TreetoDoubly(root->right, l);
}

void printList(const list<int>& l) {
    for(const auto& i : l) 
        cout<<i<<" ";
    cout<<endl;
}

int main() {
    node* root = newNode(30);
    root->left = newNode(5);
    root->middle = newNode(11);
    root->right = newNode(63);
    root->left->left = newNode(1);
    root->left->middle = newNode(4);
    root->left->right = newNode(8); 
    root->middle->left = newNode(6);
    root->middle->middle = newNode(7);
    root->middle->right = newNode(15);
    root->right->left = newNode(31);
    root->right->middle = newNode(55);
    root->right->right = newNode(65);

    list<int> l;

    TreetoDoubly(root, l);
    printList(l);

    return 0;
}