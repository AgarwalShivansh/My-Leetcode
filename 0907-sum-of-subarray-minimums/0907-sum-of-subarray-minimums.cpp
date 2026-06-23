class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>pse(n);
        vector<int >nse(n);
        stack<int>st;

        for(int i= 0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            if(st.empty()) 
                pse[i] = -1;
            else
                pse[i] = st.top();
            st.push(i);
        }

        while(!st.empty())
            st.pop();

        for(int i = n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if(st.empty())
                nse[i] = n;
            else
                nse[i] = st.top();
            st.push(i);
        }

        long long  left = 0;
        long long  right = 0;
        long long sum = 0;
        int mod = int(1e9 + 7);
        for(int i =0 ;i<n;i++)
        {
            left = i - pse[i];
            right = nse[i] - i;
            sum = (sum + (left * right*arr[i])) % mod;
        }
        return sum;
    }
};