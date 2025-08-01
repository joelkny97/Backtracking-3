// Time Complexity: O(N!)
// Space Complexity: O(N^2)
// Were you able to solve the problem? Yes
// Did you face any challenges while solving the problem? No

class Solution {
public:
    vector<vector<bool>> grid;

    vector<vector<string>> result;

    vector<vector<string>> solveNQueens(int n) {

        // initialize the grid
        grid.resize(n, vector<bool>(n, false));

        backtrack(0, n);

        return result;
        
    }
private:
    void backtrack(int row, int n){
        // base case
        // we have placed all queens and reached the last row
        if(row == n){
            vector<string> temp;
            // get the string output representation
            // where 'Q' represents a queen and '.' represents an empty space
            for (int i = 0; i < n; ++i) {
                string res = "";
                for (int j=0; j<n; ++j) {
                    
                    if (grid[i][j] == true){
                        res.push_back('Q');
                    }
                    else{
                        res.push_back('.');
                    }
                }

                temp.push_back(res);
            }
            result.push_back(temp);

            return;

        }


        // core logic
        // try placing a queen in each column of the current row
        for (int col=0; col<n; col++){
            // check if it is safe to place a queen at (row, col)
            if (isSafe(row, col)){
                // action
                grid[row][col] = true;

                // recurse
                // move to the next row
                backtrack(row+1, n);

                //backtrack
                // remove the queen from (row, col)
                grid[row][col] = false;
            }
        }

    }

    bool isSafe(int row, int col){

        // column check
        // check if there is any queen in the same column above the current row
        for (int i=row;i>=0; i-- ){
            if (grid[i][col] == true){
                return false;
            }
        }
        
        // upper left diagonal
        // check if there is any queen in the upper left diagonal
        int r=row-1;
        int c=col-1;
        while(r>=0 && c>=0) {
            if (grid[r][c]== true){
                return false;
            }
            r--;
            c--;
        }

        // upper right diagonal
        // check if there is any queen in the upper right diagonal
        r=row-1;
        c=col+1;
        while (r>=0 && c<grid.size()){
            if (grid[r][c]== true){
                return false;
            }
            r--;
            c++;
        }
        // if no queens are found in the same column or diagonals, it is safe to place a queen
        return true;
    }
};