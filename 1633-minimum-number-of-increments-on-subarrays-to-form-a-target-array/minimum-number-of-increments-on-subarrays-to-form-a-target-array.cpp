#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minNumberOperations(vector<int>& target) {
        long long ans = 0;
        int prev = 0;
        for (int x : target) {
            if (x > prev) ans += (long long)(x - prev);
            prev = x;
        }
        return ans;
    }
};
