class Solution {
public:
    string removeKdigits(string arr, int k) {
        
        if(arr.size() == k) 
        return "0";

        stack<char>st;
        string ans = "";

        for(int i =0 ; i<arr.size() ; i++)
        {
            while(!st.empty() && k>0 && st.top()>arr[i])
            {
                st.pop();
                k--;
            }
            st.push(arr[i]);
        }

        while(k!=0)
        {
            st.pop();
            k--;
        }

        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        int count = 0;
        while(count < arr.size() && ans[count] == '0')
        {
            count++;
        }

        string result = ans.substr(count);
        return (result == "")?"0" : result;
    }
};