class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=0;
        int l=0;
        int r=0;int n=s.size();
        int hash[256];
        int maxlen=0;
            for(int i = 0; i < 256; i++) hash[i] = -1;
        while(r<n){
            if(hash[s[r]]>=l){
                l=hash[s[r]]+1;
            }
            hash[s[r]]=r;
            len=r-l+1;
            maxlen=max(len,maxlen);
            r++;
        }
        return maxlen;
    }
};