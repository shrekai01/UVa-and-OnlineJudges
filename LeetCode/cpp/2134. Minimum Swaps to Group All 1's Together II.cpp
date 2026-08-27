class Solution {
public:
    // sliding window
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for(int i = 0; i < n; i++){
            if(nums[i]) k++;
        }
        int cnt = 0;
        int ans = k;
        for(int i = 0; i < n + k - 1; i++){
            cnt += nums[i % n];
            int left = i - k + 1;
            if(left < 0) continue;
            
            ans = min(ans, k - cnt);

            cnt -= nums[left % n];
        }
        return ans;
    }
    // O(n) time, O(1) extra-space, where n is nums.length
};