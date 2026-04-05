class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Stage 1: find the correct row
        int top = 0, bottom = rows - 1;
        while (top <= bottom) {
            int mid = (top + bottom) / 2;
            if (matrix[mid][0] <= target && matrix[mid][cols - 1] >= target) {
                // target must be in this row
                top = mid;
                break;
            } else if (matrix[mid][0] > target) {
                bottom = mid - 1;
            } else {
                top = mid + 1;
            }
        }

        int row = top;
        if (row < 0 || row >= rows) return false;

        // Stage 2: binary search within the row
        int l = 0, h = cols - 1;
        while (l <= h) {
            int m = (l + h) / 2;
            if (matrix[row][m] == target) return true;
            if (matrix[row][m] < target) l = m + 1;
            else h = m - 1;
        }

        return false;
    }
};
