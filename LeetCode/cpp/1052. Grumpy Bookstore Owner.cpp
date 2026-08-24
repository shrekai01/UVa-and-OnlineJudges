class Solution {
public:
    // sliding window
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans = 0;
        int s = 0, max_s = 0;
        for(int i = 0; i < customers.size(); i++){
            if(!grumpy[i]) ans += customers[i];
            else s += customers[i];

            int left = i - minutes + 1;
            if(left < 0) continue;
            
            max_s = max(max_s, s);
            
            if(grumpy[left]) s -= customers[left];
        }
        
        return ans + max_s;
    }
    // O(n) time, O(1) extra-space, where n is customers.length
};