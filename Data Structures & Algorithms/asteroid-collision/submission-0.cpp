class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        //really simple stack question
        /*
        flag to add current value in the stack or not =0
        when we push a certain astroid in the stack
            //while loop below
            while the top of the stack is not in the same direction 
            AND
            !this is pointing right and top is left
            AND
            !stack is empty

            if the astroid on top is smaller than current astroid
                //pop
                continue
            if bigger break and make flag -1
        if flag not -1, push the current astroid in the stack
        return stack
        */

        //stack declaration
        stack<int> stk;

        for (int& i: asteroids){
            bool destroyed = false;
            while (stk.size()!=0 && stk.top()>0 && i<0){
                if (stk.top()>abs(i)){
                    destroyed = true;
                    break;
                }
                if(stk.top()==abs(i)){
                    destroyed = true;
                    stk.pop();
                    break;
                }
                if(stk.top()<abs(i)){
                    stk.pop();
                    continue;
                }
            }
            if (destroyed==false){
                stk.push(i);
            }
        }
        vector<int> result(stk.size());

        for(int i = stk.size() - 1; i >= 0; i--) {
            result[i] = stk.top();
            stk.pop();
        }

        return result;
        
    }
};