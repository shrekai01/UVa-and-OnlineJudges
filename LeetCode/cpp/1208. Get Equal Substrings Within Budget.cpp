class Solution {
public:
    // sliding window
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int cost = 0;
        int left = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            cost += abs(s[i] - t[i]);
            while(cost > maxCost){
                cost -= abs(s[left] - t[left]);
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
    // O(n) time, O(1) extra-space, where n is s.length
};