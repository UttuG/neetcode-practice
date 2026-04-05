class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        from collections import Counter

        len_s1 = len(s1)
        len_s2 = len(s2)

        if len_s1 > len_s2:
            return False

        s1_count = Counter(s1)
        window_count = Counter(s2[:len_s1])

        if s1_count == window_count:
            return True

        for i in range(len_s1, len_s2):
            char_in = s2[i]
            char_out = s2[i - len_s1]

            window_count[char_in] += 1
            window_count[char_out] -= 1

            # Clean up 0-counts to keep dicts comparable
            if window_count[char_out] == 0:
                del window_count[char_out]

            if window_count == s1_count:
                return True

        return False
        