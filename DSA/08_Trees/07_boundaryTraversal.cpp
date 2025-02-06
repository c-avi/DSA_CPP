#include <iostream>
#include <vector>

using namespace std;

// Definition of Binary Tree Node
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

// Function to check if a node is leaf node
bool isLeaf(Node* node){
    return (node->left == NULL && node->right == NULL);
}

// Function to print the left boundary
void leftBoundary(Node* root, vector<int>& result){
    Node* curr = root->left;
    while(curr){
        if(!isLeaf(curr)) result.push_back(curr->data);
        curr = (curr->left) ? curr->left : curr->right;
    }
}

// Function to collect leaf nodes using inorder traversal
void leafNodes(Node* root, vector<int>& result){
    if(!root) return;

    if(isLeaf(root)){
        result.push_back(root->data);
        return;
    }

    leafNodes(root->left, result);
    leafNodes(root->right, result);
}

// Function to print the right boundary(excluding leaf nodes, in reverse order)
void rightBoundary(Node* root, vector<int>& result){
    Node* curr = root->right;
    vector<int> temp;

    while(curr){
        if(!isLeaf(curr)) temp.push_back(curr->data);
        curr = (curr->right) ? curr->right : curr->left;
    }

    // Add the right boundary in revrse order
    for(int i = temp.size()-1; i >= 0; i--){
        result.push_back(temp[i]);
    }
}

// Function to perform boundary traversal
vector<int> boundaryTraversal(Node* root){
    vector<int> result;
    if(!root) return result;

    // Add root node except when it is a leaf node
    if(!isLeaf(root)) result.push_back(root->data);

    leftBoundary(root,result);
    leafNodes(root,result);
    rightBoundary(root,result);

    return result;
}

int main(){
    // Creating a sample Binary Tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->right->left = new Node(9);
    root->left->right->right = new Node(10);
    root->right->left->right = new Node(11);

    // Performing boundary traversal
    vector<int> result = boundaryTraversal(root);

    // Output the result
    cout << "Boundary traversal of the binary Tree: ";
    for(int val : result){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}