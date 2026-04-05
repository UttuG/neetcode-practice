class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last_index = {}      # char → its most recent index
        left = 0             # window start
        max_len = 0

        for right, c in enumerate(s):
            # if c is inside current window, slide left past its previous index
            if c in last_index and last_index[c] >= left:
                left = last_index[c] + 1

            # record/update the last seen index of c
            last_index[c] = right

            # update max length so far
            window_length = right - left + 1
            if window_length > max_len:
                max_len = window_length

        return max_len
            