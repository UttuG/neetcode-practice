class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        max_area =0
        stack =[]
        for i, h in enumerate(heights):
            start = i
            while stack and stack[-1][1] > h:
                popped = stack.pop()
                max_area = max(max_area, popped[1] * (i - popped[0]))
                start = popped[0]  # ⬅️ Preserve the left boundary
            stack.append([start, h]) 
        for h in stack:
            max_area = max(max_area,h[1]*(len(heights)-h[0]))
        
        return max_area