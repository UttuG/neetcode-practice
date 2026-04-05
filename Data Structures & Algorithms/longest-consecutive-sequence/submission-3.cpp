class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // make a set of the numbers present to remove the duplicates
        unordered_set<int> s;
        for (int element : nums) {
            s.insert(element);
        }
        int max_streak = 0;
        int streak = 0;
        for (int element: s){
            streak = 1;
            if (s.count(element-1)>0) {
                continue;
            }
            if (s.count(element+1)>0) {
                streak+=1;
                while (true){
                    element = element+1;
                    if (s.count(element+1)>0){
                        streak+=1;
                        max_streak=max(max_streak,streak);
                    }
                    else{
                        break;
                    }
                }
            
            }
            max_streak=max(max_streak,streak);
        }
        return max_streak;

    }
};
