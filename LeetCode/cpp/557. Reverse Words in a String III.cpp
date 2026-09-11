class Solution {
public:
    // Two Pointers
    string reverseWords(string s) {
        int n = s.size();
        int l = 0;
        while(l < n){
            int r = s.find(' ', l);
            if(r == string::npos) r = n;
            reverse(s.begin() + l, s.begin() + r);
            l = r;
            while(l < n && s[l] == ' '){
                l++;
            }
        }
        return s;
    }
    // O(n) time, O(1) extra-space, where n is s.length
};