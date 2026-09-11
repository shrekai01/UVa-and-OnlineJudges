class Solution {
public:
    // two pointers
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int l = x;
        int r = x + k - 1;
        while(l < r){
            for(int j = y; j < y + k; j++){
                swap(grid[l][j], grid[r][j]);
            }
            l++, r--;
        }
        return grid;
    }
    // O(k^2) time, O(1) extra-space
};