class Solution {
public:
    int countTriples(int n) {
        int count=0;
        for(int i=1;i<=n;++i){
            int result=i*i;
            int left=1;
            int right=i-1;
            while(left<right){
                int sum=left*left+right*right;
                if(sum==result){
                    count=count+2;
                    left++;
                    right--;
                }
                else if(sum<result){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return count;
    }
};