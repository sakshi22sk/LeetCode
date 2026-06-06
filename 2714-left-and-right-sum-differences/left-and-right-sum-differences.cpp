class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        vector<int> numsleft(n, 0);
        vector<int> numsright(n, 0);

        int sum = 0;
        for (int i = 1; i < n; i++) {
            sum += nums[i - 1];
            numsleft[i] = sum;
        }

        int sum1 = 0;
        for (int i = n - 2; i >= 0; i--) {
            sum1 += nums[i + 1];
            numsright[i] = sum1;
        }

        vector<int> answer(n, 0);

        for (int i = 0; i < n; i++) {
            answer[i] = abs(numsleft[i] - numsright[i]);
        }

        return answer;
    }
};