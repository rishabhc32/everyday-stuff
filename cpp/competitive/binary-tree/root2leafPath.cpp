//Problem Statement -- https://www.geeksforgeeks.org/given-a-binary-tree-print-out-all-of-its-root-to-leaf-paths-one-per-line/

#include<iostream>
#include<vector>

using namespace std;

struct node  {
  int data;
  node * left = nullptr;
  node * right = nullptr;
};

node * newNode(int key) {
  node * temp = new node;

  temp->data = key;
  temp->left = nullptr;
  temp->right= nullptr;

  return temp;
}

void printVector(const vector<int>& v) {
    for(auto& i : v)
        cout<<i<<" ";
    cout<<endl;
}

void printAllPath(node* root, vector<int> v) {
    if(root == nullptr)
        return;

    v.push_back(root->data);

    if(root->left == nullptr && root->right == nullptr) {
        printVector(v);
    }

    printAllPath(root->left, v);
    printAllPath(root->right, v);
}

int main() {
    node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5); 

    vector<int> v;
    printAllPath(root, v);

    return 0;
}
