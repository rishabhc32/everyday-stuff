// Problem Statement -- https://www.geeksforgeeks.org/find-all-possible-trees-with-given-inorder-traversal/

#include <iostream>
#include <vector>

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

vector<node *> get_tree(int arr[], int start, int end) {
    vector<node *> tree;

    if(start > end) {
        tree.push_back(nullptr);
        return tree;
    }

    for(int i = start ; i <= end ; ++i) {
        vector<node *> ltree = get_tree(arr, start, i-1);
        vector<node *> rtree = get_tree(arr, i+1, end);

        for(int j = 0 ; j < ltree.size() ; ++j) {
            for(int k = 0 ; k < rtree.size() ; ++k) {
                
                node *temp = new_node(arr[i]);
                temp->left = ltree[j];
                temp->right = rtree[k];

                tree.push_back(temp);
            }
        }
    }

    return tree;
}

void preorder(node *root) {
    if (root != nullptr) {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    int arr[] = {1,2,3,4};

    vector<node *> v = get_tree(arr, 0, sizeof(arr)/sizeof(int)-1);

    for(int i = 0 ; i < v.size() ; ++i) {
        preorder(v.at(i));
        cout<<endl;
    }
    cout<<v.size()<<endl;

    return 0;
}