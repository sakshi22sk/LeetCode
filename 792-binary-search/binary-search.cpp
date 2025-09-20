class Solution {
public:
    int bsearch(vector<int>& nums,int s,int e,int target){
        int mid=s+(e-s)/2;
        if(s>e){
            return -1;
        }
        if(nums[mid]==target){
            return mid;
        }
        if(nums[mid]<target){
            return bsearch(nums,mid+1,e,target);
        }
        if(nums[mid]>target){
            return bsearch(nums,s,mid-1,target);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        return bsearch(nums,s,e,target);
    }
};