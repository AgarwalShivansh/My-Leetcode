class Solution {
private:
    void findSubsets(int ind, vector<int>& nums,
                     vector<int>& ds,
                     vector<vector<int>>& ans)
    {
        // Every current subset is a valid answer
        ans.push_back(ds);

        for(int i = ind; i < nums.size(); i++)
        {
            // Skip duplicate elements at the same recursion level
            if(i != ind && nums[i] == nums[i - 1])
                continue;

            // Pick
            ds.push_back(nums[i]);

            // Move to next index because each element is used once
            findSubsets(i + 1, nums, ds, ans);

            // Backtrack
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;

        // Required for duplicate handling
        sort(nums.begin(), nums.end());

        findSubsets(0, nums, ds, ans);

        return ans;
    }
};