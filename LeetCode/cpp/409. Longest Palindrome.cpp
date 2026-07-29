class Solution {
public:
    // greedy
    int longestPalindrome(string s) {
        int n = s.size();
        vector<int> cnt(128);
        for(int i = 0; i < n; i++){
           cnt[s[i]]++;
        }
        bool have_odd = false;
        int res = 0;
        for(int i = 0; i < 128; i++){
            if(cnt[i] % 2 == 1){
                res += cnt[i] - 1; // if odd, the part of odd-1 letters can always contribute(half for left end and half for right end) to the longest palindrome
                have_odd = true;
            }
            else res += cnt[i]; // if even, the whole part can always contribute(half for left end and half for right end) to the longest palindrome
        }
        if(have_odd) res++; // if there are odd counts, then one of the arbitrary odd counts can contribute a letter(be the middle one) to the longest palindrome.
        return res;
    }
    // O(n) time, O(1) extra-space
};