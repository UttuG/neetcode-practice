class Solution {
public:
    int max_diameter = 0;

    int maxpath(TreeNode* root) {
        if (root == nullptr) return 0;

        int depth_l = maxpath(root->left);
        int depth_r = maxpath(root->right);

        // update diameter (edges, not nodes)
        max_diameter = max(max_diameter, depth_l + depth_r);

        // return depth
        return max(depth_l, depth_r) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        maxpath(root);
        return max_diameter;
    }
};
