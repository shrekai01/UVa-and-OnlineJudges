class Solution {
public:
    // sliding window, hash table
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        int left = 0;
        unordered_set<int> ust;
        for(int i = 0; i < n; i++){
            int x = nums[i];
            while(ust.contains(x)){
                sum -= nums[left];
                ust.erase(nums[left]);
                left++;
            }
            sum += x;
            ust.insert(x);
            ans = max(ans, sum);
        }
        return ans;
    }
    // O(n) time, O(min(n, U)) extra-space, where n is nums.length and U is max(nums)
};