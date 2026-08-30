class Solution {
public:
    // sliding window, hash table
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        array<int, 128> cnt{}; // remember to initialize array
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            cnt[s[i]]++;
            while(cnt[s[i]] >= 2){
                cnt[s[left]]--;
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
    // O(n) time, O(|Σ|) extra-space, where n is s.length and |Σ| is the size of the set of alphabet, which is 128
};