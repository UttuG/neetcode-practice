class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==1){
            return nums[0];
        }

        for (int i = nums.size()-1;i>=0;i--){
            if (i==nums.size()-1){
                continue;
            }
            if (i==nums.size()-2){
                nums[i] = max(nums[i],nums[i+1]);
            }

            else{
                nums[i] = max(nums[i]+nums[i+2],nums[i+1]);
            }
        }
        return nums[0];
        
    }

    
};
