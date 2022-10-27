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
    bool hasSum(TreeNode* root, int sum, int targetSum) {
        if(!root) return false;
        sum += root->val;
        if(!root->left && !root->right && sum == targetSum) return true;
        
        return hasSum(root->left, sum, targetSum) || hasSum(root->right, sum, targetSum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return hasSum(root, 0, targetSum);
    }
};