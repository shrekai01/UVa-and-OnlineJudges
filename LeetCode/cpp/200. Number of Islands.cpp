class Solution {
public:
    // DFS
    vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<char>> &grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') return;
        grid[i][j] = '2';
        for(auto &d : dir){
            dfs(grid, i + d[0], j + d[1]);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != '1') continue;
                dfs(grid, i, j);
                ans++;
            }
        }
        return ans;
    }
    // O(m * n) time, O(m * n) extra-space(recursion at most m * n times)
};