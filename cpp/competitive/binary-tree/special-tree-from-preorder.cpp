//Problem Statement -- https://www.geeksforgeeks.org/construct-a-special-tree-from-given-preorder-traversal/

#include <iostream>
#include <queue>
#include <list>

using namespace std;

struct node {
    int data;
    struct node *left, *right;
};
 
node* newNode(int data) {
    node* temp = new node;
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}

int pre[] = {10, 30, 20, 5, 15};
char preLN[] = {'N', 'N', 'L', 'L', 'L'};

void inorder_traversaal(node* root) {
    if(root) {
        inorder_traversaal(root->left);
        cout<<root->data<<" ";
        inorder_traversaal(root->right);
    }
}

node* special_wrapper(int& index) {
    if(index > sizeof(pre)/sizeof(int))
        return nullptr;
    
    node* t = newNode(pre[index]);
    
    if(preLN[index] == 'N') {
        t->left = special_wrapper(++index);
        t->right = special_wrapper(++index);
    }

    return t;
}

node* special_tree() {
    int index = 0;
    return special_wrapper(index);
}

int main() {
    node* root = special_tree();
    inorder_traversaal(root);

    cout<<endl;

    return 0;
}