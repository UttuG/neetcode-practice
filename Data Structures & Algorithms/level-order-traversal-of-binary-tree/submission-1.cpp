class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        deque<TreeNode*> nodes;
        nodes.push_back(root);

        while (!nodes.empty()) {
            int curr_size = nodes.size();   // snapshot level size
            vector<int> temp_res;

            for (int i = 0; i < curr_size; i++) {
                TreeNode* ptr = nodes.front();
                nodes.pop_front();

                temp_res.push_back(ptr->val);

                if (ptr->left)
                    nodes.push_back(ptr->left);
                if (ptr->right)
                    nodes.push_back(ptr->right);
            }

            result.push_back(temp_res);
        }

        return result;
    }
};