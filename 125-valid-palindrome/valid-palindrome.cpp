class Solution {
public:
    bool recur_pal(string &s,int st,int e){
        while(st<e && !isalnum(s[st])){
            st++;
        }
        while(st<e && !isalnum(s[e])){
            e--;
        }
         if(st>=e){
            return true;
        }
        if(tolower(s[st])!=tolower(s[e]) && isalnum(s[st]) && isalnum(s[e])){
             return false;
        }
        
        return recur_pal(s,st+1,e-1);
    }
    bool isPalindrome(string s) {
       return recur_pal(s,0,s.length()-1);
    }
};