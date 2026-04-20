class Solution {
public:
    int binarys(vector<int>& nums, int target,int i1,int i2){
         int s=i1;
        int n=nums.size();
        int e=i2;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }  
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
       
       int part=-1;
       for(int i=0;i<nums.size()-1;i++){
        if(nums[i]>nums[i+1]){
            part=i;
            break;
        }
       }
        int ans1=-1;
        ans1=binarys(nums,target,0,part);
      
        int ans2=-1;
        ans2=binarys(nums,target,part+1,nums.size()-1);
        return max(ans1,ans2);
    }
};