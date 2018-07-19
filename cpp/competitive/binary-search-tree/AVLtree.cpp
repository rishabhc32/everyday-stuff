//Problem Statemet -- https://www.geeksforgeeks.org/avl-tree-set-2-deletion/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int data, height;
    node* left;
    node* right;
};

node* newNode(int item) {
    node* temp =  new node;
    temp->data = item;
    temp->height = 1;
    temp->left = temp->right = nullptr;

    return temp;
}

int get_height(node* root) {
    if(root == nullptr)
        return 0;
    return root->height;
}

int get_balanceFactor(node* root) {
    if(root == nullptr)
        return 0;
    return get_height(root->left) - get_height(root->right);
}

node* right_rotate(node* root) {
    node* t = root->left;
    node* t2 = t->right;

    t->right = root;
    root->left = t2;

    root->height = 1 + max(get_height(root->left), get_height(root->right));
    t->height = 1 +  max(get_height(t->left), get_height(t->right));

    return t;
}

node* left_rotate(node* root) {
    node* t = root->right;
    node* t2 = t->left;

    t->left = root;
    root->right = t2;

    root->height = 1 + max(get_height(root->left), get_height(root->right));
    t->height = 1 +  max(get_height(t->left), get_height(t->right));

    return t;
}

node* balanceHeight(node* root, int key) {
    int bf = get_balanceFactor(root);

    if(bf > 1) {
        if(key < root->left->data)
            return right_rotate(root);

        else if(key > root->left->data) {
            root->left = left_rotate(root->left);
            return right_rotate(root);
        }
    }
    else if(bf < -1) {
        if(key > root->right->data)
            return left_rotate(root);

        else if(key < root->right->data) {
            root->right = right_rotate(root->right);
            return left_rotate(root);
        }
    }

    return root;
}

node* insert(node* root, int key) {
    if(root == nullptr)
        return newNode(key);
    
    if(key < root->data)
        root->left = insert(root->left, key);
    else if(key > root->data)
        root->right = insert(root->right, key);
    
    root->height = 1 +  max(get_height(root->left), get_height(root->right));

    return balanceHeight(root, key);
}

node* findInorderSuccessor(node* root) {
    while(root->left != nullptr)
        root = root->left;
    
    return root;
}

node* balanceDeleteHeight(node* root, int key) {
    int bf = get_balanceFactor(root);

    if(bf > 1) {
        if(get_balanceFactor(root->left) < 0) 
            root->left = left_rotate(root->left);
        
        return right_rotate(root);
    }
    else if(bf < -1) {
        if(get_balanceFactor(root->left) > 0) 
            root->right = right_rotate(root->right);
        
        return left_rotate(root);
    }

    return root;
}

node* delete_node(node* root, int key) {
    if(root == nullptr)
        return root;
    
    if(key < root->data) 
        root->left = delete_node(root->left, key);
    else if(key > root->data)
        root->right = delete_node(root->right, key);

    else {
        if(root->left == nullptr || root->right == nullptr) {
            node* temp = root->left == nullptr ?
                root->right :
                root->left;
            
            delete root;
            return temp;
        }
        else {
            node* temp = findInorderSuccessor(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
    }

    root->height = 1 + max(get_height(root->left), get_height(root->right));
    
    return balanceDeleteHeight(root, key);
}

void preOrder(node *root) {
    if(root != nullptr) {
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    node *root = nullptr;
    
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    cout<<"Preorder traversal of the constructed AVL tree is\n";
    preOrder(root);
    cout<<endl;

    root = delete_node(root, 0);
    root = delete_node(root, -1);
    
    cout<<"Preorder traversal of the AVL tree after deletion is\n";
    preOrder(root);
    cout<<endl;
    
    return 0;
}
