#include <iostream>
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

int heightOfTheTree(Node * root){
    if(root == NULL) return -1;

    int leftHeight = heightOfTheTree(root->left);
    int rightHeight = heightOfTheTree(root->right);

    return max(leftHeight,rightHeight)+1;
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

    cout << "Height of thr given binary tree: " << heightOfTheTree(root) << endl;
    return 0;
}