class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        if(s.size()!=goal.size()){
            return false;
        }
        for(int i=1;i<=n;i++){
            string c=goal;
            reverse(c.begin(),c.end());
            reverse(c.begin(),c.begin()+i);
            reverse(c.begin()+i,c.end());
            if(s==c){
                return true;
            }
        }
        return false;
    }
};