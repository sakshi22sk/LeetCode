
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int prev = 0;  // length of the previous increasing run
        int cur = 0;   // length of the current increasing run
        
        for (int i = 0; i < n; ++i) {
            ++cur;
            // boundary when end of array, or next element is not strictly greater
            if (i == n - 1 || nums[i] >= nums[i + 1]) {
                // consider splitting current run, or using prev + current
                ans = max(ans, cur / 2);
                ans = max(ans, min(prev, cur));
                
                // move current run to prev, reset cur
                prev = cur;
                cur = 0;
            }
        }
        
        return ans;
    }
};