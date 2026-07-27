class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr){
        stack<int>st;
        int n = arr.size();

        for(int i= 0;i<n;i++)
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
                    while(!st.empty() && abs(arr[i]) > st.top() && st.top() > 0 )
                    {
                        st.pop();
                    }
                    if(!st.empty() && abs(arr[i]) == st.top())
                    {
                        st.pop();
                        destroy = true;
                    }
                    else if(!st.empty() && abs(arr[i]) < st.top())
                    {
                        destroy = true;
                    }   
                }

                if(st.empty() && destroy == false)
                    st.push(arr[i]);
                else if(!st.empty() && destroy == false && st.top()<0)
                    st.push(arr[i]);
            }
        }

        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin() ,ans.end());
        return ans;
    }
};