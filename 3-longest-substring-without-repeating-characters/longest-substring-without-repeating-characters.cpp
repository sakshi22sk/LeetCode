class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s==""){return 0;}
        unordered_map<char,int> m;
        int l=0;int r=0;
        int ans=0;
        int n=s.size()-1;
        while(r<=n){
            if(m.find(s[r])!=m.end()){
                l=max(l,m[s[r]]+1);
            }
            m[s[r]]=r;
            int len=r-l+1;
            ans=max(len,ans);
            r++;
            
        }
        return ans;
    }
};