class Solution {
public:
    int maxArea(vector<int>& heights) {
        // the logic here is to move pointer 
        //towards middle while improving on min(height), that way more 
        //water can be stored potentially
        int i=0;
        int j=heights.size()-1;
        int max_area=0;
        while (i<j){
            //check current area and compare to max
            int area = min(heights[j],heights[i])*(j-i);
            if (max_area<area){
                max_area = area;
            }
            if (heights[i]<heights[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return max_area;
    }
};
