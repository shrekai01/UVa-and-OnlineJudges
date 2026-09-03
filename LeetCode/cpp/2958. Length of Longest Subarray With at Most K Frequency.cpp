class Solution {
public:
    // sliding window, hash table
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        int left = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int x = nums[i];
            cnt[x]++;
            while(cnt[x] > k){
                cnt[nums[left]]--;
                if(cnt[nums[left]] == 0){
                    cnt.erase(nums[left]);
                }
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
    // O(n) time, O(min(n, U)) extra-space, where n is nums.length and U is max(nums)
};