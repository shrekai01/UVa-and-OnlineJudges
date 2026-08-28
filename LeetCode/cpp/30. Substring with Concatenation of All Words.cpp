class Solution {
public:
    // sliding window, hash table
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        unordered_map<string, int> cnt_p;
        int word_len = words[0].size();
        int window_len = word_len * words.size();
        for(const string &s : words){
            cnt_p[s]++;
        }
        for(int start = 0; start < word_len; start++){
            unordered_map<string, int> cnt_w;
            for(int right = start + word_len; right <= s.size(); right += word_len){
                cnt_w[s.substr(right - word_len, word_len)]++;
                int left = right - window_len;
                if(left < 0) continue;
                
                if(cnt_w == cnt_p) ans.emplace_back(left);

                string t = s.substr(left, word_len);
                cnt_w[t]--;
                if(cnt_w[t] == 0) cnt_w.erase(t);
            }
        }
        return ans;
    }
    // O((n * wordLen + m) * wordLen) time, O(m * wordLen) extra-space, 
    // where n is s.length, m is words.length, and wordLen is words[i].length
};