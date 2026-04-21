class Solution {
public:
    bool ispalindrome(string &s,int a,int b){
        // if at end nothing got mismatched
        if(a>=b){
            return true;
        }
        if(s[a]==s[b]){
            return ispalindrome(s,a+1,b-1);
        }
        else{
            return false;
        }
    }
    string longestPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(ispalindrome(s,i,j)){
                    if(ans.size()<j-i+1){
                        ans="";
                        ans=s.substr(i,j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};