class Solution {
public:
    // exponentiating by squaring/double-and-add
    long long qpow(long long x, int n, int mod){
        long long res = 1 % mod;
        for(; n; n >>= 1){
            if(n & 1){
                res = res * x % mod;
            }
            x = x * x % mod;
        }
        return res;
    }
    // sliding window, Rolling Hash
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int n = s.size();
        long long p = qpow(power, k - 1, modulo);
        long long hash = 0;
        string ans = "";
        int cnt = 0;
        for(int i = n - 1; i >= 0; i--){
            hash = (hash * power + (s[i] & 31)) % modulo;
            int right = i + k - 1;
            if(right >= n) continue;
            
            if(hash % modulo == hashValue){
                ans = s.substr(i, k);
            };

            hash = (hash - (s[right] & 31) * p % modulo + modulo) % modulo;
        }
        // val(s[i]) + val(s[i + 1]) * power + ... + val(s[i + k - 1]) * power^k-1
        return ans;
    }
    // O(n) time, O(1) extra-space, where n is s.length
};