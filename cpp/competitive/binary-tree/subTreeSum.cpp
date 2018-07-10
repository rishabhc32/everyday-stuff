//Problem Statement -- https://www.geeksforgeeks.org/count-subtress-sum-given-value-x/

#include <iostream>

#define getNode(x) newNode(x)

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

int TreeSum(node* root, int& count, const int x) {
    if(root == nullptr)
        return 0;
    
    int l_sum = TreeSum(root->left, count, x);
    int r_sum = TreeSum(root->right, count, x);

    int sum = root->data + l_sum + r_sum;

    if(sum == x)
        ++count;
    
    return sum;
}

int main() {
    node* root = getNode(5);
    root->left = getNode(-10);
    root->right = getNode(3);
    root->left->left = getNode(9);
    root->left->right = getNode(8);
    root->right->left = getNode(-4);
    root->right->right = getNode(7);

    int count = 0;

    TreeSum(root, count, 7);
    cout<<count<<endl;

    return 0;
}
