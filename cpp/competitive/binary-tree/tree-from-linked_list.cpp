//Problem Statement -- https://www.geeksforgeeks.org/given-linked-list-representation-of-complete-tree-convert-it-to-linked-representation/

#include <iostream>
#include <queue>
#include <list>

using namespace std;

struct node {
    int data;
    struct node *left, *right;
};
 
node* newNode(int data) {
    node* temp = new node;
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}

void make_further_tree(queue<node *>& q, auto start, auto end) {
    while(start != end) {
        node* t = q.front();
        q.pop();

        node* left = newNode(*start);
        q.push(left);
        t->left = left;

        if(start == end)
            return;
        ++start;

        if(start == end)
            return;

        node* right = newNode(*start);
        q.push(right);
        t->right = right;

        ++start;
    }
}

node* make_tree(const list<int>& l) {
    auto it = l.begin();
    queue<node *> q;

    node* root = newNode(*it);
    q.push(root);
    ++it;

    auto end = l.end();
    make_further_tree(q, it, end);

    return root;
}

void inorder_traversaal(node* root) {
    if(root) {
        inorder_traversaal(root->left);
        cout<<root->data<<" ";
        inorder_traversaal(root->right);
    }
}

int main() {
    list<int> l{10, 12, 15, 25, 30, 36};

    node* root = make_tree(l);
    inorder_traversaal(root);

    cout<<endl;

    return 0;
}