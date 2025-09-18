
class Solution {
  public:
    int firstUniqChar(string &s) {
        //  code here
        unordered_map<char,int> v;
        for(char i:s){
            v[i]++;
        }
        //kyunki map order me nhi kr rha store , to hume string ke according dekhna 
        for(int i=0;i<s.length();i++){
            if(v[s[i]]==1){ //this line
                return i;
            }
        }
        return -1;
    }
};