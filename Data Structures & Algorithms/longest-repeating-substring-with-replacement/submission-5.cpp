class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        if (n == 0) return 0;

        unordered_map<char,int> freq;
        int l = 0;
        int ans = 0;

        for (int r = 0; r < n; ++r) {
            freq[s[r]]++;

            // compute true max frequency in current window
            int maxCount = 0;
            for (auto &p : freq) {
                maxCount = max(maxCount, p.second);
            }

            while ((r - l + 1) - maxCount > k) {
                freq[s[l]]--;
                if (freq[s[l]] == 0) freq.erase(s[l]); // optional cleanup
                l++;

                // recompute true max after shrinking
                maxCount = 0;
                for (auto &p : freq) {
                    maxCount = max(maxCount, p.second);
                }
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};