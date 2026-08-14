class Solution {
public:
    // DFS
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        function<int(int, int)> dfs = [&](int i, int j) -> int{
            if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return 1;
            if(grid[i][j] == 2) return 0;
            grid[i][j] = 2;
            int ret = 0;
            for(auto &[dx, dy] : dirs){
                ret += dfs(i + dx, j + dy);
            }
            return ret;
        };
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    ans += dfs(i, j);
                    break;
                }
            }
        }
        return ans;
    }
    // O(m * n) time, O(m * n) extra-space(recursion at most m * n times)
};