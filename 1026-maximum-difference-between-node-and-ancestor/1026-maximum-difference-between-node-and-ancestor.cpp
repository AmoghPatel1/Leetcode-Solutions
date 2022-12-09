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
    void dfs(TreeNode* root, int min, int max, int &dif) {
        int p = abs(root->val-min);
        int q = abs(root->val-max);
        if(p>dif) dif = p;
        if(q>dif) dif = q;
        if(root->val < min) min = root->val;
        if(root->val > max) max = root->val;
        
        if(root->left) dfs(root->left, min, max, dif);
        if(root->right) dfs(root->right, min, max, dif);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int dif = 0;
        dfs(root, root->val, root->val, dif);
        return dif;
    }
};