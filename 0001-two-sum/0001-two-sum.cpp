class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        map<int,int>mpp;
        int n = arr.size();

        int diff = 0;
        for(int i =0;i<n;i++)
        {
            diff = target - arr[i];
            if(mpp.find(diff) != mpp.end())
            {
                return {mpp[diff] , i};
            }
            mpp[arr[i]] = i;
        }
        return {-1,-1};
    }
};