class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            // if element is smaller in dequeue but next max is coming from same window 
            while(!q.empty() && nums[q.back()]<=nums[i]){
                q.pop_back();
            }
            if(!q.empty() && q.front()==i-k){
                q.pop_front();
            }
            q.push_back(i);
            if(i>=k-1){
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};