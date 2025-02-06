#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printLevelOrder(Node* root){
    // base case
    if(root == NULL) return;

    // step1: create queue and push root and NULL
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    // Iterate until queue is empty
    while(!q.empty()){
        Node* node = q.front();
        q.pop();

        if(node != NULL){
            cout << node->data << " ";

            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }else if(!q.empty()){
            cout << endl;  // Move to next level
            q.push(NULL);
        }
    }
}

int main(){
    // Creating the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Level Order Traversal of the Tree:" << endl;
    printLevelOrder(root);

    return 0;
}
