class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxlen = 0;
        int l = 0;
        int r = 0;
        int maxfreq = 0;
        int changes = 0;
        int hash[26];
        fill(hash ,hash+26 ,0);
        while(r<n)
        {
            hash[s[r] - 'A']++;
            maxfreq = max(maxfreq , hash[s[r]-'A']);
            changes = (r-l+1) - maxfreq;

            if(changes > k)
            {
                hash[s[l] - 'A']--;
                l++;
            }
            else
            {
                maxlen = max(maxlen , (r-l+1));
            }
            r++;
        }
        return maxlen;
    }
};