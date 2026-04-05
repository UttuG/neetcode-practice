class Solution {
public:
    //global array to store combinations
    vector<vector<int>> res;

    //global stack on which values are being popped or stacked
    stack<int> stk;

    void valid_path(vector<int>& candidates, int target, int pointer){
        //the main dfs function

        //edge case/return handling here
        if(target==0){
            //already at goal
            //make a copy of the stack to push value to res;
            vector<int> temp_res;
            stack<int> stk_copy = stk;
            while(!stk_copy.empty()){
                int temp = stk_copy.top();
                temp_res.push_back(temp);
                stk_copy.pop();
            }
            res.push_back(temp_res);

            return;
        }

        if(target<0){
            return; //basically doing nothing and letting the branch end
        }

        //given the pointer we have 2 choices
            //we accept and push the value present at the pointer to the stack and move pointer
        
        if(pointer<candidates.size()){
        stk.push(candidates[pointer]);
        valid_path(candidates,target-candidates[pointer],pointer+1); //we take the value and move on to next
        stk.pop();
        while(candidates[pointer+1]==candidates[pointer]){
            pointer+=1;
        }
        valid_path(candidates,target,pointer+1);
            //we don't accept the pointer value and move pointer to next unique to avoid duplicates
        }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //this will call the function valid path with the input and return the res
        
        //need to sort the input array too
        sort(candidates.begin(),candidates.end());

        valid_path(candidates,target,0);

        return res;    
    }
};
