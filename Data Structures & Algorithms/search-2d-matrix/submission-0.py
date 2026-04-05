class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        #first finding the target search row using first int of the row (if it exists)
        if not matrix or not matrix[0]:
            return False

        # Step 1: Perform binary search on the first column to find the potential row
        lp, rp = 0, len(matrix) - 1
        t_row = -1

        while lp <= rp:
            mid = (lp + rp) // 2
            if matrix[mid][0] == target:
                return True  # Found the target in the first element of a row
            elif matrix[mid][0] < target:
                t_row = mid  # Target could be in this row
                lp = mid + 1  # Search the rows below mid
            else:
                rp = mid - 1  # Search the rows above mid

        if t_row == -1:  # No valid row found
            return False

        # Step 2: Perform binary search on the target row
        lp, rp = 0, len(matrix[t_row]) - 1

        while lp <= rp:
            mid = (lp + rp) // 2
            if matrix[t_row][mid] == target:
                return True
            elif matrix[t_row][mid] < target:
                lp = mid + 1
            else:
                rp = mid - 1

        return False