//Problem Statement -- https://www.geeksforgeeks.org/sorted-linked-list-to-balanced-bst/

#include <iostream>
#include <forward_list>
#include <iterator>

using namespace std;

struct node {
    int key;
    node* left;
    node* right;
};

node* newNode(int item) {
    node* temp =  new node;
    temp->key = item;
    temp->left = temp->right = nullptr;

    return temp;
}

node* make_bst(forward_list<int>::iterator& head, int n) {
    if(n <= 0)
        return nullptr;

    node* left = make_bst(head, n/2);

    node* root = newNode(*head);
    root->left = left;
    ++head;

    root->right = make_bst(head, n - n/2 -1);

    return root;
}

void inorder(node *root) {
    if(root == nullptr)
        return;

    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}

int main() {
    forward_list<int> f{1,2,3,4,5,6,7};
    forward_list<int>::iterator head = f.begin();

    node* root = make_bst(head, 7);

    inorder(root);
    cout<<endl;

    return 0;
}
