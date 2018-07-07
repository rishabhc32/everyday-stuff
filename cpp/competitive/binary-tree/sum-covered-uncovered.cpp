//Problem Statement -- https://www.geeksforgeeks.org/check-sum-covered-uncovered-nodes-binary-tree/

#include<iostream>

using namespace std;

struct node{
  int data;
  node *left, *right;
};

struct node* newNode(int data){
  struct node *Node = new node;
  Node->data = data;
  Node->left= nullptr;
  Node->right = nullptr;

  return Node;
}

int left_boundary(node* root) {
    int left_sum = 0;

    while(root->left || root->right) {
        left_sum += root->data;

        if(root->left) {
            root = root->left;
        }
        else if(root->right) {
            root = root->right;
        }
    }
    left_sum += root->data;

    return left_sum;
}

int right_boundary(node* root) {
    int right_sum = 0;

    while(root->left || root->right) {
        right_sum += root->data;

        if(root->right) {
            root = root->right;
        }
        else if(root->left) {
            root = root->left;
        }
    }
    right_sum += root->data;

    return right_sum;
}

int boundary_sum(node* root) {
    int boundary_sum = left_boundary(root) + right_boundary(root);
    boundary_sum -= root->data;

    return boundary_sum;
}

void total_sum(int& sum, node* root) {
    if(root == nullptr)
        return;

    total_sum(sum, root->left);
    sum += root->data;
    total_sum(sum, root->right);
}

bool if_sum_equal(node* root) {
    int sum = 0, b_sum;

    total_sum(sum, root);
    b_sum = boundary_sum(root);

    return b_sum == (sum - b_sum);
}

int main() {
    node* root = newNode(8);
    root->left = newNode(3);
    root->left->left = newNode(1);
    root->left->right = newNode(21);
    root->left->right->left = newNode(21);
    root->left->right->right = newNode(7);
    root->right = newNode(10);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);

    if(if_sum_equal(root)) 
        cout<<"Sum of covered and uncovered is same";
    else
        cout<<"Sum of covered and uncovered is not same";
    
    cout<<endl;

    return 0;
}
