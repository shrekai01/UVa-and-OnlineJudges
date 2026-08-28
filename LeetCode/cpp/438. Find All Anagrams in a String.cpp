class Solution {
public:
    // sliding window, hash table
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        array<int, 26> cnt_w, cnt_p;
        for(int i = 0; i < p.size(); i++){
            cnt_p[p[i] - 'a']++;
        }
        for(int i = 0; i < s.size(); i++){
            cnt_w[s[i] - 'a']++;
            int left = i - p.size() + 1;
            if(left < 0) continue;
            
            if(cnt_w == cnt_p) ans.emplace_back(left);

            cnt_w[s[left] - 'a']--;
        }
        return ans;
    }
    // O(n + m * |Σ|) time, O(|Σ|) extra-space, where n is s.length, m is p.length, and |Σ| is the size of the set of alphabet, which is 26
};