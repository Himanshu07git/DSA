class Solution {
public:
    int minAddToMakeValid(string s) {
        // stack<int> st;
        // int len=0;

        // for(int i=0; i<s.size(); i++){
        //     if(s[i]=='('){
        //         st.push(s[i]);
        //     }
        //     else{
        //         if(!st.empty())
        //           st.pop();

        //         else
        //           len++;
        //     }
        // }
        // return len+st.size();


        int open=0;
        int len=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(')
              open++;
            else{
                if(open>0)
                  open--;
                else
                  len++;
            }   
        }
        return len+open;
    }
};