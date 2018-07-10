//Problem Statement -- https://www.geeksforgeeks.org/find-maximum-path-sum-two-leaves-binary-tree/

#include <iostream>
#include <climits>
#include <algorithm>

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

int max_data = INT_MIN;

int maxSum(node* root) {
    if(root == nullptr)
        return 0;
    
    int left_sum = maxSum(root->left);
    int right_sum = maxSum(root->right);

    if(root->data + left_sum + right_sum > max_data)
        max_data = root->data + left_sum + right_sum;

    return max(root->data + left_sum, root->data + right_sum);
}

int main() {
    node *root = newNode(-15);
    root->left = newNode(5);
    root->right = newNode(6);
    root->left->left = newNode(-8);
    root->left->right = newNode(1);
    root->left->left->left = newNode(2);
    root->left->left->right = newNode(6);
    root->right->left = newNode(3);
    root->right->right = newNode(9);
    root->right->right->right= newNode(0);
    root->right->right->right->left= newNode(4);
    root->right->right->right->right= newNode(-1);
    root->right->right->right->right->left= newNode(10);

    maxSum(root);

    cout<<max_data<<endl;

    return 0;
}
