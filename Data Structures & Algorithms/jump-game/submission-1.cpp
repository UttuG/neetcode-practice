class Solution {
public:
    bool canJump(vector<int>& nums) {
        //the idea is that we maintain a max reach value and then iterate over the array
        //if the current index more than max reach-> false
        //if true:
            //update the max reach
            //go ahead
        
        int max_reach=0;
        for (int i=0;i<nums.size();i++){
            //is current index covered by max reach
            if (i>max_reach){
                return false;
            }
            max_reach = max(max_reach,i+nums[i]);
        }
        return true;
    }
};
