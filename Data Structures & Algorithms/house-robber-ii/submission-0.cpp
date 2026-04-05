class Solution {
public:
    // Helper function to solve the House Robber I problem
    int rob2(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        // Use dynamic programming to calculate the maximum money we can rob
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i == nums.size() - 2) {
                nums[i] = max(nums[i], nums[i + 1]);
            } else {
                nums[i] = max(nums[i] + nums[i + 2], nums[i + 1]);
            }
        }
        return nums[0];
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        // Create two subarrays:
        vector<int> nums1(nums.begin(), nums.end() - 1); // nums[0] to nums[n-2]
        vector<int> nums2(nums.begin() + 1, nums.end()); // nums[1] to nums[n-1]
        
        // Return the maximum of robbing either version
        return max(rob2(nums1), rob2(nums2));
    }
};

