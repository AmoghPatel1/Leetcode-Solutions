/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &mp) {
        if(!root) return;
        if(root->left) {
            mp[root->left] = root;
            dfs(root->left, mp);
        }
        if(root->right) {
            mp[root->right] = root;
            dfs(root->right, mp);
        }
    }
    
    void findNodes(TreeNode* target, int k, unordered_map<TreeNode*, TreeNode*> mp, unordered_set<TreeNode*> &vis, vector<int> &ans) {
        if(vis.count(target)) return;
        if(k == 0) {
            ans.push_back(target->val);
            return;
        }
        vis.insert(target);
        if(target->left) findNodes(target->left, k-1, mp, vis, ans);
        if(target->right) findNodes(target->right, k-1, mp, vis, ans);
        if(mp[target]) findNodes(mp[target], k-1, mp, vis, ans);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp;
        dfs(root, mp);
        unordered_set<TreeNode*> visited;
        vector<int> ans;
        findNodes(target, k, mp, visited, ans);
        return ans;
    }
};