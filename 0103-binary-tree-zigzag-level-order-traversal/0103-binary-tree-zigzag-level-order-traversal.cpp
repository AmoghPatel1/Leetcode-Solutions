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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            vector<int> v;
            for(int i=0;i<size;i++) {
                auto it = q.front();
                q.pop();
                v.push_back(it->val);
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
                
            }
            // if(level%2==1) {
            //     reverse(v.begin(), v.end());
            // }
            ans.push_back(v);
            // level +=1;
        }
        for(int i=0;i<ans.size();i++) {
            if(i%2==1) {
                reverse(ans[i].begin(), ans[i].end());
            }
        }
        
        return ans;
    }
};