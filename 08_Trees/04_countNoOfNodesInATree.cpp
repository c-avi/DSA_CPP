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

int noOfNodes(Node* root){
    if (root == NULL)
    {
        return 0;
    }

    int leftCount = noOfNodes(root->left);
    int rightCount = noOfNodes(root->right);

    return 1+leftCount+rightCount;
    
}

int sumNodes(Node* root){
    if (root == NULL)
    {
        return 0;
    }

    int leftSum = sumNodes(root->left);
    int rightSum = sumNodes(root->right);

    return root->data + leftSum+rightSum;

}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right= new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Total no of nodes in binary tree: " << noOfNodes(root) << endl;

    cout << " Sum of all nodes in the given binary tree: " << sumNodes(root) << endl;

    return 0;
}
