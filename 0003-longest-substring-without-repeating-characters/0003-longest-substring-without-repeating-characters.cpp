class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int n =s.size();
         int l =0;
         int r =0;
         int maxlen = 0;
         int hash[256];
         fill(hash, hash + 256, -1);
         while(r<n)
         {
            if(hash[s[r]] != -1)
            {
                if(hash[s[r]] >= l)
                {
                    l = hash[s[r]] + 1;
                }
            }
            maxlen = max(maxlen , r-l+1);
            hash[s[r]] = r;
            r++;
         }
         return maxlen;
    }
};