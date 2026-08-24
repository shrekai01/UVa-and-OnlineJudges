class Solution {
public:
    // sliding window, hash table
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        int repeat_cnt = 0;
        long long ans = 0, sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            ump[nums[i]]++;
            
            int left = i - k + 1;
            if(left < 0) continue;

            if(ump.size() == k){
                ans = max(ans, sum);
            }

            sum -= nums[left];
            ump[nums[left]]--; if(!ump[nums[left]]) ump.erase(nums[left]);
        }
        return ans;
    }
    // O(n) time, O(k) extra-space, where n is nums.length
};