#include <iostream>
#include <queue>

using namespace std;

class LevelOrderTraversal {
    int data;
    LevelOrderTraversal *left_node, *right_node;    
public:
    LevelOrderTraversal(int arg) {
        data = arg;
        left_node = nullptr;
        right_node = nullptr;
    }

    LevelOrderTraversal*& left() {
        return left_node;
    }
    LevelOrderTraversal*& right() {
        return right_node;
    }

    void Traverse() {
        queue<LevelOrderTraversal*> q;
        LevelOrderTraversal *temp_node = this;

        while(temp_node != nullptr) {
            cout<<temp_node->data<<endl;
            
             if(temp_node->left_node != nullptr)
                q.push(temp_node->left_node);
            if(temp_node->right_node != nullptr)
                q.push(temp_node->right_node);

            temp_node = q.front();
            q.pop();
        }

    }

    void insert(int data) {
        queue<LevelOrderTraversal*> q;
        LevelOrderTraversal *temp_node = this;

        while(temp_node->left_node != nullptr && temp_node->right_node != nullptr) {
            q.push(temp_node->left_node);
            q.push(temp_node->right_node);

            temp_node = q.front();
            q.pop();
        } 
        if(temp_node->left_node == nullptr)
            temp_node->left_node = new LevelOrderTraversal(data);
        else
            temp_node->right_node = new LevelOrderTraversal(data);
        
        return;
    }

    ~LevelOrderTraversal() {
        delete left_node;
        delete right_node;
    }
};

int main() {
    LevelOrderTraversal *root = nullptr;

    root = new LevelOrderTraversal(10);
    root->left() = new LevelOrderTraversal(11);
    root->right() = new LevelOrderTraversal(9);
    root->left()->left() = new LevelOrderTraversal(7);
    root->right()->left() = new LevelOrderTraversal(15);
    root->right()->right() = new LevelOrderTraversal(8);

    root->Traverse();
    root->insert(12);
    cout<<endl;
    root->Traverse();

    return 0;
}

