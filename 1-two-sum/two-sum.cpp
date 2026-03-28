class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            int need=target-nums[i];
            if(m.find(need)!=m.end()){
                v.push_back(i);
                v.push_back(m[need]);
                return v;
            }
            m[nums[i]]=i;
        }
        return {-1,-1};
    }
};