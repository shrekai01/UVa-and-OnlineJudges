class Solution {
public:
    // sliding window
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        
        long long s1 = 0, s2 = 0;
        long long ans = 0;
        for(int i = 0; i < k; i++){
            ans += prices[i] * strategy[i];
            s1 += prices[i] * strategy[i];
            if(i >= k / 2) s2 += prices[i];
        }
        long long max_diff = s2 - s1;

        for(int i = k; i < n; i++){
            ans += prices[i] * strategy[i];
            
            s1 += prices[i] * strategy[i] - prices[i - k] * strategy[i - k];
            s2 += prices[i] - prices[i - k / 2];

            max_diff = max(max_diff, s2 - s1);       
        }
        if(max_diff > 0) ans += max_diff;
        return ans;
    }
    // O(n) time, O(1) extra-space, where n is prices.length == strategy.length
};