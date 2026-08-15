class Solution {
public:
    // DFS
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        if(grid[row][col] == color) return grid;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));
        vector<pair<int, int>> borders;
        
        function<void(int, int, const int)> dfs = [&](int i, int j, const int orig) -> void{
            bool is_border = false;
            for(auto &[dx, dy] : dirs){
                int new_x = i + dx, new_y = j + dy;
                if(new_x < 0 || new_x >= m || new_y < 0 || new_y >= n || grid[new_x][new_y] != orig){
                    is_border = true;
                }
                else if(!vis[new_x][new_y]){
                    vis[new_x][new_y] = true;
                    dfs(new_x, new_y, orig);
                }
            }
            if(is_border){
                borders.emplace_back(i, j);
            }
        };

        dfs(row, col, grid[row][col]);
        for(auto &[x, y] : borders){
            grid[x][y] = color;
        }
        return grid;
    }
    // O(m * n) time, O(m * n) extra-space(recursion has a deepest level of m * n)
};