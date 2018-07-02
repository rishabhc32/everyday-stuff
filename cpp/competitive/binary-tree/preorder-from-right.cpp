//Problem Statement -- https://www.geeksforgeeks.org/modify-binary-tree-get-preorder-traversal-using-right-pointers/

#include <iostream>
#include <queue>

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

void modifyTree(node* root) {
    if(root) {
        modifyTree(root->right);
        modifyTree(root->left);

        if(root->left != nullptr) {
            node* rp = root->right;
            node* lp = root->left;

            root->left = nullptr;
            root->right = lp;

            while(lp->right != nullptr) 
                lp = lp->right;
            
            lp->right = rp;
        }
    }

    return;
}

void printTree(node* root) {
    if(root) {
        cout<<root->data<<" ";
    printTree(root->right);
    }
}
 
int main() {
    node* root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);

    modifyTree(root);
    printTree(root);
    cout<<endl;

    return 0;
}