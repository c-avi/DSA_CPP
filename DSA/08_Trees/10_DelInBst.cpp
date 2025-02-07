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

Node* minValue(Node* root){
    if(root == NULL) return NULL;

    while(root->left != NULL){
        root = root->left;
    }

    return root;
}

Node* deleteFromBST(Node* root, int val){
    if(root == NULL) return root;

    if(val < root->data){
        root->left = deleteFromBST(root->left, val); // search in left subtree
    }else if(val > root->data){
        root->right = deleteFromBST(root->right, val); // search in the right subtree
    }else{ // found the node to delete
        // case 1: node has 0 children
        
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // case 2: 1 child
        // left child
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //right child
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // case 3: 2 child
        // either we find max from left subtree or min from right subtree
        Node* minNode = minValue(root->right); // find min in right subtree
        root->data = minNode->data;
        root->right = deleteFromBST(root->right, minNode->data);
        
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<< root->data << " ";
    inorder(root->right);
}

int main(){
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    cout << "Brfore deletion inOrder traversal: ";
    inorder(root);
    cout << endl;

    root = deleteFromBST(root,3);

    cout << "After deletion of 3 (inorder traversal): ";
    inorder(root);
    cout << endl;
    
    return 0;

}