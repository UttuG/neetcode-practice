class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        bool inserted = false;

        for (auto &interval : intervals) {
            if (interval[1] < newInterval[0]) {
                // interval before newInterval
                result.push_back(interval);
            } else if (interval[0] > newInterval[1]) {
                // interval after newInterval
                if (!inserted) {
                    result.push_back(newInterval);
                    inserted = true;
                }
                result.push_back(interval);
            } else {
                // overlapping, merge into newInterval
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            }
        }

        if (!inserted) {
            result.push_back(newInterval);
        }

        return result;

    }
};
