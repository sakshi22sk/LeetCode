class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // Sort by end asc, and start desc
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });

        int a = -1, b = -1, ans = 0;

        for (auto &v : intervals) {
            int l = v[0], r = v[1];

            // Case 1: both a and b are inside interval
            if (l <= a && b <= r) continue;

            // Need at least one point
            if (l > b) {
                // Need 2 new points
                a = r - 1;
                b = r;
                ans += 2;
            }
            else {
                // Need 1 new point
                a = b;
                b = r;
                ans += 1;
            }
        }

        return ans;
    }
};
