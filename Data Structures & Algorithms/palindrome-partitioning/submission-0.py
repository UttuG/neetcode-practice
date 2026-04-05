class Solution:
    def partition(self, s: str) -> List[List[str]]:
        if not s:
            return [[]]
        
        def is_palindrome(sub: str) -> bool:
            return sub == sub[::-1]

        res = []
        for j in range(1, len(s) + 1):
            if is_palindrome(s[:j]):
                for k in self.partition(s[j:]):
                    res.append([s[:j]] + k)
        return res