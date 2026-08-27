class Solution {
public:
    // sliding window, hash table
    int distinctPoints(string s, int k) {
        unordered_set<long long> st;
        int n = s.size();
        int x = 0, y = 0;
        for(int i = 0; i < s.size(); i++){
            x += (s[i] == 'R') - (s[i] == 'L');
            y += (s[i] == 'U') - (s[i] == 'D');
            int left = i - k + 1;
            if(left < 0) continue;
            st.insert(1LL * (x + n) << 32 | (y + n)); // +n prevent from inserting negative numbers
            
            x -= (s[left] == 'R') - (s[left] == 'L');
            y -= (s[left] == 'U') - (s[left] == 'D');
        }
        return st.size();
    }
    // O(n) time, O(n - k) extra-space, where n is s.length. 
    // There are at most n - k + 1 windows, and similarly there are at most n - k + 1 elements in the set simultaneously.
};