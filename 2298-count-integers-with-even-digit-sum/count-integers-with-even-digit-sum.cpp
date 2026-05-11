class Solution {
public:
    int countEven(int num) {
        int count=0;
        for(int i=1;i<=num;i++){
            int sum=0;
            int numi=i;
            while(numi>0){
                int rem=numi%10;
                sum=sum+rem;
                numi=numi/10;
            }
            if(sum%2==0){
                count++;
            }
        }
        return count;
    }
};