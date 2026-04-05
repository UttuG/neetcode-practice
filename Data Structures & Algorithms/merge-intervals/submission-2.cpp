class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;

        for (vector<int> i : intervals){
            if (res.size()==0){
                res.push_back(i);
                continue;
            }

            if(res[res.size()-1][0]==i[0] || res[res.size()-1][1]>=i[0] ){
                res[res.size()-1][1] = max(i[1],res[res.size()-1][1]);
            }
            else{
                res.push_back(i);
            }

        }
        return res;
    }
};
