class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        // 2D DP table: palindrome[i][j] is true if s[i..j] is a palindrome
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));

        int maxLen = 1;
        int start = 0;

        // Base case 1: single characters are palindromes
        for (int i = 0; i < n; i++) {
            palindrome[i][i] = true;
        }

        // Base case 2: check pairs of characters
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                palindrome[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }

        // Expand to longer substrings
        for (int len = 2; len < n; len++) { // len is the length of the substring minus 1
            for (int i = 0; i + len < n; i++) {
                int j = i + len;
                if (s[i] == s[j] && palindrome[i + 1][j - 1]) {
                    palindrome[i][j] = true;
                    if (len + 1 > maxLen) {
                        start = i;
                        maxLen = len + 1;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};
