#include <bits/stdc++.h> 
// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};
***************/

void inorder(BinaryTreeNode<int>* root, vector<int>& vect){
    if(root == NULL) return;  // Base case
    inorder(root->left, vect);
    vect.push_back(root->data);
    inorder(root->right, vect);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Write your code here
    vector<int> inorderVal;
    inorder(root, inorderVal);

    int i = 0;
    int j = inorderVal.size() - 1;

    while (i < j) {
        int sum = inorderVal[i] + inorderVal[j];

        if (sum == target) return true;
        else if (sum < target) i++;  // Move left pointer forward
        else j--;  // Move right pointer backward
    }

    return false;
}

