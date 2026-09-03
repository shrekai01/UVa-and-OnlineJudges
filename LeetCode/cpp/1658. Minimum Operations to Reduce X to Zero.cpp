class Solution {
public:
    // sliding window
    int minOperations(vector<int>& nums, int x) {
        int target = std::reduce(nums.begin(), nums.end(), 0) - x;
        if(target < 0) return -1;

        int sum = 0;
        int max_len = -1, left = 0; // Since subarray can be empty, initialize max_len to -1 in order to differentiat no subarray found or empty subarrays found.
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            while(sum > target){
                sum -= nums[left];
                left++;
            }
            if(sum == target){
                max_len = max(max_len, i - left + 1);
            }
        }
        return max_len == -1 ? max_len : nums.size() - max_len;
    }
    // O(n) time, O(1) extra-space, where n is nums.length
};