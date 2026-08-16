class Solution {
public:
    // DFS
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));
        auto dfs = [&](this auto &&dfs, int last_i, int last_j, int i, int j) -> bool{
            if(vis[i][j]) return true;
            vis[i][j] = true;
            for(auto &[dx, dy] : dirs){
                int x = i + dx, y = j + dy;
                if(x < 0 || x >= m || y < 0 || y >= n || (x == last_i && y == last_j) || grid[x][y] != grid[i][j]) continue;
                if(dfs(i, j, x, y)) return true;
            }
            return false;
        };
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(vis[i][j]) continue;
                if(dfs(-1, -1, i, j)) return true;
            }
        }
        return false;
    }
    // O(m * n) time, O(m * n) extra-space(recursion has a deepest level of m * n)
};