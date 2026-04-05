class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height) <= 2:
            return 0

        max_height = max(height)
        max_index = height.index(max_height)

        water = 0
        curr_p = 0
        left_max = height[0]

        # Traverse from left up to max bar
        for i in range(1, max_index + 1):
            if height[i] >= left_max:
                left_max = height[i]
            else:
                water += left_max - height[i]

        # Traverse from right up to max bar
        curr_p_rev = len(height) - 1
        right_max = height[-1]

        for i in range(len(height) - 2, max_index - 1, -1):
            if height[i] >= right_max:
                right_max = height[i]
            else:
                water += right_max - height[i]

        return water
                    
                

