class Solution {
public:
    int differenceOfSums(int n, int m) {
        int um1=0;
        int um2=0;
        for(int i=1;i<=n;i++){
            if(i%m==0){
                um2=um2+i;
            }
            else{
                um1=um1+i;
            }
        }
        return um1-um2;
    }
};