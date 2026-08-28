class Solution {
public:
    // sliding window, hash table
    // 子字串越小，越能夠滿足<=maxLetters的條件；且子字串越小，越能夠在字串內出現越多次
    // 結合上述兩點，我們只需要以size恰為minSize的sliding window去解，maxSize其實並不重要
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size();
        unordered_map<string, int> ump;
        unordered_map<char, int> cnt;
        int ans = 0;
        for(int i = 0; i < n; i++){
            cnt[s[i]]++;
            int left = i - minSize + 1;
            if(left < 0) continue;
            if(cnt.size() <= maxLetters){
                ans = max(ans, ++ump[s.substr(left, minSize)]);
            }
            cnt[s[left]]--;
            if(!cnt[s[left]]) cnt.erase(s[left]);
        }
        return ans;
    }
    // O((n - minSize) * minSize) time, O((n - minSize) * minSize) extra-space,
    // where n is s.length
};