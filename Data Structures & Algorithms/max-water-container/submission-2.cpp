class Solution {
public:
    int maxArea(vector<int>& heights) {
        //let's approach this as 2 pointer too

        // the brute force would be comparing the combinations of all pillars 
        // and then calculating the volume

        //what we can do is that we can slowly move towards the better volume approach

        //initialize two pointers left and right

        //the decision to move the pointers is to move the smaller pointer one

        int l = 0;
        int r = heights.size()-1;
        int max_vol = 0;

        while(l<r){
            //calculate the current volume
            max_vol = max(max_vol,((r-l)*min(heights[r],heights[l])));

            if (heights[l]<heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return max_vol;
        
    }
};
