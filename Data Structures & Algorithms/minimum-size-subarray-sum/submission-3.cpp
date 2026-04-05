class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int l = 0;
        int r = 0;
        int curr_sum = nums[0];   // start with first element
        int min_len = nums.size() + 1;

        while (l <= r && r < nums.size()) {

            if (curr_sum >= target) {

                if (min_len > r - l + 1) {
                    min_len = r - l + 1;
                }

                curr_sum -= nums[l];
                l++;
            }
            else {
                r++;
                if (r < nums.size()) {   // prevent out-of-bounds
                    curr_sum += nums[r];
                }
            }
        }

        if (min_len == nums.size() + 1) {
            return 0;
        }
        else {
            return min_len;
        }
    }
};