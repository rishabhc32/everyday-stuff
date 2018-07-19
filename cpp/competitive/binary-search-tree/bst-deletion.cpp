//Problem Statement -- https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/

#include <iostream>

#define deleteNode delete_node

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

node* findInorderSuccessor(node* root) {
    while(root->left != nullptr)
        root = root->left;
    
    return root;
}

node* delete_node(node* root, int key) {
    if(root == nullptr)
        return root;

    if(key < root->key) 
        root->left = delete_node(root->left, key);
    else if(key > root->key)
        root->right = delete_node(root->right, key);
    
    else {
        if(root->left == nullptr || root->right == nullptr) {
            node* temp = root->left == nullptr ?
                root->right :
                root->left;

            delete root;
            return temp;
        }

        node* temp = findInorderSuccessor(root->right);
        root->key = temp->key;
        root->right = delete_node(root->right, temp->key);
    }

    return root;
}

node* insert(node*, int);
void inorder(node*);

int main() {
    node *root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of the given tree \n");
    inorder(root);
 
    printf("\nDelete 20\n");
    deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 30\n");
    deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 50\n");
    deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
    cout<<endl;

    return 0;
}

node* insert(node* root, int key) {
    if(root == nullptr)
        return newNode(key);
    
    if(key < root->key) 
        root->left = insert(root->left, key);
    else if(key > root->key)
        root->right = insert(root->right, key);
    
    return root;
}

void inorder(node* root) {
    if(root) {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}
