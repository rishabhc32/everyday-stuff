//Problem Statement -- https://www.geeksforgeeks.org/construct-full-binary-tree-using-preorder-traversal-preorder-traversal-mirror-tree/
#include <iostream>

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

int p[] = {1,2,4,5,3,6,7}, pM[] = {1,3,7,6,2,5,4};

void inorder_traversaal(node* root) {
    if(root) {
        inorder_traversaal(root->left);
        cout<<root->data<<" ";
        inorder_traversaal(root->right);
    }
}

node* make_tree(int p_start, int p_end, int pM_start, int pM_end) {
    if(p_start <= p_end && pM_start <= pM_end) {
        node* root = newNode(p[p_start]);

        if(p_start != p_end && pM_start != pM_end) {
            int right_root, left_root;

            for(int i = p_start+1 ; i<= p_end ; ++i) 
                if(p[i] == pM[pM_start+1]) {
                    right_root = i;
                    break;
                }
            for(int i = pM_start+1 ; i<= pM_end ; ++i)
                if(pM[i] == p[p_start+1]) {
                    left_root = i;
                    break;
                }
            
            root->left = make_tree(p_start+1, right_root-1, left_root, pM_end);
            root->right = make_tree(right_root, p_end, pM_start+1, left_root-1);
        }

        return root;
    }

    return nullptr;
}

int main() {
    int size = sizeof(p)/sizeof(int) - 1;

    node* root = make_tree(0, size, 0, size);
    inorder_traversaal(root);

    cout<<endl;

    return 0;
}