class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n = arr.size();
        int left = 0;
        int right = 0;
        int len = 0;
        int maxlen = 0;
        int zeroCount = 0;

        while(right < n)
        {
            if(arr[right] == 1)
            {
                right++;
            }
            else if(arr[right] == 0 && zeroCount <= k)
            {
                right++;
                zeroCount++;
            }

            while(zeroCount > k)
            {
                if(arr[left] == 0)
                    zeroCount--;
                
                left++;
            }
            
            maxlen = max(maxlen , right - left);

        }
        return maxlen;
    }
};