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
    vector<int> first, second;

    void inorder(TreeNode* root, TreeNode* p, TreeNode* q, vector<int> v, map<int, TreeNode*> &mp) {
        if(!root) return;
        if(root == p) {
            v.push_back(root->val);
            first.assign(v.begin(), v.end());
        } else if(root == q) {
            v.push_back(root->val);
            second.assign(v.begin(), v.end());
        }
        mp[root->val] = root;
        v.push_back(root->val);
        inorder(root->left,p,q,v, mp);
        inorder(root->right,p,q,v, mp);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        map<int, TreeNode*> mp;
        inorder(root, p, q, {}, mp);
        int ans = INT_MAX;
        unordered_set<int> s;

        for(auto x : first) s.insert(x);
        for(auto x : second)  {
            if(s.find(x) != s.end()) {
                if(ans != INT_MAX && x < ans) ans = x;
                else ans = x;
            }
        }
        return mp[ans];
    }
};