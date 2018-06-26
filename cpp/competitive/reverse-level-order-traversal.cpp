#include <iostream>
#include <queue>
#include <stack>

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
            cout<<temp_node->data<<" ";
            
            q.push(temp_node->left_node);
            q.push(temp_node->right_node);

            temp_node = q.front();
            q.pop();
        }

        cout<<endl;
    }

    void ReverseTraverse() {
        queue<LevelOrderTraversal*> q;
        stack<int> s;
        LevelOrderTraversal *temp_node = this;

        while(temp_node != nullptr) {
            s.push(temp_node->data);

            if(temp_node->right_node != nullptr) {
                q.push(temp_node->right_node);
            }
            if(temp_node->left_node != nullptr) {
                q.push(temp_node->left_node);
            }

            temp_node = q.front();
            q.pop(); 
        }

        while(s.empty() == false){
            cout<<s.top()<<" ";
            s.pop();
        }

        cout<<endl;
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
    root->ReverseTraverse();

    return 0;
}
