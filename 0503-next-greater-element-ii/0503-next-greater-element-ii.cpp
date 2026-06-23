class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        stack<int>st;
        for(int i = (2*n)-1; i>=0 ; i--)
        {
            if(i>=n)
            {
                if(!st.empty() && st.top()<=nums[i%n])
                {
                    st.pop();
                    st.push(nums[i%n]);
                }
                else if(st.empty())
                    st.push(nums[i%n]);
                else
                    st.push(nums[i%n]);
            }
            else
            {
                while(!st.empty() && st.top()<=nums[i])
                    st.pop();
                if(st.empty())
                    ans.push_back(-1);
                else
                    ans.push_back(st.top());
                st.push(nums[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};