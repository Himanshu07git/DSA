class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int balance=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                if(balance>0)
                  ans= ans+s[i];
                balance++;
            }
            else{
                if(balance>1)
                   ans=ans+s[i];
                balance--;
            }   
        }
        return ans;;
    }
};