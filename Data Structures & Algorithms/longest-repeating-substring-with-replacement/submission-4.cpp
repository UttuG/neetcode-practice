class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> char_count;
        int max_l = 0;
        int i = 0;

        for (int j = 0; j < s.length(); j++) {
            char_count[s[j]]++;

            int max_freq = 0;
            for (auto &p : char_count) {
                max_freq = max(max_freq, p.second);
            }

            while ((j - i + 1) - max_freq > k) {
                char_count[s[i]]--;
                i++;
            }

            max_l = max(max_l, j - i + 1);
        }

        return max_l;
    }
};
