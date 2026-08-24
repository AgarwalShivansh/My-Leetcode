class Solution {
public:

    bool palindrome(string s , int start  , int end)
    {
        while(start <= end){
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }

    void func(string s , vector<vector<string>>& ans , vector<string>temp , int ind)
    {
        if(ind == s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = ind ; i< s.size() ; i++){ // ind is starting index
            if(palindrome(s , ind , i)){
                temp.push_back(s.substr(ind , i-ind + 1));
                func(s , ans , temp , i + 1);
                temp.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        func(s , ans , temp , 0);
        return ans;
    }
};