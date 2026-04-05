class Solution {
public:
    bool isValidWithRange(TreeNode* root, long long low, long long high) {
        if (!root) return true;

        if (root->val <= low || root->val >= high)
            return false;

        return isValidWithRange(root->left, low, root->val) &&
               isValidWithRange(root->right, root->val, high);
    }

    bool isValidBST(TreeNode* root) {
        return isValidWithRange(root, LLONG_MIN, LLONG_MAX);
    }
};
