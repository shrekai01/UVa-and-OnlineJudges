class Solution {
    static constexpr int DIRS[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    // DFS
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        auto dfs = [&](this auto &&dfs, int i, int j) -> int{
            if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return 0;
            int ret = grid[i][j];
            grid[i][j] = 0;
            for(auto &[dx, dy] : DIRS){
                ret += dfs(i + dx, j + dy);
            }
            return ret;
        };

        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) continue;
                ans = max(ans, dfs(i, j));
            }
        }
        return ans;
    }
    // O(m * n) time, O(m * n) extra-space(recursion at most m * n times)
};