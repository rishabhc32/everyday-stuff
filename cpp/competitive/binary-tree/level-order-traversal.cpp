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
            
            q.push(temp_node->left_node);
            q.push(temp_node->right_node);

            temp_node = q.front();
            q.pop();
        }

    }

    ~LevelOrderTraversal() {
        delete left_node;
        delete right_node;
    }
};

int main() {
    LevelOrderTraversal *root = nullptr;

    root = new LevelOrderTraversal(1);
    root->left() = new LevelOrderTraversal(2);
    root->right() = new LevelOrderTraversal(3);
    root->left()->left() = new LevelOrderTraversal(4);
    root->left()->right() = new LevelOrderTraversal(5);

    root->Traverse();

    return 0;
}
