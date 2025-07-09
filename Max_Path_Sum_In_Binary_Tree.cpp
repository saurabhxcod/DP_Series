class Solution {
public:
    int maxSum = INT_MIN;

    int maxGain(TreeNode* root) {
        if (!root) return 0;

        // Ignore paths with negative sums
        int left = max(0, maxGain(root->left));
        int right = max(0, maxGain(root->right));

        // Max path sum with current node as highest node
        int currentPathSum = root->val + left + right;

        // Update global maximum
        maxSum = max(maxSum, currentPathSum);

        // Return max gain if continuing upward
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};
