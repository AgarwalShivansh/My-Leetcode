class Solution {
public:

    bool possible(int row , int column , char value , vector<vector<char>> &board)
    {
        for(int it = 0 ; it < 9 ; it++)
        {
            if(board[row][it] == value)
                return false;
            if(board[it][column] == value)
                return false;
            if(board[3 * (row/3) + (it / 3)][3 * (column/3) + (it % 3)] == value)
                return false;
        }
        return true;
    }

   bool func(vector<vector<char>> &board )
    {
        for(int i = 0;i<board.size() ; i++)
        {
            for(int j = 0 ; j < board[0].size() ; j++)
            {
                if (board[i][j] == '.')
                {
                    for(char k = '1' ; k <= '9' ; k++)
                    {
                        if(possible(i , j , k , board))
                        {
                            board[i][j] = k;
                        
                            if(func(board))
                                return true;
                            else 
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        func(board);
    }
};