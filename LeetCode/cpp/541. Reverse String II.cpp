class Solution {
public:
    // Two Pointers
    string reverseStr(string s, int k) {
        int n = s.size();
        for(int i = 0; i < n; i += 2 * k){
            int l = i, r = min(n - 1, i + k - 1);
            while(l < r){
                swap(s[l], s[r]);
                l++, r--;
            }
        }
        return s;
    }
    // O(n) time, O(1) extra-space, where n is s.length
};