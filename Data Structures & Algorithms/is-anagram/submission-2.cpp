class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char,int> alphacount;

        // Count characters in s
        for (int i = 0; i < s.length(); i++) {
            if (alphacount.find(s[i]) != alphacount.end()) {
                alphacount[s[i]]++;
            } else {
                alphacount[s[i]] = 1;
            }
        }

        // Subtract counts using t
        for (int i = 0; i < t.length(); i++) {
            if (alphacount.find(t[i]) != alphacount.end()) {
                alphacount[t[i]]--;
            } else {
                alphacount[t[i]] = -1;
            }
        }

        // Check if all counts are zero
        for (auto &pair : alphacount) {
            if (pair.second != 0) return false;
        }

        return true;
    }
};
