class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //for this first we need to maintain a window of size k
        int l = 0;
        int r = k-1;

        vector<int> res; //will be filled at the end when the window start/end are fixed
        //the rule for sliding would be if the incoming element is cheaper than the outgoing element
        while(r<arr.size()-1){
            if (abs(arr[r+1]-x) < abs(arr[l]-x)){
                r++;
                l++;
            }
            if (abs(arr[r+1]-x) > abs(arr[l]-x)){
                break;
            }
            if (abs(arr[r+1]-x) == abs(arr[l]-x)){
                //edge case when the r+1 and l are same values:
                if (arr[r+1]==arr[l]){
                    r++;
                    l++;
                }
                else{
                break; }//as we prefer to have the smaller of the two
            }
        }

        for(int i = l; i<=r;i++){
            res.push_back(arr[i]);
        }
        return res;
    }
};