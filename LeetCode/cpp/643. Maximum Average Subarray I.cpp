class Solution {
public:
    // sliding window
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        double ans = -10000; // values can be negative
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int left = i - k + 1;
            if(left < 0){
                continue;
            }

            ans = max(ans, sum / k);
            
            sum -= nums[left];
        }
        return ans;
    }
    // O(n) time, O(1) extra-space, where n is nums.length
};