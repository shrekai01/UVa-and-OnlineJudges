class Solution {
public:
    // DFS
    // dfs every island and assign points of each island a unique number, maintain an array that stores sizes of islands
    // traverse every point with a value of 0 and check if it connects islands or not
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> islands_sizes;
        auto dfs = [&](this auto &&dfs, int i, int j) -> int{
            grid[i][j] = islands_sizes.size() + 2;
            int ret = 1;
            for(auto &[dx, dy] : dirs){
                int x = i + dx, y = j + dy;
                if(x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1){
                    ret += dfs(x, y);
                }
            }
            return ret;
        };
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){  
                    islands_sizes.emplace_back(dfs(i, j));
                }
            }
        }

        if(islands_sizes.empty()){ // no islands
            return 1;
        }

        int ans = 0;
        unordered_set<int> ust;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]) continue;
                ust.clear();
                int area = 1;
                for(auto &[dx, dy] : dirs){
                    int x = i + dx, y = j + dy;
                    if(x >= 0 && x < n && y >= 0 && y < n && grid[x][y] && ust.insert(grid[x][y]).second){
                        area += islands_sizes[grid[x][y] - 2];
                    }
                }
                ans = max(ans, area);
            }
        }
        return ans ? ans : n * n; // check if no 0s
    }
    // O(n^2) time, O(n^2) extra-space(recursion has a deepest level of n^2)
};