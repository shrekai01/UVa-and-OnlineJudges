class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int m = baseCosts.size(), n = toppingCosts.size();
        int res = *min_element(baseCosts.begin(), baseCosts.end());
        auto dfs = [&](this auto &&dfs, int i, int now_cost) -> void{
            int d1 = abs(now_cost - target), d2 = abs(res - target);
            if(i >= n){
                if(d1 < d2 || (d1 == d2 && now_cost < res)){
                    res = now_cost;
                }
                return;
            }
            if(now_cost >= target && d1 > d2) return;
            dfs(i + 1, now_cost + toppingCosts[i] * 2);
            dfs(i + 1, now_cost + toppingCosts[i]);
            dfs(i + 1, now_cost);
        };
        for(int i = 0; i < m; i++){
            dfs(0, baseCosts[i]);
        }
        return res;
    }
    // O(m * 3^n) time, O(n) extra-space
};