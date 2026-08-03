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
private:
    int solve(TreeNode* root){
        if(root==NULL) return 0;

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        int l = 1 + solve(left);
        int r = 1 + solve(right);

        return max(l, r);

    }
public:
    int maxDepth(TreeNode* root) {
        return solve(root);
    }
};