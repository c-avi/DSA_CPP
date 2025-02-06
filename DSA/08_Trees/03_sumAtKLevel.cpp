#include <iostream>
#include <queue>
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

int sumAtKthLevel(Node* root, int k){
    if(root == 0) return 0;

    queue<Node*> q;
    q.push(root);
    int level = 0;
    int sum = 0;

    while(! q.empty()){
        int size = q.size(); // Number of nodes at current level

        // if we reach kth level compute sum
        if(level == k){
            while(size--){
                Node* node = q.front();
                q.pop();
                sum += node->data;
            }
            break;
        }

        // Process next level
        while (size--)
        {
            Node* node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        
        level++;

    }
    return sum;
}

int main(){
    // creating binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int k;
    cout<<"Enter the level k: ";
    cin>>k;
    cout << "Sum at level " << k << "is: " << sumAtKthLevel(root,k) << endl;

    return 0;
}