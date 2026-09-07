class Solution {
public:
    // Two Pointers
    string reversePrefix(string s, int k) {
        for(int l = 0, r = k - 1; l < r; l++, r--){
            swap(s[l], s[r]);
        }
        return s;
    }
    // O(k) time, O(1) extra-space
};