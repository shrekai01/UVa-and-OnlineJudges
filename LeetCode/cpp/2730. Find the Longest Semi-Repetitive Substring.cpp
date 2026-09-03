class Solution {
public:
    // sliding window
    int longestSemiRepetitiveSubstring(string s) {
        int ans = 1;
        int cnt = 0;
        int left = 0;
        for(int i = 1; i < s.size(); i++){
            cnt += (s[i] == s[i - 1]);
            while(cnt > 1){
                cnt -= (s[left] == s[left + 1]);
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
    // O(n) time, O(1) extra-space, where n is s.length
};