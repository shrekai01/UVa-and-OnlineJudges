class Solution {
public:
    // DFS
    static constexpr int dirs[3][2] = {{-1, 1}, {0, 1}, {1, 1}};
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        auto dfs = [&](this auto &&dfs, int i, int j) -> int{
            int mx = 0;
            for(auto &[dx, dy] : dirs){
                int new_x = i + dx, new_y = j + dy;
                if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && grid[new_x][new_y] > grid[i][j]){
                    mx = max(mx, 1 + dfs(new_x, new_y));
                }
            }
            grid[i][j] = 0;
            return mx;
        };
        
        int ans = 0;
        for(int i = 0; i < m; i++){
            ans = max(ans, dfs(i, 0));
        }
        return ans;
    }
    // O(m * n) time, O(n) extra-space(recursion has a deepest level of n)
};