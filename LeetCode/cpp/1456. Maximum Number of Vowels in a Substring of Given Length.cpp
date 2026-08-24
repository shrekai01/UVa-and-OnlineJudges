#define is_vowel(c) ((c) == 'a' || (c) == 'e' || (c) == 'i' || (c) == 'o' || (c) == 'u')

class Solution {
public:
    // sliding window
    int maxVowels(string s, int k) {
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(is_vowel(s[i])) cnt++;
            int left = i - k + 1;
            if(left < 0){
                continue;
            }

            ans = max(ans, cnt);
            if(ans == k) break; // answer reached the theoretical maximum
            
            if(is_vowel(s[left])) cnt--;
            left++;
        }
        return ans;
    }
    // O(n) time, O(1) extra-space, where n is s.length
};