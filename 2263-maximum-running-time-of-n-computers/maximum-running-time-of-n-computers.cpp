// C++17
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for (int b : batteries) sum += b;
        // Upper bound for runtime cannot exceed total energy / n
        long long lo = 0, hi = sum / n;
        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2; // upper mid
            // check if we can run n computers for `mid` time
            long long required = (long long)n * mid;
            long long available = 0;
            for (int b : batteries) {
                // each battery can contribute at most mid
                available += min((long long)b, mid);
                if (available >= required) break; // early exit
            }
            if (available >= required) lo = mid; // feasible
            else hi = mid - 1;                   // not feasible
        }
        return lo;
    }
};
