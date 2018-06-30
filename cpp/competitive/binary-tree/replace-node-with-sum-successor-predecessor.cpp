// Problem Statement -- https://www.geeksforgeeks.org/replace-node-binary-tree-sum-inorder-predecessor-successor/

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

void get_inorder(node *root, vector<int>* v = nullptr) {
    if (root != nullptr) {
        get_inorder(root->left, v);

        if(v != nullptr)
            v->push_back(root->data);
        else
            cout<<root->data<<" ";

        get_inorder(root->right, v);
    }
}

vector<int> replace_vector_with_sum(const vector<int> &v, const int size) {
    vector<int> return_vec;

    return_vec.push_back(v.at(1));

    for(int i = 1 ; i < size-1 ; ++i) {
        int ans = v.at(i+1) + v.at(i-1);
        return_vec.push_back(ans);
    }

    int ans = v.at(size-2);
    return_vec.push_back(ans);

    return return_vec;
}

void replace_tree_with_sum(node *root, const vector<int> &v) {
    static int i = 0;

    if(root == nullptr)
        return;

    replace_tree_with_sum(root->left, v);

    root->data = v.at(i);
    ++i;    

    replace_tree_with_sum(root->right, v);
}

int main() {
    node* root = new_node(1); 
    root->left = new_node(2);       
    root->right = new_node(3);      
    root->left->left = new_node(4); 
    root->left->right = new_node(5); 
    root->right->left = new_node(6);
    root->right->right = new_node(7);

    vector<int> inorder_traversal;

    get_inorder(root, &inorder_traversal);
    inorder_traversal = replace_vector_with_sum(inorder_traversal, inorder_traversal.size());
    replace_tree_with_sum(root, inorder_traversal);
    get_inorder(root);
    
    cout<<endl;

    return 0;
}
