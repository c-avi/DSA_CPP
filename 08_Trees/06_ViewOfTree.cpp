#include <iostream>
#include <queue>
using namespace std;

class Node
{

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

void rightView(Node* root){
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        /* we will not add null in the queue, we will calculate the size of the queue and check how many nodes are stored and traverse over it */
        int n= q.size();
        for(int i = 0; i < n; i++){
            // creating a current pointer that will start from the front of queue
            Node* curr = q.front();
            q.pop();

            // when we will reach at last node
            if(i == n-1){
                cout << curr->data << " ";
            }

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    
}

// Function to print the left view of the binary tree
void leftView(Node* root){
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size(); // Number of nodes at the current level

        for(int i = 0; i < n; i++){
            Node* node = q.front();
            q.pop();

            // If it is the first Node of the level, print it
            if(i == 0){
                cout << node->data << " ";
            }

            // Enqueue left and right children (left first for left view)
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right= new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(9);

    cout << "Right View of the given binary tree: ";
    rightView(root);
    cout << endl;

    // Calling the leftView function to print left view
    cout << "Left View of the binary tree: ";
    leftView(root);
    return 0;
}