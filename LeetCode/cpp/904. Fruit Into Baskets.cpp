class Solution {
public:
    // sliding window, hash table
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> cnt;
        int ans = 0;
        int left = 0;
        for(int i = 0; i < n; i++){
            cnt[fruits[i]]++;
            while(cnt.size() > 2){
                cnt[fruits[left]]--;
                if(cnt[fruits[left]] == 0){
                    cnt.erase(fruits[left]);
                }
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
    // O(n) time, O(1) extra-space, where n is fruits.length.
    // There are at most 3 key-value pairs in the hash table at any point.
};