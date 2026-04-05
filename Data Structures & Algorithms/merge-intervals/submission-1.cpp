class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if (intervals.empty()) return {};

        // first sort them by start time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        }
        );
        
        vector<vector<int>> result;
        //make them like a queue if you will
            //or we can use index to track the intervals covered
        int curr_index = -1; //reset this 
        int curr_end = 0;
        //while queue not empty
        for (int i = 0; i < intervals.size(); i++){

            //check the earliest from front
            if (curr_index==-1){
                curr_index = i;
                curr_end = intervals[i][1];
                continue;
            }

            if (intervals[i][0]>curr_end){
                result.push_back({intervals[curr_index][0],curr_end});
                curr_index = i;
                curr_end = intervals[i][1];
                continue;
            }

            curr_end = max(curr_end,intervals[i][1]);


            //keep in mind that the last interval should be added outside loop

        }
        result.push_back({intervals[curr_index][0],curr_end});

        //return result
        return result;

        
    }
};
