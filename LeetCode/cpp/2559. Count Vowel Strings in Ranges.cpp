#define is_vowel(c) (((c) == 'a') || ((c) == 'e') || ((c) == 'i') || ((c) == 'o') || ((c) == 'u'))

class Solution {
public:
    // prefix sum
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size(), m = queries.size();
        vector<int> pre_sum(n + 1);
        for(int i = 0; i < n; i++){
            const string &s = words[i];
            pre_sum[i + 1] = pre_sum[i];
            if(is_vowel(s[0]) && is_vowel(s[s.size() - 1])) pre_sum[i + 1]++;
        }
        
        vector<int> ans(m);
        for(int i = 0; i < m; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            ans[i] = pre_sum[r + 1] - pre_sum[l];
        }
        return ans;
    }
    // O(n + m) time, O(n) extra-space, where n is words.length, m is queries.length
};