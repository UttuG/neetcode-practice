#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> deq;   // {value, index}
        vector<int> res;

        int n = nums.size();
        if (k == 0 || n == 0) return {};
        if (k == 1) return nums;

        int l = 0;
        int r = 0;

        while (r < n) {

            if (r <= k - 1) {   // fixed syntax

                // remove smaller elements from back
                while (!deq.empty() && deq.back().first < nums[r]) {
                    deq.pop_back();
                }

                deq.push_back({nums[r], r});
                r++;

                // if first window complete, push result
                if (r == k) {
                    res.push_back(deq.front().first);
                }

                continue;
            }
            else {

                // window is sliding now
                // update left boundary first
                l++;

                // remove stale front elements
                while (!deq.empty() && deq.front().second < l) {
                    deq.pop_front();
                }

                // remove smaller elements from back
                while (!deq.empty() && deq.back().first < nums[r]) {
                    deq.pop_back();
                }

                deq.push_back({nums[r], r});
                r++;

                // push max for current window
                res.push_back(deq.front().first);
            }
        }

        return res;
    }
};