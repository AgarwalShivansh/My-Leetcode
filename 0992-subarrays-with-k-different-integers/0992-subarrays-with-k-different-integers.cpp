class Solution {
public:
    int func(vector<int> &nums , int n , int k)
    {
        int l = 0;
        int r = 0;
        int count = 0;
        map<int,int>mpp;

        while(r<n)
        {
            mpp[nums[r]]++;
            while(mpp.size() > k)
            {
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0)
                    mpp.erase(nums[l]);
                l++;
            }
            count = count + (r-l+1);
            r++;
        }
        return count;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int first = func(nums ,n , k);
        int second = func(nums, n , k-1);
        return first - second;
    }
};