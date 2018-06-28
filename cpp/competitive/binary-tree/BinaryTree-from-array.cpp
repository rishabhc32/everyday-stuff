#include <iostream>

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

void tree_from_array(int arr[], int arr_size, int index, node *& temp) {
    if(index < arr_size) {
        temp = new node;
        temp->data = arr[index];
        tree_from_array(arr, arr_size, (2*index) + 1, temp->left);
        tree_from_array(arr, arr_size, (2*index) + 2, temp->right);
    }
}

void inorder(node *t) {
    if(t) {
        inorder(t->left);
        cout<<t->data<<" ";
        inorder(t->right);
    }
}

int main() {
    int arr[] = {10,12,15,25,30,36};

    node *root = nullptr;

    tree_from_array(arr, sizeof(arr)/sizeof(int), 0, root);
    inorder(root);

    cout<<endl;

    return 0;
}
