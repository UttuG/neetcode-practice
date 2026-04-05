class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        unordered_map<int,vector<int>> bucket;

        // Populating freq map
        for (int i : nums) {
            if (freq.count(i) > 0) {
                freq[i] += 1;
            } else {
                freq[i] = 1;
            }
        }

        int max_num = 0;

        // Populating bucket map
        for (auto &pair : freq) {
            int number = pair.first;
            int frequency = pair.second;

            if (frequency > max_num) max_num = frequency;

            if (bucket.count(frequency) > 0) {
                bucket[frequency].push_back(number);
            } else {
                bucket[frequency] = vector<int>{number};
            }
        }

        // Collect top k frequent elements
        vector<int> result;
        int freq_pointer = max_num;

        while (result.size() < k && freq_pointer > 0) {
            if (bucket.count(freq_pointer) > 0) {
                for (int num : bucket[freq_pointer]) {
                    result.push_back(num);
                    if (result.size() == k) break; // stop once we have k elements
                }
            }
            freq_pointer--; // move to next lower frequency
        }

        return result;
    }
};
