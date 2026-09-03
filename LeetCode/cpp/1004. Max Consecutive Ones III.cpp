class Solution {
public:
    // sliding window
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0, left = 0, cnt0 = 0;
        for(int i = 0; i < nums.size(); i++){
            cnt0 += 1 - nums[i];
            while(cnt0 > k){
                cnt0 -= 1 - nums[left];
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
    // O(n) time, O(1) extra-space, where n is nums.length
};