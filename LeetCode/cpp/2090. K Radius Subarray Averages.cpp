class Solution {
public:
    // sliding window
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> res(nums.size(), -1);
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int left = i - 2 * k;
            if(left < 0) continue;
            
            res[i - k] = sum / (2 * k + 1);

            sum -= nums[left];
        }
        return res;
    }
    // O(n) time, O(1) extra-space, where n is nums.length
};