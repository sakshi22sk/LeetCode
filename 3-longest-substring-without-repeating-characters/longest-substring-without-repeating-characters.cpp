class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hsh[265];
        if(s==" "){
            return 1;
        }
        int l=0;
        int r=0;
        int n=s.size();
        int maxlen=0;
        for(int i=0;i<256;i++){
            hsh[i]=-1;
        }
        while(r<n){
            if(hsh[s[r]]!=-1){
                l=max(l,hsh[s[r]]+1);
            }
            int len=r-l+1;
            maxlen=max(maxlen,len);
            hsh[s[r]]=r;
            r++;
        }
        return maxlen;
    }
};