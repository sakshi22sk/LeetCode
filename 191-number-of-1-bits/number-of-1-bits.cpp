class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        while(n>0){
            //check the last digit is 1 or 0 ->if 1 count++
            //eg 1001 & 0001 gives 1  
           if(n&1){
            count++;
           }
            // make the rightmost bit vanish 
            n=n>>1;
        }
        return count;
    }
};