class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string need=word;
        int ans=0;
        while(sequence.find(need)!=string::npos){
            ans++;
            need=need+word;
        }
        return ans;
    }
};