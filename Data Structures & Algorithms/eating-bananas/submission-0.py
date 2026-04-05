class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        lp = 1  # start from speed 1, since speed 0 is invalid
        rp = max(piles)  # the maximum possible eating speed
        
        while lp <= rp:
            mid = (lp + rp) // 2  # mid is the current eating speed
            h_sum = 0  # total hours required at speed 'mid'
            
            # Calculate total hours needed to eat all bananas at speed 'mid'
            for i in piles:
                h_sum += (i // mid) + (1 if i % mid != 0 else 0)
            
            # If the total hours is within the allowed hours, try smaller speeds
            if h_sum <= h:
                rp = mid - 1  # try a smaller speed
            else:
                lp = mid + 1  # try a larger speed
        
        # lp will be the minimum speed at which Koko can finish eating all bananas in h hours
        return lp