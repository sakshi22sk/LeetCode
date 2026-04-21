class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int k = -1;

        // find break point
        for(int i = 0; i < n-1; i++){
            if(nums[i] > nums[i+1]){
                k = i + 1;  // ✅ correct split point
                break;
            }
        }

        // already sorted
        if(k == -1) return true;

        vector<int> temp = nums; // ✅ work on copy

        // reverse logic to undo rotation
        reverse(temp.begin(), temp.end());
        reverse(temp.begin(), temp.begin() + (n - k));
        reverse(temp.begin() + (n - k), temp.end());

        // check sorted
        return is_sorted(temp.begin(), temp.end());
    }
};