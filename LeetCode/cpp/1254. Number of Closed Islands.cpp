class Solution {
public:
    // DFS
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        auto dfs = [&](this auto &&dfs, int i, int j) -> void{
            if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 0) return;
            grid[i][j] = 2;
            for(auto &[dx, dy] : dirs){
                dfs(i + dx, j + dy);
            }
        };

        for(int i = 0; i < m; i++){
            if(grid[i][0] == 0) dfs(i, 0);
            if(grid[i][n - 1] == 0) dfs(i, n - 1);
        }
        for(int i = 1; i < n - 1; i++){
            if(grid[0][i] == 0) dfs(0, i);
            if(grid[m - 1][i] == 0) dfs(m - 1, i);
        }

        int ans = 0;
        for(int i = 1; i < m - 1; i++){
            for(int j = 1; j < n - 1; j++){
                if(grid[i][j] == 0){
                    dfs(i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
    // O(m * n) time, O(m * n) extra-space(recursion has a deepest level of m * n)
};