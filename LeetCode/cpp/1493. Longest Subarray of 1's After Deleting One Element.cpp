class Solution {
public:
    // sliding window
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int left = 0, zeros = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) zeros++;
            while(zeros >= 2){
                if(nums[left] == 0) zeros--;
                left++;
            }
            ans = max(ans, i - left);
        }
        return ans;
    }
    // O(n) time, O(1) extra-space, where n is nums.length
};