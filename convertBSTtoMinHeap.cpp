You are given a binary search tree which is also a complete binary tree. You have to convert the given BST 
into a Min Heap with the condition that all the values in the left subtree of a node should be less than all 
the values in the right subtree of the node.

A binary search tree (BST) is a binary tree data structure which has the following properties.

• The left subtree of a node contains only nodes with data less than the node’s data.
• The right subtree of a node contains only nodes with data greater than the node’s data.
• Both the left and right subtrees must also be binary search trees.
A Binary Tree is a Complete Binary Tree if all the levels are completely filled except possibly the last level 
and the last level has all keys as left as possible.

A Min Heap is a binary tree in which the value in each internal node is smaller than or equal to the 
values in the children of that node. In this problem, there is also a condition that all the values in
the left subtree of a node should be less than all the values in the right subtree of the node.


 void inorder(BinaryTreeNode<int>* root,vector<int> &in){

    if(root == NULL){
        return ;
    }

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

void PreorderTraversal(BinaryTreeNode<int>* root, vector<int> &in, int &idx ){

    if(root == NULL){
        return;
    }
    
    root->data = in[idx++];
    PreorderTraversal(root->left,in,idx);
    PreorderTraversal(root->right,in,idx);
}


BinaryTreeNode<int>* bstToMinHeap(BinaryTreeNode<int>* root) 
{
    if(root == NULL){
        return NULL;
    }

    vector<int> in;
    inorder(root,in);

    int idx = 0;

    PreorderTraversal(root,in,idx);

    return root;

}