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
    static bool comp(pair<int,pair<int,int>>& a, pair<int,pair<int,int>>& b) {
        if(a.first == b.first) {
            if(a.second.first == b.second.first) {
                return a.second.second < b.second.second;
            } else return a.second.first < b.second.first;
        } else return a.first < b.first;
    }
    
    void recurse(int horz, int vert, TreeNode* root, vector<pair<int,pair<int,int>>>& vpp) {
        if(!root) return;
        vpp.push_back({horz, {vert, root->val}});
        if(root->left) recurse(horz-1, vert+1, root->left, vpp);
        if(root->right) recurse(horz+1, vert+1, root->right, vpp);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<pair<int,pair<int,int>>> vpp;
        recurse(0,0,root, vpp);
        sort(vpp.begin(), vpp.end(), comp);
        int n = vpp.size();
        int minm = (-1) * vpp[0].first, maxm = vpp[n-1].first;
        vector<vector<int>> ans(minm+maxm+1);
        for(int i=0;i<n;i++) {
            ans[vpp[i].first+minm].push_back(vpp[i].second.second);
        }
        return ans;
    }
};