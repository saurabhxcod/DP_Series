class Solution {
public:
    int maxSum = INT_MIN;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        // If leaf node
        if (!root->left && !root->right)
            return root->val;

        // Recursively get left & right subtree max
        int left = dfs(root->left);
        int right = dfs(root->right);

        // If both children exist, check for leaf-to-leaf path
        if (root->left && root->right) {
            int currentSum = left + right + root->val;
            maxSum = max(maxSum, currentSum);
            return root->val + max(left, right);
        }

        // If only one child exists, return path through that child
        return root->left ? root->val + left : root->val + right;
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);

        // In case there is only one leaf, maxSum might not be updated
        return maxSum;
    }
};
