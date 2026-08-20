class Solution {
public:

    bool okay(int row , int col , vector<string>temp , int n)
    {
        int duprow = row;
        int dupcol = col;

        while(row>=0 && col >= 0)
        {
            if(temp[row][col] == 'Q') return false;
            row--;
            col--;
        }

        col = dupcol;
        row = duprow;
        while(col>=0)
        {
            if(temp[row][col] == 'Q') return false;
            col--;
        }

        col = dupcol;
        row = duprow;
        while(row<n && col>=0)
        {
            if(temp[row][col] == 'Q') return false;
            row++;
            col--;
        }
        
        return true;
    }

    void func(int n , vector<vector<string>>&ans , vector<string>temp , int col)
    {
        if(col == n)
        {
            ans.push_back(temp);
            return;
        }

        for(int row = 0 ; row<n ; row++)
        {
            if(okay(row,col,temp,n))
            {
                temp[row][col] = 'Q';
                func(n , ans , temp , col+1);
                temp[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>temp(n);
        string s(n,'.');
        for(int i = 0;i<n;i++)
        {
            temp[i] = s;
        }

        func(n,ans,temp,0);
        return ans;
    }
};