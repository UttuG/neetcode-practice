class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result = {{}};

        int prev_value = -21;
        int prev_size = 0;

        for (int i : nums) {
            int start = 0;

            if (i == prev_value) {
                start = prev_size;   // only extend newly added subsets
            }

            prev_size = result.size();

            for (int j = start; j < prev_size; j++) {
                vector<int> temp = result[j];
                temp.push_back(i);
                result.push_back(temp);
            }

            prev_value = i;
        }

        return result;
    }
};
