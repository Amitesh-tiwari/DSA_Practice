You have been given a binary search tree of integers with ‘N’ nodes. Your task is to convert it into a balanced BST with the minimum height possible.

A binary search tree (BST) is a binary tree data structure that has the following properties.

• The left subtree of a node contains only nodes with data less than the node’s data.
• The right subtree of a node contains only nodes with data greater than the node’s data.
• Both the left and right subtrees must also be binary search trees.
A Balanced BST is defined as a BST, in which the height of two subtrees of every node differs no more than 1.


void inorder(TreeNode<int>* root,vector<int> &in){

    if(root == NULL){
        return ;
    }

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

TreeNode<int>* inorderToBST(int s, int e, vector<int> in){

    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(in[mid]);
    root->left = inorderToBST(s,mid-1,in);
    root->right = inorderToBST(mid+1,e,in);
    return root;


}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
   
    vector<int> inOrderVal;
    inorder(root,inOrderVal);

    return inorderToBST(0,inOrderVal.size()-1,inOrderVal);
}
