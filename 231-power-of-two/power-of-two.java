class Solution {
    public boolean syill(int n,int i){
        if(Math.pow(2,i)>n){
            return false;
        }
        if(n==Math.pow(2,i)){
            return true;
        }
        return syill(n,i+1);
        
    }
    public boolean isPowerOfTwo(int n) {
        int i=0;
       return syill(n,i);
    }
}