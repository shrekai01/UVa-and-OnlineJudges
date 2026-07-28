#define MAXC 20000

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        vector<bool> can(MAXC + 1);
        for(const auto &b : baseCosts){
            can[b] = true;
        }
        for(const auto &t : toppingCosts){
            for(int k = 0; k < 2; k++){
                for(int i = MAXC; i >= t; i--){
                    can[i] = can[i] || can[i - t];
                }
            }
        }
        int min_gap = INT_MAX, res = 0;
        for(int i = 1; i <= MAXC; i++){
            int now_gap = abs(i - target);
            if(can[i] && now_gap < min_gap){
                res = i;
                min_gap = now_gap;
            }
        }
        return res;
    }
    // O(m + n * MAXC) time, O(MAXC) extra-space
};