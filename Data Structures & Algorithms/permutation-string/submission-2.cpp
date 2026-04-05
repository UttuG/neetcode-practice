class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()) return false;

        unordered_map<char, int> dict_s1, dict_s2;

        for (char c : s1) {
            dict_s1[c]++;
        }

        // initial window
        for (int i = 0; i < s1.length(); i++) {
            dict_s2[s2[i]]++;
        }

        if (dict_s1 == dict_s2) return true;

        int i = 0;
        for (int j = s1.length(); j < s2.length(); j++) {
            dict_s2[s2[j]]++;      // add right char
            dict_s2[s2[i]]--;      // remove left char

            if (dict_s2[s2[i]] == 0)
                dict_s2.erase(s2[i]);

            i++;

            if (dict_s1 == dict_s2) return true;
        }

        return false;
    }
};
