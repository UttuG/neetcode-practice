class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //first find the target row
        int l = 0;
        int r = matrix.size()-1;
        int mid = (l+r)/2;

        while(l<=r){
            mid = (l+r)/2;
            if(matrix[mid][0]>target){
                r = mid-1;
                continue;
            }
            if (matrix[mid][matrix[mid].size()-1]<target){
                l = mid+1;
                continue;
            }
            else{
                break;
            }

        }
        //mid is the target row
        int l_c =0;
        int r_c = matrix[mid].size()-1;

        while(l_c<=r_c){
            int mid_c = (l_c+r_c)/2;
            if (matrix[mid][mid_c]==target){
                return true;
            }
            if(matrix[mid][mid_c]>target){
                r_c = mid_c-1;
                continue;
            }
            else{
                l_c = mid_c+1;
                continue;
            }

        }
        return false;
    }
};
