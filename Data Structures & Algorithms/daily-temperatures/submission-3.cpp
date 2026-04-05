class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //create a stack to save temp
        stack<pair<int,int>> temps;

        //result array
        vector<int> days(temperatures.size());

        for (int i = 0; i<temperatures.size();i++){
            int curr_temp = temperatures[i];
            if(!temps.empty()){
                while(!temps.empty() && temps.top().first<curr_temp){
                    pair top_ = temps.top();
                    temps.pop();
                    days[top_.second] = i-top_.second;
                }
                temps.push({curr_temp,i});
            }
            else{
                temps.push({curr_temp,i});
            }
        }
        //now adding values in res vector for those that didn't get popped (aka days that didn't see a hotter day after them)
        while(!temps.empty()){
            pair top_ = temps.top();
            temps.pop();
            days[top_.second] = 0;
        }
        return days;
    }
};
