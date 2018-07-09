//Problem Statement -- https://www.geeksforgeeks.org/check-binary-tree-subtree-another-binary-tree-set-2/

#include<iostream>
#include<string>

using namespace std;

struct node  {
  char data;
  node * left = nullptr;
  node * right = nullptr;
};

node * newNode(char key) {
  node * temp = new node;

  temp->data = key;
  temp->left = nullptr;
  temp->right= nullptr;

  return temp;
}

void storeInorder(node* root, string& s) {
    if(root == nullptr) {
        s.push_back('$');
        return;
    }
    
    storeInorder(root->left, s);
    s.push_back(root->data);
    storeInorder(root->right, s);
}

void storePreorder(node* root, string& s) {
    if(root == nullptr) {
        s.push_back('$');
        return;
    }
    
    s.push_back(root->data);
    storePreorder(root->left, s);
    storePreorder(root->right, s);
}

bool isSubtree(node* T, node* S) {
    if(S == nullptr)
        return true;
    if(T == nullptr)
        return false;

    string T_inorder = "", S_inorder = "";
    storeInorder(T, T_inorder);
    storeInorder(S, S_inorder);

    if(T_inorder.find(S_inorder) == string::npos)
        return false;
    
    string T_preorder = "", S_preorder = "";
    storePreorder(T, T_preorder);    
    storePreorder(S, S_preorder);

    if(T_preorder.find(S_preorder) == string::npos)
        return false;
    
    return true;
}

int main() {
    node *T = newNode('a');
    T->left = newNode('b');
    T->right = newNode('d');
    T->left->left = newNode('c');
    T->right->right = newNode('e');
 
    node *S = newNode('a');
    S->left = newNode('b');
    S->left->left = newNode('c');
    S->right = newNode('d');
 
    if (isSubtree(T, S))
        cout << "Yes: S is a subtree of T"<<endl;
    else
        cout << "No: S is NOT a subtree of T"<<endl;

    return 0;
}
