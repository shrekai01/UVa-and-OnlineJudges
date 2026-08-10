class Solution {
public:
    // single-pass traversal
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int mn = nums[0];
        int ans = 0;
        for(int i = 1; i < n; i++){
            ans = max(ans, nums[i] - mn);
            mn = min(mn, nums[i]);
        }
        return ans ? ans : -1;
    }
    // O(n) time, O(1) extra-space, where n is nums.length
};