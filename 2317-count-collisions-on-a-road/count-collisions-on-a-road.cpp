class Solution {
public:
    int countCollisions(string directions) {
        int l=0;
        int c=0;
        int n=directions.size();
        if(n==1 && directions[0]=='R' || n==1 && directions[0]=='L'){
            c=0;
            return c;
        }
        int r=directions.size()-1;
        while(l<n && directions[l]=='L'){
            l++;
        }
        while(r>0 && directions[r]=='R'){
            r--;
        }
        for(int i=l;i<=r;i++){
            if(directions[i]!='S'){
                c++;
            }
        }
        return c;
    }
};