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
            cout<<temp_node->data<<" ";
            
            q.push(temp_node->left_node);
            q.push(temp_node->right_node);

            temp_node = q.front();
            q.pop();
        }
        cout<<endl;
    }

    int delete_rightmost() {
        queue<LevelOrderTraversal*> q;
        LevelOrderTraversal *temp_node = this, *parent = nullptr;

        while(temp_node != nullptr) {

            if(temp_node->left_node != nullptr) {
                parent = temp_node;
                q.push(temp_node->left_node);
            }
            if(temp_node->right_node != nullptr) {
                parent = temp_node;
                q.push(temp_node->right_node);
            }

            temp_node = q.front();
            q.pop();
        }

        if(parent->right_node != nullptr) {
            temp_node = parent->right_node;
            parent->right_node = nullptr;
        }
        else if(parent->left_node != nullptr) {
            temp_node = parent->left_node;
            parent->left_node = nullptr;
        }
        else {
            cout<<"Only root node left, deletion not supported "<<endl;
            return -1;
        }

        int return_data = temp_node->data;
        delete temp_node;
        return return_data;
    }

    void delete_key(int key) {        
        queue<LevelOrderTraversal*> q;
        LevelOrderTraversal *temp_node = this;

        while(temp_node != nullptr) {
            if(temp_node->data == key) {
                temp_node->data = this->delete_rightmost();
                return;
            }    
            q.push(temp_node->left_node);
            q.push(temp_node->right_node);

            temp_node = q.front();
            q.pop();
        }

        cout<<"No suck key"<<endl;
    }

    ~LevelOrderTraversal() {
        delete left_node;
        delete right_node;
    }
};

int main() {
    LevelOrderTraversal *root = nullptr;

    root = new LevelOrderTraversal(13);
    root->left() = new LevelOrderTraversal(12);
    root->right() = new LevelOrderTraversal(10);
    root->left()->left() = new LevelOrderTraversal(4);
    root->left()->right() = new LevelOrderTraversal(19);
    root->right()->left() = new LevelOrderTraversal(16);
    root->right()->right() = new LevelOrderTraversal(9);


    root->Traverse();
    root->delete_key(100);
    root->Traverse();

    return 0;
}
