class Solution {
public:
    int uniquePaths(int m, int n) {
        // we fill up a 2d grid which we will go row wise (from 0 to last array)
        //and left to right

        //we check either left value or top value (depending if possible) and then add them

        vector<vector<int>> res(m, vector<int>(n, 0));
        
        //base case
        res[0][0] = 1;
        //iterate over the array (every row colwise)
        for (int i = 0; i<m;i++){
            for (int j = 0; j<n ; j++){
                //base case should not get overwritten
                if (i==0 && j==0){
                    continue;
                }
                //from top
                int top =0;
                if (i!=0){
                    top = res[i-1][j];
                }
                int left = 0;
                if (j!=0){
                    left = res[i][j-1];
                }
                res[i][j] = top+left;
                
            }
        }
        return res[m-1][n-1];
    }
};
