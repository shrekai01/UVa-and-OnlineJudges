class Solution {
public:
    // DFS
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        auto dfs = [&](this auto &&dfs, bool &can_walk_off, int i, int j) -> int{
            if(i < 0 || i >= m || j < 0 || j >= n){
                can_walk_off = true;
                return 0;
            }
            if(grid[i][j] != 1) return 0;
            grid[i][j] = 2;
            int ret = 1;
            for(auto &[dx, dy] : dirs){
                ret += dfs(can_walk_off, i + dx, j + dy);
            }
            return ret;
        };
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 1) continue;
                bool can_walk_off = false;
                int sum = dfs(can_walk_off, i, j);
                if(!can_walk_off) ans += sum;
            }
        }
        return ans;
    }
    // O(m * n) time, O(m * n) extra-space(recursion has a deepest level of m * n)
    // we can also dfs the boundary cells with a value of 1 and finally calculate the number of inner cells with a value of 1 as answer
};