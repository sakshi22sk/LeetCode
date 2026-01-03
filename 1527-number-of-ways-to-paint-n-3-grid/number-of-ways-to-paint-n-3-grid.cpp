class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
        long long aba = 6, abc = 6;
        
        for (int i = 2; i <= n; i++) {
            long long naba = (aba * 3 + abc * 2) % MOD;
            long long nabc = (aba * 2 + abc * 2) % MOD;
            aba = naba;
            abc = nabc;
        }
        return (aba + abc) % MOD;
    }
};
