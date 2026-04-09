class Solution {
public:
    bool isValid(string st) {
       stack<char> s;
       for(char a:st){
        if(a=='{' || a=='(' || a=='['){
            s.push(a);
        }
        else{
            if(s.empty()){return false;}
            char i=s.top();
            if(i=='{' && a!='}'){return false;}
            if(i=='(' && a!=')'){return false;}
            if(i=='[' && a!=']'){return false;}
            s.pop();
        }
    }
    return s.empty();
    }
};