class Solution {
public:
    // sliding window, hash table
    int takeCharacters(string s, int k) {
        int cnt[3]{};
        for(int i = 0; i < s.size(); i++){
            cnt[s[i] - 'a']++;
        }
        if(cnt[0] < k || cnt[1] < k || cnt[2] < k) return -1;
        int max_len = 0, left = 0;
        for(int i = 0; i < s.size(); i++){
            cnt[s[i] - 'a']--;
            while(cnt[s[i] - 'a'] < k){
                cnt[s[left] - 'a']++;
                left++;
            }
            max_len = max(max_len, i - left + 1);
        }
        return s.size() - max_len;
    }
    // O(n + |Σ|) time, O(|Σ|) extra-space, where n is s.length and |Σ| is the size of the set of alphabet, which is 3.
};