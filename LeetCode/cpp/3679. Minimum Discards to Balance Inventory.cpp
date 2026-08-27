class Solution {
public:
    // sliding window, hash table, greedy
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        unordered_map<int, int> cnt;
        int ans = 0;
        for(int i = 0; i < arrivals.size(); i++){
            if(cnt[arrivals[i]] == m){
                arrivals[i] = 0; // indicate discarded by assigning a value not in arrivals
                ans++;
            }
            else cnt[arrivals[i]]++;
            int left = i - w + 1;
            
            if(left < 0) continue;
            
            cnt[arrivals[left]]--;
        }
        return ans;
    }
    // O(n + U) time, O(w) extra-space, where n is arrivals.length and U is max(arrivals)
};