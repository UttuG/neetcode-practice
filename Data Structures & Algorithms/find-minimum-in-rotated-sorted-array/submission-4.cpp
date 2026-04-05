class Solution {
public:
    int findMin(vector<int> &nums) {
        //the main idea is that there is a sorted half in the array and we can say for sure whether 
        //the min will be in the unsorted section (section where the slope trend changes)

        int l=0;
        int r = nums.size()-1;
        int min_ = INT_MAX;

        //dry run with 2,3 and 4 values in the array
        while (l<=r){
            int mid = (l+r)/2;
            int l_val = nums[l];
            int mid_val = nums[mid];
            int r_val = nums[r];
            min_ = min(min_,mid_val);
            //finding the sorted half:

            if (l_val<=mid_val && mid_val<=r_val){
                //the whole array is sorted so automatically left is global min
                min_ = min(min_,l_val);
                break; //ik this is never reached as return will make the while loop go out of scope but failsafe
            }
            if (l_val<=mid_val){
                //left is the sorted section and right unsorted
                l = mid+1;
                continue;
            }
            else{
                //right is the sorted section and left unsorted
                r = mid-1;
                continue;
            }
        }
        return min_;
    }
};
