class Solution {
public:
    // DFS
    // let grid[x][y] = 0(water), 1(land that is not visited), 2(land that is visited)
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int>(col, 0));

        auto can_reach_top = [&](this auto &&can_reach_top, int i, int j) -> bool{
            if(i == 0) return true;
            for(auto &[dx, dy] : dirs){
                int x = i + dx, y = j + dy;
                if(x >= 0 && x < row && y >= 0 && y < col && grid[x][y] == 2){
                    return true;
                }
            }
            return false;
        };
        
        auto can_reach_bot = [&](this auto &&can_reach_bot, int i, int j) -> bool{
            if(i == row - 1) return true;
            grid[i][j] = 2; // indicates visited
            for(auto &[dx, dy] : dirs){
                int x = i + dx, y = j + dy;
                if(x >= 0 && x < row && y >= 0 && y < col && grid[x][y] == 1){
                    if(can_reach_bot(x, y)) return true;
                }
            }
            return false;
        };

        for(int day = cells.size() - 1; day >= 0; day--){
            int i = cells[day][0] - 1, j = cells[day][1] - 1;
            grid[i][j] = 1;
            if(can_reach_top(i, j) && can_reach_bot(i, j)){ // we only do dfs to update the elements to be visited if it can reach top
                return day;
            }
        }
        return 0;
    }
    // O(row * col) time, O(row * col) extra-space
};