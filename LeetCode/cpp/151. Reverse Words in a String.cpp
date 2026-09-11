class Solution {
public:
    // Two Pointers
    string reverseWords(string s) {
        int n = s.size();
        int r = n - 1;
        while(r >= 0 && s[r] == ' '){
            r--;
        }
        string ans;
        while(r >= 0){
            int l = r;
            while(l >= 0 && s[l] != ' '){
                l--;
            }
            if(ans.size() != 0) ans += " ";
            ans += s.substr(l + 1, r - l);
            r = l;
            while(r >= 0 && s[r] == ' '){
                r--;
            }
        }
        return ans;
    }
    // O(n) time, O(1) extra-space, where n is s.length
};