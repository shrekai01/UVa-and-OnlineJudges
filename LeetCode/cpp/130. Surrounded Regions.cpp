class Solution {
public:
    // DFS
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        auto dfs = [&](this auto &&dfs, int i, int j) -> void{
            if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') return;
            board[i][j] = 'N';
            for(auto &[dx, dy] : dirs){
                dfs(i + dx, j + dy);
            }
        };
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O') dfs(i, 0);
            if(board[i][n - 1] == 'O') dfs(i, n - 1);
        }
        for(int i = 1; i < n - 1; i++){
            if(board[0][i] == 'O') dfs(0, i);
            if(board[m - 1][i] == 'O') dfs(m - 1, i);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'N') board[i][j] = 'O';
            }
        }
    }
    // O(m * n) time, O(m * n) extra-space(recursion has a deepest level of m * n)
};