class Solution {
public:
    // sliding window, hash table
    bool checkInclusion(string s1, string s2) {
        int k = s1.size(), n = s2.size();
        if(k > n) return false;
        unordered_map<char, int> cnt1, cnt2;
        for(int i = 0; i < k; i++){
            cnt1[s1[i]]++;
        }
        for(int i = 0; i < n; i++){
            cnt2[s2[i]]++;
            int left = i - k + 1;
            if(left < 0) continue;

            if(cnt1 == cnt2) return true;

            cnt2[s2[left]]--;
            if(!cnt2[s2[left]]) cnt2.erase(s2[left]);
        }
        return false;
    }
    // O(n * ∣Σ∣) time, O(k) extra-space, where n is s2.length, k is s1.length, and ∣Σ∣ is the size of the set of alphabet(26)
};