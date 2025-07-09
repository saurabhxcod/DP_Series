class Solution {
public:
    int maxDiameter = 0;

    int height(TreeNode* root) {
        if (!root) return 0;

        int left = height(root->left);
        int right = height(root->right);

        // update diameter at this node
        maxDiameter = max(maxDiameter, left + right);

        return 1 + max(left, right);  // height of subtree
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxDiameter;
    }
};
