typedef long long ll;

class Solution {
public:
    // DFS
    static constexpr int DIRS[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        auto dfs = [&](this auto &&dfs, int i, int j) -> ll{
            if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return 0;
            ll ret = grid[i][j];
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
                ll sum = dfs(i, j);
                if(sum % k == 0) ans++;
            }
        }
        return ans;
    }
    // O(m * n) time, O(m * n) extra-space(recursion at most m * n times)
};