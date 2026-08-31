class Solution {
public:
    // 2^(k-1) * s_{0} + 2^(k-2) * s_{1} + ... + 2^0 * s_{k-1}
    // exponentiating by squaring
    int qpow(long long x, int n){
        int res = 1;
        for(; n; n >>= 1, x *= x){
            if(n & 1){
                res *= x;
            }
        }
        return res;
    }
    // sliding window, Rolling Hash, hash table
    bool hasAllCodes(string s, int k) {
        if(k > s.size()) return false;
        unordered_set<int> ust;
        int p = qpow(2, k - 1);
        int now = 0;
        for(int i = 0; i < k; i++){
            now = now * 2 + (s[i] - '0');
        }
        ust.insert(now);
        for(int i = k; i < s.size(); i++){
            int left = i - k;
            now -= p * (s[left] - '0');
            now = now * 2 + (s[i] - '0');
            ust.insert(now);
        }
        return ust.size() == p * 2; // if ust.size() == 2^k, then every binary code of length k is a substring of s
    }
    // O(n) time, O(2^k) extra-space, where n is s.length
};