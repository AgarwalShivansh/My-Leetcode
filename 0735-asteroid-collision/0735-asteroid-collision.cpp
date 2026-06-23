class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int>st;
        vector<int>ans;

        for(int i =0 ;i<arr.size();i++)
        {
            bool destroy = false;

            if(arr[i] > 0)
            {
                st.push(arr[i]);
            }
            else
            {
                if(!st.empty() && st.top() > 0)
                {
                    while(!st.empty() && st.top()>0 && st.top() < abs(arr[i]))
                    {
                        st.pop();
                    }
                    
                    if(!st.empty() && st.top() == abs(arr[i]))
                    {
                        destroy = true;
                        st.pop();
                    }
                    else if(!st.empty() && st.top() > abs(arr[i]))
                    {
                        destroy = true;
                    }
                }
                if(destroy == false && (st.empty()|| st.top() < 0))
                {
                    st.push(arr[i]);
                }
            }
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin() ,ans.end());

        return ans;
    }
};