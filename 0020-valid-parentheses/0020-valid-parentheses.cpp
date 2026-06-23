class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n = s.size();

        int i =0;
        while(i<n)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[' ){
                st.push(s[i]);
                i++;
            }
            else{

                if(st.size() == 0) return false ;
 
                char c = st.top();
                if((c == '(' && s[i] == ')') || 
                   (c == '{' && s[i] == '}') || 
                   (c == '[' && s[i] == ']'))
                {
                    st.pop();
                }
                else
                {
                    break;
                }
                i++;
            }
        }
        if(st.size() == 0)
        return true;
        else
        return false;
    }
};