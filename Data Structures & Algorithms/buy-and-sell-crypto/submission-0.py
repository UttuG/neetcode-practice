class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit=0
        curr_min=prices[0]
        for i in prices:
            if i>curr_min:
                max_profit=max(max_profit,i-curr_min)
            else:
                curr_min=i
        return max_profit
        