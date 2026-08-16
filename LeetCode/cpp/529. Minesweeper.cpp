class Solution {
public:
    static constexpr int dirs[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1},
                                        {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size();

        auto dfs = [&](this auto &&dfs, int i, int j) -> void{
            if(board[i][j] == 'M'){
                board[i][j] = 'X';
                return;
            }
            if(board[i][j] != 'E') return;
            
            int near_mines = 0;
            for(auto &[dx, dy] : dirs){
                int x = i + dx, y = j + dy;
                if(x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'M'){
                    near_mines++;
                }
            }
            if(near_mines){
                board[i][j] = near_mines + '0';
                return;
            }
            board[i][j] = 'B';
            for(auto &[dx, dy] : dirs){
                int x = i + dx, y = j + dy;
                if(x >= 0 && x < m && y >= 0 && y < n){
                    dfs(x, y);
                }
            }
        };
        dfs(click[0], click[1]);
        return board;
    }
    // O(m * n) time, O(m * n) extra-space(recursion has a deepest level of m * n)
};