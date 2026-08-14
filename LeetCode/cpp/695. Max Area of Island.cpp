class Solution {
public:
    // DFS
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int m = grid.size(), n = grid[0].size();
        auto dfs = [&](this auto &&dfs, int i, int j) -> int{
            if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) return 0;
            grid[i][j] = 2;
            int ret = 1;
            for(auto &d : dir){
                ret += dfs(i + d[0], j + d[1]);
            }
            return ret;
        };
        int mx = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 1) continue;
                mx = max(mx, dfs(i, j));
            }
        }
        return mx;
    }
    // O(m * n) time, O(m * n) extra-space(recursion at most m * n times)
};