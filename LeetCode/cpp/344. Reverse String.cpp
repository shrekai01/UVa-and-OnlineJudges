class Solution {
public:
    // Two Pointers
    void reverseString(vector<char>& s) {
        for(int i = 0; i < s.size() / 2; i++){
            swap(s[i], s[s.size() - 1 - i]);
        }
    }
    // O(n) time, O(1) extra-space, where n is s.length
};