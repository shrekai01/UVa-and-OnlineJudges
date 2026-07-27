class Solution {
public:
    int countVowelStrings(int n) {
        char vowels[] = {'a', 'e', 'i', 'o', 'u'};
        vector<vector<int>> memo(n + 1, vector<int>(128, -1));
        auto dfs = [&](this auto &&dfs, int n, int last_ch) -> int{
            if(n == 0) return 1;
            if(memo[n][last_ch] != -1) return memo[n][last_ch];
            if(last_ch == 0){
                int res = 0;
                for(int i = 0; i < 5; i++){
                    res += dfs(n - 1, vowels[i]);
                }
                return memo[n][last_ch] = res;
            }
            else{
                int res = 0;
                for(int i = 0; i < 5; i++){
                    if(vowels[i] < last_ch) continue;
                    res += dfs(n - 1, vowels[i]);
                }
                return memo[n][last_ch] = res;
            }
        };
        return dfs(n, 0);
    }
};