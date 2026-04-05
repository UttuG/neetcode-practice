class Solution {
public:
    int maxArea(vector<int>& heights) {
        //standard 2 pointer
        int max_vol = 0;
        int l = 0;
        int r = heights.size()-1;
        while(l<r){
            max_vol = max(max_vol,min(heights[l],heights[r])*(r-l));
            if (heights[l]<=heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return max_vol;
    }
};
