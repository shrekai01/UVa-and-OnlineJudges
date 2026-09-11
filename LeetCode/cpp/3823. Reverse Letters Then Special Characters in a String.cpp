class Solution {
public:
    // Two Pointers
    void reverse(string &s, auto &&func){
        int l = 0, r = s.size() - 1;
        while(l < r){
            while(l < r && func(s[l])){
                l++;
            }
            while(l < r && func(s[r])){
                r--;
            }
            swap(s[l], s[r]);
            l++, r--;
        }
    }
    string reverseByType(string s) {
        reverse(s, ::islower);
        reverse(s, [](const char c){return !islower(c);});
        return s;
    }
    // O(n) time, O(1) extra-space, where n is s.length
};