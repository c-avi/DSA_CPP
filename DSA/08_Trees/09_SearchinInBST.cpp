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

Node* searchInBST(Node* root, int key){
    if(root == NULL || root->data == key) return root;

    if(key < root->data) return searchInBST(root->left, key);

    return searchInBST(root->right, key);
}

Node* minValue(Node* root){
    if(root == NULL) return NULL;

    while(root->left != NULL){
        root = root->left;
    }

    return root;
}

Node* maxValue(Node* root){
    if(root == NULL) return NULL;

    while(root->right != NULL){
        root = root->right;
    }

    return root;
}

int main(){
    // Creating a sample Binary Search Tree
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);


    int key = 9;
    Node* result = searchInBST(root,key);
    if(result)
        cout << "Found node value: " << result->data << endl;
    else
       cout << "node value " << key << " not found"<< endl; 

    Node* min=minValue(root);
    if(minValue){
        cout << "Min value: " << min->data<<endl;
    }else{
        cout<<"BST is empty"<<endl;
    }

    Node* max=maxValue(root);
    if(maxValue){
        cout << "Max value: " << max->data<<endl;
    }else{
        cout<<"BST is empty"<<endl;
    }
    
}