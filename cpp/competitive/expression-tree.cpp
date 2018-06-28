//Problem Statement -- https://www.geeksforgeeks.org/expression-tree/

#include <iostream>
#include <sstream>
#include <cctype>
#include <stack>

using namespace std;

struct node {
    char data;
    node *right = nullptr, *left = nullptr;
};

inline node* new_node(char data) {
    node* temp = new node;
    temp->data = data;
    return temp;
}

bool isoperand(char c) {
    if (c == '+' || c == '-' ||
        c == '*' || c == '/' ||
        c == '^')
        return true;

    return false;
}

node* construct_expression_tree(string postfix) {
    stack<node *> s;

    stringstream ss(postfix);
    char c;

    while(ss >> c) {
        node *temp = new_node(c);

        if(isoperand(c)) {
            node *right = s.top();
            s.pop();
            node *left = s.top();
            s.pop();

            temp->left = left;
            temp->right = right;
            s.push(temp);
        } 
        else   
            s.push(temp); 
    }

    return s.top();
}

void inorder(node *t) {
    if(t) {
        inorder(t->left);
        cout<<t->data<<" ";
        inorder(t->right);
    }
}

int main() {
    string postfix = "12+23*4*-";

    node *root = construct_expression_tree(postfix);
    inorder(root);

    cout<<endl;

    return 0;
}