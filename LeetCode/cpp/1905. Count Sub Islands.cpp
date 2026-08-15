class Solution {
public:
    // DFS
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        auto dfs = [&](this auto &&dfs, bool &is_sub, int i, int j) -> void{
            if(i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] != 1) return;
            if(grid1[i][j] != 1) is_sub = false;
            grid2[i][j] = 0;
            for(auto &[dx, dy] : dirs){
                dfs(is_sub, i + dx, j + dy);
            }
        };

        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid2[i][j] == 1){
                    bool is_sub = true;
                    dfs(is_sub, i, j);
                    ans += is_sub;
                }
            }
        }
        return ans;
    }
    // O(m * n) time, O(m * n) extra-space(recursion has a deepest level of m * n)
};