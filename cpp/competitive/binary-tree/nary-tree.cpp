#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10;

struct Node {
    char data;
    vector<Node *> child;

    Node(char c): data(c) {
        child.resize(MAX, nullptr);
    }
};

void postorder(Node* root) {
    if(root == nullptr)
        return;
    
    for(auto i : root->child) {
        postorder(i);
    }
    cout<<root->data<<" ";
}

int main() {
    Node *root = new Node('A');
    root->child[0] = new Node('B');
    root->child[1] = new Node('C');
    root->child[2] = new Node('D');
    root->child[3] = new Node('E');
    root->child[0]->child[0] = new Node('F');
    root->child[0]->child[1] = new Node('G');
    root->child[2]->child[0] = new Node('H');
    root->child[0]->child[0]->child[0] = new Node('I');
    root->child[0]->child[0]->child[1] = new Node('J');
    root->child[0]->child[0]->child[2] = new Node('K');
    root->child[2]->child[0]->child[0] = new Node('L');
    root->child[2]->child[0]->child[1] = new Node('M');
    
    postorder(root);
    cout<<endl;

    return 0;
}