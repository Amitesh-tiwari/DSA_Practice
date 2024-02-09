//You are given a binary search tree of integers with N nodes. You are also given references to two nodes 'P' and 'Q' from this BST.



Your task is to find the lowest common ancestor(LCA) of these two given nodes.



The lowest common ancestor for two nodes P and Q is defined as the lowest node that has both P and Q as descendants (where we allow a node to be a descendant of itself)



A binary search tree (BST) is a binary tree data structure which has the following properties.

• The left subtree of a node contains only nodes with data less than the node’s data.
• The right subtree of a node contains only nodes with data greater than the node’s data.
• Both the left and right subtrees must also be binary search trees.


TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    if(root == NULL){
        return NULL;
    }

    if(root->data < P->data && root->data < Q->data)
    {
        return LCAinaBST(root->right,P,Q);
    }

    if(root->data > P->data && root->data > Q->data)
    {
        return LCAinaBST(root->left,P,Q);
    }

    return root;
}