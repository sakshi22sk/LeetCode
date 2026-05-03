class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()){
            return false;
        }
        string ans=s+s;

        if(ans.contains(goal)){
            return true;
        }
        return false;

    }
};