class Solution {
public:
    // this problem is to find longest **subsequence**
    // so the order doesn't actually matter
    // we can sort the array at first, and solve it with sliding window

    // sliding window, sorting
    int maximumBeauty(vector<int>& nums, int k) {
        ranges::sort(nums);
        int ans = 0, left = 0;
        for(int i = 0; i < nums.size(); i++){
            while(nums[i] - nums[left] > 2 * k){
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
    // O(n * log(n)) time, O(log(n)) extra-space if considering the stack used by ranges::sort, where n is nums.length
};