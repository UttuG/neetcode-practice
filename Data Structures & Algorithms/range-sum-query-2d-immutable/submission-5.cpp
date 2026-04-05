class NumMatrix {
public:
    vector<vector<int>> prefix_sum; //the public matrix we will fill from Nummatrix function

    NumMatrix(vector<vector<int>>& matrix) {
        //we apply the prefix sum logic twice here

        //first rowwise as we enter the value into the matrix
        for (vector<int> row : matrix){
        //for each row
            //make a temp row array
            vector<int> temp_row;
            //start a temp collector variable ==0
            int collector = 0;
            //for each value in that row
            for (int i : row){
                //add to the variable
                collector+=i;
                //push the current value of the variable into the temp row array
                temp_row.push_back(collector);
            }
            //push the filled row array into the prefix sum matrix
            prefix_sum.push_back(temp_row);
        }

        //second we again col wise (top to bottom) process again
        //here as we will be doing inplace matrix manipulation, iterator through the index rather than value to be safe

        //for number of columns in the first row
        for (int j = 0; j<prefix_sum[0].size();j++){
            //make a temp collector variable ==0
            int collector =0;
            //for number of rows in the matrix
            for (int i =0;i<prefix_sum.size();i++){
                //add matrix[row][col] to the temp variable
                collector+=prefix_sum[i][j];
                //matrix[row][col] = temp variable
                prefix_sum[i][j] = collector;
            }    
        }
         
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int bigger = prefix_sum[row2][col2];
        int upper;
        int left;
        int overlap;
        if (row1-1<0){
            upper = 0;
        }
        else{
            upper = prefix_sum[row1-1][col2];
        }
        if(col1-1<0){
            left = 0;
        }
        else{
            left = prefix_sum[row2][col1-1];
        }
        if (col1-1<0 or row1-1<0){
            overlap = 0;
        }
        else{
            overlap = prefix_sum[row1-1][col1-1];
        }
        return bigger - upper - left + overlap;
        //return matrix[row2][col2]-matrix[row1-1][col2]-matrix[row2][col1-1]+matrix[row1-1][col1-1]
        //change: didn't take care of double subtracted region + the rows that are getting subtracted
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */