class Solution {
public:
    int rob(vector<int>& nums) {
        // this is a one d dp question

        //data structures
        //note this can be done in place too but for cleaner making a res array
        vector<int> res;
        //base cases
        res.push_back(0); //no house robbed, no profit -> because of this, res will be nums+1 size
        res.push_back(nums[0]); //first house can be robbed without issue;
        // iterative loop
        for(int i = 1;i<nums.size();i++){
            res.push_back(max(nums[i] + res[i-1],res[i]));
            //explaination:
                /*
                either we rob this house and add the max from house - 2
                or we don't rob this and this continues the max from house -1
                */
        }

        //return max
        return res[nums.size()];
    }
};
