class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> answer;
        for(int i=nums.size()-1;i>=0;i--){
            int temp=nums[i];
            while(temp>0){
                int rem=temp%10;
                answer.push_back(rem);
                temp=temp/10;
            }
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};