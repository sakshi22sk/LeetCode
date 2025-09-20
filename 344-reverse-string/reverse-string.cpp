class Solution {
public:
    void reverse(vector<char>& s,int si,int n){
        if(si>n){
            return;
        }
        swap(s[si],s[n]);
        reverse(s,si+1,n-1);
    }
    void reverseString(vector<char>& s) {
        int si=0;
        int n=s.size()-1;
        reverse(s,si,n);
    }
};