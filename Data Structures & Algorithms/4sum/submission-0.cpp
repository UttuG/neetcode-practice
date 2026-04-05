class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> result;
        int n = nums.size();

        if(n < 4) return result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {

            // skip duplicate i
            if(i > 0 && nums[i] == nums[i-1]) continue;

            for (int j = i + 1; j < n - 2; j++) {

                // skip duplicate j
                if(j > i + 1 && nums[j] == nums[j-1]) continue;

                long long cur_target = (long long)target - nums[i] - nums[j];

                int l = j + 1;
                int r = n - 1;

                while(l < r) {

                    long long sum = nums[l] + nums[r];

                    if(sum == cur_target) {

                        result.push_back({nums[i], nums[j], nums[l], nums[r]});

                        // skip duplicate l
                        while(l < r && nums[l] == nums[l+1]) l++;

                        // skip duplicate r
                        while(l < r && nums[r] == nums[r-1]) r--;

                        l++;
                        r--;
                    }
                    else if(sum < cur_target) {
                        l++;
                    }
                    else {
                        r--;
                    }
                }
            }
        }

        return result;
    }
};