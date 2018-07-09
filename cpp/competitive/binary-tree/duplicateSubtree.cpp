//Problem Statement -- https://www.geeksforgeeks.org/check-binary-tree-contains-duplicate-subtrees-size-2/

#include<iostream>
#include<string>
#include <unordered_set>

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

unordered_set<string> set;

string ifDuplicateSubtree(node* root) {
    if(root == nullptr)
        return "$";
    
    string lstr = ifDuplicateSubtree(root->left);
    if(lstr == "")
        return "";
    
    string rstr = ifDuplicateSubtree(root->right);
    if(rstr == "")
        return "";
    
    string s = lstr + rstr + root->data;

    if(s.length() > 3 && set.find(s) != set.end()) 
        return "";

    set.insert(s);

    return s;
}

int main() {
    node *root = newNode('A');
    root->left = newNode('B');
    root->right = newNode('C');
    root->left->left = newNode('D');
    root->left->right = newNode('E');
    root->right->right = newNode('B');
    root->right->right->right = newNode('E');
    root->right->right->left= newNode('D');

    if(ifDuplicateSubtree(root) == "")
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
