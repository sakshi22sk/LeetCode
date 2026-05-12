class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s==" "){
            return 1;
        }
        int m[265];
        int l=0;
        int r=0;
        int n=s.size();
        int len=0;
        for(int i=0;i<256;i++){
            m[i]=-1;
        }
        while(r<n){
            if(m[s[r]]!=-1){
                l=max(l,m[s[r]]+1);
            }
            m[s[r]]=r;
            int o=abs(r-l+1);
            len=max(len,o);
            
            r++;
            
        }
        return len;
    }
};