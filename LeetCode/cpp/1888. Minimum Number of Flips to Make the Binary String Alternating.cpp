class Solution {
public:
    // sliding window
    int minFlips(string s) {
        int n = s.size();
        int cnt = 0;
        int ans = n;
        for(int i = 0; i < 2 * n - 1; i++){
            cnt += ((s[i % n] - '0') % 2 != i % 2);
            int left = i - n + 1;
            if(left < 0) continue;

            ans = min({ans, cnt, n - cnt});

            cnt -= ((s[left % n] - '0') % 2 != left % 2);
        }
        return ans;
    }
    // O(n) time, O(1) extra-space, where n is s.length
};