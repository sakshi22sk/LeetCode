class Solution {
public:
    void reverse_recu(vector<char>&s,int st,int e){
        if(st>e){
            return ;
        }
        swap(s[st],s[e]);
        st++;
        e--;
        return reverse_recu(s,st,e);
    }
    void reverseString(vector<char>& s) {
        reverse_recu(s,0,size(s)-1);
    }
};