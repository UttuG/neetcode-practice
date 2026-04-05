class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //here we need to make another vector array which will track the seq length per number
        
        vector<int> res(nums.size(),1);

        //looping
        for (int i = 0; i<nums.size();i++){
            for (int j = 0; j<i;j++){
                //i is the number we are considering, j will give us numbers that are prev from it
                if (nums[j]<nums[i]){
                    res[i] = max(res[i],res[j]+1);
                }
            }
        };

        return *max_element(res.begin(),res.end());
    }
};
