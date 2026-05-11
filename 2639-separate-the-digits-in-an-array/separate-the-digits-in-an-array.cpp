class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> answer;
        for(int i=0;i<nums.size();i++){
            string temp = to_string(nums[i]);
            int n=temp.size()-1;
            int j=0;
            while(j<=n){
                answer.push_back(temp[j] - '0');
                j++;
            }
        }
        return answer;
    }
};