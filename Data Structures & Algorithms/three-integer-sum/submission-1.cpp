class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        //high level approach
        /*
        we sort the array - nlogn

        we start with a single pointer - curr

        we search a pair "in front of it" which can allow for 0 sum
        key: here we need to make sure that we are moving the pointer to unique values (so we need to track old values too of the pointer)
        keep going too (as there can be multiple pairs) (so looping would be only l<r)
        */

        /*
        edge cases:

        */

        //sort the array        
        sort(nums.begin(),nums.end());

        //result array
        vector<vector<int>> res;

        //initialize the pointers
        int curr = 0;
        int prev_curr = nums[curr];

        for (curr=0;curr<=nums.size()-3;curr++){
            if (nums[curr]==prev_curr && curr!=0){
                continue;
            }
            prev_curr = nums[curr]; //updating prev_curr with the updated curr val
            //initialize the l and r pointers
            int l = curr+1;
            int r = nums.size()-1;

            while(l<r){
                //check the sum
                    int prev_l = nums[l];
                    int prev_r = nums[r];
                    int sum = nums[curr]+nums[l]+nums[r];
                    //if 0 then append to result
                    if (sum==0){
                        res.push_back({nums[curr],nums[l],nums[r]});
                        while(prev_l == nums[l]){
                            l++;
                        }
                        continue;
                    }
                    //(for both make the update a while till prev!=curr)
                    //if less then increase l
                    if (sum<0){
                        while(prev_l == nums[l]){
                            l++;
                        }
                        continue;
                    }
                    //if decrease then decrease r
                    if (sum>0){
                        while(prev_r == nums[r]){
                            r--;
                        }
                        continue;
                    }
            }
        }
        return res;

        
    }
};
