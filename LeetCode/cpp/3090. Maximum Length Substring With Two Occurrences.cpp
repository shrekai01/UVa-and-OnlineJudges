class Solution {
public:
    // sliding window, hash table
    int maximumLengthSubstring(string s) {
        int ans = 0;
        int left = 0;
        array<int, 26> cnt;
        for(int i = 0; i < s.size(); i++){
            cnt[s[i] - 'a']++;
            while(cnt[s[i] - 'a'] > 2){
                cnt[s[left++] - 'a']--;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
    // O(n) time, O(|Σ|) extra-space, where n is s.length and |Σ| is the size of the set of alphabet, which is 26.
};