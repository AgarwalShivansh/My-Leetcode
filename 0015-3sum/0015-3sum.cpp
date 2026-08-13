class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        int n = arr.size();

        for(int i = 0;i<n;i++)
        {
            if(i>0 && arr[i] == arr[i-1]) continue;

            int j = i+1;
            int k = n-1;

            while(j<k)
            {
                long long sum = arr[i] + arr[j] + arr[k];
                if(sum>0)
                {
                    k--;
                }
                else if(sum<0)
                {
                    j++;
                }
                else
                {
                    ans.push_back({arr[i],arr[j],arr[k]});
                    j++;
                    k--;
                    while(j<k && arr[j] == arr[j-1])
                    {
                        j++;
                    }
                }
            }
        }
        return ans;
    }
};