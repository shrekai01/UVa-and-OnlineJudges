class Solution {
public:
    // dp
    void add(int i, int j, int maxMove, vector<vector<vector<int>>> &dp){
        for(int k = 1; k <= maxMove; k++){
            dp[i][j][k]++;
        }
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int MOD = 1'000'000'007;
        vector dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, 0)));
        
        // initialization
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0) add(i, j, maxMove, dp);
                if(i == m - 1) add(i, j, maxMove, dp);
                if(j == 0) add(i, j, maxMove, dp);
                if(j == n - 1) add(i, j, maxMove, dp);
            }
        }
        
        for(int k = 1; k <= maxMove; k++){
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(i - 1 >= 0) dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % MOD;
                    if(i + 1 < m) dp[i][j][k] = (dp[i][j][k] + dp[i + 1][j][k - 1]) % MOD;
                    if(j - 1 >= 0) dp[i][j][k] = (dp[i][j][k] + dp[i][j - 1][k - 1]) % MOD;
                    if(j + 1 < n) dp[i][j][k] = (dp[i][j][k] + dp[i][j + 1][k - 1]) % MOD;
                }
            }
        }
        return dp[startRow][startColumn][maxMove];
    }
    // O(m * n * maxMove) time, O(m * n * maxMove) extra-space
};