class Solution {
public:
    // prefix sum
    int subarraySum(vector<int>& nums) {
        vector<int> pre_sum(nums.size() + 1);
        for(int i = 0; i < nums.size(); i++){
            pre_sum[i + 1] = pre_sum[i] + nums[i];
        }
        
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            int l = max(0, i - nums[i]);
            int r = i;
            sum += pre_sum[r + 1] - pre_sum[l];
        }
        return sum;
    }
    // O(n) time, O(n) extra-space, where n is nums.length
};