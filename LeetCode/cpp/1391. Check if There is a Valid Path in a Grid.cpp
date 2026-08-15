class Solution {
public:
    // DFS
    static constexpr int dirs[7][2][2] = {  {{0, 0}, {0, 0}},
                                            {{0, -1}, {0, 1}},
                                            {{-1, 0}, {1, 0}},
                                            {{0, -1}, {1, 0}},
                                            {{0, 1}, {1, 0}},
                                            {{-1, 0}, {0, -1}},
                                            {{-1, 0}, {0, 1}}};

    bool hasDirection(const int street, const int dx, const int dy){
        auto &d = dirs[street];
        return  d[0][0] == dx && d[0][1] == dy || 
                d[1][0] == dx && d[1][1] == dy;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        auto dfs = [&](this auto &&dfs, int i, int j) -> bool{
            if(i == m - 1 && j == n - 1) return true;
            int k = grid[i][j];
            grid[i][j] = 7;
            for(auto &[dx, dy] : dirs[k]){
                int new_x = i + dx, new_y = j + dy;
                if(new_x < 0 || new_x >= m || new_y < 0 || new_y >= n || grid[new_x][new_y] == 7 || !hasDirection(grid[new_x][new_y], -dx, -dy)) continue;
                if(dfs(new_x, new_y)) return true;
            }
            return false;
        };
        return dfs(0, 0);
    }
    // O(m * n) time, O(m * n) extra-space(recursion has a deepest level of m * n)
};