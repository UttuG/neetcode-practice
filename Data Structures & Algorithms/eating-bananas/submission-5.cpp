class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int k = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            long long total_h = 0;
            for (int i : piles) {
                total_h += (i + mid - 1) / mid;
            }

            if (total_h <= h) {
                k = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return k;
    }
};