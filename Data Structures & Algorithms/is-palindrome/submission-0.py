class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = re.sub(r'[^a-zA-Z0-9]', '', s).lower()
        l_p=0
        r_p=len(s)-1
        while l_p<=r_p:
            if s[l_p]!=s[r_p]:
                return False
            l_p+=1
            r_p-=1
        return True
        