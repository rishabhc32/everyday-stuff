//Problem Statement -- https://www.geeksforgeeks.org/find-sum-left-leaves-given-binary-tree/

#include<iostream>

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

void leftLeafSum(node* root, bool isLeft, int& sum) {
    if(root == nullptr)
        return;
    if(isLeft && root->left == nullptr && root->right == nullptr) 
        sum += root->data;
    
    leftLeafSum(root->left, true, sum);
    leftLeafSum(root->right, false, sum);
}

int main() {
    int sum = 0;

    node *root                = newNode(20);
    root->left                = newNode(9);
    root->right               = newNode(49);
    root->right->left         = newNode(23);
    root->right->right        = newNode(52);
    root->right->right->left  = newNode(50);
    root->left->left          = newNode(5);
    root->left->right         = newNode(12);
    root->left->right->right  = newNode(12);

    leftLeafSum(root, false ,sum);
    cout<<sum<<endl;

    return 0;
}
