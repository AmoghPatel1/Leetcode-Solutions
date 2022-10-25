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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root, 0});
        while(!q.empty()) {
            int size = q.size();
            int min = q.front().second;
            unsigned long long first,last;
            for(int i=0;i<size;i++) {
                auto it = q.front();
                int cur_id = it.second - min;
                q.pop();
                if(i==0) 
                    first = cur_id;
                if(i==size-1)
                    last = cur_id;
                if(it.first->left)
                    q.push({it.first->left, 2*it.second+1});
                if(it.first->right)
                    q.push({it.first->right, 2*it.second+2});
            }
            ans = max(ans, (int)(last-first+1));
        }
        return ans;
    }
};