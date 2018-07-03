//Problem Statement -- https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/

#include <iostream>
#include <queue>

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

const int inorder[] = {9, 8, 4, 2, 10, 5, 10, 1, 6, 3, 13, 12, 7};
const int preorder[] = {1, 2, 4, 8, 9, 5, 10, 10, 3, 6, 7, 12, 13};

node* make_tree(int start, int end) {
    static int index = 0;
    int root_index;
    
    if(start < end) {
        for(int i = start ; i <= end ; ++i) {
            if(inorder[i] == preorder[index]) {
                root_index = i;
                break;
            }
        }

        node* root = newNode(inorder[root_index]);
        
        ++index;
        root->left = make_tree(start, root_index-1); 

        ++index;
        root->right = make_tree(root_index+1, end);

        return root;
    }
    else if(start == end) {
        node* root = newNode(inorder[start]);
        return root;
    }
    else {
        --index;
        return nullptr;
    }
}

void inorder_traversaal(node* root) {
    if(root) {
        inorder_traversaal(root->left);
        cout<<root->data<<" ";
        inorder_traversaal(root->right);
    }
}

int main() {
    node* root = make_tree(0, (sizeof(inorder)/sizeof(int))-1 );
    inorder_traversaal(root);

    cout<<endl;

    return 0;
}