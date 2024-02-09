You have been given a Binary Search Tree and a target value. You need to find out whether there exists a pair of node values in the BST, 
such that their sum is equal to the target value.

A binary search tree (BST), also called an ordered or sorted binary tree, is a rooted binary tree whose internal nodes
 each store a value greater than all the values keys in the node's left subtree and less than those in its right subtree.



void inorder(BinaryTreeNode<int>* root,vector<int> &in){

    if(root == NULL){
        return ;
    }

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	
    vector<int> inOrderVal;
    inorder(root,inOrderVal);
    int i =0, j= inOrderVal.size()-1;
    
    while(i<j){
        int sum = inOrderVal[i] + inOrderVal[j];

        if(sum == target){
            return true;
        }
        
        else if(sum > target)
            j--;
        else   
            i++;
    }
    return false;

}