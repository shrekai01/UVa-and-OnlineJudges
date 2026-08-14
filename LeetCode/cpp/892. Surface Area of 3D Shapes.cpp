class Solution {
public:
    // math, geometry
    int surfaceArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int k = 1; k <= grid[i][j]; k++){
                    if(k == 1) ans++;
                    if(k == grid[i][j]) ans++;
                    if(i == 0 || grid[i - 1][j] < k) ans++;
                    if(i == m - 1 || grid[i + 1][j] < k) ans++;
                    if(j == 0 || grid[i][j - 1] < k) ans++;
                    if(j == n - 1 || grid[i][j + 1] < k) ans++;
                }
            }
        }
        return ans;
    }
    // O(m * n) time, O(1) extra-space
};