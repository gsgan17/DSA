/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* getRightChild(TreeNode* node) {
        return node->right;
    }
    TreeNode* getRightmost(TreeNode* node) {
        if (node->right == NULL) {
            return node;
        }
        return getRightmost(node->right);
    }
    TreeNode* helper(TreeNode* node) {
        if (node->left == NULL) {
            return node->right;
        }
        if (node->right == NULL) {
            return node->left;
        }

        TreeNode* rightChild = getRightChild(node);
        TreeNode* rightMost = getRightmost(node->left);
        rightMost->right = rightChild;
        return node->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return root;
        }
        if (root->val == key) {
            return helper(root);
        }

        TreeNode* dummy = root;

        while (dummy != NULL) {
            if (dummy->val > key) {
                if (dummy->left != NULL && dummy->left->val == key) {
                    dummy->left = helper(dummy->left);
                    break;
                } else {
                    dummy = dummy->left;
                }
            } else {
                if (dummy->right != NULL && dummy->right->val == key) {
                    dummy->right = helper(dummy->right);
                    break;
                } else {
                    dummy = dummy->right;
                }
            }
        }
        return root;
    }
};