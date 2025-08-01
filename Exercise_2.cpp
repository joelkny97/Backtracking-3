// Time Complexity: O(m*n * 4^L) L is the length of the word
// Space Complexity: O(N) N is recursion stack space
// Were you able to solve the problem? Yes
// Did you face any challenges while solving the problem? No

class Solution {
public:
    int m, n;
    vector<pair<int,int>> directions;

    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || word.size() == 0){
            return false;
        }
        m = board.size();
        n = board[0].size();

        // if the word is longer than the number of cells in the board, it cannot exist
        if (word.size() > m * n) return false;    

        directions = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // U D L R

        // iterate through each cell in the board
        // and start backtracking from each cell
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (backtrack(board, i, j, 0, word)){
                    return true ;
                }
            }
        }
        return false;
        
    }

private:
    bool backtrack(vector<vector<char>>& board, int i, int j, int index, string& s){

        // base case
        // if index is equal to the size of the word,
        // it means we have matched all characters in the word
        // we have found the word
        if (index == s.size() ){
            return true;
        }
        // if we are out of bounds or the character does not match
        if (i < 0 || j < 0 || i == m || j == n || board[i][j] != s[index]){
            return false;
        }

        // core logic
        // action
        char temp = board[i][j]; // store char 
        board[i][j] = '#'; // mark as visited

        // recurse
        for(const auto &d: directions){
            int nr = i + d.first;
            int nc = j + d.second;
            // check all four directions (up, down, left, right)
            if (backtrack(board, nr, nc, index+1, s)){
                return true;
            }
        }
        // backtrack
        // restore the character
        board[i][j] = temp;
        
        // if no direction leads to a solution, return false
        return false;
    }
};