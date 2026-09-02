class Solution {
public:
    // sliding window
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        ranges::sort(nums);
        int ans = n;
        int left = 0;
        for(int i = 0; i < n; i++){
            while(nums[i] > 1LL * k * nums[left]){
                left++;
            }
            ans = min(ans, n - (i - left + 1));
        }
        return ans;
    }
    // O(n) time, O(1) extra-space, where n is nums.length
};