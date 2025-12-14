class Solution {
public:
    int numberOfWays(string corridor) {
        int n=count(corridor.begin(),corridor.end(),'S');
        long long ans=1;
        int o=1e9+7;
        if(n%2!=0 || n==0){
            return 0;
        }
        else{
            int s=0;
            int p=0;
            for(int i=0;i<corridor.length();i++){
                    if(corridor[i]=='S'){
                        s++;
                    
                    if(s==3){
                        ans=(ans*(p+1))%o;
                        s=1;
                        p=0;
                    }
            }
                    else if(s==2){
                        p++;
                    }
                }
            }
            return ans;
    }
};