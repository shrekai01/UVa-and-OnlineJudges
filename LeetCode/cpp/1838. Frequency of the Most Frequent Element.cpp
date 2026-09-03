class Solution {
public:
    // sliding window, sorting
    int maxFrequency(vector<int>& nums, int k) {
        ranges::sort(nums);
        long long used = 0;
        int ans = 1;
        int left = 0;
        for(int i = 1; i < nums.size(); i++){
            used += 1LL * (nums[i] - nums[i - 1]) * (i - left);
            while(used > k){
                used -= nums[i] - nums[left];
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
    // O(n * log(n)) time, O(log(n)) extra-space if considering the stack used by ranges::sort, where n is nums.length
};