class Solution {
public:
    // single-pass traversal
    int minAbsoluteDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = 101;
        int last1_idx = -1, last2_idx = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                last1_idx = i;
                if(last2_idx == -1) continue;
                ans = min(ans, i - last2_idx);
            }
            else if(nums[i] == 2){
                last2_idx = i;
                if(last1_idx == -1) continue;
                ans = min(ans, i - last1_idx);
            }
        }
        return (ans == 101 ? -1 : ans);
    }
    // O(n) time, O(1) extra-space, where n is nums.length
};