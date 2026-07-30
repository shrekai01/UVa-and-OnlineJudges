class Solution {
public:
    // DFS, Memorization
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int MOD = 1'000'000'007;
        vector memo(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        auto dfs = [&](this auto &&dfs, int i, int j, int move) -> int{
            if(i < 0 || i >= m || j < 0 || j >= n) return 1;
            if(move <= 0) return 0;
            if(memo[i][j][move] != -1) return memo[i][j][move];
            int res = 0;
            res = (res + dfs(i - 1, j, move - 1)) % MOD;
            res = (res + dfs(i + 1, j, move - 1)) % MOD;
            res = (res + dfs(i, j - 1, move - 1)) % MOD;
            res = (res + dfs(i, j + 1, move - 1)) % MOD;
            return memo[i][j][move] = res;
        };
        return dfs(startRow, startColumn, maxMove);
    }
    // O(m * n * maxMove) time, O(m * n * maxMove) extra-space
};