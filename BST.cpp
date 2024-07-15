#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BST {
public:
    TreeNode* root;

    BST() : root(nullptr) {}

    // Function to insert a new node
    TreeNode* insert(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }
        if (val < node->val) {
            node->left = insert(node->left, val);
        } else if (val > node->val) {
            node->right = insert(node->right, val);
        }
        return node;
    }

    // Function to delete a node
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            TreeNode* temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }

    // Function to search a value in BST
    TreeNode* search(TreeNode* root, int val) {
        if (root == nullptr || root->val == val) 
            return root;
        if (root->val < val) 
            return search(root->right, val);
        return search(root->left, val);
    }

private:
    // Utility function to find the node with minimum value
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
};

int main() {
    BST bst;
    bst.root = bst.insert(bst.root, 50);
    bst.insert(bst.root, 30);
    bst.insert(bst.root, 20);
    bst.insert(bst.root, 40);
    bst.insert(bst.root, 70);
    bst.insert(bst.root, 60);
    bst.insert(bst.root, 80);

    cout << "BST after insertion: ";
    // Function to print BST or its elements can be added here

    bst.deleteNode(bst.root, 20);
    cout << "\nBST after deleting 20: ";
    // Function to print BST or its elements can be added here

    if (bst.search(bst.root, 30) != nullptr) {
        cout << "\n30 is found in BST.";
    } else {
        cout << "\n30 is not found in BST.";
    }

    return 0;
}