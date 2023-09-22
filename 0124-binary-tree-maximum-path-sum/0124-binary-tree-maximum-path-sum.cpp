class Solution {
public:
    // Helper function for recursive traversal
    int traversal(TreeNode* root, int &maxi) {
        // Base case: If the current node is NULL, return 0.
        if (!root) return 0;
        
        // Calculate the maximum path sum for the left subtree,
        // but ignore negative values (max(0, ...)).
        int leftSum = max(0, traversal(root->left, maxi));
        
        // Calculate the maximum path sum for the right subtree,
        // but ignore negative values (max(0, ...)).
        int rightSum = max(0, traversal(root->right, maxi));
        
        // Calculate the maximum path sum that includes the current node.
        int currentPathSum = root->val + leftSum + rightSum;
        
        // Update the overall maximum path sum if the current path sum is greater.
        maxi = max(maxi, currentPathSum);
        
        // Return the maximum path sum that can extend from the current node,
        // either going left or right (max(leftSum, rightSum) + root->val).
        return max(leftSum, rightSum) + root->val;
    }
    
    // Main function to find the maximum path sum in the binary tree
    int maxPathSum(TreeNode* root) {
        // Initialize the maximum path sum to a very small integer.
        int maxi = INT_MIN;
        
        // Start the recursive traversal to find the maximum path sum.
        traversal(root, maxi);
        
        // Return the final maximum path sum.
        return maxi;
    }
};
