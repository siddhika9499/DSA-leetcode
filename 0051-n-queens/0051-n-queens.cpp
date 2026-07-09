class Solution {
public:

    vector<vector<string>> ans;

    void solve(int row, int n, vector<string>& board,
               vector<int>& cols,
               vector<int>& leftDiag,
               vector<int>& rightDiag)
    {
        // all queens placed
        if(row == n)
        {
            ans.push_back(board);
            return;
        }


        for(int col = 0; col < n; col++)
        {
            // check if position is safe
            if(cols[col] || 
               leftDiag[row-col+n-1] || 
               rightDiag[row+col])
            {
                continue;
            }


            // place queen
            board[row][col] = 'Q';

            cols[col] = 1;
            leftDiag[row-col+n-1] = 1;
            rightDiag[row+col] = 1;


            // move to next row
            solve(row+1,n,board,
                  cols,leftDiag,rightDiag);


            // backtrack
            board[row][col] = '.';

            cols[col] = 0;
            leftDiag[row-col+n-1] = 0;
            rightDiag[row+col] = 0;
        }
    }


    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n,string(n,'.'));


        vector<int> cols(n,0);

        // possible values of row-col:
        // -(n-1) to +(n-1)
        vector<int> leftDiag(2*n-1,0);

        // row+col ranges from 0 to 2n-2
        vector<int> rightDiag(2*n-1,0);


        solve(0,n,board,
              cols,leftDiag,rightDiag);


        return ans;
    }
};