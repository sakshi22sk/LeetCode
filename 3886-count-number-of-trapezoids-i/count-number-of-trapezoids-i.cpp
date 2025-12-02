// LeetCode 3623 - Count Number of Trapezoids I
// Approach: group points by y -> compute pairs = C(cnt_y, 2) for each y
// Answer = sum over y in increasing order of pairs[y] * prefix_sum(previous pairs)
// Return answer % MOD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<long long, long long> cnt; // y -> count of points on that y
        cnt.reserve(points.size()*2);

        for (auto &p : points) {
            long long y = p[1];
            ++cnt[y];
        }

        // gather pairs = C(cnt_y, 2) for each y
        vector<long long> pairs;
        pairs.reserve(cnt.size());
        for (auto &kv : cnt) {
            long long m = kv.second;
            if (m >= 2) {
                long long ways = (m * (m - 1) / 2) % MOD;
                pairs.push_back(ways);
            }
        }

        // accumulate answer: for each row's pairs, ans += pairs[i] * sum_of_previous_pairs
        long long ans = 0;
        long long prefix = 0;
        for (long long x : pairs) {
            ans = (ans + x * prefix) % MOD;
            prefix = (prefix + x) % MOD;
        }

        return static_cast<int>(ans);
    }
};
