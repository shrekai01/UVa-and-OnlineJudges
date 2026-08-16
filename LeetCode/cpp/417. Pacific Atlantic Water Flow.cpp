class Solution {
public:
    // DFS
    // from the border
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> result;
        auto dfs = [&](this auto &&dfs, int i, int j, vector<vector<bool>> &vis) -> void{
            if(vis[i][j]) return;
            vis[i][j] = true;
            for(auto &[dx, dy] : dirs){
                int x = i + dx, y = j + dy;
                if(x >= 0 && x < m && y >= 0 && y < n && heights[x][y] >= heights[i][j]){
                    dfs(x, y, vis);
                }
            }
        };

        vector<vector<bool>> pac_vis(m, vector<bool>(n));
        vector<vector<bool>> atl_vis(m, vector<bool>(n));
        for(int i = 0; i < m; i++){
            dfs(i, 0, pac_vis);
            dfs(i, n - 1, atl_vis);
        }
        for(int i = 1; i < n; i++){
            dfs(0, i, pac_vis);
            dfs(m - 1, i - 1, atl_vis);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pac_vis[i][j] && atl_vis[i][j]) result.push_back({i, j});
            }
        }
        return result;
    }
    // O(m * n) time, O(m * n) extra-space(recursion has a deepest level of m * n)
};