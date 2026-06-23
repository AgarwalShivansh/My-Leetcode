class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int>st;
        int n = arr.size();
        int maxi = 0;
        int pse = 0;
        int nse = 0;
        int element  =0 ;
    
        for(int i =0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
            {
                element = st.top();
                st.pop();
                pse = st.empty() ? -1 : st.top();
                nse = i;
                maxi = max(maxi , (arr[element] * (nse - pse - 1)));
            }
            st.push(i); 
        }
        while(!st.empty())
            {
                element = st.top();
                st.pop();
                nse = n;
                pse = st.empty()?-1:st.top();
                maxi = max(maxi , (arr[element] * (nse - pse - 1)));
            }
        return maxi;
        
    }
};