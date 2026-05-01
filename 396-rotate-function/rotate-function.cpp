class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long sum = 0, F = 0;

        // initial computation
        for(int i = 0; i < n; i++){
            sum += nums[i];
            F += i * nums[i];
        }

        long maxi = F;

        // compute next values in O(1)
        for(int k = 1; k < n; k++){
            F = F + sum - n * nums[n - k];
            maxi = max(maxi, F);
        }

        return maxi;
    }
};