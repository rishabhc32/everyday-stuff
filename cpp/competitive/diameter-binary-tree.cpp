#include <iostream>

#define allocate(x) (new x)

using namespace std;

struct node {
    int data;
    node *left = nullptr;
    node *right = nullptr;
};
int max_dia = 0;

void allocate_after_check(node *& temp, char c) {
    switch(c) {
        case 'L': 
            if(temp->left == nullptr)
                temp->left = allocate(node);
            break;
        
        case 'R':
            if(temp->right == nullptr)
                temp->right = allocate(node);
            break;
    }
}

void make_tree(node* root, int no_of_nodes) {

    for(int i = 0 ; i < (no_of_nodes-1) ; ++i) {
        node* temp = root;
        string s;
        int key;
        
        cin>>s>>key;

        auto it = s.begin();

        for( ; it != s.end() ; ++it) {
            if(*it == 'L') {
                allocate_after_check(temp, *it);
                temp = temp->left;
            }
            else if(*it == 'R') {
                allocate_after_check(temp, *it);
                temp = temp->right;
            }
        }

        temp->data = key;
    }
}

int maxDepth(node* node) {
    if (node==NULL) 
        return 0;
    else {
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        max_dia = ((lDepth + rDepth +1) > max_dia ? lDepth+rDepth+1 : max_dia);
              
        if (lDepth > rDepth) 
            return(lDepth+1);
        else 
            return(rDepth+1);
    }
} 

int main() {
    int no_of_nodes, root_key;
    cin>>no_of_nodes>>root_key;

    node *root = allocate(node);
    root->data = root_key;

    make_tree(root, no_of_nodes);
    maxDepth(root);

    cout<<max_dia<<endl;
}
